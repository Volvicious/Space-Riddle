#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CFrage
{
public:
	CFrage();
	~CFrage();

	void Init(CScene * scene);
	void Tick(FLOAT f_posRaumschiff, FLOAT f_posX, FLOAT f_posY);

	void SwitchOff();
	void SwitchOn();

	CHVector getPlacement(int j){ return  m_zpSphere[j].GetTranslation(); };
	FLOAT GetPlacementFrage(){ return m_zpSphere[3].GetTranslation().GetZ(); }

private:

	//
	CMaterial m_zMaterialKugel;
	CGeoSphere m_zgSphere;
	CGeoSphere m_zgFrage;
	CPlacement m_zpSphere[5];

	//Sonstige Variablen
	float fLeftpos;


};

