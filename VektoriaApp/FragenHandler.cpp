#include "FragenHandler.h"

CFragenHandler::CFragenHandler()
{
	std::srand(time(NULL));

}


CFragenHandler::~CFragenHandler()
{
}

void CFragenHandler::Init(CFileHandler * fileHandlerPtr, CViewport * mzv, CProfilHandler * ptrProfilhandler) {

	ptrProfilHandler = ptrProfilhandler;
	ptrFileHandler = fileHandlerPtr;
	

	mzv->AddOverlay(&m_zoFragenHandler);
	m_zoFragenHandler.SetLayer(0.3F);

	m_zoFragenHandler.SwitchOff();


	
	mzv->AddOverlay(&m_zoMultiFrage);
	m_ziMultiFrage.Init("textures\\grau.png");
	m_zoMultiFrage.Init(&m_ziMultiFrage, CFloatRect(0.0F, -0.1F, 1.0F, 0.1F));
	m_zoMultiFrage.SetTransparency(0.2F);

	mzv->AddOverlay(&m_zoMultiAntwort);
	m_ziMultiAntwort.Init("textures\\grau.png");
	m_zoMultiAntwort.Init(&m_ziMultiAntwort, CFloatRect(0.0F, 1.0F, 1.0F, 0.28F));
	m_zoMultiAntwort.SetTransparency(0.2F);

	m_zoMultiFrage.SetLayer(0.3F);
	m_zoMultiAntwort.SetLayer(0.3F);

	float fx = 0.0F;
	float fy = 0.0F;
	float fLayer = 0.29F; 
	 
	//mzv->AddOverlay(&m_zoDummyAntwort);
	//mzv->AddOverlay(&m_zoDummyFrage);

	//topFrage.Init(mzv, "fonts\\Nasalization-rg-Red.png", 0.0F, -.04F, 1.5F, .04F, 99);
	topFrage.Init(mzv, "fonts\\Nasalization-rg-Red.png", 0.0F, -0.2F, 1.5F, .04F, 99);
	topFrage.SwitchOff();

	for (int i = 0; i < 4; i++) {

		if (i == 1 || i == 3) { fx = 0.55F;}
		if (i == 2) { fx = 0.0F; fy += 0.1; }

		topAntwortmoegl[i].Init(mzv, "fonts\\Nasalization-rg-Red.png", 0.03F + fx,   fy+0.8F, 1.5F, .04F, fLayer);
		fLayer -= 0.001; 
	}

	//float Arrays befuellen
	floatArraysNew();
		
	for (int i = 0; i < 5; i++){
		fyWerteDownV[i] = fyWerteDown[i];
		fyWerteUpV[i] = fyWerteUp[i];
	}



	/*for (int i = 0; i < 3; i++) {

		topFalscheAntworten[i].Init(&m_zoMultiFrage, "fonts\\Nasalization-rg-White.png", 0.01F, 0.08F + fy, 1.5F, .04F);
		fy += 0.04F; 

	}
	topAntwort.Init(&m_zoMultiFrage, "fonts\\Nasalization-rg-White.png", 0.01F, 0.08F + fy, 1.5F, .04F);

	m_zoMultiFrage.SwitchOff();*/



}


void CFragenHandler::Run(float fTimeDelta) {

	if (bStelleFragen) {
	
		
		m_zoFragenHandler.SwitchOn(); 
		m_zoMultiFrage.SwitchOn();
		topFrage.WriteSavedString();

		std::string s = topFrage.GetString();
		ULDebug(stc.DoStringToChar(s));


		fadeDown(&m_zoMultiFrage, 0.0F, fTimeDelta);
		

		fadeDown(topFrage.getWritingPtr(), 0.05F, fTimeDelta, 0);
		
		fadeUp(topAntwortmoegl[0].getWritingPtr(), 0.8F, fTimeDelta, 1);
		fadeUp(topAntwortmoegl[1].getWritingPtr(), 0.8F, fTimeDelta, 2);
		fadeUp(topAntwortmoegl[2].getWritingPtr(), 0.9F, fTimeDelta, 3);
		fadeUp(topAntwortmoegl[3].getWritingPtr(), 0.9F, fTimeDelta, 4);


		fadeUp(&m_zoMultiAntwort, 0.72F, fTimeDelta);


		for (int i = 0; i < 4; i++) {

			topAntwortmoegl[i].WriteSavedString();
		}
		
	}

	if (bDoFadeOut) {

		bool btemp = fadeUp(&m_zoMultiFrage, -0.1F, fTimeDelta);
		bool btemp2 = fadeUp(topFrage.getWritingPtr(), -0.1F, fTimeDelta);
		bDoFadeOut = fadeDown(&m_zoMultiAntwort, 1.0F, fTimeDelta);
		bDoFadeOut = bDoFadeOut || btemp || btemp2;

		if (!bDoFadeOut) {
			SwitchOff();
			bFadeOutbeendet = true;
			floatArraysNew(); 
		}

	}

	if (ptrFileHandler->IsFileSelected()) {
		ReadFile();
	}

	if (bStarteVorbereitung) {

		//map_ProfilHandlerLernpakete = ptrProfilHandler->GetMapPointer(); 
		//bereiteFragenMapVor(); 

	}

}

