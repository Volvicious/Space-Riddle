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
	// Hier die Initialisierung der Vektoria-Objekte einf�gen:
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

	//Hitboxen
	m_zs.EnableAABBs();
	m_zs.SetBVHExactCalculationOn();
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Ver�nderungen einf�gen:
	//Aktualisiert alles
	m_zSceneHandler.Tick(fTimeDelta, fTime);

	m_zr.Tick(fTimeDelta);
}

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einf�gen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergr��e ver�ndert wurde.
	// Hier kannst Du dann die Aufl�sung des Viewports neu einstellen:
	m_zf.ReSize(iNewWidth, iNewHeight);
}

