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
	m_zgStargate = m_zfilewavefront.LoadGeoTriangleList("models\\Stargate.obj", true);
	m_zgStargate->Center();
	Skalierung.Scale(0.5F);
	m_zgStargate->Transform(Skalierung);
	m_zgStargate->UpdateAABB();

	//Material drauf
	//Bzw. UV Map
	m_zmStargate.MakeTextureDiffuse("textures\\Portal.png");
	m_zgStargate->SetMaterial(&m_zmStargate);

	//Material dem Root hinzufügen
	root->AddMaterial(&m_zmStargate);

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
			fLeftposX = f_posX - 3.0f;
			fLeftposY = f_posY + 3.0f;
		}
		else if (i == 1)
		{
			fLeftposX = f_posX + 3.0f;
			fLeftposY = f_posY + 3.0f;
		}
		else if (i == 2)
		{
			fLeftposX = f_posX - 3.0f;
			fLeftposY = f_posY - 3.0f;
		}
		else if (i == 3)
		{
			fLeftposX = f_posX + 3.0f;
			fLeftposY = f_posY - 3.0f;
		}

		m_zpStargate[i].Translate(fLeftposX, fLeftposY, f_posZ - 100.0f);
		m_zpStargate[i].UpdateAABBThisFromDirectChildren();
	}
	m_zgStargate->UpdateAABB();
}

void CFrageGrafik::Tick(float fTimeDelta)
{
	for (int i = 0; i < 4; i++)
	{
		CHVector save = m_zpStargate[i].GetTranslation();

		m_zpStargate[i].TranslateDelta(save * -1.0F);
		m_zpStargate[i].RotateZDelta(UM_DEG2RAD(30.0) * fTimeDelta);
		m_zpStargate[i].TranslateDelta(save);
	}
}