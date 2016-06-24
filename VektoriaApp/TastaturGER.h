#pragma once


#include "Vektoria\Root.h"
#include <list>
#include "StringToChar.h"


using namespace Vektoria; 

//----------------------------------
//Chat Klasse fuer Deutsche Tastatur
//Author: Christoph Fischmann
//Aenderung: 2015-04-01
//----------------------------------

class CTastaturGER
{
public:
	CTastaturGER();

	//
	~CTastaturGER();
	//Chatopenkey Bsp: DIR_T; Chatkeylisten: Wenn True, wird iChatOpenKey �berpr�ft und Tastatur schaltet sich beim Dr�cken dieses an.
	void Init(CDeviceKeyboard * _tastatur, int _iChatOpenKey, bool bChatkeyListenOnOff);						

	
	//Im Tick einbinden.
	void Run();																		
	//Schaltet Lesen manuell an.
	void SwitchOn();
	//Schaltet Lesen manuell aus.
	void SwitchOff();																

	// Schaltet Ueberpruefung an, ob TastaturOpenKey gedrueckt wird. Default ist On. FALSE wenn Tastatur AN. (Listen macht keinen Sinn!)
	bool SwitchListenOn();
	// Schaltet Ueberpruefung an, ob TastaturOpenKey gedrueckt wird und setzt den dazugehoerigen Key. FALSE wenn Tastatur AN. (Listen macht keinen Sinn!)
	bool SwitchListenOn(int _ChatOpenKey);
	// Schaltet Ueberpruefung aus, ob TastaturOpenKey gedrueckt wird. Wenn Manuell Off, wird Listen nach Eingabe nicht automatisch auf On gestellt.
	void SwitchListenOff();															

	//True, wenn Tastatur im LeseModus.
	bool IsOn(); 

	//Gibt den aktuellen String der Tastatur zur�ck.
	std::string GetString();														

	//Manuelles �ndern des Tastaturstrings.
	void SetString(std::string s);													

	//Pointer auf den Einlesestring
	std::string * GetStringPtr(); 


private: 

	CDeviceKeyboard * tastatur;
	int iChatOpenKey = -1;
	
	bool bTastaturOn = false; 
	bool bListenOn = false;
	bool bListenErlauben = true;

	bool bStrichLinks = false; 
	bool bStrichRechts = false;
	bool bDach = false;

	std::list<int> liKeysPressed;

	bool abKeyPressed[100]; 

	std::string sLeseString = "";
	bool leseString = false;														// weitere Aenderungen nach Abholung.



	void read();
	bool checkDoublePressed(int iKey);

	char convertToChar(int iKeyID);

	bool createString(int iKeyID);

	bool isKeyUp(int iKey);



	void Debug(std::string s);
	void Debug(std::string s, int i);
	
	CStringToChar stc; 

};

