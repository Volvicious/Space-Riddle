
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
	output.f4Pos = mul(input.f4Pos, mWorld);
	output.f4VertexPos = output.f4Pos; // Speiechere die ursprüngliche Vertex-Position in einer anderen Variablen ab, man wird sie später für die Lichtberechnung im Pixelshader nochmal brauchen
	output.f2TexCoord = input.f2TexCoord; // Reiche die UV-Koordinaten an den Pixelshader weiter!
	matrix mViewProj = mul(mView, mProjection); // Berechne die ViewProjection-Matrix ...
	output.f4Pos = mul(output.f4Pos,mViewProj); // ... und positioniere damit die Vertex-Position 

	float4 f4Z; // Ursprung
	f4Z.xyz = 0;
	f4Z.w = 1;
	output.f3CamPos = mul(f4Z, mViewInv).xyz;  // f3CamPos ist der Ursprung mit der inversen View Matrix-multipliziert ( wo liegt die Kamera?) 
	output.f3Normal = normalize(mul(input.f3Normal, (float3x3)mWorld)); // Multipliziere die Normale des Vertex mit der World-Matrix
	output.f3Tangent = normalize(mul(input.f3Tangent, (float3x3)mWorld)); // Multipliziere die Tangente des Vertex mit der World-Matrix
	output.f3Bitangent = normalize(mul(input.f3Bitangent, (float3x3)mWorld)); // Multipliziere die Biteangente des Vertex mit der World-Matrix

	SLight lightCurrent;
	int lightCurrentId = iLightsAffecting[0]; // Wir gehen vereinfachend davon aus: Es gäbe nur ein Parallellicht
	lightCurrent = Lights[lightCurrentId];
	output.aafffectinglight[0].f3Direction = normalize(lightCurrent.f3Direction);  // die Lichtrichtung f3Direction muss normalisiert werden 
	output.aafffectinglight[0].fLuminosity = 1; // Vereinfachend: Stärke des Lichtes gleich 1 

	return output;

}


//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(PS_INPUT input) : SV_Target
{
	float fSpecular = 0;
	// Berechne Entfernung zwischen Kamera und Vertex:
	float3 f3Distance = input.f3CamPos - input.f4VertexPos.xyz; // Berechne den Entfernungvektor zwischen der Kamera und der Vertex-Position
	float fDistance = length(f3Distance); // Speichere den Betrag (=Länge) des Vektors

  	float3 f3EyeVector = normalize(input.f3CamPos - input.f4VertexPos.xyz); // Berechne die Blickrichtung!
	
	float4 f4ColorOut; // Ausgangsfarbe des Pixels
	f4ColorOut.xyzw = 0; // Setze Ausgangsfarbe auf schwarz
	float2 f2ParallaxTex = input.f2TexCoord; // UV-Koordinaten
	if (uBump)  // Ist Bumpmapping dabei?
	{
		float3 f3BumpNormal = ((2 * (tex2D[3].Sample(linearSampler, f2ParallaxTex))) - 1.0).xyz; // Hole Pixelfarbe und berechne daraus den Beugungsvektor
		f3BumpNormal *= fBumpStrength; // Gewichte Beugungsvektor mit der gewünschten Bumpmapping-Stärke
		input.f3Normal = f3BumpNormal.r*input.f3Tangent + f3BumpNormal.g*input.f3Bitangent + f3BumpNormal.b*input.f3Normal; // Berechne aus dem Beugungsvektor die neue Oberflächennormale 
		input.f3Normal = normalize(input.f3Normal); // Normalisiere zur Sicherheit die Oberflächennormale (es könnte ja sein, dass die Bumpmap falsche Werte hat)
	}
	float fShading = saturate(dot(-input.aafffectinglight[0].f3Direction, input.f3Normal)); // Berechne, wie "zugewandt" die Oberflächennormale zum Licht ist
	float4 f4ColGlow;
	f4ColGlow.rgba = 0;
	if (uGlow)// Ist Glowmapping dabei?
	{
		f4ColGlow = tex2D[1].Sample(linearSampler, f2ParallaxTex)*(1 - fShading); // ´(1-fShading) ist die "Licht-Abgewandtheit", gewichte damit die Glow-Map!
	}
	float4 f4Specular;
	f4Specular.rgba = 0; // Setze die Spekulare Textur auf schwarz!
	if (uSpecular) // Gibt es eine spekulare Textur? 
	{
		float3 f3Half = normalize(-input.aafffectinglight[0].f3Direction + f3EyeVector);
		fSpecular = pow(saturate(dot(normalize(input.f3Normal), f3Half)), fSpecularSharpness); // Empirische Formel
		f4Specular.rgb = fSpecular;
	}

	f4ColorOut = tex2D[0].Sample(linearSampler, f2ParallaxTex); 
	f4ColorOut.rgb = fShading*f4ColorOut.rgb+f4ColGlow.rgb + f4Specular.rgb; // Addiere sinnfällig die spekulare, die glow-mäßige und die diffusen Textur!

	


	/*
	// Schneeshader:
	if(input.f3Normal.y>0.3)
		f4ColorOut.rgb += 2*(input.f3Normal.y-0.3f);
	if (input.f3Normal.y<-0.3)
		f4ColorOut.rgb -= 2*(input.f3Normal.y + 0.3f);
	*/	
	/*
	// Entfernungslaser:
	if (fDistance>50 && fDistance < 50.3)
		f4ColorOut.r = 1.0f;
	*/
	/*
	// Nebelshader:
	f4ColorOut.rgb += fDistance*0.0005f;
	*/

	/*
	f4ColorOut.r *= 2.5f;
	f4ColorOut.g *= 2.0f;
	*/
	/*
	// Nachtsichtgerät:
	f4ColorOut.rb = 0.0f;
	f4ColorOut.g = 1.0f - f4ColorOut.y * 2.0f;
	*/
	/*
	// Rauchshader:
	//	f4ColorOut.rgb -= fDistance*0.002f;
	*/
	/*
	// Toon-Stufen:
	int4 i4ColorOut = (int4)(f4ColorOut * 3);
	f4ColorOut = (float4)i4ColorOut;
	f4ColorOut /= 3.0f;
	*/
	f4ColorOut = saturate(f4ColorOut); // Beschneide die Ausgangspixelfarbe, die Pixelwerte dürfen nur zwischen 0.0 und 1.0 liegen 

	return f4ColorOut; // Gib die Ausgangspixelfarbe aus!
}
