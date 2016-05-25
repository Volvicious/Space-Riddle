#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

class CSkyDome
{
public:
	CSkyDome();
	~CSkyDome();

	void Init(CRoot * root, CScene * scene);
	void Tick(float fGeschwindigkeit);
	void SetZero(float fZpos);

private:

	//Geos
	CGeoDome m_zSkyDome;

	//Rotieren

	//Material
	CMaterial m_zMaterial;

	//Placement
	CPlacement m_zpSkyDome;

};

