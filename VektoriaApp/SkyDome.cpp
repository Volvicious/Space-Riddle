#include "SkyDome.h"


CSkyDome::CSkyDome()
{
}


CSkyDome::~CSkyDome()
{
}

void CSkyDome::Init(CRoot * root, CScene * scene)
{
	//Material
	m_zMaterial.MakeTextureSky("textures\\Skydome.png");

	//Skydome init
	m_zSkyDome.Init(100.0F, 100.0F, &m_zMaterial, true, 24, 12, eMapping_Cylindrical);

	//Placement geo geben
	m_zpSkyDome.AddGeo(&m_zSkyDome);

	//Material dem Root geben
	root->AddMaterial(&m_zMaterial);

	//Szene Placement geben
	scene->AddPlacement(&m_zpSkyDome);
}

void CSkyDome::SetZero()
{
	m_zpSkyDome.TranslateZ(0.0f);
}

void CSkyDome::Tick(float fGeschwindigkeit)
{
	m_zpSkyDome.TranslateZDelta(fGeschwindigkeit);
}
