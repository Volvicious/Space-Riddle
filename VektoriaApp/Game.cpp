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

	m_ziBackground.Init("textures\\neon.jpg");
	m_ztBackground.Init(&m_ziBackground);

	//Materialgebung
	//m_zMaterialBackground.MakeTextureDiffuse("textures\\neon.jpg");
	//m_zMaterialBackground.MakeTextureSky("textures\\neon.jpg");
	m_zMaterialBackground.SetTextureSky(&m_ztBackground);
	m_zMaterialBackground.SetTextureGlowAsDiffuse();

	//Raumschiff initialisieren
	m_zRaumschiff.Init(&m_zr, &m_zs);

	//Root
	m_zr.AddFrame(&m_zf);
	m_zr.AddScene(&m_zs);

	//Frame
	m_zf.AddViewport(&m_zv);
	m_zf.AddDeviceKeyboard(&m_zKeyboard);

	//Viewport
	m_zv.AddBackground(&m_zBackground);

	//Scene
	m_zs.AddLightParallel(&m_zl);

	////Skydome
	m_zSkyDome.Init(200.0F, 50.0F, &m_zMaterialBackground, true);
	m_zpSkyDome.AddGeo(&m_zSkyDome);
	m_zpSkyDome.RotateXDelta(UM_DEG2RAD(-90));
	m_zs.AddPlacement(&m_zpSkyDome);

	//Licht initialisieren
	m_zLight.Init(&m_zs);

	//Rotieren, Translieren, Skalieren
	m_zpCamera.TranslateZ(15.0F);

	//Meteoriten der Scene hinzufügen
	m_zMeteoriten.Init(&m_zs);

	//Fog initialisieren
	m_zFog.Init(&m_zr, &m_zs);
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen:

	//Raumschiffgeschwindigkeit
	fGeschwindigkeit = -30.0F * fTimeDelta;
	m_zRaumschiff.Tick(fGeschwindigkeit);

	//Cameraposition
	m_zc.Tick(m_zRaumschiff.getpRaumschiff(), &m_zKeyboard);

	//Raumschiff bewegen
	//m_zSteuerung.Tick(m_zRaumschiff.getpRaumschiff(), m_zKeyboard);

	//Dome bewegen
	//m_zpSkyDome.TranslateZDelta(fGeschwindigkeit);

	//Fog bewegt sich mit
	m_zFog.Tick(fGeschwindigkeit);

	//Lichter erneuern
	m_zLight.RenewLights(m_zRaumschiff.getpRaumschiff());

	//Meteoriten erneuern
	m_zMeteoriten.RenewMeteorits(m_zRaumschiff.getpRaumschiff());

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

