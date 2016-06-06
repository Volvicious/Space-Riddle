#include "Hitbox.h"


CHitbox::CHitbox()
{
}


CHitbox::~CHitbox()
{
}

void CHitbox::Init(CRaumschiff * raumschiff, CFrageGrafik * frage, CMeteorit * meteor, CScene * scene)
{
	//Raumschiff zwischengespeichert
	ptrRaumschiff = raumschiff;

	//Ray 1 (ganz links)
	r[0].Init(CHVector(-3.0f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[0].m_fMin = 0.0f;
	r[0].m_fMax = 3.0f;

	//Ray 2 (halb links)
	r[1].Init(CHVector(-1.5f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[1].m_fMin = 0.0f;
	r[1].m_fMax = 3.0f;

	//Ray 3 (mitte)
	r[2].Init(CHVector(0.0f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[2].m_fMin = 0.0f;
	r[2].m_fMax = 3.0f;

	//Ray 4 (halb rechts)
	r[3].Init(CHVector(1.5f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[3].m_fMin = 0.0f;
	r[3].m_fMax = 3.0f;

	//Ray 5 (ganz rechts)
	r[4].Init(CHVector(3.0f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[4].m_fMin = 0.0f;
	r[4].m_fMax = 3.0f;

	//Ray 6 (mitte oben)
	r[5].Init(CHVector(0.0f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[5].m_fMin = 0.0f;
	r[5].m_fMax = 3.0f;

	//Ray 7 (mitte unten)
	r[6].Init(CHVector(0.0f, -1.5f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
	r[6].m_fMin = 0.0f;
	r[6].m_fMax = 3.0f;


	for (int i = 0; i < 4; i++)
	{
		m_zps.Add(frage->getpFrage(i));
	}

	for (int i = 0; i <= MAX_METEOR; i++)
	{
		m_zps.Add(meteor->getpMeteor(i));
	}

	//Cylinder initialisieren um Ray sichtbar zu machen
	cylinder.Init(0.2f, 0.2f, r[5].m_vOrigin.GetZ() - r[5].m_vDirection.GetZ(), NULL);
	m_zpcylinder.AddGeo(&cylinder);

	rotate.RotateX(UM_DEG2RAD(-90));

	cylinder.Transform(rotate);
	scene->AddPlacement(&m_zpcylinder);

	//Den Cylinder auch dem Hitbox Placements geben
	m_zps.Add(&m_zpcylinder);

}

void CHitbox::HitboxFrage(CFrageGrafik * frage)
{
	for (float i = -3; i <= 3; i += 1.5)
	{
		r[(int)(i / 1.5f + 2.0f)].m_vOrigin.SetX(ptrRaumschiff->getpRaumschiff()->GetTranslation().GetX() + i);
		r[(int)(i / 1.5f + 2.0f)].m_vOrigin.SetY(ptrRaumschiff->getpRaumschiff()->GetTranslation().GetY());
		r[(int)(i / 1.5f + 2.0f)].m_vOrigin.SetZ(ptrRaumschiff->getpRaumschiff()->GetTranslation().GetZ());
	}

	//Ray 5
	r[5].m_vOrigin.SetX(ptrRaumschiff->getpRaumschiff()->GetTranslation().GetX());
	r[5].m_vOrigin.SetY(ptrRaumschiff->getpRaumschiff()->GetTranslation().GetY());
	r[5].m_vOrigin.SetZ(ptrRaumschiff->getpRaumschiff()->GetTranslation().GetZ());
	r[5].m_vOrigin.SetW(1.0F);

	//Cylinder hat Position von Ray 5
	vector.SetX(r[5].m_vOrigin.GetX());
	vector.SetY(r[5].m_vOrigin.GetY());
	vector.SetZ(r[5].m_vOrigin.GetZ());

	//Cylinder wird mit Translate an die Position verschoben
	m_zpcylinder.Translate(vector);

	//Ray 6
	r[6].m_vOrigin.SetX(ptrRaumschiff->getpRaumschiff()->GetTranslation().GetX());
	r[6].m_vOrigin.SetY(ptrRaumschiff->getpRaumschiff()->GetTranslation().GetY() - 1.5F);
	r[6].m_vOrigin.SetZ(ptrRaumschiff->getpRaumschiff()->GetTranslation().GetZ());

	//W muss immer auf 1 gesetzt werden
	//for (int i = 0; i <= 6; i++)
	//{
	//	r[i].m_vOrigin.SetW(1.0f);
	//}

	//for (int j = 0; j <= 6; j++)
	//{
	//	if (m_zpcylinder.m_aaabb[0].Intersects(r[j]))
	//	{
	//		OutputDebugString("Cylinder\n");
	//	}
	//	else
	//	{
	//		OutputDebugString("No\n");
	//	}
	//}

	//Abfrage ob Antwort getroffen wird
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			//Überprüfen ob Ray 5 mit irgendeiner Frage kollidiert
			if (frage->getpFrage(i)->m_aaabb[0].Intersects(r[5]))
			{
				OutputDebugString("Test1\n");
			}
			else
			{
				OutputDebugString("No\n");
			}
		}
	}
}

void CHitbox::HitboxMeteoriten(CMeteorit * meteoriten)
{
	//TODO: Kollsion mit Meteoriten abfragen
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