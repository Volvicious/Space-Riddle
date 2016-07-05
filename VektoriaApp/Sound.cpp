#include "Sound.h"


CSound::CSound()
{
	srand(0);
}


CSound::~CSound()
{
}


void CSound::Init(CScene * ptrscene){

		for (int jj = 0; jj < AUDIOZ; jj++) {
		LautstaerkeSpeicher[jj] = 1.0F;
	}


	//00 = Theme Song (Menu)
	//01 = Ingame Loop
	//02 = Game Over Loop
	//03 = Explosion Sound (Raumschiff zerstört)
	//04 = Mausklick
	//05 = /
	//06 = Pauseloop
	//07 = Countdown
	//08 = /
	//09 = Levelend
	//10 = Creditsong
	//11-23 = Kollisionskommentare
	//24 = /
	//25 = Introvideosound
	//26-30 = Glasbruch
	//31-35 = Kollisionssound
	//36-40 = Tastaturanschlagsgeräusch

	audio[0].Init("sounds\\Ambient_Sounds\\Theme_Short.wav");
	SetVolume(0, 0.8F);
	//audio[0].SetVolume(0.8f);
	ptrscene->AddAudio(&audio[0]);

	audio[1].Init("sounds\\Ambient_Sounds\\Ingame.wav");
	SetVolume(1, 0.9F);
	ptrscene->AddAudio(&audio[1]);

	audio[2].Init("sounds\\Ambient_Sounds\\Game_Over.wav");
	ptrscene->AddAudio(&audio[2]);

	audio[3].Init("sounds\\Ambient_Sounds\\Small_Explosion.wav");
	ptrscene->AddAudio(&audio[3]);

	audio[4].Init("sounds\\Ambient_Sounds\\Click.wav");
	ptrscene->AddAudio(&audio[4]);

	audio[5].Init("sounds\\Ambient_Sounds\\.wav");
	ptrscene->AddAudio(&audio[5]);

	audio[6].Init("sounds\\Ambient_Sounds\\Pause_Ambient.wav");
	SetVolume(6, 0.8F);
	ptrscene->AddAudio(&audio[6]);

	audio[7].Init("sounds\\Ambient_Sounds\\Countdown.aiff");
	SetVolume(7, 0.8F);
	ptrscene->AddAudio(&audio[7]);

	audio[8].Init("sounds\\Ambient_Sounds\\.wav");
	ptrscene->AddAudio(&audio[8]);

	audio[9].Init("sounds\\Ambient_Sounds\\Levelend.wav");
	SetVolume(9, 0.8F);
	ptrscene->AddAudio(&audio[9]);

	audio[10].Init("sounds\\Ambient_Sounds\\Creditsong.wav");
	SetVolume(10, 0.9F);
	ptrscene->AddAudio(&audio[10]);

	audio[11].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\01.aiff");
	ptrscene->AddAudio(&audio[11]);

	audio[12].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\02.aiff");
	ptrscene->AddAudio(&audio[12]);

	audio[13].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\03.aiff");;
	ptrscene->AddAudio(&audio[13]);

	audio[14].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\04.aiff");
	ptrscene->AddAudio(&audio[14]);

	audio[15].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\05.aiff");
	ptrscene->AddAudio(&audio[15]);

	audio[16].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\06.aiff");
	ptrscene->AddAudio(&audio[16]);

	audio[17].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\07.aiff");
	ptrscene->AddAudio(&audio[17]);

	audio[18].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\08.aiff");
	ptrscene->AddAudio(&audio[18]);

	audio[19].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\09.aiff");
	ptrscene->AddAudio(&audio[19]);

	audio[20].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\10.aiff");
	ptrscene->AddAudio(&audio[20]);

	audio[21].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\11.aiff");
	ptrscene->AddAudio(&audio[21]);

	audio[22].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\12.aiff");
	ptrscene->AddAudio(&audio[22]);

	audio[23].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\13.aiff");
	ptrscene->AddAudio(&audio[23]);

	audio[24].Init("sounds\\Ambient_Sounds\\.wav");
	ptrscene->AddAudio(&audio[24]);

	audio[25].Init("sounds\\Ambient_Sounds\\Introvideosound.wav");
	ptrscene->AddAudio(&audio[25]);

	audio[26].Init("sounds\\Ambient_Sounds\\Glasbruch\\001.aiff");
	ptrscene->AddAudio(&audio[26]);

	audio[27].Init("sounds\\Ambient_Sounds\\Glasbruch\\002.aiff");
	ptrscene->AddAudio(&audio[27]);

	audio[28].Init("sounds\\Ambient_Sounds\\Glasbruch\\003.aiff");
	ptrscene->AddAudio(&audio[28]);

	audio[29].Init("sounds\\Ambient_Sounds\\Glasbruch\\004.aiff");
	ptrscene->AddAudio(&audio[29]);

	audio[30].Init("sounds\\Ambient_Sounds\\Glasbruch\\005.aiff");
	ptrscene->AddAudio(&audio[30]);

	audio[31].Init("sounds\\Ambient_Sounds\\Kollision\\0001.aiff");
	ptrscene->AddAudio(&audio[31]);

	audio[32].Init("sounds\\Ambient_Sounds\\Kollision\\0002.aiff");
	ptrscene->AddAudio(&audio[32]);

	audio[33].Init("sounds\\Ambient_Sounds\\Kollision\\0003.aiff");
	ptrscene->AddAudio(&audio[33]);

	audio[34].Init("sounds\\Ambient_Sounds\\Kollision\\0004.aiff");
	ptrscene->AddAudio(&audio[34]);

	audio[35].Init("sounds\\Ambient_Sounds\\Kollision\\0005.aiff");
	ptrscene->AddAudio(&audio[35]);

	audio[36].Init("sounds\\Ambient_Sounds\\Tastatur\\00001.aiff");
	ptrscene->AddAudio(&audio[36]);

	audio[37].Init("sounds\\Ambient_Sounds\\Tastatur\\00002.aiff");
	ptrscene->AddAudio(&audio[37]);

	audio[38].Init("sounds\\Ambient_Sounds\\Tastatur\\00003.aiff");
	ptrscene->AddAudio(&audio[38]);

	audio[39].Init("sounds\\Ambient_Sounds\\Tastatur\\00004.aiff");
	ptrscene->AddAudio(&audio[39]);

	//audio[40].Init("sounds\\Ambient_Sounds\\Tastatur\\00005.aiff");
	//ptrscene->AddAudio(&audio[40]);




}



