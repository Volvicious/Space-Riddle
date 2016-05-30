#pragma once
#include "FrageText.h"
#include "FrageMulti.h"
#include "Frage.h"

#include "FileReader.h"
#include "TextOutput.h"
#include "FileHandler.h"
#include "StringToChar.h"

#include <map>
#include <functional>
#include <list>
#include <vector>

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

	void Run(); 
	void Init(CFileHandler * filehandlerPtr, CViewport * mzv, CTastaturGER * ptrtg);
	void ReadFile();
	void stelleFragen();

	void BereiteFragevor();
	void SetStelleFrage(bool b = false);

	bool bStelleFragen = false; 

private:

	CFileHandler * ptrFileHandler;
	CTastaturGER * tger; 
	



	COverlay m_zoFragenHandler;						//An diesem Overlay hängt alles.
	
	CImage m_ziFrage; 
	COverlay m_zoFrage;

	CImage m_ziAntwortzeile; 
	COverlay m_zoAntwortzeile; 


	COverlay m_zoMultiFrage; 

	CImage m_ziMultiFrage; 
	COverlay m_zoMutiFrage; 
	
	
	CTextOutput topFrage; 
	CTextOutput topAntwort;
	CTextOutput topFalscheAntworten[3]; 


	std::list <CFrageText> liFragenText; //niu
	std::vector <CFrageMulti> vecFrageMulti; //nui
	
	std::map <int, CFrage*> map_fragen; 


	CFrageText Textfrage;


	std::vector <std::string> * ptrLinesFromFile; 
	CFileReader filereader;

	std::string rifalsch = ""; 
	int i = 0; 
	

	void insertTextFrage();

	void frageEinfuegen();

	void clearPuffer(); 


	bool bTextfrage = false;
	bool bMultiFrage = false; 
	//Interne Hilfsvaris.
	std::string sFragePuffer;											
	std::string sAntwortPuffer;
	std::string sFalscheAntwortePuffer[3];
	int iNummerPuffer = -1;
	int ihoechsteNummer = -1; 
	int iAntworten = 0;



	//Fragen stelllen

	int iZuStellendeFrage = 1; 


	CStringToChar stc;


};

