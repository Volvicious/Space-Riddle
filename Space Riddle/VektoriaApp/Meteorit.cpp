#include "Meteorit.h"

CMeteorit::CMeteorit()
{
	//Random Größe und verschiebung
	float xi = (rand() % 7) - 3;
	float yi = (rand() % 7) - 3;
	float zi = (rand() % 7) - 3;
	float ri = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	//Meteorit erstellen
	m_zMeteorit.Init(ri, NULL, 10.0, 10.0);

	//Placement hinzufügen
	m_zpMeteorit.AddGeo(&m_zMeteorit);

	//Meteorit verschieben
	m_zpMeteorit.Translate(xi, yi, zi);
}


CMeteorit::~CMeteorit()
{
}
