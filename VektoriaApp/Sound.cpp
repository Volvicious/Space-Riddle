#include "Sound.h"


CSound::CSound()
{
}


CSound::~CSound()
{
}

/*void CSound::Init(char*stringWavFile, float fRadius){

	audio[2].Init("sounds\\3D_Sounds\\Passing_Object.wav");

}*/

void CSound::Init(CScene * ptrscene){


	placement.Translate(10.5F, 10.5F, 10.5F);
	

	//0 is normal theme
	
	audio[0].Init("sounds\\Ambient_Sounds\\Theme.wav");
	audio[0].Fini(); 
	ptrscene->AddAudio(&audio[0]);
	
	audio[1].Init("sounds\\Ambient_Sounds\\Over.wav");
	audio[1].Fini();
	ptrscene->AddAudio(&audio[1]);

	

	
	//audio[2].Init3D("sounds\\3D_Sounds\\Passing_Object.wav", 3.0F);

	//audio[2].SetRadius(3.0F);
	//audio[2].Fini();
	//audio[2].Loop();
	//mcs->AddAudio(&audio[2]);



}

CAudio* CSound::getAudioPointr(int iSoundNummer){
	
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

void CSound::SetVolume(int iSoundNummer, float f){

	audio[iSoundNummer].SetVolume(f);
}
