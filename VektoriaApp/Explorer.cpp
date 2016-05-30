#include "Explorer.h"




CExplorer::CExplorer()
{

}


CExplorer::~CExplorer()
{
	
}


void CExplorer::Init(CViewport * m_zv, CMaus * ptrMaus_, CFileHandler * filehandlerPtr, char * caHintergrundBildPfad, char * caIconBildPfad, char * caOrdnerPfad) {

	filefinder = filehandlerPtr->GetFileFinderPtr();
	ptrfilehandler = filehandlerPtr;
	

	ptrMaus = ptrMaus_;
	
	m_zoExplorer.SetLayer(0.9F); 

	//Wird immer erzeugt.


	//m_ziMainmbackground.Init("textures\\menubild_lernpaketexplorer.jpg");
	m_ziMainmbackground.Init(caHintergrundBildPfad);


	m_zoMainmbackground.InitFull(&m_ziMainmbackground);

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

		 
	
	//filefinder->findFiles("..\\VektoriaApp\\fragen");
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

		

		aTextOutput[iZaheler].Init(&aOverlayTextIcon[iZaheler], "fonts\\Nasalization-rg-White.png", 0.05F, 0.00F, 2.5F, .06F); //Writing wird an das txt Icon angehängt.
		aTextOutput[iZaheler].SetString(s);
		

		iZaheler++;
		fZaehler += 0.08F;

	
	}

	m_zoExplorer.SwitchOff();

}

void CExplorer::SwitchOn() {

	m_zoExplorer.SwitchOn();
	ptrMaus->SwitchOff();
	ptrMaus->SwitchOn();
	bOn = true; 
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

void CExplorer::Run() {


	if (bOn){

		for (int i = 0; i < igroesseArray; i++) {
			
			aTextOutput[i].WriteSavedString();
		}


		for (int i = 0; i < igroesseArray; i++) {

			if ( ptrMaus->PickOverlayandLeftKlick(&aOverlayTextIcon[i]) || ptrMaus->PickOverlayOrWritingandLeftKlick(aTextOutput[i].getWritingPtr()) ) {


				//std::string s = aTextOutput[i].GetString();

				std::set<std::string>::iterator iter = filefinder->getFiles()->begin();

				for (int j = 0; j < i; j++) {
					iter++;
				}

				std::string s = *iter; 


			
				ptrfilehandler->setSelectedFileandPath(s);
				

				//m_zoExplorer.SwitchOff(); 
				//aOverlayTextIcon[i].SwitchOff();

				char tab2[1024];
				strcpy(tab2, s.c_str());
				ULDebug(tab2);
				
				bmakeMenueOn = true;
				SwitchOff();
				

				break;
			}

		}

	

		if (ptrMaus->PickOverlayandLeftKlick(&m_zoBackButton)){
			ULDebug("Ich bin hier drin, in der Backzeile!");
			m_zoExplorer.SwitchOff();
			bmakeMenueOn = true;

		}

	}


	


}