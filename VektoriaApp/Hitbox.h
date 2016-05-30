#pragma once
#include "Vektoria\Root.h"
#include "Meteorit.h"

using namespace Vektoria;

class CHitbox
{
public:

	CHitbox();
	~CHitbox();

	void Init();
	bool CollisionDetection(CHVector * v, CHVector * vRaumschiff);
	bool CollisionMeteorit(CHVector * Raumschiff, CMeteorit * Meteor);
	int CollisionAntwort(CHVector * posRaumschiff, CHVector * posAntwort, int ABCD);
	void SetXY(FLOAT x, FLOAT y);

private:

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

