#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

#define MAX_METEOR 50

class CMeteorit
{
public:
	CMeteorit();
	~CMeteorit();

	CPlacement * getPlacement(){ return m_azp; };
	void Init(CScene* scene);
	void RenewMeteorits(CPlacement * pRaumschiff, bool b );

	int getiCounterMeteoriten() { return iCounterMeteoriten; };

	

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

	//Globale Variablen
	int iCounterMeteoriten = 0;
	int iCounter = 0;
};

