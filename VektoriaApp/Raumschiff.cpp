#include "Raumschiff.h"


CRaumschiff::CRaumschiff()
{
}


CRaumschiff::~CRaumschiff()
{
}

void CRaumschiff::Init(CScene * scene)
{
	//Raumschiff Objekt reinladen
	m_zRaumschiff = m_filewavefront.LoadGeo("textures\\Raumschiff.obj");

	//Raumschiff dem Geo hinzufügen
	m_zpRaumschiff.AddGeo(m_zRaumschiff);

	//Placement der Szene hinzufügen
	scene->AddPlacement(&m_zpRaumschiff);
}
