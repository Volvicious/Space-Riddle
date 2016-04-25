#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

#define MAX_LIGHT 60

class CLightTunnel
{
public:
	CLightTunnel();
	~CLightTunnel();

	void Init(CScene* scene);
	void RenewLights(CPlacement * Raumschiff);

private:
	// Hier ist Platz für die Vektoriaobjekte:
	CScene m_zs;
	CGeoSphere m_zLight;

	//Meteoriten Placements
	CPlacement m_azpRechtsUnten[MAX_LIGHT / 4];
	CPlacement m_azpRechtsOben[MAX_LIGHT / 4];
	CPlacement m_azpLinksUnten[MAX_LIGHT /4 ];
	CPlacement m_azpLinksOben[MAX_LIGHT /4 ];

	//Globale Variablen
	int iCounter = 0;
};

