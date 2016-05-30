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

	void Init(CFrageGrafik * frage, CMeteorit * meteor);
	void HitboxFrage(CRaumschiff * raumschiff, CFrageGrafik * frage);


	bool CollisionDetection(CHVector * v, CHVector * vRaumschiff);
	int CollisionAntwort(CHVector * posRaumschiff, CHVector * posAntwort, int ABCD);
	void SetXY(FLOAT x, FLOAT y);

private:

	CRay r[7];
	CPlacements m_zps;

	FLOAT f_StartX, f_StartY;
	CHVector m_zVektor;
	CHVector m_zVektor1;
	CHVector m_zVektorFin;
	CRay m_zRay;
	FLOAT m_fAbstand;
	FLOAT m_fRadius;
	FLOAT y_Abstand, x_Abstand;
	FLOAT a, b, c, d, e, f;
};

