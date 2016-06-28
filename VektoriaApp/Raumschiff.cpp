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
	m_zRaumschiff = m_filewavefront.LoadGeo("models\\RaumschiffFinal.obj", true);
	m_zRaumschiff->Transform(mathskalierung);

	//Raumschiff Material
	//UV Map draufladen 
	//TODO:
	m_zmRaumschiff.MakeTextureDiffuse("textures\\RTextur.png");

	//Dem Raumschiff das Material geben
	m_zRaumschiff->SetMaterial(&m_zmRaumschiff);

	//Material dem Root hinzufügen
	//root->AddMaterial(&m_zmRaumschiff);

	//Raumschiff dem Geo hinzufügen
	m_zpRaumschiff.AddGeo(m_zRaumschiff);

	//Placement der Szene hinzufügen
	scene->AddPlacement(&m_zpRaumschiff);

	//Raumschiff auf 0 setzen
	m_zpRaumschiff.Translate(0, 0, 0);

	scene->AddPlacement(&m_zpSonne);
	m_zpSonne.AddLightSpot(&m_zls);
	m_zpSonne.TranslateY(10.0f);
	m_zpSonne.SetPointing(&m_zpRaumschiff);
	m_zls.Init(CColor(255.0f, 255.0f, 255.0f), 0.05f, 0.9f, 0.0025f);
}

void CRaumschiff::Tick(float Geschwindigkeit)
{
	m_zpRaumschiff.TranslateZDelta(Geschwindigkeit);
	CHVector vec = m_zpSonne.GetTranslation();
	vec.SetZ(m_zpRaumschiff.GetTranslation().GetZ() + 20.0f);
	m_zpSonne.Translate(vec);
}

void CRaumschiff::SetZero()
{
	m_zpRaumschiff.Translate(CHVector(0.0f, 0.0f, 0.0f));
}