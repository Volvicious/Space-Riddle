#include "Hitbox.h"


CHitbox::CHitbox()
{
}


CHitbox::~CHitbox()
{
}

void CHitbox::Init(CFrageGrafik * frage, CMeteorit * meteor)
{
	//Ray 1 (ganz links)
	r[0].Init(CHVector(-3.0f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[0].m_fMin = 0.0f;
	r[0].m_fMax = 10.0f;

	//Ray 2 (halb links)
	r[1].Init(CHVector(-1.5f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[1].m_fMin = 0.0f;
	r[1].m_fMax = 10.0f;

	//Ray 3 (mitte)
	r[2].Init(CHVector(0.0f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[2].m_fMin = 0.0f;
	r[2].m_fMax = 10.0f;

	//Ray 4 (halb rechts)
	r[3].Init(CHVector(1.5f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[3].m_fMin = 0.0f;
	r[3].m_fMax = 10.0f;

	//Ray 5 (ganz rechts)
	r[4].Init(CHVector(3.0f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[4].m_fMin = 0.0f;
	r[4].m_fMax = 10.0f;

	//Ray 6 (mitte oben)
	r[5].Init(CHVector(0.0f, 1.5f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[5].m_fMin = 0.0f;
	r[5].m_fMax = 10.0f;

	//Ray 7 (mitte unten)
	r[6].Init(CHVector(0.0f, -1.5f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[6].m_fMin = 0.0f;
	r[6].m_fMax = 10.0f;


	for (int i = 0; i < 4; i++)
	{
		m_zps.Add(frage->getpFrage(i));
	}

	for (int i = 0; i <= MAX_METEOR; i++)
	{
		m_zps.Add(meteor->getpMeteor(i));
	}
}

void CHitbox::HitboxFrage(CRaumschiff * Raumschiff, CFrageGrafik * frage)
{
	for (float i = -3; i <= 3; i += 1.5)
	{
		r[(int)(i / 1.5f + 2.0f)].m_vOrigin.SetX(Raumschiff->getpRaumschiff()->GetTranslation().GetX() + i);
		r[(int)(i / 1.5f + 2.0f)].m_vOrigin.SetY(Raumschiff->getpRaumschiff()->GetTranslation().GetY());
		r[(int)(i / 1.5f + 2.0f)].m_vOrigin.SetZ(Raumschiff->getpRaumschiff()->GetTranslation().GetZ());
	}

	//Ray 5
	r[5].m_vOrigin.SetX(Raumschiff->getpRaumschiff()->GetTranslation().GetX());
	r[5].m_vOrigin.SetY(Raumschiff->getpRaumschiff()->GetTranslation().GetY() + 1.5f);
	r[5].m_vOrigin.SetZ(Raumschiff->getpRaumschiff()->GetTranslation().GetZ());

	//Ray 6
	r[6].m_vOrigin.SetX(Raumschiff->getpRaumschiff()->GetTranslation().GetX());
	r[6].m_vOrigin.SetY(Raumschiff->getpRaumschiff()->GetTranslation().GetY() - 1.5f);
	r[6].m_vOrigin.SetZ(Raumschiff->getpRaumschiff()->GetTranslation().GetZ());

	for (int i = 0; i <= 6; i++)
	{
		r[i].m_vOrigin.SetW(1.0f);
	}

	//Abfrage ob Antwort getroffen wird
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			if (frage->getpFrage(i)->m_aaabb[0].Intersects(r[j]))
			{
				frage->getpFrage(i)->m_aaabb[0].Intersects(r[j]);
				OutputDebugString("Test1\n");
			}
			else
			{
				OutputDebugString("No\n");
			}
		}
	}

	//Abfrage ob Raumschiff mit Meteoriten kollidiert
	//TODO
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