#include "Hitbox.h"


CHitbox::CHitbox()
{
}


CHitbox::~CHitbox()
{
}

void CHitbox::Init(CRaumschiff * raumschiff, CFrageGrafik * frage, CMeteorit * meteor, CScene * scene)
{
	for (int i = 0; i < 3; i++)
	{
		r[i].Init(CHVector(0.0f, 0.0f, 0.0f, 1.0f), CHVector(0.0f, 0.0f, -1.0f, 0.0f));
		r[i].m_fMin = 0.0f;
		r[i].m_fMax = 3.0f;
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
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			r[0].m_vOrigin.SetX(raumschiff->getpRaumschiff()->GetTranslation().GetX() -0.75F);
			r[0].m_vOrigin.SetY(raumschiff->getpRaumschiff()->GetTranslation().GetY());
			r[0].m_vOrigin.SetZ(raumschiff->getpRaumschiff()->GetTranslation().GetZ());
		}
		
		if (i == 1)
		{
			r[1].m_vOrigin.SetX(raumschiff->getpRaumschiff()->GetTranslation().GetX() + 0.75F);
			r[1].m_vOrigin.SetY(raumschiff->getpRaumschiff()->GetTranslation().GetY());
			r[1].m_vOrigin.SetZ(raumschiff->getpRaumschiff()->GetTranslation().GetZ());
		}

		if (i == 2)
		{
			r[2].m_vOrigin.SetX(raumschiff->getpRaumschiff()->GetTranslation().GetX());
			r[2].m_vOrigin.SetY(raumschiff->getpRaumschiff()->GetTranslation().GetY());
			r[2].m_vOrigin.SetZ(raumschiff->getpRaumschiff()->GetTranslation().GetZ());
		}
	}

	for (int i = 0; i < 3; i++)
	{
		r[i].m_vOrigin.SetW(1.0f);
	}
}

int CHitbox::HitboxFrage(CRaumschiff * raumschiff, CFrageGrafik * frage)
{
	//Abfrage ob Antwort getroffen wird
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (frage->getpFrage(i) && frage->getpFrage(i)->m_aaabb)
			{
				if (frage->getpFrage(i)->m_aaabb[0].Intersects(r[j]))
				{
					if (Kollision == false)
					{
						switch (i)
						{
						Kollision = true;

						case 0: OutputDebugString("Kugel 1"); return 0; 
							break;
						case 1: ULDebug("Kugel 2"); return 1; 
							break;
						case 2: ULDebug("Kugel 3"); return 2; 
							break;
						case 3: ULDebug("Kugel 4"); return 3; 
							break;
						}
					}
				}
				else if (frage->getpFrage(1)->GetTranslation().GetZ() >= raumschiff->getpRaumschiff()->GetTranslation().GetZ())
				{
					ULDebug("Garnix");
					iFrage = 2;
					Kollision = true;
					return 4;

				}
			}
		}
	}

	//Noch nicht kollidiert
	return -1;

}
void CHitbox::HitboxMeteoriten(CRaumschiff * raumschiff, CMeteorit * meteoriten)
{
	if (Kollision == false)
	{
		for (int j = 0; j < 3; j++)
		{
			if (meteoriten->getpMeteor(meteoriten->getiMeteorNummer()) && meteoriten->getpMeteor(meteoriten->getiMeteorNummer())->m_aaabb)
			{
				if (meteoriten->getpMeteor(meteoriten->getiMeteorNummer())->m_aaabb[0].Intersects(r[j]))
				{
					Kollision = true;
				}
			}
		}
	}
}