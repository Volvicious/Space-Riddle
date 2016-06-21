#include "RaumschiffAnimation.h"



CRaumschiffAnimation::CRaumschiffAnimation()
{
}


CRaumschiffAnimation::~CRaumschiffAnimation()
{
}



bool CRaumschiffAnimation::Run(CPlacement * ptrRaumschiff, CDeviceKeyboard * ptrKeyboard, float fTimeDelta) {

	fTimeGesA += fTimeDelta;
	fTimeGesD += fTimeDelta;

	if (ptrKeyboard->KeyDown(DIK_A)) {
		
		iAHit++;
		
		if (fTimeGesA > 0.2F) {
			fTimeGesA = 0.0F; 
			iAHit = 1; 
			
		}
		else {
			if (iAHit == 2) {
				
				if (ptrRaumschiff->GetTranslation().GetX() > -14) {

					bDoRotateA = !bDoRotateD;
					fTimeGesA = 0.0F;
					iAHit = 1;

				}
			}
		}
	}

	if (ptrKeyboard->KeyDown(DIK_D)) {

		iDHit++;

		if (fTimeGesD > 0.2F) {
			fTimeGesD = 0.0F;
			iDHit = 1;

		}
		else {
			if (iDHit == 2) {

				if (ptrRaumschiff->GetTranslation().GetX() < 14) {

					bDoRotateD = !bDoRotateA;
					fTimeGesD = 0.0F;
					iDHit = 0;
				}
			}
		}


	}

	if (bDoRotateA) {
		
		bDoRotateA = DoingRotationA(ptrRaumschiff, fTimeDelta); 
	}

	if (bDoRotateD) {
		bDoRotateD = DoingRotationD(ptrRaumschiff, fTimeDelta);

	}


	return bDoRotateA || bDoRotateD;
}

bool CRaumschiffAnimation::DoingRotationA(CPlacement * ptrRaumischiffi, float fTimeDelta) {


	CHVector vec = ptrRaumischiffi->GetTranslation(); 

	fRotate += 9.5 * fTimeDelta;
	fvec -= 0.02F * fTimeDelta; 

	vec.SetX(vec.GetX() + fvec);

	bool retval = true; 

	if (fRotate > 6.3F) {
		fRotate = 0.0F;
		fvec = 0.0F; 
		retval =  false; 
	}
	
	ptrRaumischiffi->RotateX(0.05F);
	ptrRaumischiffi->RotateZDelta(fRotate);
	ptrRaumischiffi->TranslateDelta(vec);
	
	return retval; 


}

bool CRaumschiffAnimation::DoingRotationD(CPlacement * ptrRaumischiffi, float fTimeDelta) {


	CHVector vec = ptrRaumischiffi->GetTranslation();

	fRotate -=  9.5 * fTimeDelta ;
	fvec += 0.02F * fTimeDelta;

	vec.SetX(vec.GetX() + fvec);

	bool retval = true;

	if (fRotate < -6.3F) {
		fRotate = 0.0F;
		fvec = 0.0F;
		retval = false;
	}
	
	ptrRaumischiffi->RotateX(+0.05F);
	ptrRaumischiffi->RotateZDelta(fRotate);
	ptrRaumischiffi->TranslateDelta(vec);

	return retval;


}



