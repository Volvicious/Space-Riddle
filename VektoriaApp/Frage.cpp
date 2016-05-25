#include "Frage.h"


CFrage::CFrage()
{
}


CFrage::~CFrage()
{
}

void CFrage::Init(CScene * scene)
{
	//Frage initialisieren
	m_zgSphere.Init(1.0F, &m_zMaterialKugel, 50, 50);
	m_zgFrage.Init(3.0f, &m_zMaterialKugel, 50, 50);

	//Frage und Antworten hinzufügen
	for (int i = 0; i < 4; i++)
	{
		m_zpSphere[i].AddGeo(&m_zgSphere);
		scene->AddPlacement(&m_zpSphere[i]);
	}

	//Dem Placement die Frage hinzufügen
	m_zpSphere[4].AddGeo(&m_zgFrage);

	//Der Szene das Placement hinzufügen
	scene->AddPlacement(&m_zpSphere[4]);
}

void CFrage::SwitchOff()
{
	for (int i = 0; i <= 5; i++)
	{
		m_zpSphere[i].SwitchOff();
	}
}

void CFrage::SwitchOn()
{
	for (int i = 0; i <= 5; i++)
	{
		m_zpSphere[i].SwitchOn();
	}
}

void CFrage::Tick(FLOAT f_posZ, FLOAT f_posX, FLOAT f_posY)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			fLeftpos = f_posX - 7.5f;
		}
		else
		{
			fLeftpos = fLeftpos + 5.0f;
		}
		m_zpSphere[i].Translate(fLeftpos, f_posY, f_posZ - 100.0f);
	}

	m_zpSphere[4].Translate(f_posX, f_posY + 5.0f, f_posZ - 100.0f);
}