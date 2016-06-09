#include "Sound.h"


CSound::CSound()
{
}


CSound::~CSound()
{
}

//
void CSound::Init(CScene * ptrscene){

	//placement.Translate(10.5F, 10.5F, 10.5F);

	//0 = Theme Song (Menu)
	//1 = Ingame Loop
	//2 = Game Over Loop
	//3 = Explosion Sound (Meteorkollision)

	audio[0].Init("sounds\\Ambient_Sounds\\Theme.wav");
	audio[0].Fini();
	
	audio[1].Init("sounds\\Ambient_Sounds\\Ingame.wav");
	audio[1].Fini();

	audio[2].Init("sounds\\Ambient_Sounds\\Game_Over.wav");
	audio[2].Fini();

	audio[3].Init("sounds\\Small_Explosion.wav");
	audio[3].Fini();

	audio[4].Init("sounds\\Countdown.wav");
	audio[4].Fini();

	for (int i = 0; i < 10; i++)
	{
		ptrscene->AddAudio(&audio[i]);
	}
}

CAudio*CSound::getAudioPointr(int iSoundNummer)
{
	return &audio[iSoundNummer];
}


void CSound::Loop(int iSoundNummer)
{
	audio[iSoundNummer].Loop();
}


void CSound::Start(int iSoundNummer)
{
	audio[iSoundNummer].Start();
}


void CSound::Stop(int iSoundNummer)
{
	audio[iSoundNummer].Stop();
}

void CSound::Pause(int iSoundNummer)
{
	audio[iSoundNummer].Pause();
}

void CSound::SetVolume(int iSoundNummer, float f)
{
	audio[iSoundNummer].SetVolume(f);
}

void CSound::SwitchSounds(int iAktuellerSound, int iNextSound, bool bLoop)
{
	audio[iAktuellerSound].Stop();

	if (bLoop == true)
		audio[iNextSound].Loop();
	else
		audio[iNextSound].Start();
	
}

void CSound::StopAll()
{
	for (int i = 0; i < 10; i++)
	{
		audio[i].Stop();
	}
}
