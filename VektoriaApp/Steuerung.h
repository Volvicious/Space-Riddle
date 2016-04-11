#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CSteuerung
{

public:
	CSteuerung();
	~CSteuerung();

	void Tick(CPlacement * placement, CDeviceKeyboard keyboard);
	void Inertia(CPlacement * placement);

private:
	CHVector m_zvRaumschiff;

	//Globale Variablen
	float pfvVertikal = 0;
	float pfvHorizontal = 0;


};

