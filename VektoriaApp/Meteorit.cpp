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
	//Textur draufwerfen
	m_zMaterialMeteorit[0].SetBumpStrength(2);
	m_zMaterialMeteorit[0].MakeTextureDiffuse("textures\\textur1.jpg");
	m_zMaterialMeteorit[0].MakeTextureBump("textures\\textur1Bump.png");

	m_zMaterialMeteorit[1].SetBumpStrength(2);
	m_zMaterialMeteorit[1].MakeTextureDiffuse("textures\\textur2.JPG");
	m_zMaterialMeteorit[1].MakeTextureBump("textures\\textur2Bump.png");

	m_zMaterialMeteorit[2].SetBumpStrength(2);
	m_zMaterialMeteorit[2].MakeTextureDiffuse("textures\\textur3.jpg");
	m_zMaterialMeteorit[2].MakeTextureBump("textures\\textur3Bump.png");

	//Kugel initialisieren
	m_zgMeteorit[0].Init(1.0F, &m_zMaterialMeteorit[0]);
	m_zgMeteorit[1].Init(1.0F, &m_zMaterialMeteorit[1]);
	m_zgMeteorit[2].Init(1.0F, &m_zMaterialMeteorit[2]);

	//Deformieren
	Deform();

	//Prepare Roation

	PrepareRotate(); 

	//Meteoriten hinzufügen
	for (int i = 0; i < MAX_METEOR; i++)
	{
		//Random Meteoriten auswählen
		int varMeteor = (rand() % 3);

		//Meteoriten dem Placement geben
		m_zpMeteoriten[i].AddGeo(&m_zgMeteorit[varMeteor]);
	}

	//Texturen dem Root hinzufügen
	for (int i = 0; i < 3; i++)
	{
		root->AddMaterial(&m_zMaterialMeteorit[i]);
	}

	//Meteoriten in die Szene laden
	for (int i = 0; i < MAX_METEOR; i++)
	{
		scene->AddPlacement(&m_zpMeteoriten[i]);
	}

}


void CMeteorit::PrepareRotate() {

	for (int i = 0; i < MAX_METEOR; i++) {
  

		fRotStartWerteXYZ[i][0] = (float)(5 - (rand() % 11)) / 999999.F;
		fRotationXYZ[i][0] = 0.0F;

		
		fRotStartWerteXYZ[i][1] = (float)(5 - (rand() % 11)) / 999999.F;
		fRotationXYZ[i][1] = 0.0F;

		fRotStartWerteXYZ[i][2] = (float)(5 - (rand() % 11)) / 2554.F;
		fRotationXYZ[i][2] = 0.0F;

		
	}
}

void CMeteorit::Deform()
{
	//Meteoriten deformieren
	// Form 1
	m_zgMeteorit[0].TaperY(0.5F, true, false, true);
	m_zgMeteorit[0].WaveX(0.1F, 1.5f, 0.0f, true, false, true);
	CHVector v1(1, 1, 1, 1);
	m_zgMeteorit[0].Magnet(v1, 1.5f, 1.0f, true);

	//Form 2
	m_zgMeteorit[1].TaperX(0.2F, false, true, true);
	m_zgMeteorit[1].WaveX(0.6F, 5.0f, 0.0f, true, false, true);
	CHVector v2(0, 2, 2, 1);
	m_zgMeteorit[1].Magnet(v2, 1.0f, 1.0f, true);

	//Form3
	m_zgMeteorit[2].TaperY(0.2f, true, false, true);
	m_zgMeteorit[2].RippleY(0.1f, 4, 0.0f, true, false, true);
	m_zgMeteorit[2].WaveX(0.1F, 4.0f, 0.0f, true, false, true);
	CHVector v3(1, 1, 1, 1);
	m_zgMeteorit[2].Magnet(v3, 1.2f, 1.5f, true);
}

void CMeteorit::Tick(CPlacement * pRaumschiff, float fTimeDelta)
{
	if (m_zpMeteoriten[iCounter].GetTranslation().GetZ() >= pRaumschiff->GetTranslation().GetZ())
	{
		iCounter++;
	}

	for (int i = iCounter; i < MAX_METEOR; i++) {

		CHVector vec = m_zpMeteoriten[i].GetTranslation();
		
		fRotationXYZ[i][0] += fRotStartWerteXYZ[i][0]/fTimeDelta;
		fRotationXYZ[i][1] += fRotStartWerteXYZ[i][1]/fTimeDelta;
		fRotationXYZ[i][2] += fRotStartWerteXYZ[i][2]/fTimeDelta;

		

		m_zpMeteoriten[i].RotateX(fRotationXYZ[i][0]);
		m_zpMeteoriten[i].RotateYDelta(fRotationXYZ[i][1]);
		//m_zpMeteoriten[i].RotateZDelta(fRotationXYZ[i][2]);

		m_zpMeteoriten[i].TranslateDelta(vec);

	}

	

}

void CMeteorit::NewLevel(CPlacement * raumschiff)
{
	for (int i = 0; i <= MAX_METEOR; i++)
	{
		//Translations Variablen Random erstellen
		float xi = rand() % 30 + (-15);
		float yi = rand() % 30 + (-15);
		float zi = i * -15.0F - 20.0f;

		//Meteoriten verschieben
		m_zpMeteoriten[i].Translate(xi, yi, raumschiff->GetTranslation().GetZ() + zi);
	}

	iCounter = 0;
}


void CMeteorit::SwitchOff()
{
	for (int i = 0; i <= MAX_METEOR; i++)
	{
		m_zpMeteoriten[i].SwitchOff();
	}
}

void CMeteorit::SwitchOn()
{
	for (int i = 0; i <= MAX_METEOR; i++)
	{
		m_zpMeteoriten[i].SwitchOn();
	}
}


