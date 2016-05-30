#pragma once
#include "Vektoria\Root.h"
#include "TextOutput.h"
using namespace Vektoria;
#include "TextOutput.h"
#include "StringToChar.h"

class CLLAnzeige
{
public:
	CLLAnzeige();
	~CLLAnzeige();

	void setLevelNummer(int i); 
	int getLevelNummer();

	void setLebenAnzahl(int i); 
	int getLebenAnzahl();

	void Init(CViewport * mzv); 

	void Run();

	void SwitchOn(); 
	void SwitchOff(); 

private:

	int iLevelNummer; 
	int iLebenAnzahl;
	bool bIsOn = false; 

	COverlay m_zoAnzeige; // Dummy

	CTextOutput top; 

	CImage LebensImages[11];
	COverlay LebensOverlays[11];
	

	CStringToChar stc; 


};

