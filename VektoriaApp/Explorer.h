#pragma once
#include "Vektoria\Root.h"
#include "TextOutput.h"
#include <list>
#include "FileFinder.h"
#include "FileHandler.h"
#include "Maus.h"
#include "TastaturGER.h"

#include "StringToChar.h"

using namespace Vektoria;

//----------------------------------
//Klasse fuer Exploreransicht - Listen von Dateien im Ordner
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

class CExplorer
{
public:
	CExplorer();
	~CExplorer();

	
	void Init(CViewport * m_zv, CMaus  * ptrMaus_, CFileHandler * filehandlerPtr, char * caHintergrundBildPfad, char * caIconBildPfad, char * caOrdnerPfad);
	void Init(CViewport * m_zv, CMaus  * ptrMaus_, CFileHandler * filehandlerPtr, char * caHintergrundBildPfad, char * caIconBildPfad, char * caOrdnerPfad, CDeviceKeyboard * ptrdk);



	void Run();



	void SwitchOff(); 
	void SwitchOn();

	bool getMakeMenuOn();
	void setMakeMenuOn(bool b);
	
	
	CFileHandler * getFileHandlerPtr(); 

private:

	COverlay m_zoExplorer;								//An diesem Overlay hängt alles dran.

	COverlay m_zoMainmbackground;						//Hintergrund wie im Main. (Eventuall später mit Pointer Übernehmen.
	
	CImage m_ziMainmbackground;
	CImage m_ziTextIcon; 
	CMaterial m_zmMainmbackground;


	COverlay m_zoBackButton;
	CImage m_ziBackButton;


	

	CFileFinder * filefinder;
	CFileHandler * ptrfilehandler; 

	CTextOutput topNamenEingabe;
	
	bool bOn = false;
	bool bmakeMenueOn = false; 
	

	int igroesseArray;

	CWriting MainTop; 
	CTextOutput * aTextOutput;
	COverlay * aOverlayTextIcon; 



	CMaus * ptrMaus;
	CTastaturGER TastaturGer; 
	
	CStringToChar stc;

	int iTyp; 
	bool bTastaturStarted = false; 

	float fTransp = 1.0F; 

};

