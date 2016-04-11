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
	m_zMaterialBackground.MakeTextureDiffuse("textures\\neon.jpg");
	m_zMaterialBackground.SetTextureGlowAsDiffuse();
	m_zMaterialTube.LoadPreset("Glass");

	//Background
	m_zBackground.Init(&m_zMaterialBackground, CFloatRect(0.0, 0.0, 1.0, 1.0));

	//Init Objects
	m_zgSphere.Init(0.5F, &m_zMaterialKugel, 50, 50);
	//m_zTube.Init(CHVector(0, 0, 0), &m_zMaterialTube, );

	//Root
	m_zr.AddFrame(&m_zf);
	m_zr.AddScene(&m_zs);
	m_zr.AddMaterial(&m_zMaterialKugel);
	m_zr.AddMaterial(&m_zMaterialBackground);

	//Frame
	m_zf.AddViewport(&m_zv);
	m_zf.AddDeviceKeyboard(&m_zKeyboard);

	//Viewport
	m_zpCamera.AddCamera(&m_zc);
	m_zpSphere.AddGeo(&m_zgSphere);
	m_zpTube.AddGeo(&m_zTube);
	m_zv.AddBackground(&m_zBackground);

	//Scene
	m_zs.AddPlacement(&m_zpCamera);
	m_zs.AddPlacement(&m_zpSphere);
	m_zs.AddLightParallel(&m_zl);
	m_zs.AddPlacement(&m_zpTube);

	//Rotieren, Translieren, Skalieren
	m_zpTube.RotateX(UM_DEG2RAD(90));
	m_zpCamera.TranslateZ(15.0F);

	//Keyboard sensitivity
	m_zKeyboard.SetWASDTranslationSensitivity(5.0F);

	//Meteoriten der Scene hinzufügen
	m_zMeteoriten.Init(&m_zs);
}

void CGame::Tick(float fTime, float fTimeDelta)
{

	// Hier die Echtzeit-Veränderungen einfügen:
	

	//Raumschiffgeschwindigkeit
	m_zpSphere.TranslateZDelta(-2.0F * fTimeDelta); //Raumschiffgeschwindigkeit

	//Cameraposition
	CameraPosition(); 

	//Meteoriten werden erzeugt und erneuert
	m_zMeteoriten.RenewMeteorits(&m_zpSphere);

	m_zSteuerung.Bewegung(&m_zpSphere);

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

void CGame::CameraPosition()
{
	m_zpCamera.Translate(m_zCameraTranslation.operator = (m_zpSphere.GetTranslation()));

	if (bFirstPerson == false)
		m_zpCamera.TranslateZDelta(15.0F);
}

float CGame::Clamp(float input, float min, float max)
{
	float output = input;

	if (output > max)
		output = max;
	if (output < min)
		output = min;

	return output;
}

