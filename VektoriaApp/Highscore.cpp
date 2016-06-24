#include "Highscore.h"



CHighscore::CHighscore()
{
}


CHighscore::~CHighscore()
{
}


void CHighscore::Init(CViewport * mvz) {

	topHighscore.Init(mvz, "fonts\\Nasalization-rg-Red.png", 0.0F, 0.01F, 2.0F, 0.02F);
	topHighscore.SetString("0");

	topChange.Init(mvz, "fonts\\Nasalization-rg-Red.png", 0.0F, 0.06F, 2.0F, 0.02F);
	
	topChange.SetString("");

	bOn = true; 
}

void CHighscore::Run(float ftime, float fTimeDelta) {

	if (bOn) {

		if (ftime > fTimeStart + 1) {

			fTimeStart = ftime;
			iHighscore++;
			changeString();
		}

		ULDebug("Highscore");

		topHighscore.WriteSavedString();
		changeAnimation(ftime, fTimeDelta); 

	}

}

void CHighscore::Start(float fTime) {

	fTimeStart = fTime; 
	bOn = true;
}


void CHighscore::Stop() {

	bOn = false; 

}



void CHighscore::Pause() {

	//fTimePauseSpeicher = fTimeStart;
	fTimeStart = INT_MAX;

	
}

void CHighscore::GoOn(float fTime) {

	fTimeStart = fTime; 
}

void CHighscore::SetHighscore (int i) {

	iHighscore = i;
	changeString();

}

int CHighscore::GetHighscore () {

	return iHighscore;
}

void CHighscore::AddToHighscore (int i) {

	iHighscore += i;
	changeString();
	if (i > 0) {
	sChange = "+";
	}
	sChange += std::to_string(i);
	bDisplayChange = true; 


}

void CHighscore::SubstractFromHighscore (int i) {
	
	if (i > 0) {
		sChange = "-";
		iHighscore -= i;
	}
	else {
		sChange = "";
		iHighscore += i;
	}

	sChange += std::to_string(i);
	bDisplayChange = true;

}

void CHighscore::changeString() {

	topHighscore.SetString(std::to_string(iHighscore));
}

void CHighscore::changeAnimation(float fTime, float fTimeDelta) {

	if (bDisplayChange) {
		fxSize = 0.0F; 
		fySize = 0.0F; 
		topChange.SetString(sChange);
		bDisplayChange = false; 
	}

	if (fxSize < fxEndSize) {
		fxSize += fxEndSize * fTimeDelta; 
		fySize += fyEndSize *fTimeDelta;
		topChange.SetWritingRect(CFloatRect(fxPos, fyPos, fxSize, fySize));
		fTimeStartChange = fTime; 
	}
	else {

		if (fTime > fTimeStartChange + 1) {
			topChange.SetString("");
		}

	}

	topChange.WriteSavedString(); 

}