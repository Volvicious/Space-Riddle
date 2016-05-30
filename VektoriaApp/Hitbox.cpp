#include "Hitbox.h"


CHitbox::CHitbox()
{
}


CHitbox::~CHitbox()
{
}

bool CHitbox::CollisionMeteorit(CHVector * Raumschiff, CMeteorit * Meteor)
{
	//FLOAT zRaumschiff = Raumschiff->GetZ();

	//for (int i = 0; i < 24; i++)
	//{
	bool b_istKollidiert = false;

	////Da krieg ich AIDS!
	//CPlacement * placeMeteor = Meteor->getPlacement(Meteor->getiCounterMeteoriten() + i);
	//	
	//float m_iposMet = placeMeteor->GetTranslation().GetZ();

	//if (m_iposMet - zRaumschiff >= 0)
	//{
	//	b_istKollidiert = CollisionDetection(&placeMeteor->GetTranslation(), Raumschiff);
	//}

	return b_istKollidiert;
	//}
}

bool CHitbox::CollisionDetection(CHVector * v, CHVector * vRaumschiff)
{
	m_zVektor1.SetX(v->GetX());
	m_zVektor1.SetY(v->GetY());
	m_zVektor1.SetZ(v->GetZ());

	m_zVektor.SetX(vRaumschiff->GetX());
	m_zVektor.SetY(vRaumschiff->GetY());
	m_zVektor.SetZ(vRaumschiff->GetZ());

	m_zVektor1 = m_zVektor1 - m_zVektor;

	m_fAbstand = sqrt((m_zVektor1.GetX() * m_zVektor1.GetX())
		+ (m_zVektor1.GetY() *  m_zVektor1.GetY()) 
		+ (m_zVektor1.GetZ() *  m_zVektor1.GetZ())); // Abstand der beiden Kugeln 
	m_fRadius = 2.3F;

	if (m_fAbstand <= m_fRadius)
	{
		//an dieser stelle ist man kollidiert.
		return true;
	}
	else
	{
		return false;
	}

}

void CHitbox::SetXY(FLOAT f_x, FLOAT f_y)
{
	f_StartX = f_x;
	f_StartY = f_y;
}

int CHitbox::CollisionAntwort(CHVector * posRaumschiff, CHVector * posAntwort, int ABCD)
{
	m_zVektor1.SetX(posAntwort->GetX());
	m_zVektor1.SetY(posAntwort->GetY());
	m_zVektor1.SetZ(posAntwort->GetZ());

	m_zVektor.SetX(posRaumschiff->GetX());
	m_zVektor.SetY(posRaumschiff->GetY());
	m_zVektor.SetZ(posRaumschiff->GetZ());

	m_zVektor1 = m_zVektor - m_zVektor1;

	m_fAbstand = sqrt((m_zVektor1.GetX() * m_zVektor1.GetX()) 
		+ (m_zVektor1.GetY() *  m_zVektor1.GetY()) 
		+ (m_zVektor1.GetZ() *  m_zVektor1.GetZ())); // Abstand der beiden Kugeln 

	m_fRadius = 2.3F;

	if (m_fAbstand <= m_fRadius)
	{
		return ABCD;
	}
	else
	{
		return 5;
	}
}