// VektoriaApp.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//


#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include <WinUser.h>
#include "resource.h"
#include "Game.h"
#include "Vektoria\Timer.h"
#include "Vektoria\Splash.h"
#include "Mmsystem.h"

#pragma comment(lib, "winmm.lib")


// Globale Variablen:
TCHAR szClassName[] = _T("VektoriaWindowClass");
static bool g_bFullscreen = false;

// Protoheader: 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static void ChangeDisplay(HWND, unsigned int);

// Globale Variablen:
CGame * g_pgame = nullptr; // Das Spiel:
CSplash g_splash;// Der Vektoria-Splash-Screen



// Eintrittspunkt:
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = NULL;   // Fenster-Handle
	MSG msg;
	WNDCLASSEX wcex;    // Datenstruktur für die Fensterklasse
	BOOL bQuit = FALSE; // True, falls das Programm beendet werden soll

	// Fenstertruktur:
	wcex.hInstance = hInstance;
	wcex.lpszClassName = szClassName;
	wcex.lpfnWndProc = WndProc;  // Diese Funktion wird von Windows aufgerufen
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;    
	wcex.cbSize = sizeof(WNDCLASSEX);

	// Handles für das Vektoria-Icon und den Standardmauszeiger:
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.lpszMenuName = NULL;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  /* Use Windows's default colour as the background of the window */


	if (!RegisterClassEx(&wcex))  {
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("VektoriaV9App"), NULL);
		return 1;
	}

	// Nun wird das Programm erzeugt:
	hWnd = CreateWindowEx(
		0,                      // Erweiterte 
		szClassName,            // Klassenname 
		_T("VektoriaApp"),		// Überschrift 
		WS_OVERLAPPEDWINDOW,    // Default Window 
		CW_USEDEFAULT,          // Windows entscheidet, wo das Fenster liegt
		CW_USEDEFAULT,          // Wo das Fenster liegt
		1920,                   // Breite in Pixel
		1080,                   // Höhe in Pixel
		HWND_DESKTOP,           // Das Fenster ist ein Unterfenster des Desktops
		NULL,                   // Kein Menu
		hInstance,              // Programminstanz
		NULL                    // Keine Fenstererzeugungsdaten
		);

	if (!hWnd) 
	{
		MessageBox(NULL, _T("CreateWindow failed!"), _T("VektoriaApp"), NULL);
		return 1;
	}

	g_pgame = (CGame*)(new CGame());

	// Zeig den Splash-Screen:
	g_splash.Init(hWnd, hInstance);
	g_splash.Show();

	// Zeig das Fenster:
	ShowWindow(hWnd, nCmdShow);

	// Initialisiere das Spiel:
	RECT rect;
	GetClientRect(hWnd, &rect); // Ermittle die Größe des Fensters
	g_pgame->Init(hWnd, ChangeDisplay, &g_splash);

	CTimer timer;
	timer.SwitchFrameRateCalculationOn();
	double dStartTime = timer.GetElapsedTime();
	double dLastTime = dStartTime;

	float fTimeDelta;
	float fTime;
	float fTimeLastShow = 0.0F;
	bool bFirstTick = true;
	do
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bQuit = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			//FrameRate
			timer.Tick(fTime, fTimeDelta);

			if (fTime - fTimeLastShow >= 0.2F) // SetWindowTextA stürzt ab, wenn es zu schnell hintereinander aufgerufen wird (Microsoft-Fehler) => daher die Zeitbegrenzung
			{
				char ac[300];
				sprintf_s(ac, 300, "VektoriaApp        FR-Average: %.3f; FR-Long Average: %.3f; FR Min: %.3f; FR Max: %.3f", timer.m_fFrameRateAverage, timer.m_fFrameRateAverageLong, timer.m_fFrameRateMin, timer.m_fFrameRateMax);
				SetWindowTextA(hWnd, ac);
				fTimeLastShow = fTime;
			}

			// Game Tick
			g_pgame->Tick(fTime, fTimeDelta);
			if (bFirstTick)
			{
				g_splash.Hide();
				bFirstTick = false;
			}

		}
	} while (!bQuit);
	g_pgame->Fini();
	delete g_pgame;
	return ERROR_SUCCESS;
}



//  Diese Funktion wird von Windows aufgerufen:
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)                  
	{
	case WM_SIZE:
		g_pgame->WindowReSize(LOWORD(lParam), HIWORD(lParam));
		return 0;

	case WM_KEYDOWN:
		if (wParam == VK_F11)
		{
			g_bFullscreen = !g_bFullscreen;
			if (g_bFullscreen)
				ChangeDisplay(hwnd, 3);
			else
				ChangeDisplay(hwnd, 2);

		}
		if (wParam != VK_ESCAPE)
			break;

	case WM_DESTROY:
		PostQuitMessage(0);           
		break;

	default:                        
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}


