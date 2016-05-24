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
	m_zMeteorit[0] = m_zfilewavefront[0].LoadGeoTriangleList("models\\Meteorit3.obj");
	m_zMeteorit[1] = m_zfilewavefront[1].LoadGeoTriangleList("models\\Meteorit2.obj");
	//m_zMeteorit[2] = m_zfilewavefront[2].LoadGeo("models\\Meteorit3.obj");

//	m_zMeteorit[0]->ReduceRedundancy(true, 6.5f);
	//m_zMeteorit[1]->ReduceRedundancy(true, 6.5f);
	//m_zMeteorit[2]->ReduceRedundancy(true, 1.5f);

//	m_zMeteorit[0].Init(2, NULL);
//	m_zMeteorit[1].Init(3, NULL);
//	m_zMeteorit[2].Init(4, NULL);

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
		int maxTextur = (rand() % 5);

		//Random Meteoriten auswählen
		int varMeteor = (rand() % 2);

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
			m_zpMeteoriten[iCounter].TranslateZDelta(-200.0F);

			//Meteorit random verschieben
			//m_zpMeteoriten[iCounter].TranslateDelta(CHVector(rndx, rndy, -150.0F));

			//if (m_zpMeteoriten[iCounter].GetTranslation().GetX() <= -20 || m_zpMeteoriten[iCounter].GetTranslation().GetX() >= 20)
			//{
			//	m_zvMeteorit.SetX(0.0F);
			//}

			//if (m_zpMeteoriten[iCounter].GetTranslation().GetY() <= -20 || m_zpMeteoriten[iCounter].GetTranslation().GetY() >= 20)
			//{
			//	m_zvMeteorit.SetY(0.0F);
			//}

			++iCounter;
			iCounterMeteoriten++;
		}
}

void CMeteorit::SwitchOff()
{
	for (int i = 0; i < MAX_METEOR; i++)
	{
		m_zpMeteoriten[i].SwitchOff();
	}
}

void CMeteorit::SwitchOn()
{
	for (int i = 0; i < MAX_METEOR; i++)
	{
		m_zpMeteoriten[i].SwitchOn();
	}
}


void CMeteorit::LowGraphics(CRoot * root, CScene * scene)
{
	float ri = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	m_zGeos.Init(1.0F, NULL, 10.0, 10.0);

	for (int i = 0; i < MAX_METEOR; i++)
	{
		float xi = rand() % 30 + (-15);
		float yi = rand() % 30 + (-15);
		float zi = i * -5.0F;

		//Meteorit erstellen
		m_zpMeteoriten[i].AddGeo(&m_zGeos);

		//Meteorit verschieben
		m_zpMeteoriten[i].Translate(xi, yi, zi);
	}

	//Meteoriten in Scene laden
	for (int i = 0; i < MAX_METEOR; i++)
	{
		scene->AddPlacement(&m_zpMeteoriten[i]);
	}
}

