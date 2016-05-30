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

private:

	//Geos
	CGeoDome m_zSkyDome;

	//Material
	CMaterial m_zMaterial;

	//Placement
	CPlacement m_zpSkyDome;

};

