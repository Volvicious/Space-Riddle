#include "Explorer.h"




CExplorer::CExplorer()
{

}


CExplorer::~CExplorer()
{
	
}


void CExplorer::Init(CViewport * m_zv, CMaus * ptrMaus_, CFileHandler * filehandlerPtr, char * caHintergrundBildPfad, char * caIconBildPfad, char * caOrdnerPfad) {

	iTyp = 0; 

	filefinder = filehandlerPtr->GetFileFinderPtr();
	ptrfilehandler = filehandlerPtr;

	ptrMaus = ptrMaus_;
	
	m_zoExplorer.SetLayer(0.9F); 

	//Wird immer erzeugt.

	m_ziMainmbackground.Init(caHintergrundBildPfad);


//	m_zoMainmbackground.InitFull(&m_ziMainmbackground);
	m_zoMainmbackground.InitFull("textures//explorer//menubild_lernpaketexplorer.jpg");

	m_zoExplorer.AddOverlay(&m_zoMainmbackground);
	m_zoMainmbackground.SetLayer(0.8F);

	m_zv->AddOverlay(&m_zoExplorer);

	//m_ziTextIcon.Init("textures\\TextIcon.gif"),
	m_ziTextIcon.Init(caIconBildPfad);

	// BackButton 
	m_ziBackButton.Init("textures\\Back.gif");
	m_zoBackButton.Init(&m_ziBackButton, CFloatRect(0.78f, 0.85f, 0.15f, 0.06f));
	m_zoExplorer.AddOverlay(&m_zoBackButton);
	m_zoBackButton.SetLayer(0.5);

	//Wird dynamisch erzeugt.

	filefinder->findFiles(caOrdnerPfad);


	float	fZaehler = 0; 
	int		iZaheler = 0; 

	igroesseArray = filefinder->getFiles()->size();

	aTextOutput = new CTextOutput[igroesseArray];
	aOverlayTextIcon = new COverlay[igroesseArray];


	for (std::set<std::string>::iterator iter = filefinder->getFiles()->begin(); iter != filefinder->getFiles()->end(); ++iter) {

		std::string s = *iter;

		aOverlayTextIcon[iZaheler].Init(&m_ziTextIcon, CFloatRect(0.42F, 0.35F + fZaehler, 0.04F, 0.05F), true);
		aOverlayTextIcon[iZaheler].SetLayer(0.5F);

		m_zoExplorer.AddOverlay(&aOverlayTextIcon[iZaheler]);


		for (int i = s.size(); i != 0; i--) { //Schneidet .txt weg

			if (s[i] == '.') {

				s.erase(i, s.size() - i);
			}
		}

		aTextOutput[iZaheler].Init(&aOverlayTextIcon[iZaheler], "fonts\\Nasalization-rg-Red.png", 0.05F, 0.00F, 2.5F, .06F); //Writing wird an das txt Icon angeh�ngt.
		aTextOutput[iZaheler].SetString(s);
		

		iZaheler++;
		fZaehler += 0.08F;

	}

	m_zoExplorer.SwitchOff();

}

//Explorer mit Eingabe Funktion.
void CExplorer::Init(CViewport * m_zv, CMaus * ptrMaus_, CFileHandler * filehandlerPtr, char * caHintergrundBildPfad, char * caIconBildPfad, char * caOrdnerPfad, CDeviceKeyboard * ptrdk) {

	iTyp = 1;
	bTastaturStarted = false; 

	filefinder = filehandlerPtr->GetFileFinderPtr();
	ptrfilehandler = filehandlerPtr;
	TastaturGer.Init(ptrdk, 9999, false);

	ptrMaus = ptrMaus_;

	m_zoExplorer.SetLayer(0.9F);

	topNamenEingabe.Init(&m_zoExplorer, "fonts\\Nasalization-rg-Red.png", 0.421F, 0.315F, 2.15F, 0.08F);

	//Wird immer erzeugt.

	m_ziMainmbackground.Init(caHintergrundBildPfad);

	m_zmMainmbackground.MakeTextureSprite("textures//explorer//menubild_profilmanager.jpg");
	m_zmMainmbackground.SetTransparencyOn();

	m_zoMainmbackground.InitFull(&m_zmMainmbackground);

	m_zoExplorer.AddOverlay(&m_zoMainmbackground);
	m_zoMainmbackground.SetLayer(0.8F);

	m_zv->AddOverlay(&m_zoExplorer);

	m_ziTextIcon.Init(caIconBildPfad);

	// BackButton 
	m_ziBackButton.Init("textures\\Back.gif");
	m_zoBackButton.Init(&m_ziBackButton, CFloatRect(0.78f, 0.85f, 0.15f, 0.06f));
	m_zoExplorer.AddOverlay(&m_zoBackButton);
	m_zoBackButton.SetLayer(0.5);

	//Wird dynamisch erzeugt.

	filefinder->findFiles(caOrdnerPfad);


	float	fZaehler = 0;
	int		iZaheler = 0;

	igroesseArray = filefinder->getFiles()->size();

	aTextOutput = new CTextOutput[igroesseArray];
	aOverlayTextIcon = new COverlay[igroesseArray];


	for (std::set<std::string>::iterator iter = filefinder->getFiles()->begin(); iter != filefinder->getFiles()->end(); ++iter) {

		std::string s = *iter;

		aOverlayTextIcon[iZaheler].Init(&m_ziTextIcon, CFloatRect(0.42F, 0.5F + fZaehler, 0.04F, 0.05F), true);
		aOverlayTextIcon[iZaheler].SetLayer(0.5F);

		m_zoExplorer.AddOverlay(&aOverlayTextIcon[iZaheler]);


		for (int i = s.size(); i != 0; i--) { //Schneidet .txt weg

			if (s[i] == '.') {

				s.erase(i, s.size() - i);
			}
		}

		aTextOutput[iZaheler].Init(&aOverlayTextIcon[iZaheler], "fonts\\Nasalization-rg-Red.png", 0.05F, 0.00F, 2.5F, .06F); //Writing wird an das txt Icon angeh�ngt.
		aTextOutput[iZaheler].SetString(s);


		iZaheler++;
		fZaehler += 0.08F;

	}

	m_zoExplorer.SwitchOff();

}

