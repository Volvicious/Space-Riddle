#pragma once
#include "Vektoria\Root.h"
#include "TextOutput.h"
#include <list>
#include "FileFinder.h"
#include "FileHandler.h"
#include "Maus.h"


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


	COverlay m_zoBackButton;
	CImage m_ziBackButton;


	

	CFileFinder * filefinder;
	CFileHandler * ptrfilehandler; 

	CTextOutput top;
	
	bool bOn = false;
	bool bmakeMenueOn = false; 
	

	int igroesseArray;
	CTextOutput * aTextOutput;
	COverlay * aOverlayTextIcon; 



	CMaus * ptrMaus;
	
	CStringToChar stc;

};

