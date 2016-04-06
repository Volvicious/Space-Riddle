#include "StdAfx.h"
#include "Game.h"

CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash)
{
	// Hier die Initialisierung der Vektoria-Objekte einfügen:
	m_zr.Init(psplash);
	m_zc.Init(QUARTERPI);
	m_zf.Init(hwnd, procOS);
	m_zv.InitFull(&m_zc);
	m_zl.Init(CHVector(1.0f, 1.0f, 1.0f), CColor(1.0f, 1.0f, 1.0f));


	
	//Materialgebung
	m_zMaterialKugel.MakeTextureDiffuse("textures\\Textur.jpg");
	m_zMaterialBoden.MakeTextureDiffuse("textures\\Boden.JPG");
	//m_zMaterialTube.MakeTextureDiffuse("textures\\Background1.jpg");
	m_zMaterialBackground.MakeTextureDiffuse("textures\\neon.jpg");
	m_zMaterialBackground.SetTextureGlowAsDiffuse();
	m_zMaterialTube.LoadPreset("Glass");

	//Background
	m_zBackground.Init(&m_zMaterialBackground, CFloatRect(0.0, 0.0, 1.0, 1.0));

	//Init Objects
	m_zgSphere.Init(0.5F, &m_zMaterialKugel, 50, 50);
	m_zTube.InitStraight(10.0F, 10.5F, 100.0F, &m_zMaterialTube);

	//Root
	m_zr.AddFrameHere(&m_zf);
	m_zr.AddScene(&m_zs);
	m_zr.AddMaterial(&m_zMaterialKugel);
	m_zr.AddMaterial(&m_zMaterialBoden);
	m_zr.AddMaterial(&m_zMaterialBackground);

	//Frame
	m_zf.AddViewport(&m_zv);
	m_zf.AddDeviceKeyboard(&m_zKeyboard);
	m_zf.AddDeviceCursor(&m_zCursor);

	//Viewport
	m_zpCamera.AddCamera(&m_zc);
	m_zpSphere.AddGeo(&m_zgSphere);
	m_zpBoden.AddGeo(&m_zPlane1);
	m_zpTube.AddGeo(&m_zTube);
	m_zv.AddBackground(&m_zBackground);

	//Scene
	m_zs.AddPlacement(&m_zpCamera);
	m_zs.AddPlacement(&m_zpSphere);
	m_zs.AddPlacement(&m_zpBoden);
	m_zs.AddLightParallel(&m_zl);
	m_zs.AddPlacement(&m_zpTube);
	m_zs.AddAudio(&m_zHomeScreen);

	//Rotieren, Translieren, Skalieren
	m_zpBoden.Translate(CHVector(0.0F, -2.0F, -1.0F));
	m_zpBoden.CopyRotationXDelta(UM_DEG2RAD(-89));
	m_zpTube.RotateX(UM_DEG2RAD(90));
	m_zpCamera.TranslateZ(15.0F);

	//Keyboard sensitivity
	m_zKeyboard.SetWASDTranslationSensitivity(5.0F);

	//fGeschwindigkeitRotation = 0.0F;

	m_zHomeScreen.Init("res\\Vektoria.wav");

	//Meteoriten Random erstellen
	//srand(time(0));

	tastaturGer.Init(&m_zKeyboard, DIK_T, true);
	textoutput.Init(&m_zv);



}

void CGame::Tick(float fTime, float fTimeDelta)
{


	
	tastaturGer.Run();
	textoutput.WriteFromTastatur(&tastaturGer);

	//TEst 

	// Hier die Echtzeit-Veränderungen einfügen:

	//Raumschiffgeschwindigkeit
	m_zpSphere.TranslateZDelta(-2.0F * fTimeDelta); //Raumschiffgeschwindigkeit

	CameraPosition(); //Cameraposition

	//WASD - Steuerung
	/*
	if (m_zKeyboard.KeyPressed(DIK_W))
	{
		m_zpSphere.TranslateYDelta(3.0F * fTimeDelta);
	}

	if (m_zKeyboard.KeyPressed(DIK_A))
	{
		m_zpSphere.TranslateXDelta(-3.0F * fTimeDelta);
	}

	if (m_zKeyboard.KeyPressed(DIK_S))
	{
		m_zpSphere.TranslateYDelta(-3.0F * fTimeDelta);
	}

	if (m_zKeyboard.KeyPressed(DIK_D))
	{
		m_zpSphere.TranslateXDelta(3.0F * fTimeDelta);
	}

	

	//Switch von 1stPerson zu 3rdPerson und vice versa
	if (m_zKeyboard.KeyDown(DIK_C))
	{
		if (bFirstPerson == true)
		{
			m_zpCamera.Translate(m_zCameraTranslation.operator = (m_zpSphere.GetTranslation()));
			m_zpCamera.TranslateZDelta(15.0F);
			bFirstPerson = false;
		}
		else
		{
			m_zpCamera.Translate(m_zCameraTranslation.operator = (m_zpSphere.GetTranslation()));
			bFirstPerson = true;
		}
	}

	//Meteorit random hinzufügen

	//m_zs.AddPlacement(&m_zm.getPlacement());

	if (m_zKeyboard.KeyPressed(DIK_U))
	{
		//fGeschwindigkeitRotation = 0.001F;
		//m_zpCamera.Translate(RotateAroundAxes('y', m_zpSphere.GetTranslation(), fGeschwindigkeitRotation, m_zpCamera.GetTranslation()));
	}
	*/
	m_zr.Tick(fTimeDelta);
}

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einfügen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:
	m_zf.ReSize(iNewWidth, iNewHeight);
}

CHVector CGame :: RotateAroundAxes(char cAxis, CHVector Origin, float fangle, CHVector Target)
{
	float xnew;
	float ynew;
	float znew;

	float s = sin(fangle);
	float c = cos(fangle);

	//Translate point back to origin
	Target.x -= Origin.x;
	Target.y -= Origin.y;
	Target.z -= Origin.z;

	//Rotation around axes
	if (cAxis == 'y')
	{
		//rotate around y axis
		xnew = Target.x * c + Target.z * s;
		ynew = Target.y;
		znew = -1.0F * s * Target.x + Target.z * c;
	}
	else if (cAxis == 'x')
	{
		//rotate around x axis
		xnew = Target.x;
		ynew = Target.y * c + (-1.0F * s * Target.z);
		znew = Target.y * s + Target.z * c;
	}
	else if (cAxis == 'z')
	{
		//rotate around z axis
		xnew = Target.x * c + (-1.0F * s * Target.y);
		ynew = Target.x * s + Target.y * c;
		znew = Target.z;
	}

	//translate point back
	Target.x = xnew + Origin.x;
	Target.y = ynew + Origin.y;
	Target.z = znew + Origin.z;

	return Target;
}

void CGame::CameraPosition()
{
	m_zpCamera.Translate(m_zCameraTranslation.operator = (m_zpSphere.GetTranslation()));

	if (bFirstPerson == false)
		m_zpCamera.TranslateZDelta(15.0F);
}