bool CFragenHandler::fadeDown(COverlay * ptrO, float yuntil, float fTimeDelta){

	if (ptrO->GetRect().GetYPos() < yuntil) {

		float fy = ptrO->GetRect().GetYPos();
		CFloatRect rect = ptrO->GetRect();

		std::string s = std::to_string(fTimeDelta);
		ULDebug(stc.DoStringToChar(s));



		fy += fTimeDelta*.9F;

		if (fy > yuntil) {
			fy = yuntil;
		}

		rect.SetYPos(fy);
		ptrO->SetRect(rect);
		
		return true; 
	}


	return false; 
}

bool CFragenHandler::fadeUp(COverlay * ptrO, float yuntil, float fTimeDelta) {

	if (ptrO->GetRect().GetYPos() >  yuntil) {

		float fy = ptrO->GetRect().GetYPos();
		CFloatRect rect = ptrO->GetRect();

		std::string s = std::to_string(fTimeDelta);
		ULDebug(stc.DoStringToChar(s));

		fy -= fTimeDelta*.9F;

		if (fy < yuntil) {
			fy = yuntil;
		}

		rect.SetYPos(fy);
		ptrO->SetRect(rect);

		return true;
	}


	return false;
}


bool CFragenHandler::fadeDown(CWriting * ptrW, float yuntil, float fTimeDelta, int iNummer){

	


	if (fyWerteDownV[iNummer] < yuntil) {

		
		fyWerteDownV[iNummer] += fTimeDelta*.9F;

		if (fyWerteDownV[iNummer] > yuntil) {
			fyWerteDownV[iNummer] = yuntil;
		}


		CFloatRect rect = ptrW->GetRect();

		rect.SetYPos(fyWerteDownV[iNummer]);
		ptrW->SetRect(rect);


		return true;
	}


	fyWerteUpV[iNummer] = fyWerteUp[iNummer];

	return false;
}

bool CFragenHandler::fadeUp(CWriting * ptrW, float yuntil, float fTimeDelta, int iNummer) {

	if (fyWerteUpV[iNummer] > yuntil) {


		fyWerteUpV[iNummer] -= fTimeDelta*.9F;

		if (fyWerteUpV[iNummer] < yuntil) {
			fyWerteUpV[iNummer] = yuntil;
		}


		CFloatRect rect = ptrW->GetRect();

		rect.SetYPos(fyWerteUpV[iNummer]);
		ptrW->SetRect(rect);


		return true;
	}

	fyWerteDownV[iNummer] = fyWerteDown[iNummer];

	return false;
}


