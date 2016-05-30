#include "Frage.h"



CFrage::CFrage()
{
}


CFrage::~CFrage()
{
}


void CFrage::setTyp(int i) {
	iTyp = i; 
}

int CFrage::getTyp() {
	return iTyp; 
}

void CFrage::setFrage(std::string s) {
	sFrage = s; 
}

std::string CFrage::getFrage() {
	return sFrage;
}

void CFrage::setUUID(std::string s) {
	sUUID = s; 
}

std::string CFrage::getUUID() {
	return sUUID;
}


void CFrage::setGewichtung(float fFaktor){

	fGewichtung = fFaktor;
}

float CFrage::getGewichtung(){

	return fGewichtung;
}

void CFrage::setAntwort(std::string sAntwort_) {
	sAntwort = sAntwort_; 
}

std::string CFrage::getAntwort() {
	return sAntwort; 
}

void CFrage::setFalscheAntwort(std::string sFalscheAntwort_) {
	
	falscheAntworten[iFalsacheAntwort] = sFalscheAntwort_;
	iFalsacheAntwort++;
}

std::string CFrage::getFalscheAntwort(int i) {
	return falscheAntworten[i];
}