#include "FrageText.h"



CFrageText::CFrageText()
{
}


CFrageText::~CFrageText()
{
}

//Public!

void CFrageText::SetAntwort(std::string sAntwort_) {
	 
	sAntwort = sAntwort_; 


}

bool CFrageText::vergleicheAntwort(std::string s) {

	s = bereiteStringsVor(s);

	if (s.length() != sAntwort.length()) return false; 
	
	for (int i = 0; i < s.length() && sAntwort.length(); i++) {

		if (s[i] != sAntwort[i]) {
			return false; 
		}

	}


	return true ;
}



//Interne Sachen

std::string CFrageText::bereiteStringsVor(std::string s) {

	std::transform(s.begin(), s.end(), s.begin(), tolower);
	std::transform(sAntwort.begin(), sAntwort.end(), sAntwort.begin(), tolower);

	std::string olaf = sAntwort;

	for (int i = 0; i < 2; i++) {

		for (int i = 0; i < olaf.length() - 1; i++) {

			if (olaf[i] == ' ') {
				olaf.erase(i, 1);
				i--;
			}
			else {
				break;
			}
		}

		for (int i = olaf.length() - 1; i >= 0; i--) {

			if (olaf[i] == ' ') {
				olaf.erase(i, 1);
			}
			else {
				break;
			}
		}

		sAntwort = olaf;
		olaf = s; 
	}


	return s; 

}