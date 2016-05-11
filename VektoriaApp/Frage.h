#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CFrage
{
public:
	CFrage();
	~CFrage();

	void Init(FLOAT f_posRaumschiff, FLOAT f_posX, FLOAT f_posY);
	void Init1(CScene * scene1);
	CHVector getPlacement(int j){ return  m_zpSphere[j].GetTranslation(); };

private:

	//
	CMaterial m_zMaterialKugel;
	CGeoSphere m_zgSphere;
	CGeoSphere m_zgFrage;
	CPlacement m_zpSphere[5];

	//Sonstige Variablen
	float fLeftpos;


};

