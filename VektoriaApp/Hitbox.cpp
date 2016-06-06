#include "Hitbox.h"


CHitbox::CHitbox()
{
}


CHitbox::~CHitbox()
{
}

void CHitbox::Init(CRaumschiff * raumschiff, CFrageGrafik * frage, CMeteorit * meteor, CScene * scene)
{
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
	r[5].m_fMax = 10.0f;

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

void CHitbox::RayTick(CRaumschiff * raumschiff)
{
	for (float i = -3; i <= 3; i += 1.5)
	{
		r[(int)(i / 1.5f + 2.0f)].m_vOrigin.SetX(raumschiff->getpRaumschiff()->GetTranslation().GetX() + i);
		r[(int)(i / 1.5f + 2.0f)].m_vOrigin.SetY(raumschiff->getpRaumschiff()->GetTranslation().GetY());
		r[(int)(i / 1.5f + 2.0f)].m_vOrigin.SetZ(raumschiff->getpRaumschiff()->GetTranslation().GetZ());
	}

	//Ray 5
	r[5].m_vOrigin.SetX(raumschiff->getpRaumschiff()->GetTranslation().GetX());
	r[5].m_vOrigin.SetY(raumschiff->getpRaumschiff()->GetTranslation().GetY() + 0.5F);
	r[5].m_vOrigin.SetZ(raumschiff->getpRaumschiff()->GetTranslation().GetZ());
	r[5].m_vOrigin.SetW(1.0F);

	//Cylinder hat Position von Ray 5
	vector.SetX(r[5].m_vOrigin.GetX());
	vector.SetY(r[5].m_vOrigin.GetY());
	vector.SetZ(r[5].m_vOrigin.GetZ());

	//Cylinder wird mit Translate an die Position verschoben
	m_zpcylinder.Translate(vector);

	//Ray 6
	r[6].m_vOrigin.SetX(raumschiff->getpRaumschiff()->GetTranslation().GetX());
	r[6].m_vOrigin.SetY(raumschiff->getpRaumschiff()->GetTranslation().GetY() - 1.5F);
	r[6].m_vOrigin.SetZ(raumschiff->getpRaumschiff()->GetTranslation().GetZ());
}

void CHitbox::HitboxFrage(CRaumschiff * raumschiff, CFrageGrafik * frage)
{
	//Abfrage ob Antwort getroffen wird
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			//Überprüfen ob Ray 5 mit irgendeiner Frage kollidiert
			//if (frage->getpFrage(i)->m_aaabb[0].Intersects(.Intersects(r[5]))
			float fDistance;
			CAABB aabb(r[5].m_vOrigin, r[5].m_vOrigin + r[5].m_vDirection);;
			aabb.m_vMin = r[5].m_vOrigin;
			aabb.m_vMax = r[5].m_vOrigin + r[5].m_vDirection;

			if (frage->getpFrage(i)->m_aaabb[0].Intersects(aabb))
			{
				OutputDebugString("Test1\n");
				ULVector("vMin", frage->getpFrage(i)->m_aaabb[0].m_vMin);
				ULVector("vMax", frage->getpFrage(i)->m_aaabb[0].m_vMax);
				ULVector("vOrigin", r[5].m_vOrigin);
				ULVector("vDirection", r[5].m_vDirection);
				ULDebug("Ray Min: %f, Max: %f ", r[5].m_fMin, r[5].m_fMax);
				ULDebug("Distance: %f ", fDistance);
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
	for (int i = 0; i <= MAX_METEOR; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			if (meteoriten->getpMeteor(i)->m_aaabb[0].Intersects(r[j]))
			{
				//TODO: Sagen was passiert wenn ich kollidiere
			}
		}
	}
}