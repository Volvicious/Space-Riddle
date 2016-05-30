#pragma once
#include "Frage.h"

class CFrageMulti : public CFrage
{
public:
	CFrageMulti();
	~CFrageMulti();

	void setLoesung(std::string);
	void setFalschAntwort(std::string);


	std::string getLoesung();
	std::string getFalscheAntwort(int i); 


private: 

	std::string sAntworten[4]; 

};

