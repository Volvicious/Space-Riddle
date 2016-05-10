#include "Raumschiff.h"


CRaumschiff::CRaumschiff()
{
}


CRaumschiff::~CRaumschiff()
{
}

void CRaumschiff::Init(CRoot * root,  CScene * scene)
{

	//Raumschiff Objekt reinladen
	m_zRaumschiff = m_filewavefront.LoadGeo("models\\Raumschiff.obj");

	//Raumschiff Material
	m_zmRaumschiff.Init();

	//Dem Raumschiff das Material geben
	m_zRaumschiff->SetMaterial(&m_zmRaumschiff);

	//Material dem Root hinzuf�gen
	root->AddMaterial(&m_zmRaumschiff);

	//Raumschiff rotieren
	//m_zpRaumschiff.RotateY(UM_DEG2RAD(180));

	//Raumschiff dem Geo hinzuf�gen
	m_zpRaumschiff.AddGeo(m_zRaumschiff);

	//Placement der Szene hinzuf�gen
	scene->AddPlacement(&m_zpRaumschiff);
}

void CRaumschiff::Tick(float Geschwindigkeit)
{
	m_zpRaumschiff.TranslateZDelta(Geschwindigkeit);
}