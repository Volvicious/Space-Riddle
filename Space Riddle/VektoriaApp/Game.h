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

	CHVector RotateAroundAxes(char cAxis, CHVector Origin, float angle, CHVector Target);

	void CameraPosition();

private:
    // Hier ist Platz für die Vektoriaobjekte:
	CRoot m_zr;
	CCamera m_zc;
	CScene m_zs;
	CFrame m_zf;
	CViewport m_zv;
	CLightParallel m_zl;

	// Placements
	CPlacement m_zpCamera;
	CPlacement m_zpSphere;
	CPlacement m_zpBoden;
	CPlacement m_zpTube;
	CPlacement m_zpComet;
	CPlacement m_zpMeteoritMain;
	CMeteorit m_zm;

	//Extras
	CDeviceKeyboard m_zKeyboard;
	CDeviceCursor m_zCursor;
	CMaterial m_zMaterialKugel;
	CMaterial m_zMaterialBoden;
	CMaterial m_zMaterialBackground;
	CMaterial m_zMaterialTube;
	CBackground m_zBackground;
	CHMat m_zMath;

	CHVector m_zCameraPosition;
	CHVector m_zCameraTranslation;

	//Fonts
	CWritingFont m_zFont;

	//Files laden
	CFileVektoria m_zFile;

	//Audio
	CAudio m_zHomeScreen;

	//Vektoren
	CHVector m_zVektorTube;

	//Objekte
	CGeoQuad m_zPlane1;
	CGeoSphere m_zgSphere;
	CGeoTube m_zTube;
	CGeoSphere m_zComet;

	//Globale Variablen
	float fGeschwindigkeitRotation;
	bool bFirstPerson = true;
};


