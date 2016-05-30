#include "LightTunnel.h"


CLightTunnel::CLightTunnel()
{
}


CLightTunnel::~CLightTunnel()
{
}

void CLightTunnel::Init(CScene * scene)
{
	//Farbe der Lichter
	m_zcLights.InitGreen();
	m_zmLights.Translate(m_zcLights);
	m_zLight.Init(0.2, &m_zmLights, 24, 12);

	for (int i = 0; i < MAX_LIGHT / 8; i++)
	{
		float zi = i * -10.0;

		m_azpRechtsOben[i].AddGeo(&m_zLight);
		m_azpRechtsOben[i].TranslateDelta(10.0, 10.0, zi);
		scene->AddPlacement(&m_azpRechtsOben[i]);

		m_azpRechtsUnten[i].AddGeo(&m_zLight);
		m_azpRechtsUnten[i].TranslateDelta(10.0, -10.0, zi);
		scene->AddPlacement(&m_azpRechtsUnten[i]);

		m_azpLinksOben[i].AddGeo(&m_zLight);
		m_azpLinksOben[i].TranslateDelta(-10.0, 10.0, zi);
		scene->AddPlacement(&m_azpLinksOben[i]);

		m_azpLinksUnten[i].AddGeo(&m_zLight);
		m_azpLinksUnten[i].TranslateDelta(-10.0, -10.0, zi);
		scene->AddPlacement(&m_azpLinksUnten[i]);

		m_azpLinks[i].AddGeo(&m_zLight);
		m_azpLinks[i].TranslateDelta(-15.0, 0, zi);
		scene->AddPlacement(&m_azpLinks[i]);

		m_azpRechts[i].AddGeo(&m_zLight);
		m_azpRechts[i].TranslateDelta(15.0, 0, zi);
		scene->AddPlacement(&m_azpRechts[i]);

		m_azpOben[i].AddGeo(&m_zLight);
		m_azpOben[i].TranslateDelta(0, 15.0, zi);
		scene->AddPlacement(&m_azpOben[i]);

		m_azpUnten[i].AddGeo(&m_zLight);
		m_azpUnten[i].TranslateDelta(0, -15.0, zi);
		scene->AddPlacement(&m_azpUnten[i]);
	}
}

void CLightTunnel::RenewLights(CPlacement * Raumschiff)
{
	if (m_azpRechtsOben[iCounter].GetTranslation().GetZ() >= Raumschiff->GetTranslation().GetZ() + 15.0F)
	{
		//Licht hinter die Plane schieben
		m_azpRechtsOben[iCounter].TranslateZDelta(-150.0F);
		m_azpRechtsUnten[iCounter].TranslateZDelta(-150.0F);
		m_azpLinksOben[iCounter].TranslateZDelta(-150.0F);
		m_azpLinksUnten[iCounter].TranslateZDelta(-150.0F);
		m_azpLinks[iCounter].TranslateZDelta(-150.0F);
		m_azpRechts[iCounter].TranslateZDelta(-150.0F);
		m_azpOben[iCounter].TranslateZDelta(-150.0F);
		m_azpUnten[iCounter].TranslateZDelta(-150.0F);
		iCounter++;

		//Zählt von neuem Hoch
		iCounter %= MAX_LIGHT / 8;
	}
}
