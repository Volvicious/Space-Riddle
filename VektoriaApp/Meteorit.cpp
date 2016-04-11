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
	iCounterStart = 0;
	iCounterEnd = MAX_METEOR / 2;

	for (int i = 0; i < MAX_METEOR; i++)
	{
		float xi = rand() % 30 + (-19);
		float yi = rand() % 30 + (-19);
		float zi = i * -5;

		//Meteorit erstellen
		m_azp[i].AddGeo(&m_zMeteorit);

		//Meteorit verschieben
		m_azp[i].Translate(xi, yi, zi);

		//Die Anzahl der anzuzeigenden Meteoriten am Anfang festlegen
		if (i > MAX_METEOR / 2)
		{
			m_azp[i].SwitchOff();
		}
	}

	m_pzpStart = &m_azp[0];
	m_pzpEnd = &m_azp[MAX_METEOR / 2];

	//Meteoriten in Scene laden
	for (int i = 0; i < MAX_METEOR; i++)
	{
		scene->AddPlacement(&m_azp[i]);
	}
}

void CMeteorit::RenewMeteorits(CPlacement * pRaumschiff)
{
	//Start und Ende müssen jeweils um eins hochgezählt werden
	iCounterEnd = iCounterStart + MAX_METEOR / 2;

	//Wenn das Ende des Arrays erreicht wird, wird von neuem durchgezählt
	iCounterStart %= MAX_METEOR;
	iCounterEnd %= MAX_METEOR;

	m_zvRaumschiff = pRaumschiff->GetTranslation();
	m_zvMeteorit = m_azp[iCounterStart].GetTranslation();

	//Alten Meteoriten deaktivieren und neuen aktivieren
	if (m_zvMeteorit.GetZ() >= m_zvRaumschiff.GetZ() + 15.0F)
	{
		++iCounterStart;
		m_azp[iCounterStart].SwitchOff();
		m_azp[iCounterEnd].SwitchOn();
	}

}

