#include "TastaturGER.h"



CTastaturGER::CTastaturGER()
{
	
}


CTastaturGER::~CTastaturGER()
{
}



void CTastaturGER::Init(CDeviceKeyboard * _tastatur, int _iChatOpenKey, bool bChatKeyListenOnOff) {

	tastatur = _tastatur; 
	iChatOpenKey = _iChatOpenKey;
	bListenOn = bChatKeyListenOnOff;
	bListenErlauben = bChatKeyListenOnOff;

	//   .................... //ULDebug("Init erstellt.");

}

bool CTastaturGER::IsOn() {
	return bTastaturOn;
}



//
void CTastaturGER::Run() {

	if (bTastaturOn) {

		//ULDebug("Tastatur On");
		read();


	}else if (bListenOn) {

			//ULDebug("ListenOn");

		if (tastatur->KeyPressed(iChatOpenKey)) {
			
			//ULDebug("T pressed");
			checkDoublePressed(iChatOpenKey);

			bListenOn = false; 
			bTastaturOn = true; 
			sLeseString = ""; 

		}
	}
}


void CTastaturGER::SwitchOn() {
	bTastaturOn = true; 
	bListenOn = false; 
}

void CTastaturGER::SwitchOff() {
	bTastaturOn = false; 
	if (bListenErlauben) bListenOn = true; 
}

bool CTastaturGER::SwitchListenOn() {
	
	if (!bTastaturOn) {
		bListenOn = true; 
		bListenErlauben = true; 
		return true; 
	}
	return false; 
}

bool CTastaturGER::SwitchListenOn(int _iChatOpenKey) {

	if (SwitchListenOn()) {
		iChatOpenKey = _iChatOpenKey;
		return true;
	}
	return false;
}

void CTastaturGER::SwitchListenOff() {
	bListenOn = false; 
	bListenErlauben = false; 
}


std::string CTastaturGER::GetString() {

	return sLeseString;
}

void CTastaturGER::SetString(std::string s) {
	sLeseString = s; 
}

std::string * CTastaturGER::GetStringPtr() {

	return &sLeseString; 
}

/////////////////////////////////// END OF PUBLIC /////////////////////////////////////////


void CTastaturGER::read() {

	int iKey = tastatur->GetKey();

	if (iKey != 0) {

		if (!checkDoublePressed(iKey)) {
		

			if (!createString(iKey)) {						//False, String durch Eingabe fertig gestellt. Tastatur Off, Listener wieder On.

				bTastaturOn = false; 
				
				if (bListenErlauben) bListenOn = true;
				liKeysPressed.clear();

			}
		}

	}


	std::list<int>::iterator it;
	for (it = liKeysPressed.begin(); it != liKeysPressed.end(); ++it) {
			//liKeysPressed.remove_if(isKeyUp((int) *it));
		int iAKey = (int)*it;
		if (isKeyUp(iAKey)) {
			liKeysPressed.remove(iAKey);
			break;
		}
	}

}

bool CTastaturGER::isKeyUp (int iKey) {

	return tastatur->KeyUp(iKey);

}

bool CTastaturGER::createString(int iKeyID) {

	char cToAdd = convertToChar(iKeyID);
	
	if (cToAdd == '`' && !bStrichLinks){
		bStrichLinks = true; 
		return true; 
	}


	if (cToAdd == '´' && !bStrichRechts){
		bStrichRechts = true;
		return true;

	}

	if (cToAdd == '^' && !bDach){
		bDach = true;
		return true;

	}


	if (bStrichLinks){

		switch (cToAdd)
		{
		case 'a':
			cToAdd = 'à';
			ULDebug("a");
			break;
		case 'e':
			cToAdd = 'è';
			break;
		case 'i':
			cToAdd = 'ì';
			break;
		case 'o':
			cToAdd = 'ò';
			break;
		case 'u':
			cToAdd = 'ù';
			break;
		case 'A':
			cToAdd = 'À';
			break;
		case 'E':
			cToAdd = 'È';
			break;
		case 'I':
			cToAdd = 'Ì';
			break;
		case 'O':
			cToAdd = 'Ò';
			break;
		case 'U':
			cToAdd = 'Ù';
			break;
		default:
			cToAdd = '`';
			break;
		}

		sLeseString += cToAdd;
		bStrichLinks = false; 
		return true; 
	}

	if (bStrichRechts){

		switch (cToAdd)
		{

		case 'a':
			cToAdd = 'á';
			break;
		case 'e':
			cToAdd = 'é';
			break;
		case 'i':
			cToAdd = 'í';
			break;
		case 'o':
			cToAdd = 'ó';
			break;
		case 'u':
			cToAdd = 'ú';
			break;
		case 'A':
			cToAdd = 'Á';
			break;
		case 'E':
			cToAdd = 'É';
			break;
		case 'I':
			cToAdd = 'Í';
			break;
		case 'O':
			cToAdd = 'Ó';
			break;
		case 'U':
			cToAdd = 'Ú';
			break;
		default:
			cToAdd = '´';
			break;
		}

		bStrichRechts = false; 
		sLeseString += cToAdd;
		return true; 
	}

	if (bDach){

		switch (cToAdd)
		{

		case 'a':
			cToAdd = 'â';
			break;
		case 'e':
			cToAdd = 'ê';
			break;
		case 'i':
			cToAdd = 'î';
			break;
		case 'o':
			cToAdd = 'ô';
			break;
		case 'u':
			cToAdd = 'û';
			break;
		case 'A':
			cToAdd = 'Â';
			break;
		case 'E':
			cToAdd = 'Ê';
			break;
		case 'I':
			cToAdd = 'Î';
			break;
		case 'O':
			cToAdd = 'Ô';
			break;
		case 'U':
			cToAdd = 'Û';
			break;
		default:
			cToAdd = '^';
			break;
		}

		bDach = false;
		sLeseString += cToAdd;
		return true;

	}

	if (cToAdd == 10) {
		/*char tab2[1024];
		strcpy(tab2, sLeseString.c_str());
		ULDebug(tab2);*/
		//sLeseString = "";
		
		return false; 
	}

	if (cToAdd == 24){
		return true;										 //Taste Ohne Belegung = nix.
	}

	if (cToAdd == 8) {

		if (sLeseString.size() > 0) sLeseString.resize(sLeseString.size() - 1);
		return true; 

	}

	sLeseString += cToAdd;
	

	


	return true; 
}

