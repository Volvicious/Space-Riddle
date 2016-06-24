#pragma once
#include "Frage.h"

#include "FileReader.h"
#include "TextOutput.h"
#include "FileHandler.h"
#include "StringToChar.h"
#include "ProfilHandler.h"

#include <map>
#include <functional>
#include <list>
#include <vector>

#include "..//..//Lib//Vektoria/Timer.h"

#define MAP_sii std::map <std::string, std::map<int, int> *>

//----------------------------------
//Chat Klasse fuer das Verwalten der Fragen
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

class CFragenHandler
{
public:
	CFragenHandler();
	~CFragenHandler();

	void Run(float fTimeDelta); 
	void Init(CFileHandler * filehandlerPtr, CViewport * mzv, CProfilHandler * ptrProfilhandler);
	//void Init(CFileHandler * filehandlerPtr, CViewport * mzv);

	void ReadFile();
	void stelleFragen();

	void BereiteFragevor();
	void SetStelleFrage(bool b = false);
	
	bool IstAntwortRichtig(int i);


private:

	bool bStarteVorbereitung = false; 

	CProfilHandler * ptrProfilHandler; 

	CFileHandler * ptrFileHandler;
	CTastaturGER * tger; 

	COverlay m_zoFragenHandler;						//An diesem Overlay hängt alles.
	
	
	//Frageneinheit MultiFrage
	COverlay m_zoMultiFrage; 
	CMaterial m_zmMultiFrage;

	COverlay m_zoDummyAntwort;
	COverlay m_zoDummyFrage; 
	COverlay m_zoMultiAntwort; 
	CMaterial m_zmMultiAntwort; 


	CTextOutput topFrage; 
	CTextOutput topAntwort;
	CTextOutput topFalscheAntworten[3];
	CTextOutput topAntwortmoegl[4];
	int iRichtigeAntwort = -1; 

	std::string sLernpaketname; 
	std::map <int, CFrage*> map_fragen; 

	std::vector <std::string> * ptrLinesFromFile; 

	//Hilfsvariabeln und Funktionen beim Ein und Ausblenden.
	bool fadeDown(COverlay * ptrO, float yuntil,  float fTimeDelta);
	bool fadeUp(COverlay * ptro, float yuntil, float fTimeDelta);
	bool bDoFadeOut = false; 
	float m_fx = 0.0F;
	float m_fy = 0.0F; 

	//Hilfsvars beim Fragestellen
	bool bTextfrage = false;
	bool bMultiFrage = false;

	//Interne Hilfsfunktionen beim Einlesen
	void insertTextFrage();
	void frageEinfuegen();
	void clearPuffer();  

	//Interne Hilfsvaris beim Einlesen der Fragen:
	std::string sFragePuffer;											
	std::string sAntwortPuffer;
	std::string sFalscheAntwortePuffer[3];
	int iNummerPuffer = -1;
	int ihoechsteNummer = -1; 
	int iAntworten = 0;

	//Fragenmap vorbereiten: 
	
	//std::map <std::string, std::map<int, int> *> * map_ProfilHandlerLernpakete;
	MAP_sii * map_ProfilHandlerLernpakete;

	void bereiteFragenMapVor(); 

	//Fragen stelllen

	int iZuStellendeFrage = 1; 

	//Hilfsfunktion:
	CStringToChar stc;

	//CTimer timer; 

	bool bStelleFragen = false;


};

