#pragma once
#include "Vektoria\Root.h"
#include "TastaturGER.h"
#include "StringToChar.h"

//----------------------------------
//Grafische Darstellung von Text mit Workaround fuer Umlaute....
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

using namespace Vektoria; 
class CTextOutput
{
public:
	CTextOutput();
	
	~CTextOutput();

	
	CColor color; 

	CWritingFont writingfont;
	//CWritingChar writingchar;
	CFloatRect floatrect;
	CWriting writing;

	void Init(CViewport * ViewPortPtr, char* sPathFont, float fxPos, float fyPos, float fxSize, float fySize);
	void Init(CViewport * ViewPortPtr, char* sPathFont, CFloatRect * floatrect);
	void Init(CViewport * ViewPortPtr, CTastaturGER * TastaturGer, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize);

	void Init(COverlay * OverLayPtr, char* sPathFont, float fxPos, float fyPos, float fxSize, float fySize);


	void SwitchOn(); 

	void SwitchOff();

	CWriting * getWritingPtr(); 


	void SetString(std::string);
	std::string GetString(); 
	//void Init(CViewport * ViewPortPtr, CTastaturGER * TastaturGer);
	void Write(std::string * s );
	void Write(std::string  s);
	void WriteSavedString();
	void WriteFromTastatur();
	void WriteFromTastatur(CTastaturGER * TastaturGer);
	void WriteTest();


private: 
	
	CStringToChar strToChar;


	bool bUpdating = false;
	bool bCheckForTastaturOn = false; 

	std::string sStringToWrite; 

	CTastaturGER * ptrTastaturGer; 
	void Workaround(std::string * s);
	
	 
	

};
//

