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
}

void CHitbox::HitboxFrage(CRaumschiff * raumschiff, CFrageGrafik * frage)
{
	//Abfrage ob Antwort getroffen wird
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			if (frage->getpFrage(i) && frage->getpFrage(i)->m_aaabb)
			{
				if (frage->getpFrage(i)->m_aaabb[0].Intersects(r[j]))
				{
					if (Kollision = false)
					{
						switch (i)
						{
						case 0: OutputDebugString("Kugel 1");
							break;
						case 1: OutputDebugString("Kugel 2");
							break;
						case 2: OutputDebugString("Kugel 3");
							break;
						case 3: OutputDebugString("Kugel 4");
							break;
						default: OutputDebugString("Kugel Garnix");
							break;
						}
						Kollision = true;
					}
				}
			}
		}
	}
}
void CHitbox::HitboxMeteoriten(CPlacement * raumschiff, CMeteorit * meteoriten)
{
	for (int j = 0; j <= 6; j++)
	{
		if (meteoriten->getpMeteor(meteoriten->getiMeteorNummer()) && meteoriten->getpMeteor(meteoriten->getiMeteorNummer())->m_aaabb)
		{
			if (meteoriten->getpMeteor(meteoriten->getiMeteorNummer())->m_aaabb[0].Intersects(r[j]))
			{
				if (Kollision = false)
				{
					Kollision = true;
				}
			}
		}
	}
}