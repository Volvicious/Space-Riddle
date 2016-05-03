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

	//Raumschiff dem Geo hinzuf�gen
	m_zpRaumschiff.AddGeo(m_zRaumschiff);

	//Placement der Szene hinzuf�gen
	scene->AddPlacement(&m_zpRaumschiff);
}
