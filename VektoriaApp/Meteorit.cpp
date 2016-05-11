#include "Meteorit.h"

CMeteorit::CMeteorit()
{
	srand(time(0));
}


CMeteorit::~CMeteorit()
{
}

void CMeteorit::Init(CScene * scene)
{
	float ri = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	m_zMeteorit.Init(1.0F, NULL, 10.0, 10.0);

	for (int i = 0; i < MAX_METEOR; i++)
	{
		float xi = rand() % 30 + (-15);
		float yi = rand() % 30 + (-15);
		float zi = i * -5.0F;

		//Meteorit erstellen
		m_azp[i].AddGeo(&m_zMeteorit);

		//Meteorit verschieben
		m_azp[i].Translate(xi, yi, zi);
	}

	//Meteoriten in Scene laden
	for (int i = 0; i < MAX_METEOR; i++)
	{
		scene->AddPlacement(&m_azp[i]);
		
	}
}

void CMeteorit::RenewMeteorits(CPlacement * pRaumschiff, bool b)
{
		//Wenn das Ende des Arrays erreicht wird, wird von neuem durchgezählt
		iCounter %= MAX_METEOR;

		//Raumschiff und Meteoriten position wird in einen Vektor umgewandelt
		m_zvRaumschiff = pRaumschiff->GetTranslation();
		m_zvMeteorit = m_azp[iCounter].GetTranslation();

		//Meteoriten hinter den Fog schieben
		if (m_zvMeteorit.GetZ() >= m_zvRaumschiff.GetZ() + 15.0F)
		{
			m_azp[iCounter].TranslateZDelta(-50.0F);
			if (b) {
				m_azp[iCounter].SwitchOn();

			}
			else {
				m_azp[iCounter].SwitchOff();
				iCounterMeteoriten = 0;

			}


			++iCounter;
			iCounterMeteoriten++;
		}
}

