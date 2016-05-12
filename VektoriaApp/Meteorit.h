#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

#define MAX_METEOR 50
#define VAR_METEOR 3

class CMeteorit
{
public:
	CMeteorit();
	~CMeteorit();

	CPlacement * getPlacement(){ return m_zpMeteoriten; };
	void Init(CScene* scene);
	void Tick(CPlacement * pRaumschiff, bool b );

	int getiCounterMeteoriten() { return iCounterMeteoriten; };

	void LoadBlenderFiles(CScene * scene);

private:

	// Hier ist Platz für die Vektoriaobjekte:
	CScene m_zs;
	CMaterial m_zMaterialMeteorit;

	//Vektor meteorit
	CHVector m_zvRaumschiff;
	CHVector m_zvMeteorit;

	//Blender Meteoriten reinladen
	CGeo * m_zMeteorit[VAR_METEOR];
	CFileWavefront m_zfilewavefront[VAR_METEOR];
	CPlacement m_zpMeteoriten[MAX_METEOR];

	//Globale Variablen
	int iCounterMeteoriten = 0;
	int iCounter = 0;
};

