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
	m_zMaterialBackground.MakeTextureDiffuse("textures\\Background.jpg");
	m_zMaterialBackground.SetTextureGlowAsDiffuse();
	m_zMaterialFog.MakeTextureDiffuse("textures\\FogULTIMATE.png");
	m_zMaterialFog.SetAni(3, 2, 24);

	//Background
	m_zBackground.Init(&m_zMaterialBackground, CFloatRect(0.0, 0.0, 1.0, 1.0));

	//Init Objects
	m_zTeaPot.Init(0.5F, &m_zMaterialKugel, 8, false);

	//Root
	m_zr.AddFrame(&m_zf);
	m_zr.AddScene(&m_zs);
	m_zr.AddMaterial(&m_zMaterialKugel);
	m_zr.AddMaterial(&m_zMaterialBackground);
	m_zr.AddMaterial(&m_zMaterialFog);

	//Frame
	m_zf.AddViewport(&m_zv);
	m_zf.AddDeviceKeyboard(&m_zKeyboard);

	//Viewport
	m_zpTeaPot.AddGeo(&m_zTeaPot);
	m_zv.AddBackground(&m_zBackground);

	//Scene
	m_zs.AddPlacement(&m_zpTeaPot);
	m_zs.AddLightParallel(&m_zl);

	//FOG
	m_zFog.Init(50.0, 10.0, &m_zMaterialFog);
	m_zpFog.AddGeo(&m_zFog);
	m_zs.AddPlacement(&m_zpFog);
	m_zpFog.RotateXDelta(UM_DEG2RAD(90));

	//Licht initialisieren
	//m_zLight.Init(&m_zs);

	//Walls initialisieren
	//m_zTube.Init(&m_zs);

	//Tunnel initinialisieren
	//m_zTunnel.InitStraight(20.0F, 20.5F, 150.0F, NULL);
	//m_zpTunnel.AddGeo(&m_zTunnel);
	//m_zs.AddPlacement(&m_zpTunnel);
	//m_zpTunnel.RotateX(UM_DEG2RAD(90));

	//Rotieren, Translieren, Skalieren
	m_zpCamera.TranslateZ(15.0F);

	//Meteoriten der Scene hinzufügen
	m_zMeteoriten.Init(&m_zs);

	//m_zr.AddMaterial(m_zc.getMaterial());
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen:
	//Raumschiffgeschwindigkeit
	m_zpTeaPot.TranslateZDelta(-10.0F * fTimeDelta); //Raumschiffgeschwindigkeit

	//Cameraposition
	m_zc.Tick(&m_zpTeaPot, &m_zKeyboard);

	//Tube verschieben
	//m_zpTunnel.TranslateZDelta(-10.0F * fTimeDelta);

	//Wall verschieben
	//m_zTube.RenewWalls(&m_zpTeaPot);

	//Lichter erstellen
	//m_zLight.RenewLights(&m_zpTeaPot);

	//Fog verschieben
	m_zpFog.TranslateZ(m_zpTeaPot.GetTranslation().GetZ() - 150.0F);

	//Meteoriten erneuern
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

