#include "Frage.h"


CFrage::CFrage()
{
}


CFrage::~CFrage()
{
}

void CFrage::Init1(CScene * scene)
{
	m_zgSphere.Init(1.0F, &m_zMaterialKugel, 50, 50);
	m_zgFrage.Init(3.0f, &m_zMaterialKugel, 50, 50);

	for (int i = 0; i < 4; i++)
	{
		m_zpSphere[i].AddGeo(&m_zgSphere);
		scene->AddPlacement(&m_zpSphere[i]);
	}

	m_zpSphere[4].AddGeo(&m_zgFrage);
	scene->AddPlacement(&m_zpSphere[4]);
}

void CFrage::Init(FLOAT f_posZ, FLOAT f_posX, FLOAT f_posY)
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