static void ChangeDisplay(HWND hWnd, unsigned int uWndFlags)
{
	static bool s_bNextIsText = false;
	static unsigned int s_uNextIsProgressEvents = 0;
	static unsigned int s_uProgressEvents = 0;
	static unsigned int s_uFrames = 0;
	static unsigned int s_uViewports = 0;
	static unsigned int s_uGeos = 0;
	static unsigned int s_uMaterials = 0;
	static unsigned int s_uAudios = 0;

	static unsigned int s_uFrame = 0;
	static unsigned int s_uViewport = 0;
	static unsigned int s_uGeo = 0;
	static unsigned int s_uMaterial = 0;
	static unsigned int s_uAudio = 0;


	DWORD dwExStyle;
	DWORD dwStyle;
	if (s_bNextIsText)
	{
		char ac[200];
		switch (uWndFlags)
		{
		case 'F':
			s_uFrame++;
			sprintf(ac, "Initializing Frame %i", s_uViewport);
			break;
		case 'V':
			s_uViewport++;
			sprintf(ac, "Initializing Viewport %i", s_uViewport);
			break;
		case 'G':
			s_uGeo++;
			sprintf(ac, "Creating Geometry %i", s_uGeo);
			break;
		case 'M':
			s_uMaterial++;
			sprintf(ac, "Loading Material %i", s_uMaterial);
			break;
		case 'A':
			s_uMaterial++;
			sprintf(ac, "Loading Audio %i", s_uMaterial);
			break;
		case 'a':
			s_uMaterial++;
			sprintf(ac, "Initializing Sound Api");
			break;
		default:
			sprintf(ac, "Initializing App");
			break;
		}
		SetWindowTextA(hWnd, ac);
		s_bNextIsText = false;
	}
	else if (s_uNextIsProgressEvents > 0)
	{
		switch (s_uNextIsProgressEvents)
		{
		case 5: s_uFrames = uWndFlags; break;
		case 4: s_uViewports = uWndFlags; break;
		case 3: s_uGeos = uWndFlags; break;
		case 2: s_uMaterials = uWndFlags; break;
		case 1: s_uAudios = uWndFlags;
			s_uProgressEvents = (s_uMaterials + s_uGeos + 1)*s_uFrames + s_uViewports + s_uAudios + 2;
			break;
		}
		s_uNextIsProgressEvents--;
	}
	else if (uWndFlags == 2) // Schalte Fullscreen aus:
	{
		g_bFullscreen = false;
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		dwStyle = WS_OVERLAPPEDWINDOW;
		SetWindowLongPtr(hWnd, GWL_EXSTYLE, dwExStyle);
		SetWindowLongPtr(hWnd, GWL_STYLE, dwStyle);

		SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 1920, 1080, SWP_SHOWWINDOW); //TODO: alte width und height werte merken und dann wieder setzen
		SetForegroundWindow(hWnd);
		SetFocus(hWnd);
		ChangeDisplaySettings(NULL, 0);
	}
	else if (uWndFlags == 3) // Schalte Fullscreen an:
	{
		g_bFullscreen = true;
		// Automatisch die Größe des primären Monitors ermitteln
		int iWidth = GetSystemMetrics(SM_CXSCREEN);
		int iHeight = GetSystemMetrics(SM_CYSCREEN);

		DEVMODE dmScreenSettings;
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));

		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (DWORD)iWidth;
		dmScreenSettings.dmPelsHeight = (DWORD)iHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		dwExStyle = WS_EX_APPWINDOW;
		dwStyle = WS_POPUP;
		SetWindowLongPtr(hWnd, GWL_EXSTYLE, dwExStyle);
		SetWindowLongPtr(hWnd, GWL_STYLE, dwStyle);
		SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, (DWORD)iWidth, (DWORD)iHeight, SWP_SHOWWINDOW);
		g_pgame->WindowReSize(iWidth, iHeight);
		SetForegroundWindow(hWnd);
		SetFocus(hWnd);
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
	}
	else if (uWndFlags == 4) // Rücke Fortschrittsanzeiger weiter:
	{
		static int s_uProgress = 0;



		s_uProgress++;
		if (s_uProgressEvents>0)
			g_splash.ShowProgressBar((float)s_uProgress / (float)s_uProgressEvents);

		s_bNextIsText = true;

	}
	else if (uWndFlags == 8) // Versteckte Fortschrittsanzeiger:
	{
		g_splash.HideProgressBar();
		s_uProgressEvents = 1;
		s_uFrame = 0;
		s_uViewport = 0;
		s_uGeo = 0;
		s_uMaterial = 0;
		s_uAudio = 0;
	}
	else if (uWndFlags == 16) // Nächste fünf Events werden Knotenanzahlen übermittelt:
	{
		s_uNextIsProgressEvents = 5;
	}
}