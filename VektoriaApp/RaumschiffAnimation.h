#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CRaumschiffAnimation
{
public:
	CRaumschiffAnimation();
	~CRaumschiffAnimation();

	//Returnt true, sollte sich das Raumschiff um die eigene Achse drehen.
	bool Run(CPlacement * ptrraumschiff, CDeviceKeyboard * ptrkeyboard, float fTimeDelta);

private: 


	bool DoingRotationA(CPlacement * ptrRaumischiffi, float fTimeDelta);
	bool DoingRotationD(CPlacement * ptrRaumischiffi, float fTimeDelta);

	float fTimeGesA = 0.0F;
	bool bDoRotateA = false; 
	int iAHit = 0; 

	float fTimeGesD = 0.0F;
	bool bDoRotateD = false;
	int iDHit = 0;

	float fRotate = 0.0F;
	float fvec = 0.0F; 

};

