#include "Mainmenu.h"




void CMainmenu::menuInit(CViewport * m_zv, CMaus * ptrMaus_, CExplorer * ptrExplorer_, CExplorer * ptrExplorerprof_, CProfilHandler * ptrProfilhandler)
{
	ptrExplorer = ptrExplorer_; //Lernpakete
	ptrExplorerProfil = ptrExplorerprof_; //Name festlegen
	ptrMaus = ptrMaus_;
	ptrProfilHandler = ptrProfilhandler;

	/// ALLES AB HIER IS JULIANS
	
	// TextOutPuts

	m_zTOPProfil.Init(m_zv, "fonts\\Nasalization-rg-Red.png", 0.115F, 0.045F, 1.2F, .03F);
	m_zTOPProfil.SetString("nicht ausgewählt");

	m_zTOPLernpaket.Init(m_zv, "fonts\\Nasalization-rg-Red.png", 0.18F, 0.13F, 1.2F, .03F);
	m_zTOPLernpaket.SetString("nicht ausgewählt");




	// Hauptmenü
	m_ziMainmbackground.Init("textures\\menubild.jpg");
	m_zoMainmbackground.InitFull(&m_ziMainmbackground);
	m_zv->AddOverlay(&m_zoMainmbackground);
	m_zoMainmbackground.SetLayer(0.9F);
	

	//Steuerungbackground
	m_ziSteuerungBackground.Init("textures\\menubild_steuerung.jpg");
	m_zoSteuerungBackground.InitFull(&m_ziSteuerungBackground);
	m_zv->AddOverlay(&m_zoSteuerungBackground);
	m_zoSteuerungBackground.SetLayer(0.91F);
	m_zoSteuerungBackground.SwitchOff();
	

	//Optionsbackground
	m_ziOptionsBackground.Init("textures\\menubild_Optionen.jpg");
	m_zoOptionsBackground.InitFull(&m_ziOptionsBackground);
	m_zv->AddOverlay(&m_zoOptionsBackground);
	m_zoOptionsBackground.SetLayer(0.91F);
	m_zoOptionsBackground.SwitchOff();

	//Highscorebackground
	m_ziHighscoreBackground.Init("textures\\menubild_Highscore.jpg");
	m_zoHighscoreBackground.InitFull(&m_ziHighscoreBackground);
	m_zv->AddOverlay(&m_zoHighscoreBackground);
	m_zoHighscoreBackground.SetLayer(0.91F);
	m_zoHighscoreBackground.SwitchOff();
	

	//PickName
	m_zmName.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoName.Init(&m_zmName, CFloatRect(0.41f, 0.241f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoName);
	m_zoName.SetTransparency(0.5);
	
	

	////Picklernpacket
	 m_zmLernPaket.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	 m_zoLernPaket.Init(&m_zmLernPaket, CFloatRect(0.41f, 0.36f, 0.4f, 0.06f));
	 m_zoMainmbackground.AddOverlay(&m_zoLernPaket);
	 m_zmLernPaket.SetTransparency(0.5);




	////Pickeinstellung
	m_zmEinstellung.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoEinstellung.Init(&m_zmEinstellung, CFloatRect(0.41f, 0.480f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoEinstellung);
	m_zoEinstellung.SetTransparency(0.5F);


	//////Picksteuerung
	m_zmSteuerung.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoSteuerung.Init(&m_zmSteuerung, CFloatRect(0.41f, 0.602f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoSteuerung);
	m_zoSteuerung.SetTransparency(0.5F);


	//////PickHighscore
	m_zmHiscore.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoHighscore.Init(&m_zmHiscore, CFloatRect(0.41f, 0.718f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoHighscore);
	m_zoHighscore.SetTransparency(0.5F);



	//////Pickexit 
	m_zmExit.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoExit.Init(&m_zmExit, CFloatRect(0.41f, 0.84f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoExit);
	m_zoExit.SetTransparency(0.5F);

	// GoButton


	m_ziGoButton.Init("textures\\GoButton.png");
	m_zoGoButton.Init(&m_ziGoButton, CFloatRect(0.9f, 0.3f, 0.08f, 0.08f));
	m_zoMainmbackground.AddOverlay(&m_zoGoButton);
	m_zoGoButton.SetLayer(0.6F);
	m_zoGoButton.SetTransparency(0.3F);
	

	m_zoMainmbackground.SwitchOff(); 

}


bool CMainmenu::getbGo() {
	return bGo;
}

void CMainmenu::menuTick()
{

	if (ptrExplorer->getMakeMenuOn()){
		m_zoMainmbackground.SwitchOn();

		std::string s = ptrExplorer->getFileHandlerPtr()->getSelectedFileDisplayName();
		if (s != ""){
			m_zTOPLernpaket.SetString(s);
			bLernpaket = true;
		}
		ptrExplorer->setMakeMenuOn(false); 
	}

	if (ptrExplorerProfil->getMakeMenuOn()){
		m_zoMainmbackground.SwitchOn();

		std::string s = ptrExplorerProfil->getFileHandlerPtr()->getSelectedFileDisplayName();
		if (s != "") {
			m_zTOPProfil.SetString(s);
			bProfil = true;
		}
		ptrExplorerProfil->setMakeMenuOn(false);
	}

	m_zTOPLernpaket.WriteSavedString();
	m_zTOPProfil.WriteSavedString(); 

	//------------------------------------------------------------------------------------------------------------------------------------
	//Voreinstellung für die Auswahl des Aktuellen Menüpunktes

	m_zoName.SwitchOn();
	m_zoEinstellung.SwitchOn();
	m_zoHighscore.SwitchOn();
	m_zoLernPaket.SwitchOn();
	m_zoExit.SwitchOn();
	m_zoSteuerung.SwitchOn();
	
	

	// Pick Name
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoName))
	{
		ULDebug("Bin hier drin: 1!!!");
		m_zoMainmbackground.SwitchOff();
		ptrExplorerProfil->SwitchOn();

		//m_zoEinstellung.SwitchOff();
		
		// Funktion um Name einzutragen

	}

	// Pick LernPaket
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoLernPaket))
	{
		if (ptrProfilHandler->IsFileLoaded()) {

			m_zoMainmbackground.SwitchOff();
			ptrExplorer->SwitchOn();

			// Funktion um Lernpacket auszuwählen

		}
		else {
			ULDebug("Noch kein Profil gewählt!");

		}
	}



	//Pick Einstellung
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoEinstellung))
	{	
		m_zoMainmbackground.SwitchOff();
		m_zoOptionsBackground.SwitchOn();
		
		ULDebug("Bin hier drin: 3!!!");
		
		// Menü der Einstellungen

	}

	//Pick Steuerung
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoSteuerung))
	{
		ULDebug("Bin hier drin: 4!!!");
		m_zoMainmbackground.SwitchOff();
		m_zoSteuerungBackground.SwitchOn();

	}


	//Pick Hiscore
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoHighscore))
	{
		m_zoMainmbackground.SwitchOff();
		m_zoHighscoreBackground.SwitchOn();
		ULDebug("Bin hier drin: 5!!!");
		// Auflistung Hiscore
		// Erstmal nur Template, rest wird mit CWRiting erstellt

	}

	


	// Pick Exit
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoExit))
	{
		ULDebug("Bin hier drin: 6!!!");
	

	}


	//Pick Go
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoGoButton))
	{
		
		if (bLernpaket) {

			bGo = true;
			m_zoMainmbackground.SwitchOff();
			ULDebug("Go Button");
		}

		

	}



	// Pick Back

	if (ptrMaus->PickOverlayandLeftKlick(&m_zoBackButton))
	{
		ptrExplorer->SwitchOff();
		m_zoMainmbackground.SwitchOn();
		m_zoSteuerungBackground.SwitchOff();
		ULDebug("Bin hier drin: 8!!!");

	}
