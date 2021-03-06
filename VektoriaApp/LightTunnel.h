#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

#define MAX_LIGHT 160
#define MAX_CORNER 8

class CLightTunnel
{
public:
	CLightTunnel();
	~CLightTunnel();

	void Init(CScene* scene);
	void Tick(CPlacement * Raumschiff);

	void SetZero();

private:
	// Hier ist Platz f�r die Vektoriaobjekte:
	CScene m_zs;
	CGeoCylinder m_zLight;

	CColor m_zcLights;
	CMaterial m_zmLights;

	CHVector PosLight[8];

	//Placements der Lichter
	CPlacement m_azpRechtsUnten[MAX_LIGHT / 8];
	CPlacement m_azpRechtsOben[MAX_LIGHT / 8];
	CPlacement m_azpLinksUnten[MAX_LIGHT / 8];
	CPlacement m_azpLinksOben[MAX_LIGHT / 8];
	CPlacement m_azpOben[MAX_LIGHT / 8];
	CPlacement m_azpUnten[MAX_LIGHT / 8];
	CPlacement m_azpLinks[MAX_LIGHT / 8];
	CPlacement m_azpRechts[MAX_LIGHT / 8];

	//Globale Variablen
	int iCounter = 0;
};

