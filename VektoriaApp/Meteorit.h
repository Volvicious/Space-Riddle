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

	void NextMeteor(CPlacement * raumschiff);

	CPlacement * getpMeteor(int i) { return &m_zpMeteoriten[i]; };

	void Deform();

	int getiCounterMeteoriten() { return iMeteorPassed; };

	void SetiCounterZero(){ iMeteorPassed = 0; };
	FLOAT getiCounterZPos(){ return m_zpMeteoriten[iCounter].GetTranslation().GetZ(); };

	void SwitchOff();
	void SwitchOn();


private:

	// Hier ist Platz für die Vektoriaobjekte:
	CScene m_zs;
	CMaterial m_zMaterialMeteorit[3];

	//Math
	CHMat mat;

	//Vektor meteorit
	CHVector m_zvRaumschiff;
	CHVector m_zvMeteorit;

	//Blender Meteoriten reinladen
	CGeoSphere m_zgMeteorit[3];
	CPlacement m_zpMeteoriten[MAX_METEOR];

	//Kugeln
	CGeoSphere m_zGeos;

	//Globale Variablen
	int iMeteorPassed = 0;
	int iCounter = 0;
	int i = 0;
};