char CTastaturGER::convertToChar(int iKeyID) {

	bool bShift = GetAsyncKeyState(VK_SHIFT);
	bool bAltgr = GetAsyncKeyState(VK_RMENU);
	


	switch (iKeyID)
	{


	
	case 2:					return bShift ? '!' : '1';		//1
	case 3:					return bAltgr ? '²' : bShift ? '"' : '2';		// ...
	case 4:					return bAltgr ? '³' : bShift ? '§' : '3';
	case 5:					return bShift ? '$' : '4';
	case 6:					return bShift ? '%' : '5';
	case 7:					return bShift ? '&' : '6';
	case 8:					return bAltgr ? '{' : bShift ? '/' : '7';
	case 9:					return bAltgr ? '[' : bShift ? '(' : '8';
	case 10:			    return bAltgr ? ']' : bShift ? ')' : '9';		// ...
	case 11:			    return bAltgr ? '}' : bShift ? '=' : '0';		// 0

	case 12:			    return bAltgr ? '\\' : bShift ? '?' : 'ß';

	case 13:			    return bShift ? '´' : '`';

	case 14:			    return 8;						// BACKSPACE

	case 15:			    return 11;						//TAB
	//

	case 16:			    return bShift ? 'Q' : 'q';
	case 17:			    return bShift ? 'W' : 'w';
	case 18:			    return bAltgr ? '€' : bShift ? 'E' : 'e';
	case 19:			    return bShift ? 'R' : 'r';
	case 20:			    return bShift ? 'T' : 't';
	case 21:			    return bShift ? 'Z' : 'z';
	case 22:			    return bShift ? 'U' : 'u';
	case 23:			    return bShift ? 'I' : 'i';
	case 24:			    return bShift ? 'O' : 'o';
	case 25:			    return bShift ? 'P' : 'p';
	case 26:			    return bShift ? 'Ü' : 'ü';
	case 27:			    return bAltgr ? '~' : bShift ? '*' : '+';

		

	case 28:			    return 10;						//Return

	//case 29:			    return bShift ? '!' : '';		// Strg

	case 30:			    return bShift ? 'A' : 'a';
	case 31:			    return bShift ? 'S' : 's';
	case 32:			    return bShift ? 'D' : 'd';
	case 33:			    return bShift ? 'F' : 'f';
	case 34:			    return bShift ? 'G' : 'g';
	case 35:			    return bShift ? 'H' : 'h';
	case 36:			    return bShift ? 'J' : 'j';
	case 37:			    return bShift ? 'K' : 'k';
	case 38:			    return bShift ? 'L' : 'l';
	case 39:			    return bShift ? 'Ö' : 'ö';
	case 40:			    return bShift ? 'Ä' : 'ä';
	
	case 41:			    return bShift ? '°' : '^';		

	//case 42:			    return bShift ? '!' : '';		// N/V

	case 43:			    return bShift ? '\'' : '#';

	case 44:			    return bShift ? 'Y' : 'y';
	case 45:			    return bShift ? 'X' : 'x';
	case 46:			    return bShift ? 'C' : 'c';
	case 47:			    return bShift ? 'V' : 'v';
	case 48:			    return bShift ? 'B' : 'b';
	case 49:			    return bShift ? 'N' : 'n';
	case 50:			    return bShift ? '´M' : 'm';
	case 51:			    return bShift ? ';' : ',';
	case 52:			    return bShift ? ':' : '.';
	case 53:			    return bShift ? '_' : '-';
	
	//case 54:					return bShift ? '' : '';
	
	case 55:					return '*';					//Numblock mal

	case 56:					return 14;					// ALT

	case 57:					return ' ';					//Leertaste
	
	//case 69:					return bShift ? '' : '';	//Numblock Num

	case 181:					return '/';					//Numblock geteilt

	case 71:					return '7';					//Numblock
	case 72:					return '8';					//Numblock
	case 73:					return '9';					//Numblock
	case 74:					return '-';					//Numblock
	case 75:					return '4';					//Numblock
	case 76:					return '5';					//Numblock
	case 77:					return '6';					//Numblock
	case 78:					return '+';					//Numblock
	case 79:					return '1';					//Numblock
	case 80:					return '2';					//Numblock
	case 81:					return '3';					//Numblock
	case 82:					return '0';					//Numblock


	



	case 86:			    return bShift ? '>' : '<';

	case 156:				return 10;						//Numblock Return



	default:

		return 24;											//Cancel Bedingung

		break;
	}


}


bool CTastaturGER::checkDoublePressed(int iKey) {


	if (std::find(liKeysPressed.begin(), liKeysPressed.end(), iKey) != liKeysPressed.end()) {
		return true; 
	}

	liKeysPressed.push_back(iKey);
	return false; 

}



void CTastaturGER::Debug(std::string s) {

	char temp[1024];
	strcpy_s(temp, s.c_str());
	ULDebug(temp);
}


void CTastaturGER::Debug(std::string s, int i) {

	char temp[1024];

	std::string tmp = std::to_string(i);
	s += tmp;
	strcpy_s(temp, s.c_str());
	ULDebug(temp);
}