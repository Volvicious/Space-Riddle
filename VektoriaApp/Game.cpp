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
	m_zf.AddDeviceKeyboard(&m_zKeyboard);

	//Scene
	m_zs.AddLightParallel(&m_zl);

	//Licht initialisieren
	m_zLight.Init(&m_zs);


	//Initialisiert einfach alles
	m_zSceneHandler.Init(&m_zv,  &m_zs, &m_zf, &m_zKeyboard);
	m_zSceneHandler.InitRaumschiff(&m_zr, &m_zs);
	m_zSceneHandler.InitCamera(&m_zv, &m_zs);
	m_zSceneHandler.InitMeteorits(&m_zs);
	m_zSceneHandler.InitFrage();


	////Skydome
	m_zMaterial.MakeTextureSky("textures\\Background.jpg");
	m_zSkyDome.Init(100.0F, 100.0F, &m_zMaterial, true, 24, 12, eMapping_Cylindrical);
	m_zpSkyDome.AddGeo(&m_zSkyDome);
	m_zs.AddPlacement(&m_zpSkyDome);



	//Rotieren, Translieren, Skalieren
	//m_zpCamera.TranslateZ(15.0F);

	//Fog initialisieren
	m_zFog.Init(&m_zr, &m_zs);
}

void CGame::Tick(float fTime, float fTimeDelta)
{

	m_zSceneHandler.Tick(fTimeDelta, &m_zs);

	
	// Hier die Echtzeit-Veränderungen einfügen:

	//Raumschiffgeschwindigkeit
	fGeschwindigkeit = -40.0F * fTimeDelta;
	/*
	//Raumschiff Geschwindigkeit
	//m_zRaumschiff.Tick(fGeschwindigkeit);
	
	//Cameraposition
	//m_zc.Tick(m_zRaumschiff.getpRaumschiff(), &m_zKeyboard);
	m_zSceneHandler.Tick(fTimeDelta, &m_zc.getPlacement(), &m_zs);
	
	//Raumschiff steuern
	//m_zSteuerung.Tick(fTimeDelta, m_zRaumschiff.getpRaumschiff(), m_zKeyboard);
	//m_zSceneHandler.Scene_Raumschiff();
	*/
	//Dome bewegen
	m_zpSkyDome.TranslateZDelta(fGeschwindigkeit);
	
	//Fog bewegt sich mit
	m_zFog.Tick(fGeschwindigkeit);
	
	//Lichter erneuern
	m_zLight.RenewLights(m_zRaumschiff.getpRaumschiff());

	/*

	//Meteoriten erneuern
	m_zMeteoriten.RenewMeteorits(m_zRaumschiff.getpRaumschiff());

	
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

