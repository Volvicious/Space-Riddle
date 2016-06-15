#pragma once
#include "Vektoria\Root.h"

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
	void MaxTube(CPlacement * placement);


	int PauseGame(int iScene, CDeviceKeyboard * keyboard);
	int StartGame(int iScene, CDeviceKeyboard * keyboard);
	int ContinueGame(int iScene, CDeviceKeyboard * keyboard);

private:

	//Lokale Variablen
	float pfvVertikal = 0;
	float pfvHorizontal = 0;
	int SceneSpeicher = 0;
	int iScene = 0;

};

