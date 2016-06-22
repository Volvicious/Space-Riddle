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

	void SetZero();

	CPlacement * getpRaumschiff(){ return &m_zpRaumschiff; };

private:

	//Raumschiff laden
	CGeo * m_zRaumschiff;
	CFileWavefront m_filewavefront;
	CPlacement m_zpRaumschiff;
	CHMat mathskalierung;

	//Material Raumschiff
	CMaterial m_zmRaumschiff;
	CLightSpot m_zls;
	CPlacement m_zpSonne;


	
};

