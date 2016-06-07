#pragma once
#include "Vektoria\Root.h"
#include "Meteorit.h"
#include "Raumschiff.h"
#include "FrageGrafik.h"

using namespace Vektoria;

class CHitbox
{
public:

	CHitbox();
	~CHitbox();

	void Init(CRaumschiff * raumschiff, CFrageGrafik * frage, CMeteorit * meteor, CScene * scene);
	void HitboxFrage(CRaumschiff * raumschiff, CFrageGrafik * frage);
	void HitboxMeteoriten(CPlacement * raumschiff, CMeteorit * meteoriten);

	void RayTick(CRaumschiff * raumschiff);

	bool Collision(){ return Kollision; };

private:

	//Alles nur wegen dem Ray
	CHMat rotate;
	CHVector vector;
	CGeoCylinder cylinder;
	CPlacement m_zpcylinder[7];

	CRay r[7];
	CPlacements m_zps;

	//Lokale Variablen
	bool Kollision = false;
};

