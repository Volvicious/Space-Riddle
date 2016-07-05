#pragma once
#include "Vektoria\Root.h"
#include "TextOutput.h"
#include "StringToChar.h"
#include <time.h>


using namespace Vektoria;
class CHighscore
{
public:
	CHighscore();
	~CHighscore();

	void Init(CViewport * mvz); 
	void Run(float fTime, float fTimeDelta); 
	void Start(float fTime); 
	void Stop(); 
	void Pause();
	void GoOn(float fTime); 
	
	void Save();
	void AddHighscore(std::string sName, int iScore);
	void Load(); 
	void Delete();

	void PreRunMenue();
	void RunHauptMenue();
	void SwitchMenueOff(); 
	void SwitchIngameOff();
	void SwitchIngameOn(); 
	void Sort();
	


	void SetHighscore(int i); 
	int GetHighscore(); 
	void AddToHighscore(int i);
	void SubstractFromHighscore(int i);
	void DisplayTextIngame(std::string Text);


private: 


	int iHighscore = 0;
	
	CTextOutput topHighscore;
	bool bOn = false; 
	float fTimeStart= 0.0F;
	float fTimePauseSpeicher = 0.0F; 

	//Animationszeux
	void changeAnimation(float fTime, float fTimeDelta);
	CTextOutput topChange;
	bool bDisplayChange;
	float fTimeStartChange = 0.0F;
	std::string sChange;

	float fxPos = 0.0F; 
	float fyPos = 0.0F; 
	float fxSize = 0; 
	float fySize = 0;

	float fxEndSize = 4.0F;
	float fyEndSize = .4F; 

	void changeString();

	CStringToChar stc; 

	std::vector<std::pair<std::string, int>>  * v_NamePunktZahl = new std::vector<std::pair<std::string, int>>;

	CTextOutput aTextOutputsNamen[6]; 
	CTextOutput aTextOutputInts[6];
	

};

