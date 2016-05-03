#pragma once
#include "Vektoria\Root.h"

#define MAX_TUBE 20.0F
#define MIN_TUBE -20.0F

using namespace Vektoria;

class CSteuerung
{

public:
	CSteuerung();
	~CSteuerung();

	void Tick(CPlacement * placement, CDeviceKeyboard keyboard);
	void Inertia(CPlacement * placement);

private:

	//Globale Variablen
	float pfvVertikal = 0;
	float pfvHorizontal = 0;


};

