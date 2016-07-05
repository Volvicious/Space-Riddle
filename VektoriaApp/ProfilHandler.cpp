#include "ProfilHandler.h"



CProfilHandler::CProfilHandler()
{
}


CProfilHandler::~CProfilHandler()
{
}

void CProfilHandler::Init(CFileHandler * ptr) {
	ptrFileHandler = ptr; 


	file.SetPath("fragen\\Allgemeinwissen.txt");



}

void CProfilHandler::Run() {

	if (ptrFileHandler->IsFileSelected()) {
		

		if (ptrFileHandler->DoNewFile()){ // Wenn true, muss neues File angelegt werden

			SaveStats();

		}
		//else{
			readFile(); // Eventuell noch mit einbauen.
		//}
	}
	
}

void CProfilHandler::readFile() {


	std::ifstream file(ptrFileHandler->getSelectedFilePath());
	std::string s;

	std::string sPufferNameLernpaket;
	int iPufferNummer; 
	int iPufferGewichtung; 

	int i = 0;

	while (std::getline(file, s))
	{

		if (s.size()> 1) {

			switch (s[0])
			{

			case '#':

				if (i == 2) {

					fuegeLernpaketein(sPufferNameLernpaket, v_FrageGewichtung);
					sPufferNameLernpaket = "";
					i = 0; 

				}

				if (i == 0) {
					s.erase(0, 1);

					for (int j = 0; j < s.length() && s[0] == ' '; j++) {

						s.erase(0, 1);
					}

					v_FrageGewichtung = new std::vector<std::pair<int, int>>(); 

					//map_FrageGewichtung = new std::map<int, int>();

					sPufferNameLernpaket = s; 
					i = 1;
					break;

				}
				
			case '-':

				if (i > 0) {

					s.erase(0, 1);

					for (int j = 0; j < s.length() && s[0] == ' '; j++) {
						s.erase(0, 1);
					}


					std::string spuffer = ""; 
					for (int j = 0; j < s.length() && s[0] >= '0' && s[0] <= '9'; j++) {
						spuffer += s[0]; 
						s.erase(0, 1);
					}

					if (spuffer != "") {

						try
						{
							iPufferNummer = std::stoi(spuffer);
						}
						catch (const std::exception&)
						{
							ULDebug("Profilhandler: Fehler beim Konvertieren in int!");
						}

					}

					s.erase(0, 1); // : entfernen

					spuffer = "";
					for (int j = 0; j < s.length() && s[0] >= '0' && s[0] <= '9'; j++) {
						spuffer += s[0];
						s.erase(0, 1);
					}

					if (spuffer != "") {

						try
						{
							iPufferGewichtung = std::stoi(spuffer);
							
							v_FrageGewichtung->push_back(std::pair<int, int>(iPufferNummer, iPufferGewichtung)); 

							
							int i = 2; 

						}
						catch (const std::exception&)
						{
							ULDebug("Profilhandler: Fehler beim Konvertieren in int 2");

						}

					}
				}

				break;

		
			default:
				break;
			}
		}

	}

	if (i == 2) {

		fuegeLernpaketein(sPufferNameLernpaket, v_FrageGewichtung);
		sPufferNameLernpaket = "";

	}

	file.close();

	//bStelleFragen = true; 
	

	bFileLoaded = true; 
}

void CProfilHandler::fuegeLernpaketein(std::string s, std::vector<std::pair<int, int>>  * _vector) {

	sort(v_FrageGewichtung);

	map_FrageGewichtung = new std::map<int, int>();
	
	std::vector<std::pair<int, int>>::iterator it; 

	for (it = _vector->begin(); it < _vector->end(); ++it) {


		map_FrageGewichtung->insert(std::make_pair(it->first, it->second));

	}


	map_Lernpakete.insert(std::make_pair(s, map_FrageGewichtung));
	ULDebug("Profilhandler: Lernpaket eingefuegt!");


}




void CProfilHandler::SaveStats() {

	ULDebug("SaveStats");
	ULDebug(stc.DoStringToChar(ptrFileHandler->getSelectedFilePath()));

	std::ofstream file(ptrFileHandler->getSelectedFilePath());

	if (file.is_open()) {

		//typedef std::map <std::string, std::vector<std::pair<int, int>>*>::iterator it_type1;

		for (auto &ent1 : map_Lernpakete) {

			file << ent1.first;
			file << "\n";

			
			std::map<int, int>::iterator it; 

			for (it = ent1.second->begin(); it != ent1.second->end(); ++it){

				std::string s = "-";
				s += std::to_string(it->first);
				s += ":";
				s += std::to_string(it->second);
				s += ";";

				file << s;

			}

		/*	std::vector<std::pair<int, int>>::iterator it; //TO DELETE

			for (it = ent1.second->begin(); it < ent1.second->end(); ++it) {

				std::string s = "-";
				s += std::to_string(it->first);
				s += ":";
				s += std::to_string(it->second);
				s += ";";

				file << s;
			*/
		
		
		}

	} //ende for

		file.close(); 
}




void CProfilHandler::clear() {




}

bool CProfilHandler::IsFileLoaded(){

	return bFileLoaded;
}

void CProfilHandler::sort(std::vector<std::pair<int, int>> * v_FrageGewichtung) {

	std::sort(v_FrageGewichtung->begin(), v_FrageGewichtung->end(),
		[](const std::pair<int, int>& p1, const std::pair<int, int>& p2) { return p1.second < p2.second; });


}

std::map <std::string, std::map<int, int> *> * CProfilHandler::GetMapPointer() {

	return & map_Lernpakete;
}