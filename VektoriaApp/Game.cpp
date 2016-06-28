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

	//Frame
	m_zf.AddViewport(&m_zv);

	//Scene
	m_zs.AddLightParallel(&m_zl);

	//Initialisiert einfach alles
	m_zSceneHandler.Init(&m_zv,  &m_zs, &m_zf);
	m_zSceneHandler.InitRaumschiff(&m_zr, &m_zs);
	m_zSceneHandler.InitCamera(&m_zv, &m_zs);
	m_zSceneHandler.InitMeteorits(&m_zr, &m_zs);
	m_zSceneHandler.InitSkyDome(&m_zr, &m_zs);
	m_zSceneHandler.InitLights(&m_zs);
	m_zSceneHandler.InitFrageGrafik(&m_zr, &m_zs);
	m_zSceneHandler.InitHitbox(&m_zs);
	m_zSceneHandler.InitOverlays(&m_zv);

	//Hitboxenhttp://ipm.avira.com/images/avira-logo-ipm-dark.jpg
	m_zs.EnableAABBs();
	m_zs.SetBVHExactCalculationOn();

	//maus.Init(&m_zv, &m_zf);
	//maus.SwitchOn();

}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen:
	//Aktualisiert alles
	m_zSceneHandler.Tick(fTimeDelta, fTime);

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

