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