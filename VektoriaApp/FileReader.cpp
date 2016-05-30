#include "FileReader.h"


CFileReader::CFileReader()
{


}


CFileReader::~CFileReader()
{
}


void CFileReader::checkallfiles(std::string s) {
}


std::vector<std::string> *  CFileReader::ReadFromFile(std::string sPfad) {


	std::ifstream file(sPfad);
	std::string s;
	while (std::getline(file, s))
	{
		liZeilen.push_back(s);
	}


	

	return &liZeilen;
}