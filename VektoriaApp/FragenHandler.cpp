#include "FragenHandler.h"



CFragenHandler::CFragenHandler()
{
}


CFragenHandler::~CFragenHandler()
{
}

void CFragenHandler::Init(CFileHandler * fileHandlerPtr, CViewport * mzv, CTastaturGER * ptrtg) {

	ptrFileHandler = fileHandlerPtr;
	tger = ptrtg;

	mzv->AddOverlay(&m_zoFragenHandler);
	m_zoFragenHandler.SetLayer(0.9F);

	m_ziFrage.Init("textures\\spaceblue.jpg");
	m_zoFrage.Init(&m_ziFrage, CFloatRect(0.0F, 0.7F, 1.0F, 0.3F));
	m_zoFrage.SetLayer(0.8F);
	m_zoFragenHandler.AddOverlay(&m_zoFrage);


	m_ziAntwortzeile.Init("textures\\spaceblue.gif");
	m_zoAntwortzeile.Init(&m_ziAntwortzeile, CFloatRect(0.0F, 0.2F, 1.0F, 0.2F));
	m_zoAntwortzeile.SetLayer(0.7F);
	m_zoFrage.AddOverlay(&m_zoAntwortzeile);

	//topFrage.Init(&m_zoFrage, "fonts\\LucidaConsoleWhiteF.png", 0.3F, 0.1F, 1.0F, 0.02F);
	//topAntwort.Init(&m_zoAntwortzeile, "fonts\\LucidaConsoleWhiteF.png", 0.3F, 0.0F, 1.0F, 0.02F);

	m_zoFragenHandler.SwitchOff();


	mzv->AddOverlay(&m_zoMultiFrage);
	m_zoMultiFrage.SetLayer(0.9F);

	m_ziMultiFrage.Init("textures\\spaceblue.jpg");
	m_zoMultiFrage.Init(&m_ziMultiFrage, CFloatRect(0.0F, 0.6F, 1.0F, 0.3F));
	m_zoMultiFrage.SetLayer(0.8F);

	float fy = 0;

	topFrage.Init(&m_zoMultiFrage, "fonts\\Nasalization-rg-White.png", 0.01F, 0.0F, 1.5F, .04F);
	for (int i = 0; i < 3; i++) {

		topFalscheAntworten[i].Init(&m_zoMultiFrage, "fonts\\Nasalization-rg-White.png", 0.01F, 0.08F + fy, 1.5F, .04F);
		fy += 0.04F; 

	}
	topAntwort.Init(&m_zoMultiFrage, "fonts\\Nasalization-rg-White.png", 0.01F, 0.08F + fy, 1.5F, .04F);

	m_zoMultiFrage.SwitchOff();

}

void CFragenHandler::Run() {

	if (bStelleFragen) {
	
		m_zoMultiFrage.SwitchOn();
		topFrage.WriteSavedString();

		for (int i = 0; i < 3; i++) {
			topFalscheAntworten[i].WriteSavedString();
		
		}
	
		topAntwort.WriteSavedString();



		
	}

	if (ptrFileHandler->IsFileSelected()) {
		ReadFile();
	}




}


