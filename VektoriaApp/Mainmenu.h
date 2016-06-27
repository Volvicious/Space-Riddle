
#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "Explorer.h"
#include "Maus.h"
#include "TextOutput.h"
#include "ProfilHandler.h"
#include "Highscore.h"



using namespace Vektoria;

class CMainmenu
{
public:

	CMainmenu(){};
	~CMainmenu(){};
	void menuInit(CViewport * m_zv, CMaus * ptrMaus_, 
		CExplorer * ptrExplorer_, CExplorer * ptrExplorerProf,
		CProfilHandler * ptrProfilhandler, CHighscore * ptrHighscore);
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

	COverlay m_zoBackButton;
	CImage m_ziBackButton;

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

	//TransparenzpickwerkzeugeSteuerungsmenu

	COverlay m_zoPickAntianilisingOn;
	CMaterial m_zmPickAntianilisingOn;

	COverlay m_zoPickAntianilisingOff;
	CMaterial m_zmPickAntianilisingOff;

	COverlay m_zoPickTonAn;
	CMaterial m_zmPickTonAn;

	COverlay m_zoPickTonAus;
	CMaterial m_zmPickTonAus;

	COverlay m_zoPickFullScreen;
	CMaterial m_zmPickFullScreen;

	COverlay m_zoPickWindowScreen;
	CMaterial m_zmPickWindowScreen;

	COverlay m_zoPickHighscore;
	CMaterial m_zmPickHighscore;




	// Steuerungsbuttons

	COverlay m_zoCredits;
	CImage m_ziCredits;

	COverlay m_zoCreditsBackground;
	CImage m_ziCreditsBackground;

	COverlay m_zoBackButton3;
	CImage m_ziBackButton3;

	COverlay m_zoBackButton2;
	CImage m_ziBackButton2;

	COverlay m_zoGoButton;
	CImage m_ziGoButton;

	//Maus
	CMaus * ptrMaus;

	CExplorer * ptrExplorer;
	CExplorer * ptrExplorerProfil; 
	CProfilHandler * ptrProfilHandler;
	CHighscore * ptrHighScore; 


	//Hilfsvars

	bool bLernpaket = false;
	bool bProfil = false;

	bool bGo = false;

	bool bHighscore = false;





};