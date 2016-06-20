#include "Raumschiff.h"


CRaumschiff::CRaumschiff()
{
}


CRaumschiff::~CRaumschiff()
{
}

void CRaumschiff::Init(CRoot * root,  CScene * scene)
{
	//Raumschiff verkleinern
	mathskalierung.Scale(0.55F);

	//Raumschiff Objekt reinladen
	m_zRaumschiff = m_filewavefront.LoadGeo("models\\RaumschiffNew.obj", true);
	m_zRaumschiff->Transform(mathskalierung);

	//Raumschiff Material
	//UV Map draufladen 
	//TODO:
	m_zmRaumschiff.MakeTextureDiffuse("textures\\RaumschiffTextur.png");

	//Dem Raumschiff das Material geben
	m_zRaumschiff->SetMaterial(&m_zmRaumschiff);

	//Material dem Root hinzufügen
	root->AddMaterial(&m_zmRaumschiff);

	//Raumschiff dem Geo hinzufügen
	m_zpRaumschiff.AddGeo(m_zRaumschiff);

	//Placement der Szene hinzufügen
	scene->AddPlacement(&m_zpRaumschiff);

	//Raumschiff auf 0 setzen
	m_zpRaumschiff.Translate(0, 0, 0);
}

void CRaumschiff::Tick(float Geschwindigkeit)
{
	m_zpRaumschiff.TranslateZDelta(Geschwindigkeit);
}

void CRaumschiff::SetZero()
{
	m_zpRaumschiff.Translate(CHVector(0.0f, 0.0f, 0.0f));
}