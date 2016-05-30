#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CFrageGrafik
{
public:
	CFrageGrafik();
	~CFrageGrafik();

	void Init(FLOAT f_posRaumschiff, FLOAT f_posX, FLOAT f_posY);
	void Init1(CScene * scene);

	void SwitchOff();
	void SwitchOn();

	CPlacement * getpFrage(int i) { return &m_zpSphere[i]; };
	CHVector getPlacement(int j){ return  m_zpSphere[j].GetTranslation(); };
	FLOAT GetPlacementFrage(){ return m_zpSphere[3].GetTranslation().GetZ(); }

private:

	//
	CMaterial m_zMaterialKugel;
	CGeoSphere m_zgSphere;
	CPlacement m_zpSphere[4];

	//Sonstige Variablen
	float fLeftpos;


};

