#pragma once


#include "Vektoria\Root.h"
#include <list>


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

	void Init(CDeviceKeyboard * _tastatur, int _iChatOpenKey, bool bChatkeyListenOnOff);						//Tastatur-Init

	

	void Run();																		//Einbinden, um Tasten abzufragen.

	void SwitchOn();																//Schaltet Lesen manuell an.
	void SwitchOff();																//Schaltet Lesen manuell aus.

	bool SwitchListenOn();															// Schaltet Ueberpruefung an, ob TastaturOpenKey gedrueckt wird. Default ist On. FALSE wenn Tastatur AN. (Listen macht keinen Sinn!)
	bool SwitchListenOn(int _ChatOpenKey);											// Schaltet Ueberpruefung an, ob TastaturOpenKey gedrueckt wird und setzt den dazugehoerigen Key. FALSE wenn Tastatur AN. (Listen macht keinen Sinn!)
	void SwitchListenOff();															// Schaltet Ueberpruefung aus, ob TastaturOpenKey gedrueckt wird. Wenn Manuell Off, wird Listen nach Eingabe nicht automatisch auf On gestellt.

	std::string GetString();


private: 

	CDeviceKeyboard * tastatur;
	int iChatOpenKey = -1;
	
	bool bTastaturOn = false; 
	bool bListenOn = false;
	bool bListenErlauben = true; 


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
	


};

