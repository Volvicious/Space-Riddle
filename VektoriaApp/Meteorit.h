#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

#define MAX_METEOR 10
#define VAR_METEOR 4
#define MAX_TEXTUR 5

class CMeteorit
{
public:
	CMeteorit();
	~CMeteorit();

	void Init(CRoot * root, CScene * scene);
	void Tick(CPlacement * pRaumschiff);
	void NewLevel(CPlacement * raumschiff);


	CPlacement * getpMeteor(int i) { return &m_zpMeteoriten[i]; };

	void SetZero(CPlacement * raumschiff);
	void SwitchOff();
	void SwitchOn();
	void Deform();

	int getiMeteorNummer() { return iCounter; };

private:

	// Hier ist Platz für die Vektoriaobjekte:
	CScene m_zs;
	CMaterial m_zMaterialMeteorit[3];

	//Math
	CHMat mat;

	//Blender Meteoriten reinladen
	CGeoSphere m_zgMeteorit[3];
	CPlacement m_zpMeteoriten[MAX_METEOR];

	//Kugeln
	CGeoSphere m_zGeos;

	//Globale Variablen
	int iCounter = 0;
};

