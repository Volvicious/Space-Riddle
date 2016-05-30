#pragma once
#include "Vektoria\Root.h"
#include <windows.h>

#include <iostream>
#include <set>
#include <string>

using namespace Vektoria; 

//----------------------------------
//Klasse fuer das finden der Files im Ordner
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

class CFileFinder
{
public:
	CFileFinder();
	~CFileFinder();

	void Init(std::string sPathFragen); 

	void findFiles(std::string path);
	std::set <std::string>* getFiles();
	std::set <std::string>* getDirs();

	std::string getPath(); 


private:
	std::set <std::string> setFiles;
	std::set <std::string> setDirs;

	std::string m_sPath; 

};

