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
	int HitboxFrage(CRaumschiff * raumschiff, CFrageGrafik * frage);
	void HitboxMeteoriten(CRaumschiff * raumschiff, CMeteorit * meteoriten);

	void RayTick(CRaumschiff * raumschiff);

	bool getCollision(){ return Kollision; };

	void setCollision(bool boom){ Kollision = boom; };

	int getiFrage(){ return iFrage; };

private:

	//Alles nur wegen dem Ray
	CHMat rotate;
	CHVector vector;

	CRay r[7];
	CPlacements m_zps;

	//Lokale Variablen
	bool Kollision = false;
	int iFrage;
};

