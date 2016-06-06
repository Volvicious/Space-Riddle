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
	m_zf.Init(hwnd, procOS);
	m_zl.Init(CHVector(1.0f, 1.0f, 1.0f), CColor(1.0f, 1.0f, 1.0f));

	//Root
	m_zr.AddFrame(&m_zf);
	m_zr.AddScene(&m_zs);
	m_zr.AddMaterial(&m_zMaterial);

	//Frame
	m_zf.AddViewport(&m_zv);

	//Scene
	m_zs.AddLightParallel(&m_zl);

	//Licht initialisieren
	m_zLight.Init(&m_zs);

	//Initialisiert einfach alles
	m_zSceneHandler.Init(&m_zv,  &m_zs, &m_zf);
	m_zSceneHandler.InitRaumschiff(&m_zr, &m_zs);
	m_zSceneHandler.InitCamera(&m_zv, &m_zs);
	m_zSceneHandler.InitMeteorits(&m_zr, &m_zs);
	m_zSceneHandler.InitSkyDome(&m_zr, &m_zs);
	m_zSceneHandler.InitLights(&m_zs);
	m_zSceneHandler.FrageTranslation();
	m_zSceneHandler.InitHitbox(&m_zRaumschiff, &m_zFrageGrafik, &m_zMeteor, &m_zs);

	m_zs.EnableAABBs();
	m_zs.SetBVHExactCalculationOn();

	//Fog initialisieren
	//m_zFog.Init(&m_zr, &m_zs);
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen:

	//Raumschiffgeschwindigkeit
	fGeschwindigkeit = -100.0F * fTimeDelta;

	//Aktualisiert alles
	m_zSceneHandler.Tick(fTimeDelta, fTime);

	//Fog bewegt sich mit
	//m_zFog.Tick(fGeschwindigkeit);

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

