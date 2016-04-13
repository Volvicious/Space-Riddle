#pragma once
#include "Vektoria\Root.h"
#include "Sound.h"
using namespace Vektoria;

#define MAX_METEOR 100

class CMeteorit
{
public:
	CMeteorit();
	~CMeteorit();

	CPlacement * getPlacement(){ return m_azp; };
	void Init(CScene* scene, CSound * sound);
	void RenewMeteorits(CPlacement * pRaumschiff);

	
	
	CAudio audio;
	 

private:
	// Hier ist Platz für die Vektoriaobjekte:
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

