#pragma once
#include <string>

//----------------------------------
//Fragenklasse
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

class CFrage
{
public:
	CFrage();
	~CFrage();

	
	void setTyp(int);
	int getTyp(); 
	
	void setUUID(std::string);
	std::string getUUID(); 

	void setFrage(std::string);
	std::string getFrage(); 

	void setGewichtung(float fFaktor);
	float getGewichtung();

	void setAntwort(std::string sAntwort_);
	std::string getAntwort(); 

	void setFalscheAntwort(std::string sFalscheAntwort); 
	std::string getFalscheAntwort(int i);
	
	


private: 

	int iTyp;
	float fGewichtung; 
	std::string sUUID; 
	std::string sFrage;
	std::string sAntwort;
	std::string falscheAntworten[3];
	int iFalsacheAntwort = 0; 

};

