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
	//CFloatRect floatrect;
	CWriting writing;

	void Init(CViewport * ViewPortPtr, char* sPathFont, float fxPos, float fyPos, float fxSize, float fySize);
	
	//Hängt Writing an Overlay an, ermöglicht die Übergabe des LayerWertes
	void Init(COverlay * ptrOverlay, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize, float iLayer);

	//an ein Overlay anhängen
	void Init(COverlay * OverLayPtr, char* sPathFont, float fxPos, float fyPos, float fxSize, float fySize);
	//zum "in der Mitte durcken"
	void Init(COverlay * OverLayPtr, char* sPathFont, float fxPos, float fyPos, float fxSize, float fySize, int iVisibleChars);



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

	CFloatRect GetWritingRect(); 
	void SetWritingRect(CFloatRect rect);



private: 
	
	CStringToChar strToChar;

	COverlay * ptrOverlay;


	bool bUpdating = false;
	bool bCheckForTastaturOn = false; 

	int iVisibleChars = 100;
	bool bPrintMiddle = false; 

	std::string sStringToWrite = ""; 

	CTastaturGER * ptrTastaturGer; 
	void Workaround(std::string * s);
	
	 
	

};
//

