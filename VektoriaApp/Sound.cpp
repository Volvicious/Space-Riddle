#include "Sound.h"


CSound::CSound()
{
	srand(0);
}


CSound::~CSound()
{
}


void CSound::Init(CScene * ptrscene){

	//placement.Translate(10.5F, 10.5F, 10.5F);

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
	audio[0].Fini();
	ptrscene->AddAudio(&audio[0]);
	audio[0].Loop();
	
	audio[1].Init("sounds\\Ambient_Sounds\\Ingame.wav");
	audio[1].Fini();
	ptrscene->AddAudio(&audio[1]);

	audio[2].Init("sounds\\Ambient_Sounds\\Game_Over.wav");
	audio[2].Fini();
	ptrscene->AddAudio(&audio[2]);

	audio[3].Init("sounds\\Ambient_Sounds\\Small_Explosion.wav");
	audio[3].Fini();
	ptrscene->AddAudio(&audio[3]);

	audio[4].Init("sounds\\Ambient_Sounds\\Click.wav");
	audio[4].Fini();
	ptrscene->AddAudio(&audio[4]);

	audio[5].Init("sounds\\Ambient_Sounds\\.wav");
	audio[5].Fini();
	ptrscene->AddAudio(&audio[5]);

	audio[6].Init("sounds\\Ambient_Sounds\\Pause_Ambient.wav");
	audio[6].Fini();
	ptrscene->AddAudio(&audio[6]);

	audio[7].Init("sounds\\Ambient_Sounds\\Countdown.aiff");
	audio[7].Fini();
	ptrscene->AddAudio(&audio[7]);

	audio[8].Init("sounds\\Ambient_Sounds\\.wav");
	audio[8].Fini();
	ptrscene->AddAudio(&audio[8]);

	audio[9].Init("sounds\\Ambient_Sounds\\Levelend.wav");
	audio[9].Fini();
	ptrscene->AddAudio(&audio[9]);

	audio[10].Init("sounds\\Ambient_Sounds\\Creditsong.wav");
	audio[10].Fini();
	ptrscene->AddAudio(&audio[10]);

	audio[11].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\01.aiff");
	audio[11].Fini();
	ptrscene->AddAudio(&audio[11]);

	audio[12].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\02.aiff");
	audio[12].Fini();
	ptrscene->AddAudio(&audio[12]);

	audio[13].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\03.aiff");
	audio[13].Fini();
	ptrscene->AddAudio(&audio[13]);

	audio[14].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\04.aiff");
	audio[14].Fini();
	ptrscene->AddAudio(&audio[14]);

	audio[15].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\05.aiff");
	audio[15].Fini();
	ptrscene->AddAudio(&audio[15]);

	audio[16].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\06.aiff");
	audio[16].Fini();
	ptrscene->AddAudio(&audio[16]);

	audio[17].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\07.aiff");
	audio[17].Fini();
	ptrscene->AddAudio(&audio[17]);

	audio[18].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\08.aiff");
	audio[18].Fini();
	ptrscene->AddAudio(&audio[18]);

	audio[19].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\09.aiff");
	audio[19].Fini();
	ptrscene->AddAudio(&audio[19]);

	audio[20].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\10.aiff");
	audio[20].Fini();
	ptrscene->AddAudio(&audio[20]);

	audio[21].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\11.aiff");
	audio[21].Fini();
	ptrscene->AddAudio(&audio[21]);

	audio[22].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\12.aiff");
	audio[22].Fini();
	ptrscene->AddAudio(&audio[22]);

	audio[23].Init("sounds\\Ambient_Sounds\\Kollisionskommentar\\13.aiff");
	audio[23].Fini();
	ptrscene->AddAudio(&audio[23]);

	audio[24].Init("sounds\\Ambient_Sounds\\.wav");
	audio[24].Fini();
	ptrscene->AddAudio(&audio[24]);

	audio[25].Init("sounds\\Ambient_Sounds\\Introvideosound.wav");
	audio[25].Fini();
	ptrscene->AddAudio(&audio[25]);

	audio[26].Init("sounds\\Ambient_Sounds\\Glasbruch\\001.aiff");
	audio[26].Fini();
	ptrscene->AddAudio(&audio[26]); 

	audio[27].Init("sounds\\Ambient_Sounds\\Glasbruch\\002.aiff");
	audio[27].Fini();
	ptrscene->AddAudio(&audio[27]);

	audio[28].Init("sounds\\Ambient_Sounds\\Glasbruch\\003.aiff");
	audio[28].Fini();
	ptrscene->AddAudio(&audio[28]);

	audio[29].Init("sounds\\Ambient_Sounds\\Glasbruch\\004.aiff");
	audio[29].Fini();
	ptrscene->AddAudio(&audio[29]);

	audio[30].Init("sounds\\Ambient_Sounds\\Glasbruch\\005.aiff");
	audio[30].Fini();
	ptrscene->AddAudio(&audio[30]);

	audio[31].Init("sounds\\Ambient_Sounds\\Kollision\\0001.aiff");
	audio[31].Fini();
	ptrscene->AddAudio(&audio[31]);

	audio[32].Init("sounds\\Ambient_Sounds\\Kollision\\0002.aiff");
	audio[32].Fini();
	ptrscene->AddAudio(&audio[32]);

	audio[33].Init("sounds\\Ambient_Sounds\\Kollision\\0003.aiff");
	audio[33].Fini();
	ptrscene->AddAudio(&audio[33]);

	audio[34].Init("sounds\\Ambient_Sounds\\Kollision\\0004.aiff");
	audio[34].Fini();
	ptrscene->AddAudio(&audio[34]);

	audio[35].Init("sounds\\Ambient_Sounds\\Kollision\\0005.aiff");
	audio[35].Fini();
	ptrscene->AddAudio(&audio[35]);

	audio[36].Init("sounds\\Ambient_Sounds\\Tastatur\\00001.aiff");
	audio[36].Fini();
	ptrscene->AddAudio(&audio[36]);

	audio[37].Init("sounds\\Ambient_Sounds\\Tastatur\\00002.aiff");
	audio[37].Fini();
	ptrscene->AddAudio(&audio[37]);

	audio[38].Init("sounds\\Ambient_Sounds\\Tastatur\\00003.aiff");
	audio[38].Fini();
	ptrscene->AddAudio(&audio[38]);

	audio[39].Init("sounds\\Ambient_Sounds\\Tastatur\\00004.aiff");
	audio[39].Fini();
	ptrscene->AddAudio(&audio[39]);

	audio[40].Init("sounds\\Ambient_Sounds\\Tastatur\\00005.aiff");
	audio[40].Fini();
	ptrscene->AddAudio(&audio[40]);

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
	audio[iSoundNummer].SetVolume(f);
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

void CSound::SetAllVolume(float f) {

	for (int i = 0; i < AUDIOZ; i++) 
	{
		audio[i].SetVolume(f);
	}

}

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


