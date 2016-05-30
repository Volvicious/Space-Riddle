#pragma once
#include "Vektoria\Root.h"
#include "TextOutput.h"
#include <list>
#include "FileFinder.h"
#include "FileHandler.h"
#include "Maus.h"


using namespace Vektoria;

//----------------------------------
//Klasse fuer Exploreransicht - Listen von Dateien im Ordner mit Eingabezeile fuer Neue Datei
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

class CExplorerProfil
{
public:
	CExplorerProfil();
	~CExplorerProfil();


	void Init(CViewport * m_zv, CMaus  * ptrMaus_, CFileHandler * filehandlerPtr);

	void Run();



	void SwitchOff();
	void SwitchOn();


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


	int igroesseArray;
	CTextOutput * aTextOutput;
	COverlay * aOverlayTextIcon;



	CMaus * ptrMaus;



};

