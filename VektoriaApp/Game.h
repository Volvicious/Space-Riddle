#pragma once


#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#pragma comment (lib, "ApiUtils_Debug64.lib")
#pragma comment (lib, "ApiNullRenderer_Debug64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug64.lib")
#pragma comment (lib, "ApiDirectInput08_Debug64.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug64.lib")
#pragma comment (lib, "ApiOpenGL40_Debug64.lib")
#pragma comment (lib, "ApiNullSound_Debug64.lib")
#pragma comment (lib, "ApiDirectSound_Debug64.lib")
#pragma comment (lib, "ApiRenderDistributed_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#pragma comment (lib, "ApiUtils_Release64.lib")
#pragma comment (lib, "ApiNullRenderer_Release64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release64.lib")
#pragma comment (lib, "ApiDirectInput08_Release64.lib")
#pragma comment (lib, "ApiDirectX11FP_Release64.lib")
#pragma comment (lib, "ApiOpenGL40_Release64.lib")
#pragma comment (lib, "ApiNullSound_Release64.lib")
#pragma comment (lib, "ApiDirectSound_Release64.lib")
#pragma comment (lib, "ApiRenderDistributed_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#pragma comment (lib, "ApiUtils_Debug.lib")
#pragma comment (lib, "ApiNullRenderer_Debug.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug.lib")
#pragma comment (lib, "ApiDirectInput08_Debug.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug.lib")
#pragma comment (lib, "ApiOpenGL40_Debug.lib")
#pragma comment (lib, "ApiNullSound_Debug.lib")
#pragma comment (lib, "ApiDirectSound_Debug.lib")
#pragma comment (lib, "ApiRenderDistributed_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#pragma comment (lib, "ApiUtils_Release.lib")
#pragma comment (lib, "ApiNullRenderer_Release.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release.lib")
#pragma comment (lib, "ApiDirectInput08_Release.lib")
#pragma comment (lib, "ApiDirectX11FP_Release.lib")
#pragma comment (lib, "ApiOpenGL40_Release.lib")
#pragma comment (lib, "ApiNullSound_Release.lib")
#pragma comment (lib, "ApiDirectSound_Release.lib")
#pragma comment (lib, "ApiRenderDistributed_Release.lib")
#endif
#endif


#include "Vektoria\Root.h"
#include "Meteorit.h"
#include "Steuerung.h"
#include "CameraController.h"
#include "LightTunnel.h"
#include "Tube.h"
#include "Fog.h"
#include "Raumschiff.h"
#include "SceneHandler.h"
#include "Hitbox.h"
#include "Frage.h"

using namespace Vektoria;


class CGame
{
public:
	CGame(void);																				// Wird vor Begin einmal aufgerufen (Konstruktor)
	~CGame(void);																				// Wird nach Ende einmal aufgerufen (Destruktor)

	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash);	// Wird zu Begin einmal aufgerufen
	void Tick(float fTime, float fTimeDelta);													// Wird während der Laufzeit bei jedem Bildaufbau aufgerufen
	void Fini();																				// Wird am Ende einmal aufgerufen

	void WindowReSize(int iNewWidth, int iNewHeight);											// Wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat

	void CameraPosition();

	float Clamp(float input, float min, float max);

	//Geschwindigkeit des Raumschiffs
	float fGeschwindigkeit;

private:
    // Hier ist Platz für die Vektoriaobjekte:
	CRoot m_zr;
	//CCameraController m_zc; //CFix
	CScene m_zs;
	CFrame m_zf;
	CViewport m_zv;
	CLightParallel m_zl;
	CSteuerung m_zSteuerung;
	CFog m_zFog;
	CRaumschiff m_zRaumschiff;
	SceneHandler m_zSceneHandler;

	// Placements
	//CPlacement m_zpCamera;
	CPlacement m_zpFog;
	CPlacement m_zpSkyDome;

	//Extras
	//Skydome
	CMaterial m_zMaterial;


	//Materialien
	CMaterial m_zmBackground;
	CMaterial m_zMaterialFog;

	//Keyboard
	CGeoDome m_zSkyDome;
	CDeviceKeyboard m_zKeyboard;

	//Cameravektor
	CHVector m_zCameraTranslation;

	//Objekte
	//CMeteorit m_zMeteoriten;
	
	//Lichter
	CLightTunnel m_zLight;

	//Globale Variablen
	bool bFirstPerson = true;
};


