#include "Tube.h"


CTube::CTube()
{
}


CTube::~CTube()
{
}

void CTube::Init(CScene * scene)
{
	//Tunnel
	m_zWall.Init(150.0, 0.1, 0.1, NULL);

	for (int i = 0; i < MAX_WALLS; i++)
	{
		//Dem Placement das Geo hinzufügen
		m_azp[i].AddGeo(&m_zWall);

		//Tunnel rotieren
		m_azp[i].RotateYDelta(UM_DEG2RAD(90));

		if (i == 0)
		{
			m_azp[i].TranslateDelta(10.0, 10.0, 0.0);
		}

		if (i == 1)
		{
			m_azp[i].TranslateDelta(10.0, -10.0, 0.0);
		}

		if (i == 2)
		{
			m_azp[i].TranslateDelta(-10.0, 10.0, 0.0);
		}

		if (i == 3)
		{
			m_azp[i].TranslateDelta(-10.0, -10.0, 0.0);
		}

		//Tunnel der Szene  hinzufügen
		scene->AddPlacement(&m_azp[i]);
	}
}

void CTube::RenewWalls(CPlacement * placement)
{
	for (int i = 0; i < MAX_WALLS; i++)
	{
		if (m_azp[i].GetTranslation().GetZ() >= placement->GetTranslation().GetZ())
		{
			m_azp[i].TranslateZDelta(-0.1F);
		}
	}
}