//------------------------------------------------------------------------------------------------------------------------------------

// In diesem Teil wird geregelt, welche Auswahl aktuell ausgewählt wird


	// Auswahl Exit
	if (!ptrMaus->PickOverlay(&m_zoName ))
	{
		m_zoName.SwitchOff();

	}

	// Auswahl Exit
	if (!ptrMaus->PickOverlay(&m_zoLernPaket  ))
	{

		m_zoLernPaket.SwitchOff();

	}



	// Auswahl Exit
	if (!ptrMaus->PickOverlay(&m_zoEinstellung ))
	{

		m_zoEinstellung.SwitchOff();

	}

	// Auswahl Exit
	if (!ptrMaus->PickOverlay(&m_zoSteuerung))
	{
		m_zoSteuerung.SwitchOff();

	}


	// Auswahl Exit
	if (!ptrMaus->PickOverlay(&m_zoHighscore ))
	{
		m_zoHighscore.SwitchOff();

	}




	// Auswahl Exit
	if (!ptrMaus->PickOverlay(&m_zoExit))
	{
		m_zoExit.SwitchOff();

	}


}


void CMainmenu::SwitchOn() {

	m_zoMainmbackground.SwitchOn();
	ptrMaus->SwitchOn(); 

}

void CMainmenu::SwitchOff() {

	m_zoMainmbackground.SwitchOff();

}

//CDeviceCursor * CMainmenu::GetCursorPtr() {
//
//	return &m_zdCursor;
//
//}
//
//COverlay * CMainmenu::GetCursorOverPtr() {
//
//	return &m_zoCurser;
//
//}