#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

#define MAX_METEOR 100

class CMeteorit
{
public:
	CMeteorit();
	~CMeteorit();

	CPlacement * getPlacement(){ return m_azp; };
	void Init(CScene* scene);
	void RenewMeteorits(CPlacement * pRaumschiff);

private:
	// Hier ist Platz f�r die Vektoriaobjekte:
	CScene m_zs;
	CMaterial m_zMaterialMeteorit;
	CGeoSphere m_zMeteorit;

	//Vektor meteorit
	CHVector m_zvRaumschiff;
	CHVector m_zvMeteorit;

	//Meteoriten Placements
	CPlacement m_azp[MAX_METEOR];
	CPlacement * m_pzpStart;
	CPlacement * m_pzpEnd;

	//Globale Variablen
	int iCounterStart = 0;
	int iCounterEnd = 0;
};

