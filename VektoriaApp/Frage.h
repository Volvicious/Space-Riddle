#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CFrage
{
public:
	CFrage();
	~CFrage();

	void Init(FLOAT f_posRaumschiff, FLOAT f_posX, FLOAT f_posY);
	void Init1(CScene * scene1);
	CHVector getPlacement(int j){ return  m_zpSphere[j].GetTranslation(); };
private:


	CMaterial m_zMaterialKugel;
	CGeoSphere m_zgSphere;
	CGeoSphere m_zgFrage;
	CPlacement m_zpSphere[5];
	float fLeftpos;



	//	CGeoSphere m_zgSFrage;
	//	CGeoSphere m_zgSA;
	//////	CGeoSphere m_zgSB;
	//	CGeoSphere m_zgSC;
	//	CGeoSphere m_zgSD;

	//CPlacement m_zpSFrage;
	//	CPlacement m_zpSA;
	//	CPlacement m_zpSB;
	//	CPlacement m_zpSC;
	//	CPlacement m_zpSD;


};

