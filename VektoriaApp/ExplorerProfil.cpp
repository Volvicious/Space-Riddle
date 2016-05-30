#include "ExplorerProfil.h"




CExplorerProfil::CExplorerProfil()
{

}


CExplorerProfil::~CExplorerProfil()
{

}


void CExplorerProfil::Init(CViewport * m_zv, CMaus * ptrMaus_, CFileHandler * filehandlerPtr) {

	filefinder = filehandlerPtr->GetFileFinderPtr();
	ptrfilehandler = filehandlerPtr;


	ptrMaus = ptrMaus_;

	m_zoExplorer.SetLayer(0.9F);

	//Wird immer erzeugt.


	m_ziMainmbackground.Init("textures\\menubild_explorer_profil.jpg");
	m_zoMainmbackground.InitFull(&m_ziMainmbackground);

	m_zoExplorer.AddOverlay(&m_zoMainmbackground);
	m_zoMainmbackground.SetLayer(0.8F);

	m_zv->AddOverlay(&m_zoExplorer);



	m_ziTextIcon.Init("textures\\TextIcon.gif"),

		// BackButton 


		m_ziBackButton.Init("textures\\Back.gif");
	m_zoBackButton.Init(&m_ziBackButton, CFloatRect(0.78f, 0.85f, 0.15f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoBackButton);
	m_zoBackButton.SetLayer(0.8);




	//Wird dynamisch erzeugt.



	filefinder->findFiles("..\\VektoriaApp\\fragen");

	float	fZaehler = 0;
	int		iZaheler = 0;

	igroesseArray = filefinder->getFiles()->size();

	aTextOutput = new CTextOutput[igroesseArray];
	aOverlayTextIcon = new COverlay[igroesseArray];



	for (std::set<std::string>::iterator iter = filefinder->getFiles()->begin(); iter != filefinder->getFiles()->end(); ++iter) {

		std::string s = *iter;

		aOverlayTextIcon[iZaheler].Init(&m_ziTextIcon, CFloatRect(0.4F, 0.25F + fZaehler, 0.04F, 0.05F), true);
		aOverlayTextIcon[iZaheler].SetLayer(0.5F);

		m_zoExplorer.AddOverlay(&aOverlayTextIcon[iZaheler]);

		aTextOutput[iZaheler].Init(&aOverlayTextIcon[iZaheler], "fonts\\LucidaConsoleWhiteF.png", 0.05F, 0.020F, 1.0F, .02F); //Writing wird an das txt Icon angehängt.
		aTextOutput[iZaheler].SetString(s);


		iZaheler++;
		fZaehler += 0.05F;


	}

	m_zoExplorer.SwitchOff();

}

void CExplorerProfil::SwitchOn() {

	m_zoExplorer.SwitchOn();
	ptrMaus->SwitchOff();
	ptrMaus->SwitchOn();
	bOn = true;
}

void CExplorerProfil::SwitchOff() {
	m_zoExplorer.SwitchOff();
	bOn = false;
}

void CExplorerProfil::Run() {




	if (bOn){
		//m_zoCursorPtr->SwitchOff(); 


		//float fx, fy;
		//m_zdCursorPtr->GetFractional(fx, fy, true);
		//m_zoCursorPtr->SetRect(CFloatRect(fx - 0.01F, fy - 0.01F, 0.04F, 0.04F));

		for (int i = 0; i < igroesseArray; i++) {

			aTextOutput[i].WriteSavedString();

		}


		for (int i = 0; i < igroesseArray; i++) {

			if (ptrMaus->PickOverlayandLeftKlick(&aOverlayTextIcon[i]) || ptrMaus->PickOverlayOrWritingandLeftKlick(aTextOutput[i].getWritingPtr())) {


				std::string s = aTextOutput[i].GetString();


				ptrfilehandler->setSelectedFileandPath(s);

				//m_zoExplorer.SwitchOff(); 
				//aOverlayTextIcon[i].SwitchOff();

				char tab2[1024];
				strcpy(tab2, s.c_str());
				ULDebug(tab2);


				SwitchOff();


				break;
			}

		}


		//m_zoCursorPtr->SwitchOn(); 
	}




}