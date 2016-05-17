#include "Meteorit.h"

CMeteorit::CMeteorit()
{
	srand(time(0));
}


CMeteorit::~CMeteorit()
{
}

void CMeteorit::Init(CRoot * root, CScene * scene)
{
	//Blender File Laden
	m_zMeteorit[0] = m_zfilewavefront[0].LoadGeo("models\\Meteorit1.obj");
	m_zMeteorit[1] = m_zfilewavefront[1].LoadGeo("models\\Meteorit2.obj");
	m_zMeteorit[2] = m_zfilewavefront[2].LoadGeo("models\\Meteorit3.obj");
	m_zMeteorit[3] = m_zfilewavefront[3].LoadGeo("models\\Meteorit4.obj");

	//Texturen der Meteoriten laden
	m_zMaterialMeteorit[0].MakeTextureDiffuse("textures\\MeteoritTextur1.obj");
	m_zMaterialMeteorit[1].MakeTextureDiffuse("textures\\MeteoritTextur2.obj");
	m_zMaterialMeteorit[2].MakeTextureDiffuse("textures\\MeteoritTextur3.obj");
	m_zMaterialMeteorit[3].MakeTextureDiffuse("textures\\MeteoritTextur4.obj");
	m_zMaterialMeteorit[4].MakeTextureDiffuse("textures\\MeteoritTextur5.obj");

	//Meteoriten hinzufügen
	for (int i = 0; i < MAX_METEOR; i++)
	{
		//Random Textur auswählen
		int maxTextur = (rand() % 6);

		//Random Meteoriten auswählen
		int varMeteor = (rand() % 5);

		//Translations Variablen Random erstellen
		float xi = rand() % 30 + (-15);
		float yi = rand() % 30 + (-15);
		float zi = i * -5.0F;

		//Textur auf Meteorit laden
		//m_zMeteorit[i]->SetMaterial(&m_zMaterialMeteorit[maxTextur]);

		//Meteoriten dem Placement geben
		m_zpMeteoriten[i].AddGeo(m_zMeteorit[varMeteor]);

		//Meteoriten random verschieben
		m_zpMeteoriten[i].Translate(xi, yi, zi);
	}

	//Texturen dem Root hinzufügen
	for (int i = 0; i < 5; i++)
	{
		root->AddMaterial(&m_zMaterialMeteorit[i]);
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

		//Random zahlen generieren
		float rndxy = rand() % 30 -15;
		float rndx = rand() % 10 - 5;
		float rndy = rand() % 10 - 5;

		//Raumschiff und Meteoriten position wird in einen Vektor umgewandelt
		m_zvRaumschiff = pRaumschiff->GetTranslation();
		m_zvMeteorit = m_zpMeteoriten[iCounter].GetTranslation();

		//Meteoriten hinter den Fog schieben
		if (m_zvMeteorit.GetZ() >= m_zvRaumschiff.GetZ() + 15.0F)
		{
			//Meteorit random verschieben
			m_zpMeteoriten[iCounter].TranslateDelta(CHVector(rndx, rndy, -150.0F));

			if (m_zpMeteoriten[iCounter].GetTranslation().GetX() <= -20 || m_zpMeteoriten[iCounter].GetTranslation().GetX() >= 20)
			{
				m_zvMeteorit.SetX(0.0F);
			}

			if (m_zpMeteoriten[iCounter].GetTranslation().GetY() <= -20 || m_zpMeteoriten[iCounter].GetTranslation().GetY() >= 20)
			{
				m_zvMeteorit.SetY(0.0F);
			}

			/*if (b) 
			{
				m_zpMeteoriten[iCounter].SwitchOn();
			}
			else 
			{
				m_zpMeteoriten[iCounter].SwitchOff();
				iCounterMeteoriten = 0;
			}*/
			++iCounter;
			iCounterMeteoriten++;
		}
}

