#pragma once
#include "Frage.h"
#include <algorithm>

//----------------------------------
//Fragenklasse: Enth�lt Textfrage
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

class CFrageText : public CFrage
{

public:
	CFrageText();
	~CFrageText();

	std::string sAntwort; 

	bool vergleicheAntwort(std::string);

	void SetAntwort(std::string sAntwort_); 
	


private: 

	std::string bereiteStringsVor (std::string); 

};

