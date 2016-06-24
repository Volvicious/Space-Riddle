#include "Animation.h"



CAnimation::CAnimation()
{

}


CAnimation::~CAnimation()
{
}


void CAnimation::Init(CViewport * mzv, int iAnzahlBilder, std::string sBilderPfad, std::string sDateityp) {

	iArraygroesse = iAnzahlBilder;

	MainImageAnimation.Init("textures\\animation\\background.jpg");
	MainOverlayAnimation.InitFull(&MainImageAnimation);
	MainOverlayAnimation.SetLayer(0.35F);
	mzv->AddOverlay(&MainOverlayAnimation);

	aMaterials = new CMaterial[iAnzahlBilder];
	aOverlays = new COverlay[iAnzahlBilder];
	afFadeOutTimes = new float[iAnzahlBilder];
	afAnzeigeDauer = new float[iAnzahlBilder];

	float f = 0.3499F;

	for (int i = 0; i < iAnzahlBilder; i++) {

		afFadeOutTimes[i] = FLT_MAX;
		afAnzeigeDauer[i] = 1000.0F; 

		std::string s = sBilderPfad;
		s += "\\";
		s += std::to_string(i);
		s += ".";
		s += sDateityp;
		char * temp = (char*)s.c_str();
		ULDebug(temp);
		//UÖDebug("%s", sBilderPfad.)

		aMaterials[i].MakeTextureSprite(temp);

		aOverlays[i].InitFull(&aMaterials[i]);

		aOverlays[i].SetLayer(f);
		MainOverlayAnimation.AddOverlay(&aOverlays[i]);
		aOverlays[i].SwitchOff();

		f -= 0.0001F;

	}

	MainOverlayAnimation.SwitchOff();
	bAnimationOn = false; 

}

void CAnimation::Run(float fTime) {

	if (bAnimationOn) {

		fTime *= 1000; 
		

		if (fTimeStart == -1) {
			fTimeStart = fTime;
		}

		if (fTime - fTimeStart > afAnzeigeDauer[iAktuellesBild]) {
			aOverlays[iAktuellesBild].SwitchOff();
			//aOverlays[iAktuellesBild].SetTransparency(.1F);

			if (iAktuellesBild < iArraygroesse - 1) {
				iAktuellesBild++;
				aOverlays[iAktuellesBild].SwitchOn();
				//aOverlays[iAktuellesBild].SetTransparency(0.0F);
				bFadeOutStarted = false;

				fTimeStart = fTime;

			}
			else {

				bAnimationOn = false;
				bFadeOutStarted = false;
				bAnimationbeendet = true;
				aOverlays[iAktuellesBild - 1].SwitchOff();
				MainOverlayAnimation.SwitchOff();

			}
		}



		if (fTime - fTimeStart > afFadeOutTimes[iAktuellesBild] && !bFadeOutStarted) {

			bFadeOutStarted = true;
			
		

			if (iAktuellesBild < iArraygroesse-1) {
				aOverlays[iAktuellesBild + 1].SwitchOn();				
			}
		}

		if (bFadeOutStarted) {

				////aOverlays[iAktuellesBild].SetTransparency(1 - fTransparency);
				////aOverlays[iAktuellesBild].SetTransparency(0.5F);
				//aMaterials[iAktuellesBild].SetTransparency(0.5F);
				//aOverlays[iAktuellesBild].SetMaterial(&aMaterials[iAktuellesBild]);
				//fTransparency -= 0.01F; 
				//fFadeOutTimer = fTime;
				//ULDebug("Setzte Transparenz nach unten!");

				if (aOverlays[iAktuellesBild+1].IsOn()) {
					aOverlays[iAktuellesBild+1].SwitchOff();

				}
				else {
					aOverlays[iAktuellesBild+1].SwitchOn();
				}
			}
	}





}





void CAnimation::SetTime(int iBildNummer, float fTimeinMilli) {

	afAnzeigeDauer[iBildNummer] = fTimeinMilli;

}

void CAnimation::SetFadeInOut(int iBildnummer, float fTimeinMilli) {

	afFadeOutTimes[iBildnummer] = afAnzeigeDauer[iBildnummer] - fTimeinMilli;

}

void CAnimation::StartAnimation() {

	MainOverlayAnimation.SwitchOn(); 
	aOverlays[0].SwitchOn();
	fTimeStart = -1;
	bAnimationOn = true;
	bAnimationbeendet = false;
	iAktuellesBild = 0; 

}

void CAnimation::StopAnimation() {

	for (int i = 0; i < iArraygroesse - 1; i++) {
		aOverlays[i].SwitchOff();
	}
	bAnimationOn = false;
	bFadeOutStarted = false;
	bAnimationbeendet = true;
	MainOverlayAnimation.SwitchOff();
}

bool CAnimation::IsFinished() {
	return bAnimationbeendet; 
}