void CFragenHandler::ReadFile() {


	std::ifstream file(ptrFileHandler->getSelectedFilePath());
	std::string s;
	int i = 0; 

	while (std::getline(file, s))
		{


		if (s.size()> 1){ 

			switch (s[0] )
			{

			case '#':
			
				if (i == 0) {
					s.erase(0, 1); 
					sFragePuffer = s;
					i = 1; 
					break; 
				
				}else if (i == 4) {

					if (iNummerPuffer != -1) {

						if (ihoechsteNummer < iNummerPuffer) ihoechsteNummer = iNummerPuffer;

						frageEinfuegen();
						s.erase(0, 1);
						sFragePuffer = s;
						i = 1;
						break;
					}
				}else{
					
					clearPuffer();
					s.erase(0, 1);
					sFragePuffer = s;
					i = 1;
					break;
				}



			case '!': 

				if (i == 1) {

					s.erase(0, 1); 
					sAntwortPuffer = s;
					i = 2; 

				}else {

					clearPuffer();
					i = 0; 

				}


				break; 

			case '?':

				break; 

			case '-':

				if (i == 2) {

					s.erase(0, 1); 
					sFalscheAntwortePuffer[iAntworten] = s; 
					iAntworten++;
					if (iAntworten == 3) {
						i = 3;
					}

				}
				else {

					clearPuffer();
					i = 0; 

				}


				break; 

			case '$':


				if (i == 3) {

					s.erase(0, 1);

					try
					{
						iNummerPuffer = std::stoi(s);
						i = 4; 
					}
					catch (const std::exception&)
					{
						clearPuffer(); 
						i = 0; 
						ULDebug("Fehler beim konvertieren in int.");
					}
					

				}
				else {
					clearPuffer(); 
					i = 0; 

				}

				break; 


			default:
				break;
			}
		}

	}

	if (i == 4) {

		frageEinfuegen(); 

	}

	//bStelleFragen = true; 
	ULDebug("Das einlesen der Fragen war von Erfolg gekrönt.");
	ULDebug("Laenge der Map ist:  %i",map_fragen.size());


}

void CFragenHandler::frageEinfuegen() {

	CFrage * Frage = new CFrage();
	Frage->setFrage(sFragePuffer);
	Frage->setAntwort(sAntwortPuffer);
	for (int i = 0; i < 3; i++) {
		//ULDebug("Jetzt sollte eine Falsche Antwort hier eingefuegt werden: ");
		//ULDebug(stc.DoStringToChar(sFalscheAntwortePuffer[i]));
		Frage->setFalscheAntwort(sFalscheAntwortePuffer[i]);
	}
	Frage->setTyp(4);


	map_fragen.insert(std::make_pair(iNummerPuffer, Frage));

	ULDebug("Frage %i wird eingefuegt!", iNummerPuffer);
	clearPuffer();

}


void CFragenHandler::insertTextFrage() {

	Textfrage.setFrage(sFragePuffer);
	Textfrage.SetAntwort(sAntwortPuffer);

	clearPuffer();

}

void CFragenHandler::clearPuffer() {

	bTextfrage = false; 
	sFragePuffer.clear();
	sAntwortPuffer.clear();
	iNummerPuffer = -1; 

	
	for (int i = 0; i < 3; i++) {
		sFalscheAntwortePuffer[i].clear();
	}
	iAntworten = 0; 



}


void CFragenHandler::stelleFragen() { //niu

	switch (i) {

		case 0: topFrage.Write(Textfrage.getFrage());
				tger->SwitchOn(); 
				i++;
				break;

		case 1: if (!tger->IsOn()) {

			if (Textfrage.vergleicheAntwort(tger->GetString())) { rifalsch = "richtig"; i++; break; }
			else {
				rifalsch = "falsch, richtig ist " + Textfrage.sAntwort; i++; break;

				

			}
			

		}
				else {
					topAntwort.Write(tger->GetString());

				}
				break; 

		case 2 : topAntwort.Write(rifalsch);

		
			break; 
	default:
		break;
	}

}

void CFragenHandler::BereiteFragevor() {



	std::string s = map_fragen[iZuStellendeFrage]->getFrage();
	topFrage.SetString(s);

	for (int i = 0; i < 3; i++) {

		std::string s = map_fragen[iZuStellendeFrage]->getFalscheAntwort(i);
		

		topFalscheAntworten[i].SetString(s);

	}

	topAntwort.SetString(map_fragen[iZuStellendeFrage]->getAntwort());

	iZuStellendeFrage++;

}


void CFragenHandler::SetStelleFrage(bool b) {

	if (!b) {
		m_zoMultiFrage.SwitchOff(); 

	}

	bStelleFragen = b; 

}