void CExplorer::Run() {
	

	if (bOn){

		if (iTyp == 1){

			//m_zoMainmbackground.SetTransparency(fTransp);
			m_zoMainmbackground.m_pmaterial->SetTransparency(0.8f);
			m_zmMainmbackground.SetTransparency(0.8f);
			
			fTransp += 0.05F; 
			
			//ptrTastatur->Run(); 
			TastaturGer.Run(); 
			if (TastaturGer.GetString() != ""){
				topNamenEingabe.SetString(TastaturGer.GetString());

			}
			else{
				topNamenEingabe.SetString("Name eingeben oder w�hlen.");
			}
			topNamenEingabe.WriteSavedString();

		}

		for (int i = 0; i < igroesseArray; i++) {

			aTextOutput[i].WriteSavedString();
		}


		for (int i = 0; i < igroesseArray; i++) {

			if (ptrMaus->PickOverlayandLeftKlick(&aOverlayTextIcon[i]) || ptrMaus->PickOverlayOrWritingandLeftKlick(aTextOutput[i].getWritingPtr())) {

				std::set<std::string>::iterator iter = filefinder->getFiles()->begin();

				for (int j = 0; j < i; j++) {
					iter++;
				}

				std::string s = *iter;

				ptrfilehandler->setSelectedFileandPath(s);

				bmakeMenueOn = true;
				SwitchOff();
				break;
			}
		}

		if (iTyp == 1 && !TastaturGer.IsOn()){

			std::string tastaturStringMitTxt = ""; 
			tastaturStringMitTxt += TastaturGer.GetString();
			tastaturStringMitTxt += ".txt";
			ptrfilehandler->setSelectedFileandPath(tastaturStringMitTxt);

			//ptrfilehandler->GetFileFinderPtr()->getFiles(); 

			std::string tempStringAllesKlein = tastaturStringMitTxt; 

			
			bool bFileExistiert = false; 
			for (std::set <std::string>::iterator it = filefinder->getFiles()->begin(); it != filefinder->getFiles()->end(); ++it){

				if (stc.MachAllesKlein(tastaturStringMitTxt) == stc.MachAllesKlein(*it)){

					ptrfilehandler->setSelectedFileandPath(TastaturGer.GetString());
					bFileExistiert = true; 
					break; 
				}
			}

			if (!bFileExistiert){

				ptrfilehandler->setSelectedFileandPath(tastaturStringMitTxt);
				ptrfilehandler->SetDoNewFile(true);
				ULDebug("Neues File muss angelegt werden.");
			}


			bmakeMenueOn = true; 
			SwitchOff();

		}


		if (ptrMaus->PickOverlayandLeftKlick(&m_zoBackButton)){
			ULDebug("Ich bin hier drin, in der Backzeile!");
			m_zoExplorer.SwitchOff();
			bmakeMenueOn = true;

		}

	}

}

void CExplorer::SwitchOn() {

	m_zoExplorer.SwitchOn();
	ptrMaus->SwitchOff();
	ptrMaus->SwitchOn();
	bOn = true;
	//
	
	if (iTyp == 1) {

		TastaturGer.SwitchOn();
		TastaturGer.SetString("");
		topNamenEingabe.SetString("Name eingeben oder w�hlen.");

	}
		
}

void CExplorer::SwitchOff() {
	m_zoExplorer.SwitchOff();
	bOn = false; 
}



bool CExplorer::getMakeMenuOn(){

	return bmakeMenueOn;
}

void CExplorer::setMakeMenuOn(bool b){

	bmakeMenueOn = b; 

}




CFileHandler *  CExplorer::getFileHandlerPtr(){

	return ptrfilehandler;

}

