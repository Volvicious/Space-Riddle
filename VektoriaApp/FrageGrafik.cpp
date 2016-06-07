#include "FrageGrafik.h"


CFrageGrafik::CFrageGrafik()
{
}


CFrageGrafik::~CFrageGrafik()
{
}

void CFrageGrafik::Init(CRoot * root, CScene * scene)
{
	//Geo laden
	m_zgStargate = m_zfilewavefront.LoadGeo("models\\Stargate.obj");
	Skalierung.Scale(0.5F);
	m_zgStargate->Transform(Skalierung);

	//Material drauf
	//Bzw. UV Map
	//m_zgStargate->SetMaterial(&m_zmStargate);

	//Material dem Root hinzufügen
	//root->AddMaterial(&m_zmStargate);

	//Stargates den Placements geben
	for (int i = 0; i < 4; i++)
	{
		m_zpStargate[i].AddGeo(m_zgStargate);
		scene->AddPlacement(&m_zpStargate[i]);
		SwitchOff();
	}
}

void CFrageGrafik::SwitchOff()
{
	for (int i = 0; i < 4; i++)
	{
		m_zpStargate[i].SwitchOff();
	}
}

void CFrageGrafik::SwitchOn()
{
	for (int i = 0; i < 4; i++)
	{
		m_zpStargate[i].SwitchOn();
	}
}

void CFrageGrafik::Translate(FLOAT f_posZ, FLOAT f_posX, FLOAT f_posY)
{
	//Fragen wieder hinzufügen
	SwitchOn();

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

		m_zpStargate[i].Translate(fLeftpos, f_posY, f_posZ - 100.0f);
	}
}