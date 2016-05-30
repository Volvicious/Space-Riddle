#include "FrageMulti.h"


CFrageMulti::CFrageMulti()
{
}


CFrageMulti::~CFrageMulti()
{
}


void CFrageMulti::setLoesung(std::string sLoesung){

	sAntworten[0] = sLoesung;
}

void CFrageMulti::setFalschAntwort(std::string sFalscheAntwort){

	for (int i = 1; i < 4; i++){

		if (sAntworten[i].empty()){
			sAntworten[i] = sFalscheAntwort;
		}
	}

}

std::string CFrageMulti::getLoesung(){

	return sAntworten[0];
}

std::string CFrageMulti::getFalscheAntwort(int i){

	return sAntworten[i];
}