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

	void Tick(float fGeschwindigkeit, CPlacement * placement, CDeviceKeyboard * keyboard);
	void MaxTube(float fGeschwindigkeit, CPlacement * placement);
	void Inertia(float fGeschwindigkeit, CPlacement * placement);

	int PauseGame(int iScene, CDeviceKeyboard * keyboard);

private:

	//Lokale Variablen
	float pfvVertikal = 0;
	float pfvHorizontal = 0;
	int SceneSpeicher = 0;

};

