#include "LightTunnel.h"


CLightTunnel::CLightTunnel()
{
}


CLightTunnel::~CLightTunnel()
{
}

void CLightTunnel::Init(CScene * scene)
{
	m_zLight.Init(0.1, NULL, 24, 12);

	for (int i = 0; i < MAX_LIGHT / 4; i++)
	{
		float zi = i * -10.0;

		m_azpRechtsOben[i].AddGeo(&m_zLight);
		m_azpRechtsOben[i].TranslateDelta(10.0, 10.0, zi);
		scene->AddPlacement(&m_azpRechtsOben[i]);
	}

	for (int i = 0; i < MAX_LIGHT / 4; i++)
	{
		float zi = i * -10.0;
		m_azpRechtsUnten[i].AddGeo(&m_zLight);
		m_azpRechtsUnten[i].TranslateDelta(10.0, -10.0, zi);
		scene->AddPlacement(&m_azpRechtsUnten[i]);
	}

	for (int i = 0; i < MAX_LIGHT / 4; i++)
	{
		float zi = i * -10.0;
		m_azpLinksOben[i].AddGeo(&m_zLight);
		m_azpLinksOben[i].TranslateDelta(-10.0, 10.0, zi);
		scene->AddPlacement(&m_azpLinksOben[i]);
	}

	for (int i = 0; i < MAX_LIGHT / 4; i++)
	{
		float zi = i * -10.0;
		m_azpLinksUnten[i].AddGeo(&m_zLight);
		m_azpLinksUnten[i].TranslateDelta(-10.0, -10.0, zi);
		scene->AddPlacement(&m_azpLinksUnten[i]);
	}
}

void CLightTunnel::RenewLights(CPlacement * Raumschiff)
{
	if (Raumschiff->GetTranslation().GetZ() <= m_azpRechtsOben[iCounter].GetTranslation().GetZ() + 15.0F)
	{
		//Licht hinter die Plane schieben
		m_azpRechtsOben[iCounter].TranslateZDelta(-150.0F);
		m_azpRechtsUnten[iCounter].TranslateZDelta(-150.0F);
		m_azpLinksOben[iCounter].TranslateZDelta(-150.0F);
		m_azpLinksUnten[iCounter].TranslateZDelta(-150.0F);
		iCounter++;

		//Zählt von neuem Hoch
		iCounter %= MAX_LIGHT / 4;
	}
}
