#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CFrageGrafik
{
public:
	CFrageGrafik();
	~CFrageGrafik();

	void Init(CScene * scene);
	void Translate(float f_posRaumschiff, float f_posX, float f_posY);

	void SwitchOff();
	void SwitchOn();

	CPlacement * getpFrage(int i) { return &m_zpSphere[i]; };

private:

	//Fragenzeugs
	CMaterial m_zMaterialKugel;
	CGeoSphere m_zgSphere;
	CPlacement m_zpSphere[4];

	//Sonstige Variablen
	float fLeftpos;


};

