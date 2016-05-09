#pragma once

#include "Vektoria\Root.h"

using namespace Vektoria;

class CRaumschiff
{
public:
	CRaumschiff();
	~CRaumschiff();

	void Init(CRoot * root, CScene * scene);
	void Tick(float Geschwindigkeit);
	CPlacement * getpRaumschiff(){ return &m_zpRaumschiff; };

private:

	//Raumschiff laden
	CGeo * m_zRaumschiff;
	CFileWavefront m_filewavefront;
	CPlacement m_zpRaumschiff;

	//Material Raumschiff
	CColor m_zcRaumschiff;
	CMaterial m_zmRaumschiff;
	CImage m_ziRaumschiff;
	CTexture m_ztRaumschiff;
	
};

