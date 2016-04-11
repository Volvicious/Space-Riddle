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
	m_zc.Init(&m_zv, &m_zs);
	m_zf.Init(hwnd, procOS);
	m_zl.Init(CHVector(1.0f, 1.0f, 1.0f), CColor(1.0f, 1.0f, 1.0f));

	//Materialgebung
	m_zMaterialKugel.MakeTextureDiffuse("textures\\Textur.jpg");
	m_zMaterialBackground.MakeTextureDiffuse("textures\\neon.jpg");
	m_zMaterialBackground.SetTextureGlowAsDiffuse();
	m_zMaterialTube.LoadPreset("Glass");

	//Background
	m_zBackground.Init(&m_zMaterialBackground, CFloatRect(0.0, 0.0, 1.0, 1.0));

	//Init Objects
	m_zTeaPot.Init(0.5F, &m_zMaterialKugel, 8, false);

	//Root
	m_zr.AddFrame(&m_zf);
	m_zr.AddScene(&m_zs);
	m_zr.AddMaterial(&m_zMaterialKugel);
	m_zr.AddMaterial(&m_zMaterialBackground);

	//Frame
	m_zf.AddViewport(&m_zv);
	m_zf.AddDeviceKeyboard(&m_zKeyboard);

	//Viewport
	m_zpTeaPot.AddGeo(&m_zTeaPot);
	m_zpTube.AddGeo(&m_zTube);
	m_zv.AddBackground(&m_zBackground);

	//Scene
	m_zs.AddPlacement(&m_zpTeaPot);
	m_zs.AddLightParallel(&m_zl);
	m_zs.AddPlacement(&m_zpTube);

	//Rotieren, Translieren, Skalieren
	m_zpTube.RotateX(UM_DEG2RAD(90));
	m_zpCamera.TranslateZ(15.0F);

	//Meteoriten der Scene hinzufügen
	m_zMeteoriten.Init(&m_zs);
}

void CGame::Tick(float fTime, float fTimeDelta)
{

	// Hier die Echtzeit-Veränderungen einfügen:

	//Raumschiffgeschwindigkeit
	m_zpTeaPot.TranslateZDelta(-2.0F * fTimeDelta); //Raumschiffgeschwindigkeit

	//Cameraposition
	m_zc.Tick(&m_zpTeaPot, m_zKeyboard);

	//Meteoriten werden erzeugt und erneuert
	m_zMeteoriten.RenewMeteorits(&m_zpTeaPot);

	//Raumschiff bewegen
	m_zSteuerung.Tick(&m_zpTeaPot, m_zKeyboard);

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

float CGame::Clamp(float input, float min, float max)
{
	float output = input;

	if (output > max)
		output = max;
	if (output < min)
		output = min;

	return output;
}

