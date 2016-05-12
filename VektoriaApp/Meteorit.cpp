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
	//Meteoriten laden und dem Placement hinzufügen
	LoadBlenderFiles(scene);
}

void CMeteorit::LoadBlenderFiles(CScene * scene)
{
	//Blender File Laden
	m_zMeteorit[0] = m_zfilewavefront[0].LoadGeo("models\\Meteorit1.obj");
	m_zMeteorit[1] = m_zfilewavefront[1].LoadGeo("models\\Meteorit2.obj");
	m_zMeteorit[2] = m_zfilewavefront[2].LoadGeo("models\\Meteorit3.obj");

	//Meteoriten hinzufügen
	for (int i = 0; i < MAX_METEOR; i++)
	{
		//Random Meteoriten auswählen
		int varMeteor = (rand() % VAR_METEOR);

		//Translations Variablen Random erstellen
		float xi = rand() % 30 + (-15);
		float yi = rand() % 30 + (-15);
		float zi = i * -5.0F;

		//Meteoriten dem Placement geben
		m_zpMeteoriten[i].AddGeo(m_zMeteorit[varMeteor]);

		//Meteoriten random verschieben
		m_zpMeteoriten[i].Translate(xi, yi, zi);
	}

	//Meteoriten in die Szene laden
	for (int i = 0; i < MAX_METEOR; i++)
	{
		scene->AddPlacement(&m_zpMeteoriten[i]);
	}

}

void CMeteorit::Tick(CPlacement * pRaumschiff, bool b)
{
		//Wenn das Ende des Arrays erreicht wird, wird von neuem durchgezählt
		iCounter %= MAX_METEOR;

		//Raumschiff und Meteoriten position wird in einen Vektor umgewandelt
		m_zvRaumschiff = pRaumschiff->GetTranslation();
		m_zvMeteorit = m_zpMeteoriten[iCounter].GetTranslation();

		//Meteoriten hinter den Fog schieben
		if (m_zvMeteorit.GetZ() >= m_zvRaumschiff.GetZ() + 15.0F)
		{
			m_zpMeteoriten[iCounter].TranslateZDelta(-50.0F);

			if (b) 
			{
				m_zpMeteoriten[iCounter].SwitchOn();
			}
			else 
			{
				m_zpMeteoriten[iCounter].SwitchOff();
				iCounterMeteoriten = 0;
			}
			++iCounter;
			iCounterMeteoriten++;
		}
}

