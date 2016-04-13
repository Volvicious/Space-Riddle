#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria; 
class CSound
{
public:

	 


	CSound();
	~CSound();
	//void Init(char *stringWavFile, float fRadius);
	void SetRadius(float fRadius);
	void SetDoppler(float fFactor);
	void Init(CScene * mzs); 
	void Loop(int iSoundNummer); 
	void Stop(int iSoundNummer);
	void Start(int iSoundNummer);
	void SetVolume(int iSoundNummer, float f);

	void Fini();

	CAudio * getAudioPointr(int iSoundNummer); 
	



private:
	//CAudio audio;
	CAudio audio[10];
	CPlacement placement; 


};



