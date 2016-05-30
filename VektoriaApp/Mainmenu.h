
#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "Explorer.h"
#include "Maus.h"
#include "TextOutput.h"




using namespace Vektoria;

class CMainmenu
{
public:

	CMainmenu(){};
	~CMainmenu(){};
	void menuInit(CViewport * m_zv, CMaus * ptrMaus_, CExplorer * ptrExplorer_);
	void menuTick();

	void SwitchOn();
	void SwitchOff();

	bool getbGo(); 

	//CDeviceCursor * GetCursorPtr(); 
	//COverlay * GetCursorOverPtr();

	//Alles ab Hier Julians 

	//Hauptmenuzeugs
	COverlay m_zoMainmbackground;
	CImage m_ziMainmbackground;


	//Steuerung
	COverlay m_zoSteuerungBackground;
	CImage m_ziSteuerungBackground;

	//Highscore
	COverlay m_zoHighscoreBackground;
	CImage m_ziHighscoreBackground;


	//Optionen
	COverlay m_zoOptionsBackground;
	CImage m_ziOptionsBackground;



	//Transparenzpickwerkzeuge

	
	COverlay m_zoName;
	CMaterial m_zmName;


	CMaterial m_zmLernPaket;
	COverlay m_zoLernPaket;
	
	COverlay m_zoEinstellung;
	CMaterial m_zmEinstellung;

	COverlay m_zoSteuerung;
	CMaterial m_zmSteuerung;

	COverlay m_zoHighscore;
	CMaterial m_zmHiscore;

	COverlay m_zoExit;
	CMaterial m_zmExit;

	CTextOutput m_zTOPProfil; 
	CTextOutput m_zTOPLernpaket; 





	// Steuerungsbuttons

	COverlay m_zoBackButton;
	CImage m_ziBackButton;

	COverlay m_zoGoButton;
	CImage m_ziGoButton;

	//Maus
	CMaus * ptrMaus;

	CExplorer * ptrExplorer;
	

	//Hilfsvars

	bool bLernpaket = false; 
	bool bProfil = false; 
	
	bool bGo = false; 
	
	




};