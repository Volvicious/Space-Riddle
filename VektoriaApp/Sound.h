#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

class CSound
{
public:

	CSound();
	~CSound();

	void Setradius(float fRadius);
	void SetDoppler(float fFactor);
	void Init(CScene * mzs);
	void Loop(int iSoundNummer);
	void Stop(int iSoundNummer);
	void Pause(int iSoundNummer);
	void Start(int iSoundNummer);
	void SetVolume(int iSoundNummer, float f);

	void Fini();
	
	CAudio * getAudioPointr(int iSoundNummer);

private:

	//Audio und Placement
	CAudio audio[10];
	CPlacement placement;
};

