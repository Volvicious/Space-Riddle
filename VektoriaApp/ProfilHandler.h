#pragma once

//----------------------------------
//Klasse zur Verwaltung von Profildaten.
//Author: Christoph Fischmann
//Aenderung: 2015-06-05
//----------------------------------

#include <map>
#include <vector>
#include <functional>


#include "FileHandler.h"
#include "..//..//Lib//Vektoria/Timer.h"
#include "StringToChar.h"

class CProfilHandler
{
public:
	CProfilHandler();
	~CProfilHandler();

	void Init(CFileHandler * ptrFilehandler_);
	void Run(); 
	void SaveStats();
	bool IsFileLoaded(); 


	std::map <std::string, std::map<int, int> *> * GetMapPointer(); 


private:



	std::vector<std::pair<int, int>>  * v_FrageGewichtung = NULL;
	std::map<int, int> * map_FrageGewichtung = NULL; 

	
	std::map <std::string, std::map<int, int> *> map_Lernpakete;


	
	void readFile();
	void fuegeLernpaketein(std::string s, std::vector<std::pair<int, int>>  * v_FrageGewichtung);
	void sort(std::vector<std::pair<int, int>>  * v_FrageGewichtung);
	void clear(); 


	CFileHandler * ptrFileHandler;
	CFileVektoria filecev; 
	
	bool bFileLoaded = false;

	CTimer timer;
	CStringToChar stc; 

	CFileVektoria file;
};

