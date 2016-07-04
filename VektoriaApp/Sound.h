#pragma once
#include "Vektoria\Root.h"
#define AUDIOZ 40

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
	//In Prozent (0-1.0F) zum Ursprungswert, der festgelegt wurde
	void SetAllVolume(float f);
	//Mute=true -> Ton aus, Mute=false -> Ton an.
	void Mute();
	void SwitchSounds(int iCurrentSound, int iNextSound, bool loop = false);

	void randCrash();
	void randComment();
	void randKeystroke();
	void randGlassbreak();

	void Fini();
	
	CAudio*getAudioPointr(int iSoundNummer);

private:

	//Audio und Placement
   
	CAudio audio[AUDIOZ];
	float LautstaerkeSpeicher[AUDIOZ];
	CPlacement placement;

	bool bMute = false; 



};

