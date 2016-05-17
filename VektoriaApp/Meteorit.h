#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

#define MAX_METEOR 50
#define VAR_METEOR 4
#define MAX_TEXTUR 5

class CMeteorit
{
public:
	CMeteorit();
	~CMeteorit();

	CPlacement * getPlacement(){ return m_zpMeteoriten; };
	void Tick(CPlacement * pRaumschiff, bool b );
	void Init(CRoot * root, CScene * scene);

	int getiCounterMeteoriten() { return iCounterMeteoriten; };


private:

	// Hier ist Platz für die Vektoriaobjekte:
	CScene m_zs;
	CMaterial m_zMaterialMeteorit[5];

	//Vektor meteorit
	CHVector m_zvRaumschiff;
	CHVector m_zvMeteorit;

	//Blender Meteoriten reinladen
	CGeo * m_zMeteorit[4];
	CFileWavefront m_zfilewavefront[4];
	CPlacement m_zpMeteoriten[50];

	//Globale Variablen
	int iCounterMeteoriten = 0;
	int iCounter = 0;
};

