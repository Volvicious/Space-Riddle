#pragma once
#include "Game.h"
class CSteuerung
{

public:
	CSteuerung();
	~CSteuerung();

	void Init(CPlacement * placement);
	void Trägheit(float fvVertikal, float fvHorizontal);
	void Bewegung(CPlacement * placement);
	float getfvVertikal(){ return fvVertikal; };
	float getfvHorizontal(){ return fvHorizontal; };

private:
	CDeviceKeyboard m_zKeyboard;
	CHVector m_zvRaumschiff;

	//Globale Variablen
	float fvVertikal = 0;
	float fvHorizontal = 0;


};

