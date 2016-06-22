#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CFrageGrafik
{
public:
	CFrageGrafik();
	~CFrageGrafik();

	void Init(CRoot * root, CScene * scene);
	void Translate(float f_posRaumschiff, float f_posX, float f_posY);

	void SwitchOff();
	void SwitchOn();

	CPlacement * getpFrage(int i) { return &m_zpStargate[i]; };

private:

	//Fragenzeugs
	CMaterial m_zmStargate;
	CPlacement m_zpStargate[4];

	CGeoTriangleList * m_zgStargate;
	CFileWavefront m_zfilewavefront;
	CHMat Skalierung;

	//Sonstige Variablen
	float fLeftposX;
	float fLeftposY;
	float fLeftposZ;

	int iFrage;


};

