#pragma once

#define MAX_FOG 5

#include "Vektoria\Root.h"

using namespace Vektoria;


class CFog
{
public:
	CFog();
	~CFog();
	void Init(CRoot * root,  CScene * scene);
	void InitLame(CRoot * root, CScene * scene);
	void Tick(float fGeschwindigkeit);

private:

	//Objekte
	CGeoQuad m_zFog[MAX_FOG];

	//Placement
	CPlacement m_zpFog[MAX_FOG];

	//Material
	CMaterial m_zmFog[MAX_FOG];

	//Bla
	float fAnzahl = 100;
	float fAbstand = -150;

};

