#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

#define MAX_WALLS 4

class CTube
{
public:
	CTube();
	~CTube();

	void Init(CScene* scene);
	void RenewWalls(CPlacement * placement);

private:
	// Hier ist Platz für die Vektoriaobjekte:
	CScene m_zs;
	CGeoWall m_zWall;

	//Meteoriten Placements
	CPlacement m_azp[MAX_WALLS];

};

