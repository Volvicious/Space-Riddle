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
//	//Blender File Laden
//	m_zMeteorit[0] = m_zfilewavefront[0].LoadGeoTriangleList("models\\Meteorit3.obj");
//	m_zMeteorit[1] = m_zfilewavefront[1].LoadGeoTriangleList("models\\Meteorit2.obj");
//	//m_zMeteorit[2] = m_zfilewavefront[2].LoadGeo("models\\Meteorit3.obj");
//
//	m_zMeteorit[0]->ReduceRedundancy(true, 6.5f);
//	m_zMeteorit[1]->ReduceRedundancy(true, 6.5f);
//	//m_zMeteorit[2]->ReduceRedundancy(true, 1.5f);
//
////	m_zMeteorit[0].Init(2, NULL);
////	m_zMeteorit[1].Init(3, NULL);
////	m_zMeteorit[2].Init(4, NULL);

	//Texturen der Meteoriten laden
	m_zMaterialMeteorit[0].MakeTextureDiffuse("textures\\MeteoritTextur1.obj");
	m_zMaterialMeteorit[1].MakeTextureDiffuse("textures\\MeteoritTextur2.obj");
	m_zMaterialMeteorit[2].MakeTextureDiffuse("textures\\MeteoritTextur3.obj");
	m_zMaterialMeteorit[3].MakeTextureDiffuse("textures\\MeteoritTextur4.obj");
	m_zMaterialMeteorit[4].MakeTextureDiffuse("textures\\MeteoritTextur5.obj");

	//Kugel initialisieren
	m_zgMeteorit.Init(1.0F, NULL);

	//Deformieren
	Deform();

	//Meteoriten hinzufügen
	for (int i = 0; i < MAX_METEOR; i++)
	{

		//Random Textur auswählen
		//int maxTextur = (rand() % 5);

		//Random Meteoriten auswählen
		//int varMeteor = (rand() % 2);

		//Translations Variablen Random erstellen
		float xi = rand() % 30 + (-15);
		float yi = rand() % 30 + (-15);
		float zi = i * -5.0F;

		float fuck = rand() % 360;

		//Textur auf Meteorit laden
		//m_zMeteorit[i]->SetMaterial(&m_zMaterialMeteorit[maxTextur]);

		//Meteoriten dem Placement geben
		m_zpMeteoriten[i].AddGeo(&m_zgMeteorit);

		//Meteoriten random verschieben
		m_zpMeteoriten[i].Translate(xi, yi, zi);

		//Rotieren
		m_zpMeteoriten[i].RotateXDelta(fuck);
		m_zpMeteoriten[i].RotateZDelta(fuck);
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

void CMeteorit::Deform()
{
	//Hier wird die Kugel deformiert, dass sie aussieht wie ein Meteorit
	//m_zgSphere.SetMaterial(&Kugel);
	//Kugel.SetBumpStrength(5.0f);
	//Kugel.MakeTextureDiffuse("textures\\m2g.jpg");
	////Kugel.MakeTextureBump("textures\\m3.jpg");

	//Meteoriten deformieren
	mat.TranslateY(1.0F);
	m_zgMeteorit.Transform(mat);
	m_zgMeteorit.TaperY(0.2f, false, true, false);
	m_zgMeteorit.WaveY(0.1f, 2.0f, 0.0f, true, false, true);
	
	m_zgMeteorit.Magnet(CHVector(1, 1, 1, 1), 2.0f, 1.0f, true);
	m_zgMeteorit.TaperX(0.1f, true, false, false);
}

void CMeteorit::Tick(CPlacement * pRaumschiff, bool b)
{
	//Wenn das Array überschritten wird muss es wieder bei 0 anfangen
	iCounter %= MAX_METEOR;

	if (m_zpMeteoriten[iCounter].GetTranslation().GetZ() >= pRaumschiff->GetTranslation().GetZ())
	{
		if (iCounter % 10 == 0)
		{
			//Meteoriten auf Raumschiff X,Y Position setzen
			m_zpMeteoriten[iCounter].m_mLocal.m_fx03 = pRaumschiff->GetTranslation().GetX();
			m_zpMeteoriten[iCounter].m_mLocal.m_fx13 = pRaumschiff->GetTranslation().GetY();
			m_zpMeteoriten[iCounter].TranslateZDelta(-150.0F);
		}
		iCounter++;
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
	m_zGeos.Init(1.0F, NULL);

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

