#include "Mainmenu.h"




void CMainmenu::menuInit(CViewport * m_zv, CMaus * ptrMaus_,
	CExplorer * ptrExplorer_, CExplorer * ptrExplorerprof_,
	CProfilHandler * ptrProfilhandler, CHighscore * ptrHighscore,
	CSound * ptrsound)
{
	ptrExplorer = ptrExplorer_; //Lernpakete
	ptrExplorerProfil = ptrExplorerprof_; //Name festlegen
	ptrMaus = ptrMaus_;
	ptrProfilHandler = ptrProfilhandler;
	ptrHighScore = ptrHighscore; 
	ptrSound = ptrsound;

	/// ALLES AB HIER IS JULIANS

	////Maus 
	//m_ziCurser.Init("textures\\cursor.gif");
	//m_zoCurser.Init(&m_ziCurser, CFloatRect(0.5F, 0.5F, 0.02F, 0.02F),true);
	//m_zf->AddDeviceCursor(&m_zdCursor);
	//m_zv->AddOverlay(&m_zoCurser);
	//m_zoCurser.SetLayer(0.4);


	//Backbutton

	// Hauptmen�
	m_ziMainmbackground.Init("textures\\menubild.jpg");
	m_zoMainmbackground.InitFull(&m_ziMainmbackground);
	m_zv->AddOverlay(&m_zoMainmbackground);
	m_zoMainmbackground.SetLayer(0.9F);

	overlays.push_back(&m_zoMainmbackground);

	//Steuerungbackground
	m_ziSteuerungBackground.Init("textures\\menubild_steuerung.jpg");
	m_zoSteuerungBackground.InitFull(&m_ziSteuerungBackground);
	m_zv->AddOverlay(&m_zoSteuerungBackground);
	m_zoSteuerungBackground.SetLayer(0.91F);
	m_zoSteuerungBackground.SwitchOff();

	overlays.push_back(&m_zoSteuerungBackground);


	//Optionsbackground
	m_ziOptionsBackground.Init("textures\\menubild_Optionen.jpg");
	m_zoOptionsBackground.InitFull(&m_ziOptionsBackground);
	m_zv->AddOverlay(&m_zoOptionsBackground);
	m_zoOptionsBackground.SetLayer(0.91F);
	m_zoOptionsBackground.SwitchOff();

	overlays.push_back(&m_zoOptionsBackground);


	//Highscorebackground
	m_ziHighscoreBackground.Init("textures\\menubild_Highscore.jpg");
	m_zoHighscoreBackground.InitFull(&m_ziHighscoreBackground);
	m_zv->AddOverlay(&m_zoHighscoreBackground);
	m_zoHighscoreBackground.SetLayer(0.91F);
	m_zoHighscoreBackground.SwitchOff();

	overlays.push_back(&m_zoHighscoreBackground);


	//PickName
	m_zmName.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoName.Init(&m_zmName, CFloatRect(0.41f, 0.241f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoName);
	m_zoName.SetTransparency(0.5F);
	m_zoName.SetLayer(0.4F);

	overlays.push_back(&m_zoName);



	////Picklernpacket
	m_zmLernPaket.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoLernPaket.Init(&m_zmLernPaket, CFloatRect(0.41f, 0.36f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoLernPaket);
	m_zmLernPaket.SetTransparency(0.5F);


	overlays.push_back(&m_zoLernPaket);



	////Pickeinstellung
	m_zmEinstellung.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoEinstellung.Init(&m_zmEinstellung, CFloatRect(0.41f, 0.480f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoEinstellung);
	m_zoEinstellung.SetTransparency(0.5F);
	m_zoEinstellung.SetLayer(0.4F);

	overlays.push_back(&m_zoEinstellung);


	//////Picksteuerung
	m_zmSteuerung.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoSteuerung.Init(&m_zmSteuerung, CFloatRect(0.41f, 0.602f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoSteuerung);
	m_zoSteuerung.SetTransparency(0.5F);
	m_zoSteuerung.SetLayer(0.4F);

	overlays.push_back(&m_zoSteuerung);


	//////PickHighscore
	m_zmHiscore.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoHighscore.Init(&m_zmHiscore, CFloatRect(0.41f, 0.718f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoHighscore);
	m_zoHighscore.SetTransparency(0.5F);
	m_zoPickHighscore.SetLayer(0.4F);

	overlays.push_back(&m_zoHighscore);



	//////Pickexit 
	m_zmExit.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoExit.Init(&m_zmExit, CFloatRect(0.41f, 0.84f, 0.4f, 0.06f));
	m_zoMainmbackground.AddOverlay(&m_zoExit);
	m_zoExit.SetTransparency(0.5F);
	m_zoExit.SetLayer(0.4F);

	overlays.push_back(&m_zoExit);


	/////////Picksetting f�r Einstellungen
	//Pick Antialising on
	m_zmPickAntianilisingOn.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoPickAntianilisingOn.Init(&m_zmPickAntianilisingOn, CFloatRect(0.67f, 0.46f, 0.05f, 0.06f));
	m_zoOptionsBackground.AddOverlay(&m_zoPickAntianilisingOn);
	m_zoPickAntianilisingOn.SetTransparency(0.5F);

	overlays.push_back(&m_zoPickAntianilisingOn);


	//Pick Antialising Off
	m_zmPickAntianilisingOff.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoPickAntianilisingOff.Init(&m_zmPickAntianilisingOff, CFloatRect(0.79f, 0.46f, 0.05f, 0.06f));
	m_zoOptionsBackground.AddOverlay(&m_zoPickAntianilisingOff);
	m_zoPickAntianilisingOff.SetTransparency(0.5F);
	m_zoPickAntianilisingOff.SwitchOff();

	overlays.push_back(&m_zoPickAntianilisingOff);




	//PickTonAn
	m_zmPickTonAn.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoPickTonAn.Init(&m_zmPickTonAn, CFloatRect(0.67f, 0.36f, 0.05f, 0.06f));
	m_zoOptionsBackground.AddOverlay(&m_zoPickTonAn);
	m_zoPickTonAn.SetTransparency(0.5F);
	m_zoPickTonAn.SwitchOn();

	overlays.push_back(&m_zoPickTonAn);



	//PickTonAus
	m_zmPickTonAus.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoPickTonAus.Init(&m_zmPickTonAus, CFloatRect(0.79f, 0.36f, 0.05f, 0.06f));
	m_zoOptionsBackground.AddOverlay(&m_zoPickTonAus);
	m_zoPickTonAus.SetTransparency(0.5F);
	m_zoPickTonAus.SwitchOff();

	overlays.push_back(&m_zoPickTonAus);



	//PickWindow
	m_zmPickWindowScreen.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoPickWindowScreen.Init(&m_zmPickWindowScreen, CFloatRect(0.463f, 0.64f, 0.1f, 0.06f));
	m_zoOptionsBackground.AddOverlay(&m_zoPickWindowScreen);
	m_zoPickWindowScreen.SetTransparency(0.5F);
	m_zoPickWindowScreen.SwitchOff();

	overlays.push_back(&m_zoPickWindowScreen);


	//PickFullscreen
	m_zmPickFullScreen.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoPickFullScreen.Init(&m_zmPickFullScreen, CFloatRect(0.63f, 0.64f, 0.14f, 0.06f));
	m_zoOptionsBackground.AddOverlay(&m_zoPickFullScreen);
	m_zoPickFullScreen.SetTransparency(0.5F);

	overlays.push_back(&m_zoPickFullScreen);



	//Pick Hiscore l�schen
	m_zmPickHighscore.MakeTextureDiffuse("textures\\MenuAuswahl.gif");
	m_zoPickHighscore.Init(&m_zmPickHighscore, CFloatRect(0.45f, 0.75f, 0.35f, 0.06f));
	m_zoOptionsBackground.AddOverlay(&m_zoPickHighscore);
	m_zoPickHighscore.SetTransparency(0.5F);
	m_zoPickHighscore.SwitchOn();

	overlays.push_back(&m_zoPickHighscore);


	// GoButton


	m_ziGoButton.Init("textures\\GoButton.png");
	m_zoGoButton.Init(&m_ziGoButton, CFloatRect(0.9f, 0.3f, 0.08f, 0.08f));
	m_zoMainmbackground.AddOverlay(&m_zoGoButton);
	m_zoGoButton.SetLayer(0.3F);
	m_zoGoButton.SetTransparency(0.3F);

	overlays.push_back(&m_zoGoButton);


	// TextOutPuts

	m_zTOPProfil.Init(&m_zoMainmbackground, "fonts\\Nasalization-rg-Red.png", 0.115F, 0.045F, 1.2F, .03F);
	m_zTOPProfil.SetString("nicht ausgew�hlt");

	m_zTOPLernpaket.Init(&m_zoMainmbackground, "fonts\\Nasalization-rg-Red.png", 0.18F, 0.13F, 1.2F, .03F);
	m_zTOPLernpaket.SetString("nicht ausgew�hlt");

	////Backbutton verkn�pfungen
	//Backbutton f�r einstellungen

	m_ziBackButton2.Init("textures\\Back.gif");
	m_zoBackButton2.Init(&m_ziBackButton2, CFloatRect(0.78f, 0.85f, 0.15f, 0.06f));
	m_zoOptionsBackground.AddOverlay(&m_zoBackButton2);
	m_zoBackButton2.SetLayer(0.5F);
	m_zoBackButton2.SwitchOn();

	overlays.push_back(&m_zoBackButton2);


	//Backbutton f�r Steuerung

	m_ziBackButton2.Init("textures\\Back.gif");
	m_zoBackButton2.Init(&m_ziBackButton2, CFloatRect(0.78f, 0.85f, 0.15f, 0.06f));
	m_zoSteuerungBackground.AddOverlay(&m_zoBackButton2);
	m_zoBackButton2.SetLayer(0.5);

	//Backbutton f�r Hiscore

	m_ziBackButton2.Init("textures\\Back.gif");
	m_zoBackButton2.Init(&m_ziBackButton2, CFloatRect(0.78f, 0.85f, 0.15f, 0.06f));
	m_zoHighscoreBackground.AddOverlay(&m_zoBackButton2);
	m_zoBackButton2.SetLayer(0.5);

	//Credits
	m_ziCredits.Init("textures\\Credits.png");
	m_zoCredits.Init(&m_ziCredits, CFloatRect(0.9f, 0.9f, 0.07f, 0.05f));
	m_zoMainmbackground.AddOverlay(&m_zoCredits);
	m_zoCredits.SetTransparency(0.6);
	m_zoCredits.SetLayer(0.6);
	m_zoCredits.SetName("Credits");

	overlays.push_back(&m_zoCredits);



	//Creditsbackground
	m_ziCreditsBackground.Init("textures\\Credits_Background.jpg");
	m_zoCreditsBackground.InitFull(&m_ziCreditsBackground);
	m_zv->AddOverlay(&m_zoCreditsBackground);
	m_zoCreditsBackground.SetLayer(0.89);
	m_zoCreditsBackground.SwitchOff();

	overlays.push_back(&m_zoCreditsBackground);



	//BackButton f�r Credits
	m_ziBackButton3.Init("textures\\Back.gif");
	m_zoBackButton3.Init(&m_ziBackButton3, CFloatRect(0.06f, 0.75f, 0.15f, 0.06f));
	m_zoCreditsBackground.AddOverlay(&m_zoBackButton3);
	m_zoBackButton3.SetLayer(0.5);
	m_zoBackButton3.SetTransparency(0.3);

	overlays.push_back(&m_zoBackButton3);


	SwitchOff(); 
}


bool CMainmenu::getbGo() {
	return bGo; 
}

void CMainmenu::menuTick(){
	

	if (ptrMaus->getDevicePtr()->PickOverlay() && m_zoMainmbackground.IsOn()) {

		bool b = false; 

		for (std::vector<COverlay *>::iterator it = overlays.begin();
		it != overlays.end(); it++) {
			
			if (ptrMaus->getDevicePtr()->PickOverlay() == *it) {
				b = true;
				break; 
			}
		}

		if (!b) {
			ptrMaus->getDevicePtr()->PickOverlay()->SwitchOff();
		}
	}




	if (ptrExplorer->getMakeMenuOn()) {
		SwitchOn();

		std::string s = ptrExplorer->getFileHandlerPtr()->getSelectedFileDisplayName();
		if (s != "") {
			m_zTOPLernpaket.SetString(s);
			bLernpaket = true;
		}
		ptrExplorer->setMakeMenuOn(false);
	}

	if (ptrExplorerProfil->getMakeMenuOn()) {
		SwitchOn();

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
	//Voreinstellung f�r die Auswahl des Aktuellen Men�punktes

	m_zoName.SwitchOn();
	m_zoEinstellung.SwitchOn();
	m_zoHighscore.SwitchOn();
	m_zoLernPaket.SwitchOn();
	m_zoExit.SwitchOn();
	m_zoSteuerung.SwitchOn();
	


	//PickCreits
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoCredits))
	{
		m_zoCreditsBackground.SwitchOn();


		SwitchOff(); 
		ptrMaus->SwitchOn();
		ptrSound->Stop(0);
		ptrSound->Start(10);


	}

	//Highscore Loeschen
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoPickHighscore)) {
		ptrHighScore->Delete();
	}


	// Pick Name
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoName))
	{
		
		m_zoMainmbackground.SwitchOff();
		ptrExplorerProfil->SwitchOn();
		//m_zoEinstellung.SwitchOff();

		// Funktion um Name einzutragen

	}

	// Pick LernPaket
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoLernPaket) && bProfil)
	{
		
		m_zoMainmbackground.SwitchOff();
		ptrExplorer->SwitchOn();

		// Funktion um Lernpacket auszuw�hlen

	}



	//Pick Einstellung
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoEinstellung))
	{
		m_zoMainmbackground.SwitchOff();
		m_zoOptionsBackground.SwitchOn();

		ULDebug("Bin hier drin: 3!!!");

		// Men� der Einstellungen

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
		ptrHighScore->PreRunMenue();
		m_zoHighscoreBackground.SwitchOn();
		bHighscore = true; 
		ULDebug("Bin hier drin: 5!!!");
		
		// Auflistung Hiscore
		// Erstmal nur Template, rest wird mit CWRiting erstellt

	}

	if (bHighscore) {
		ptrHighScore->RunHauptMenue();
		//topTest.WriteSavedString(); 
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
		}



	}


	//PickBack3 - F�r Creditmen�
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoBackButton3))
	{

		ptrSound->Stop(10);
		ptrSound->Start(0);

		m_zoCreditsBackground.SwitchOff();

		SwitchOn();
		/*m_zoMainmbackground.SwitchOn();
		m_zoCredits.SwitchOn();
		m_zoGoButton.SwitchOn();
		m_zTOPLernpaket.SwitchOn();
		m_zTOPProfil.SwitchOn();*/

	}


	//PickBack2 - F�r Alles Andere
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoBackButton2))
	{

		m_zoOptionsBackground.SwitchOff();
		m_zoSteuerungBackground.SwitchOff();
		m_zoHighscoreBackground.SwitchOff();

		bHighscore = false; 
		ptrHighScore->SwitchMenueOff(); 

		m_zoMainmbackground.SwitchOn();

	}


	// Pick Back - F�r Explorer

	if (ptrMaus->PickOverlayandLeftKlick(&m_zoBackButton))
	{
		ptrExplorer->SwitchOff();
		m_zoMainmbackground.SwitchOn();
		m_zoSteuerungBackground.SwitchOff();

	}
	//------------------------------------------------------------------------------------------------------------------------------------

	// In diesem Teil wird geregelt, welche Auswahl aktuell ausgew�hlt wird (Hauptmenu)


	// Auswahl Name
	if (!ptrMaus->PickOverlay(&m_zoName))
	{
		m_zoName.SwitchOff();

	}

	// Auswahl Lernpacket
	if (!ptrMaus->PickOverlay(&m_zoLernPaket))
	{

		m_zoLernPaket.SwitchOff();

	}



	// Auswahl Einstellungen
	if (!ptrMaus->PickOverlay(&m_zoEinstellung))
	{

		m_zoEinstellung.SwitchOff();

	}

	// Auswahl Steuerung
	if (!ptrMaus->PickOverlay(&m_zoSteuerung))
	{
		m_zoSteuerung.SwitchOff();

	}


	// Auswahl Hiscore
	if (!ptrMaus->PickOverlay(&m_zoHighscore))
	{
		m_zoHighscore.SwitchOff();

	}




	// Auswahl Exit
	if (!ptrMaus->PickOverlay(&m_zoExit))
	{
		m_zoExit.SwitchOff();

	}

	// In diesem Teil wird geregelt, welche Auswahl aktuell ausgew�hlt wird (Optionsmenu)
	//Voreinstellung
	m_zoPickTonAus.SwitchOn();
	m_zoPickAntianilisingOff.SwitchOn();
	m_zoPickWindowScreen.SwitchOn();
	m_zoPickHighscore.SwitchOn();


	//PickEinstellung f�r L�schung des Hiscores
	if (!ptrMaus->PickOverlay(&m_zoPickHighscore))
	{
		m_zoPickHighscore.SwitchOff();

	}

	//Pickeinstellung f�r Ton An/Aus
	//Solange nichts gepickt wird schalte Ton An ein

	if (!ptrMaus->PickOverlay(&m_zoPickTonAus))
	{
		m_zoPickTonAus.SwitchOff();
		m_zoPickTonAn.SwitchOn();

	}

	//Ton An Ausschalten, wenn Maus �ber TonAus ist 
	if (ptrMaus->PickOverlay(&m_zoPickTonAus))
	{
		m_zoPickTonAn.SwitchOff();


	}



	//TON  Aus speichern
	if (ptrMaus->PickOverlayandLeftKlick(&m_zoPickTonAus))
	{

		
		m_zoPickTonAus.SwitchOn();
		m_zoPickTonAn.SwitchOff();

	}



	//Antianilising Aus Anzeigen wenn maus dr�ber f�hrt

	if (!ptrMaus->PickOverlay(&m_zoPickAntianilisingOff))
	{
		m_zoPickAntianilisingOff.SwitchOff();

	}

	//Antianilising-On wird ausgeschaltet wenn Maus �ber Off f�hrt
	if (ptrMaus->PickOverlay(&m_zoPickAntianilisingOff))
	{
		m_zoPickAntianilisingOn.SwitchOff();
	}

	else
	{
		m_zoPickAntianilisingOn.SwitchOn();

	}

	//WindowSize wird markiert wenn man dr�berf�hrt
	//Antianilising Aus Anzeigen wenn maus dr�ber f�hrt

	if (!ptrMaus->PickOverlay(&m_zoPickWindowScreen))
	{
		m_zoPickWindowScreen.SwitchOff();

	}

	//Antianilising-On wird ausgeschaltet wenn Maus �ber Off f�hrt
	if (ptrMaus->PickOverlay(&m_zoPickWindowScreen))
	{
		m_zoPickFullScreen.SwitchOff();
	}

	else
	{
		m_zoPickFullScreen.SwitchOn();

	}

	//Hiscore zur�cksetzten Anzeigen wenn Maus dr�berf�hrt

	if (!ptrMaus->PickOverlay(&m_zoPickHighscore))

	{
		m_zoPickHighscore.SwitchOff();

	}

}

void CMainmenu::SwitchOn() {

	m_zoMainmbackground.SwitchOn();
	ptrMaus->SwitchOn();
	m_zTOPLernpaket.SwitchOn();
	m_zTOPProfil.SwitchOn();
	ptrSound->Start(0);
	

}


void CMainmenu::SwitchOff() {

	ptrMaus->SwitchOff();
	m_zoMainmbackground.SwitchOff();
	m_zTOPLernpaket.SwitchOff();
	m_zTOPProfil.SwitchOff();
	ptrSound->Stop(0);

}

void CMainmenu::Reset() {
	bLernpaket = false;
	bProfil = false;
	bGo = false;
	bHighscore = false;
	m_zTOPLernpaket.SetString("Lernpaket w�hlen");
	m_zTOPProfil.SetString("Profil w�hlen");
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