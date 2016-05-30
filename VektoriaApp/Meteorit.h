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
	void LowGraphics(CRoot * root, CScene * scene);

	int getiCounterMeteoriten() { return iCounterMeteoriten; };

	void SetiCounterZero(){ iCounterMeteoriten = 0; };
	FLOAT getiCounterZPos(){ return m_zpMeteoriten[iCounter].GetTranslation().GetZ(); };

	void SwitchOff();
	void SwitchOn();


private:

	// Hier ist Platz für die Vektoriaobjekte:
	CScene m_zs;
	CMaterial m_zMaterialMeteorit[5];

	//Vektor meteorit
	CHVector m_zvRaumschiff;
	CHVector m_zvMeteorit;

	//Blender Meteoriten reinladen
	CGeo * m_zMeteorit[4];
//	CGeoCube m_zMeteorit[4];
	CFileWavefront m_zfilewavefront[4];
	CPlacement m_zpMeteoriten[50];

	//Kugeln
	CGeoSphere m_zGeos;

	//Globale Variablen
	int iCounterMeteoriten = 0;
	int iCounter = 0;
};

