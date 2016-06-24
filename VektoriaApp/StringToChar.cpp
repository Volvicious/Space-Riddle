#include "StringToChar.h"



CStringToChar::CStringToChar()
{
}


CStringToChar::~CStringToChar()
{
}

char * CStringToChar::DoStringToChar(std::string s) {
	
	char *ret = new char[s.size()]();
	strncpy(ret, s.c_str(), sizeof(ret));
	ret[sizeof(ret) - 1] = 0; 

	return ret; 

}


std::string CStringToChar::MachAllesKlein(std::string s) {


	for (int i = 0; i < s.size(); i++) {
		if ( s[i] >= 'A' &&  s[i] <= 'Z') {
			s[i] += 32;
		}
	}
	


	return s;
}