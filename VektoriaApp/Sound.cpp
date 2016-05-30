#include "Sound.h"


CSound::CSound()
{
}


CSound::~CSound()
{
}


void CSound::Init(CScene * ptrscene){

	//placement.Translate(10.5F, 10.5F, 10.5F);

	//0 = Theme Song (Menu)
	//1 = Ingame Loop
	//2 = Game Over Loop
	//3 = Explosion Sound (Meteorkollision)

	audio[0].Init("sounds\\Ambient_Sounds\\Theme.wav");
	audio[0].Fini();
	ptrscene->AddAudio(&audio[0]);
	
	audio[1].Init("sounds\\Ambient_Sounds\\Ingame.wav");
	audio[1].Fini();
	ptrscene->AddAudio(&audio[1]);
	audio[1].Loop();


	audio[2].Init("sounds\\Ambient_Sounds\\Game_Over.wav");
	audio[2].Fini();
	ptrscene->AddAudio(&audio[2]);

	audio[3].Init("sounds\\Small_Explosion.wav");
	audio[3].Fini();
	ptrscene->AddAudio(&audio[3]);
}

CAudio*CSound::getAudioPointr(int iSoundNummer){
	return &audio[iSoundNummer];
}


void CSound::Loop(int iSoundNummer){
	audio[iSoundNummer].Loop();
}


void CSound::Start(int iSoundNummer){
	audio[iSoundNummer].Start();
}


void CSound::Stop(int iSoundNummer){
	audio[iSoundNummer].Stop();
}

void CSound::Pause(int iSoundNummer){
	audio[iSoundNummer].Pause();
}

void CSound::SetVolume(int iSoundNummer, float f){
	audio[iSoundNummer].SetVolume(f);
}
