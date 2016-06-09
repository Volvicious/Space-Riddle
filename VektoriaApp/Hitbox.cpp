#include "Hitbox.h"


CHitbox::CHitbox()
{
}


CHitbox::~CHitbox()
{
}

void CHitbox::Init(CRaumschiff * raumschiff, CFrageGrafik * frage, CMeteorit * meteor, CScene * scene)
{
	for (int i = 0; i < 7; i++)
	{
		r[i].Init(CHVector(0.0f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
		r[i].m_fMin = 0.0f;
		r[i].m_fMax = 10.0f;
	}

	for (int i = 0; i < 4; i++)
	{
		m_zps.Add(frage->getpFrage(i));
	}

	for (int i = 0; i <= MAX_METEOR; i++)
	{
		m_zps.Add(meteor->getpMeteor(i));
	}

	//Cylinder als Ray anzeigen
	cylinder.Init(0.01f, 0.01f, r[0].m_vOrigin.GetZ() - r[0].m_vDirection.GetZ(), NULL);

	for (int i = 0; i < 7; i++)
	{
		m_zpcylinder[i].AddGeo(&cylinder);
		rotate.RotateX(UM_DEG2RAD(-90));

		cylinder.Transform(rotate);
		scene->AddPlacement(&m_zpcylinder[i]);

		m_zps.Add(&m_zpcylinder[i]);

	}

	//Fragen ausmachen
	//frage->SwitchOff();
}

void CHitbox::RayTick(CRaumschiff * raumschiff)
{
	for (float i = -1.5; i <= 1.5; i += 0.75)
	{
		r[(int)(i / 0.75f + 2.0f)].m_vOrigin.SetX(raumschiff->getpRaumschiff()->GetTranslation().GetX() + i);
		r[(int)(i / 0.75f + 2.0f)].m_vOrigin.SetY(raumschiff->getpRaumschiff()->GetTranslation().GetY());
		r[(int)(i / 0.75f + 2.0f)].m_vOrigin.SetZ(raumschiff->getpRaumschiff()->GetTranslation().GetZ());
	}

	//Ray 5
	r[5].m_vOrigin.SetX(raumschiff->getpRaumschiff()->GetTranslation().GetX());
	r[5].m_vOrigin.SetY(raumschiff->getpRaumschiff()->GetTranslation().GetY() + 0.2);
	r[5].m_vOrigin.SetZ(raumschiff->getpRaumschiff()->GetTranslation().GetZ());

	//Ray 6
	r[6].m_vOrigin.SetX(raumschiff->getpRaumschiff()->GetTranslation().GetX());
	r[6].m_vOrigin.SetY(raumschiff->getpRaumschiff()->GetTranslation().GetY() - 0.2F);
	r[6].m_vOrigin.SetZ(raumschiff->getpRaumschiff()->GetTranslation().GetZ());

	for (int i = 0; i < 7; i++)
	{
		r[i].m_vOrigin.SetW(1.0f);
	}

	for (int i = 0; i < 7; i++)
	{
		vector.SetX(r[i].m_vOrigin.GetX());
		vector.SetY(r[i].m_vOrigin.GetY());
		vector.SetZ(r[i].m_vOrigin.GetZ());

		m_zpcylinder[i].Translate(vector);
	}
}

void CHitbox::HitboxFrage(CRaumschiff * raumschiff, CFrageGrafik * frage)
{
	//Abfrage ob Antwort getroffen wird
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			if (frage->getpFrage(i)->m_aaabb[0].Intersects(r[j]))
			{
				switch (i)
				{
				case 0: 
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				default: 
					break;
				}
			}
		}
	}
}
void CHitbox::HitboxMeteoriten(CPlacement * raumschiff, CMeteorit * meteoriten)
{
	for (int j = 0; j <= 6; j++)
	{
		if (meteoriten->getiMeteorNummer() >= 49)
		{
			break;
		}
		if (meteoriten->getpMeteor(meteoriten->getiMeteorNummer() + 1)->m_aaabb[0].Intersects(r[j]))
		{
			Kollision = false;
			ULDebug("BLA: %f", meteoriten->getiMeteorNummer());
		}
		else
		{
			Kollision = false;
		}
	}
}