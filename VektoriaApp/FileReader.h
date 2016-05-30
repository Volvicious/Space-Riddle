#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <direct.h>

using namespace std; 

//----------------------------------
//Momentan Klasse ohne Funktion
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

class CFileReader

{
public:
	CFileReader();
	~CFileReader();

	std::vector<std::string> * ReadFromFile(std::string);


private: 



	
	void checkallfiles(std::string s); 
	std::vector<std::string> liDateien;
	std::vector<std::string> liZeilen;


	




};