CAudio*CSound::getAudioPointr(int iSoundNummer)
{
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

void CSound::SetVolume(int iSoundNummer, float f)
{
	LautstaerkeSpeicher[iSoundNummer] = f; 
	audio[iSoundNummer].SetVolume(f);
}

void CSound::SetAllVolume(float f) {

	for (int i = 0; i < AUDIOZ; i++) {
		audio[i].SetVolume(f * LautstaerkeSpeicher[i]);
	}
}

void CSound::SwitchSounds(int iCurrentSound, int iNextSound, bool loop)
{
	audio[iCurrentSound].Pause();
	audio[iNextSound].Start();

	

	if (loop == true)
	{
		audio[iNextSound].Loop();
	}
}

void CSound::Mute() {

	if (!bMute) {
		for (int i = 0; i < AUDIOZ; i++) 
		{
			audio[i].SetVolume(0);
			
		}
		bMute = true; 
	}
	else {
		for (int i = 0; i < AUDIOZ; i++)
		{
			audio[i].SetVolume(LautstaerkeSpeicher[i]);
		}
		bMute = false; 
	}

}
//Crashsound
void CSound::randCrash()
{
	int zahl = rand() % 5 + 31;

	audio[zahl].Start();
}

void CSound::randComment()
{
	int zahl = rand() % 13 + 11;

	audio[zahl].Start();
}

void CSound::randGlassbreak()
{
	int zahl = rand() % 5 + 26;

	audio[zahl].Start();
}