void CFragenHandler::ReadFile() {

	sLernpaketname = ptrFileHandler->getSelectedFileDisplayName(); 

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

					for (int j = 0; j < s.length() && s[0] == ' '; j++) {

						s.erase(0, 1);
					}

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

					for (int j = 0; j < s.length() && s[0] == ' '; j++) {

						s.erase(0, 1);
					}


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

					for (int j = 0; j < s.length() && s[0] == ' '; j++) {

						s.erase(0, 1);
					}

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

					for (int j = 0; j < s.length() && s[0] == ' '; j++) {

						s.erase(0, 1);
					}


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
	//ULDebug("Das einlesen der Fragen war von Erfolg gekrönt.");
	//ULDebug("Laenge der Map ist:  %i",map_fragen.size());
	iZuStellendeFrage = std::rand() % map_fragen.size()-1; 


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

bool CFragenHandler::IstAntwortRichtig(int i){

	return i == iRichtigeAntwort ;

}

string CFragenHandler::GetRichtigeAntwort() {

	return map_fragen[iZuStellendeFrage - 1]->getAntwort();

}


void CFragenHandler::insertTextFrage() {

	

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

	//switch (i) {

	//	case 0: topFrage.Write(Textfrage.getFrage());
	//			tger->SwitchOn(); 
	//			i++;
	//			break;

	//	case 1: if (!tger->IsOn()) {

	//		if (Textfrage.vergleicheAntwort(tger->GetString())) { rifalsch = "richtig"; i++; break; }
	//		else {
	//			rifalsch = "falsch, richtig ist " + Textfrage.sAntwort; i++; break;

	//			

	//		}
	//		

	//	}
	//			else {
	//				topAntwort.Write(tger->GetString());

	//			}
	//			break; 

	//	case 2 : topAntwort.Write(rifalsch);

	//	
	//		break; 
	//default:
	//	break;
	//}

}

void CFragenHandler::BereiteFragevor() {



	while (!map_fragen.count(iZuStellendeFrage)) {
		iZuStellendeFrage++;
		if (iZuStellendeFrage > 10000) {
			iZuStellendeFrage = 0; 
		}
	}

	std::string s = map_fragen[iZuStellendeFrage]->getFrage();
	topFrage.SetString(s);

	//for (int i = 0; i < 3; i++) {

	//	std::string s = map_fragen[iZuStellendeFrage]->getFalscheAntwort(i);
	//	topFalscheAntworten[i].SetString(s);

	//}

	iRichtigeAntwort = rand() % 4; 

	int j = 0; 

	for (int i = 0; i < 4; i++) {

		if (i == iRichtigeAntwort) {
			topAntwortmoegl[i].SetString(map_fragen[iZuStellendeFrage]->getAntwort());
		}
		else {
			topAntwortmoegl[i].SetString(map_fragen[iZuStellendeFrage]->getFalscheAntwort(j)); 
			j++;
		}


	}


	//topAntwort.SetString(map_fragen[iZuStellendeFrage]->getAntwort());
	topFrage.SwitchOn();


	iZuStellendeFrage++;

}


void CFragenHandler::SetStelleFrage(bool b) {

	if (!b) {
		bDoFadeOut = true;
		topFrage.SwitchOff(); 
		
		for (int i = 0; i < 4; i++){
			topAntwortmoegl[i].SwitchOff();
		}

		bFadeOutbeendet = false;
		ULDebug("StelleFrage");
		
	}
	else{
		SwitchOn();
		bFadeOutbeendet = false;

	}

	bStelleFragen = b; 

}

bool CFragenHandler::FadeOutBeendet(){
	return bFadeOutbeendet;
}


void CFragenHandler::bereiteFragenMapVor() {

	bool bLernpaketVorhanden; 

	MAP_sii::iterator it; 
	it = map_ProfilHandlerLernpakete->find(sLernpaketname);

	if (it != map_ProfilHandlerLernpakete->end()) {
		bLernpaketVorhanden = true; 
	}
	else {
		bLernpaketVorhanden = false; 
	}
}

void CFragenHandler::SwitchOn(){

	topFrage.SwitchOn(); 
	for (int i = 0; i < 4; i++){
		topAntwortmoegl[i].SwitchOn(); 
	}



}


void CFragenHandler::SwitchOff(){
	topFrage.SwitchOff();
	for (int i = 0; i < 4; i++){
		topAntwortmoegl[i].SwitchOff();
	}


}

void CFragenHandler::floatArraysNew() {

	fyWerteDown[0] = -0.1F;
	fyWerteDown[1] = 0.8F;
	fyWerteDown[2] = 0.8F;
	fyWerteDown[3] = 0.9F;
	fyWerteDown[4] = 0.9F;

	fyWerteUp[0] = 0.026F;
	fyWerteUp[1] = 1.1F;
	fyWerteUp[2] = 1.1F;
	fyWerteUp[3] = 1.2F;
	fyWerteUp[4] = 1.2F;

}