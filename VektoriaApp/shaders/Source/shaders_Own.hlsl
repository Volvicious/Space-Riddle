
//--------------------------------------------------------------------------------------
// Copyright (c) Tobias Breiner, Vektoria UG (haftungsbeschränkt)
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// Shadow Map Samplers
//--------------------------------------------------------------------------------------

SamplerComparisonState shadowSampler : register(s2);

SamplerState pointSampler : register(s1);

SamplerState linearSampler : register(s0);

//--------------------------------------------------------------------------------------
// Information that are provided by object
// ie: position in world space and lights affecting its surface
//--------------------------------------------------------------------------------------
cbuffer ObjectInfo : register(b0)
{
	matrix mWorld;
	matrix mView;
	matrix mViewInv;
	matrix mProjection;
	vector<uint, 4> iLightsAffecting;
	uint uLights;
}

//--------------------------------------------------------------------------------------
// Material & Texture Information Variables
//--------------------------------------------------------------------------------------
cbuffer TexInfo : register(b1)
{
	matrix mColor					: packoffset(c0);

	float fBumpStrength				: packoffset(c4);
	float fHeightStrength			: packoffset(c4.y);
	float fGlowStrength				: packoffset(c4.z);
	float fDummyStrength			: packoffset(c4.w);

	float fSpecularSharpness		: packoffset(c5);
	float fDiffuseSharpness			: packoffset(c5.y);
	float fGlowSharpness			: packoffset(c5.z);

	float frTransparency			: packoffset(c5.w);
	float fDummy2					: packoffset(c6.x);
	float fFresnel					: packoffset(c6.y);
	float fRefractionRatio			: packoffset(c6.z);
	float frTransparencyEdge		: packoffset(c6.w);

	float3 f3ColorSSS				: packoffset(c7);
	float  fDummy3					: packoffset(c7.w);

	float4 f4SSSBRDFParams			: packoffset(c8);

	uint uImage						: packoffset(c9);
	uint uGlow						: packoffset(c9.y);
	uint uSpecular					: packoffset(c9.z);
	uint uBump						: packoffset(c9.w);
	uint uImageBlack				: packoffset(c10);
	uint uGlowAsImage				: packoffset(c10.y);
	uint uSpecularAsImage			: packoffset(c10.z);
	uint uHeightAsImage				: packoffset(c10.w);
	uint uImageWhite				: packoffset(c11);
	uint uGlowWhite					: packoffset(c11.y);
	uint uSpecularWhite				: packoffset(c11.z);
	uint uHeight					: packoffset(c11.w);
	uint uShadingOn					: packoffset(c12);
	uint uGlowAsAmbient				: packoffset(c12.y);
	uint uChromaKeying				: packoffset(c12.z);
	uint uEnvironment				: packoffset(c12.w);
	uint uPOM						: packoffset(c13);
	uint uTexBRDF					: packoffset(c13.y);
	uint uTexSSS					: packoffset(c13.z);
	uint uReflectionMap				: packoffset(c13.w);
	uint uixPos						: packoffset(c14);
	uint uiyPos						: packoffset(c14.y);
	uint uixPics					: packoffset(c14.z);
	uint uiyPics					: packoffset(c14.w);


	//	uint uiTextureAdressMode		: packoffset(c15);
}

cbuffer ViewportArt : register(b2)
{
	float4 f4ColorViewportOutline	: packoffset(c0);
	float4 f4FogParams				: packoffset(c1);
	matrix mColorModification		: packoffset(c2);

	uint uStyleColor				: packoffset(c6);
	uint uPostprocessing			: packoffset(c6.y);
	uint uStylePopart				: packoffset(c6.z);
	uint uStyleOutlining			: packoffset(c6.w);
	uint uStyleMonochrome			: packoffset(c7);
	uint uStyleOwn					: packoffset(c7.y);
	uint uStyleFog					: packoffset(c7.z);
	uint uPad0						: packoffset(c7.w);
}

//--------------------------------------------------------------------------------------
// Light information variables
//--------------------------------------------------------------------------------------
struct SLight
{
	float3 f3Position;				// all lights
	uint uType;						// all lights
	float4 f4Color;					// all lights
	float3 f3Direction;				// directional light, spot light
	float fInnerCosAngle;			// spot light
	float fOuterCosAngle;			// spot light
	float fAttenuationConstant;		// point light, spot light
	float fAttenuationLinear;		// point light, spot light
	float fAttenuationQuadratic;	// point light, spot light
	bool bCauseShadow;				// spot light, true, wenn das Spotlight Schatten verursachen soll
	bool bSoftShadow;				// spot light, true, wenn die Schatten weich sein sollen 
	bool bCascadedShadow;			// spot light, true, wenn die Schatten kaskadiert sein sollen
	float4x4 mLightViewProj;		// all lights, mView-korrigierte Projektionsmatrix des Lichtes
};

struct SAffectingLight
{
	float fLuminosity;
	float3 f3Direction;
	float4 f4Color;
	float3 f3SpotDirection;
	float fSpotInnerCosAngle;
	float fSpotOuterCosAngle;
	bool bCauseShadow;
	bool bSoftShadow;
	bool bCascadedShadow;
	uint uId;
	uint uType;
	float4 f4LightPos : TEXCOORD0;
};

StructuredBuffer<SLight> Lights : register (t10);

Texture2D shadowMap : register (t11);

//--------------------------------------------------------------------------------------
// Textur Buffer
// 0=Diffuse, 1=Glow(emissive), 2=Specular, 3=DotBumpMap, 4 = Environmental 
//--------------------------------------------------------------------------------------

Texture2D tex2D[7] : register (t15); // texture

//--------------------------------------------------------------------------------------

struct VS_INPUT
{
	float4 f4Pos : POSITION;
	float3 f3Normal : NORMAL;
	float2 f2TexCoord : TEXCOORD;
	float3 f3Tangent : TANGENT;
	float3 f3Bitangent : BITANGENT;
};

struct PS_INPUT
{
	float4 f4Pos : SV_POSITION0;
	float3 f3Normal : NORMAL;
	float3 f3Tangent : TANGENT0;
	float3 f3Bitangent : BITANGENT0;
	float2 f2TexCoord : TEXCOORD0;
	float3 f3CamPos : TEXCOORD1;
	float4 f4VertexPos : TEXCOORD2;
	SAffectingLight aafffectinglight[4] : LIGHTS; // Zurzeit können maximal 4 Lichter berrechnet werden
	uint uLights : COUNT;	// Anzahl der Lichter in der Szene
};

//--------------------------------------------------------------------------------------
// Phong Lighting Reflection Model
//--------------------------------------------------------------------------------------
struct DirectionalLight
{
	float4 f4Color;
	float3 f3Dir;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
PS_INPUT VS(VS_INPUT input)
{
	PS_INPUT output = (PS_INPUT)0;
	return output;

}


//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(PS_INPUT input) : SV_Target
{
	float4 f4ColorOut; // Ausgangsfarbe des Pixels
	f4ColorOut.xyzw = 0; // Setze Ausgangsfarbe auf schwarz
	return f4ColorOut; // Gib die Ausgangspixelfarbe aus!
}
