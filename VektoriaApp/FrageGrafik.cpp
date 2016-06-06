#include "FrageGrafik.h"


CFrageGrafik::CFrageGrafik()
{
}


CFrageGrafik::~CFrageGrafik()
{
}

void CFrageGrafik::Init(CScene * scene)
{
	m_zgSphere.Init(1.0F, &m_zMaterialKugel, 50, 50);

	for (int i = 0; i < 4; i++)
	{
		m_zpSphere[i].AddGeo(&m_zgSphere);
		scene->AddPlacement(&m_zpSphere[i]);
		SwitchOff();
	}
}

void CFrageGrafik::SwitchOff()
{
	for (int i = 0; i < 4; i++)
	{
		m_zpSphere[i].SwitchOff();
	}
}

void CFrageGrafik::SwitchOn()
{
	for (int i = 0; i < 4; i++)
	{
		m_zpSphere[i].SwitchOn();
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

		m_zpSphere[i].Translate(fLeftpos, f_posY, f_posZ - 100.0f);
	}
}