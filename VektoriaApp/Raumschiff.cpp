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
	m_zRaumschiff = m_filewavefront.LoadGeo("models\\Raumschiff_alt.obj");

	//Raumschiff Material
	m_zmRaumschiff.Init();

	//Dem Raumschiff das Material geben
	m_zRaumschiff->SetMaterial(&m_zmRaumschiff);

	//Material dem Root hinzufügen
	root->AddMaterial(&m_zmRaumschiff);

	//Raumschiff dem Geo hinzufügen
	m_zpRaumschiff.AddGeo(m_zRaumschiff);

	//Placement der Szene hinzufügen
	scene->AddPlacement(&m_zpRaumschiff);
}

void CRaumschiff::Tick(float Geschwindigkeit)
{
	m_zpRaumschiff.TranslateZDelta(Geschwindigkeit);
}

void CRaumschiff::SetZero(FLOAT ZPos)
{
	m_zpRaumschiff.Translate(CHVector(0.0f, 0.0f, ZPos));
}