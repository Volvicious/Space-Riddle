#pragma once
#include "Vektoria\Root.h"
#include "RaumschiffAnimation.h"

#define MAX_TUBE 15.0F
#define MIN_TUBE -15.0F

using namespace Vektoria;

class CSteuerung
{

public:
	CSteuerung();
	~CSteuerung();

	void Tick(float fTimeDelta, CPlacement * placement, CDeviceKeyboard * keyboard);
	void Inertia(float fTimeDelta, CPlacement * placement);
	bool SoftBorder(float fTimeDelta, CPlacement * placement);

	int PauseGame(int iScene, CDeviceKeyboard * keyboard);
	int StartGame(int iScene, CDeviceKeyboard * keyboard);
	int ContinueGame(int iScene, CDeviceKeyboard * keyboard);
	int Highscore(int iScene, CDeviceKeyboard * keyboard);
	int Hauptmenue(int iScene, CDeviceKeyboard * keyboard);

private:

	//Lokale Variablen
	float pfvVertikal = 0;
	float pfvHorizontal = 0;
	int SceneSpeicher = 0;
	int iScene = 0;

	bool bFadeSoft = false; 

	float fFadeVer = 0.0F; 
	float fFadeHor = 0.0F; 

	CRaumschiffAnimation m_RAnimation; 

};

