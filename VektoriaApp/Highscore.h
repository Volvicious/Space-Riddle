#pragma once
#include "Vektoria\Root.h"
#include "TextOutput.h"


using namespace Vektoria;
class CHighscore
{
public:
	CHighscore();
	~CHighscore();

	void Init(CViewport * mvz); 
	void Run(float fTime); 
	void Start(float fTime); 
	void Stop(); 
	void Pause();
	void GoOn(float fTime); 
	
	void Save();
	void Load(); 

	void SetHighscore(int i); 
	int GetHighscore(); 
	void AddToHighscore(int i);
	void SubstractFromHighscore(int i);


private: 


	int iHighscore = 0;
	CTextOutput topHighscore;
	bool bOn = false; 
	float fTimeStart= 0.0F;

	//Animationszeux
	void changeAnimation(float fTime);
	CTextOutput topChange;
	bool bDisplayChange;
	float fTimeStartChange = 0.0F;
	std::string sChange;

	float fxPos = 0.0F; 
	float fyPos = 0.06F; 
	float fxSize = 0; 
	float fySize = 0;

	float fxEndSize = 2.0F;
	float fyEndSize = .02F; 

	void changeString();

	CStringToChar stc; 

};

