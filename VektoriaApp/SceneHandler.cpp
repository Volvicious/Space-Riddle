#include "SceneHandler.h"


SceneHandler::SceneHandler()
{
}


SceneHandler::~SceneHandler()
{
}

#pragma region Init

void SceneHandler::Init(CViewport * viewPort, CScene * scene, CFrame * frame) 
{
	//Kamera
	m_zc.Init(viewPort, scene);

	//Keyboard
	frame->AddDeviceKeyboard(&m_zKeyboard);
	m_zTastaturGer.Init(&m_zKeyboard, 9999, false);
	
	//Maus 
	m_dMaus.Init(viewPort, frame);

	//Fragen
	m_zFragenHandler.Init(&m_zFilehandlerLernpaket, viewPort, &m_zProfilhandler);

	//Menu
	m_zHauptmenu.menuInit(viewPort, &m_dMaus, &m_zExplorerLernpaket,
		&m_zExplorerProfil, &m_zProfilhandler);

	//Lernpakete

	m_zExplorerLernpaket.Init(viewPort, &m_dMaus, &m_zFilehandlerLernpaket, 
		"textures\\explorer\\menubild_lernpaketexplorer.jpg", "textures\\TextIcon.gif",
		"..\\VektoriaApp\\fragen"); 

	m_zProfilhandler.Init(&m_zFilehandlerProfil);
	m_zFragenHandler.Init(&m_zFilehandlerLernpaket, viewPort, &m_zProfilhandler);

	m_zExplorerProfil.Init(viewPort, &m_dMaus, &m_zFilehandlerProfil,
		"textures\\explorer\\menubild_profilmanager.jpg", "textures\\TextIcon.gif",
		"..\\VektoriaApp\\profil", &m_zKeyboard); 

	//Countdown-Animation
	m_zAnimationCountdown.Init(viewPort, 4, "textures\\animation\\countdown", "jpg");
	m_zAnimationCountdown.SetTime(0, 1000);
	m_zAnimationCountdown.SetTime(1, 1000);
	m_zAnimationCountdown.SetTime(2, 1000);
	m_zAnimationCountdown.SetTime(3, 1000);

	//Intro-Animation

	m_zAnimationIntro.Init(viewPort, 5, "textures\\animation\\storyintro", "png");
	m_zAnimationIntro.SetTime(0, 1000.0F);
	m_zAnimationIntro.SetTime(1, 1000.0F);
	m_zAnimationIntro.SetTime(2, 2000.F);
	m_zAnimationIntro.SetTime(3, 1000.F);
	m_zAnimationIntro.SetTime(4, 1000.F);


	//Leben- & Levelanzeige
	m_zLLA.Init(viewPort);

	// Highscore
	m_zHighscore.Init(viewPort);

	//Sound
	m_zSound.Init(scene);

	////Geschwindigkeit
	m_fGeschwindigkeit = -40.0f;

	//Szene setzen
	iScene =  Intro;
}

void SceneHandler::InitMeteorits(CRoot * root, CScene * scene)
{
	m_zMeteoriten.Init(root, scene);
}

void SceneHandler::InitRaumschiff(CRoot * root, CScene * scene)
{
	m_zRaumschiff.Init(root, scene);
}

void SceneHandler::InitCamera(CViewport * viewport, CScene * scene)
{
	m_zc.Init(viewport, scene);
}

void SceneHandler::InitLights(CScene * scene)
{
	m_zLights.Init(scene);
}

void SceneHandler::InitSkyDome(CRoot * root, CScene * scene)
{
	m_zSkydome.Init(root, scene);
}

void SceneHandler::InitHitbox(CScene * scene)
{
	m_zHitbox.Init(&m_zRaumschiff, &m_zFrageGrafik, &m_zMeteoriten, scene);
}

void SceneHandler::InitFrageGrafik(CRoot * root, CScene * scene)
{
	m_zFrageGrafik.Init(root, scene);
}

void SceneHandler::InitOverlays(CViewport * viewport)
{
	m_zIngameOverlays.Init(viewport);
}

#pragma endregion

void SceneHandler::FrageTranslation()
{
	f_PosRaumschiffZ = m_zRaumschiff.getpRaumschiff()->GetTranslation().GetZ();
	f_PosRaumschiffY = 0.0F;
	f_PosRaumschiffX = 0.0F;

	m_zFrageGrafik.Translate(f_PosRaumschiffZ, f_PosRaumschiffX, f_PosRaumschiffY);
}



void SceneHandler::MeteoritenTick(float fTimeDelta)
{
	if (MeteoritenSwitch == true)
	{
		//Kamerposition fixen
		m_zc.setFristPerson(false);
		m_zc.setOverlayCockpit()->SwitchOff();

		//Meteoriten verschieben
		m_zMeteoriten.NewLevel(m_zRaumschiff.getpRaumschiff());

		MeteoritenSwitch = false;
	}

	if (bFirstTick == false)
	{
		//Kollision
		m_zHitbox.HitboxMeteoriten(&m_zRaumschiff, &m_zMeteoriten);
	}

	//Meteoriten erneuern
	m_zMeteoriten.Tick(m_zRaumschiff.getpRaumschiff(), fTimeDelta);

	if (m_zHitbox.getCollision() == true)
	{
		//m_zLLA.setLebenAnzahl(m_zLLA.getLebenAnzahl() - 1);
		//TODO: Animation

		//Crashsound
		m_zSound.Start(3);
	}

	//Wenn alle Meteoriten vorbei sind
	if (m_zMeteoriten.getiMeteorNummer() == MAX_METEOR)
	{
		m_zMeteoriten.getiMeteorNummer();
		iScene = Fragen;
		SwitchScene();
		FrageSwitch = true;
	}

	//Firsttick setzen
	bFirstTick = false;
}

void SceneHandler::SwitchScene()
{
	if (iScene == Meteoriten)
	{
		m_zFrageGrafik.SwitchOff();
		m_zMeteoriten.SwitchOn();
	}
	else if (iScene == Fragen)
	{
		m_zMeteoriten.SwitchOff();
		m_zFrageGrafik.SwitchOn();
	}

	//Kollision für Hitboxen aktivieren
	m_zHitbox.setCollision(false);
	bFirstTick = true;
}

void SceneHandler::FrageTick()
{
	if (FrageSwitch == true)
	{
		FrageTranslation();
		FrageSwitch = false;
	}

	//First Person umstellen
	m_zc.setFristPerson(true);
	m_zc.setOverlayCockpit()->SwitchOn();

	if (bFirstTick == false)
	{
		//Hitboxen
		int j = m_zHitbox.HitboxFrage(&m_zRaumschiff, &m_zFrageGrafik);
	}

	//Die Hitbox darf nur einmal Kollidieren und nicht mehrmals
	if (m_zHitbox.getCollision() == true)
	{
		//Überprüfen mit welcher Frage ich kollidiert bin
		/*if (j > -1)
		{
			if(Fragenhandler.IsAntwortRichtig(j))
			{
				m_zLLA.setLebenAnzahl(m_zLLA.getLebenAnzahl() + 3);
				m_zLLA.setLevelNummer(m_zLLA.getLevelNummer() + 1);
				iScene = LevelCompleted;
				m_zIngameOverlays.SwitchOn(1);
			}
			else
			{
				m_zLLA.setLebenAnzahl(m_zLLA.getLebenAnzahl() - 3);
				m_zLLA.setLevelNummer(m_zLLA.getLevelNummer() + 1);
			}
		}*/
		

		//Level Completed
		iScene = LevelCompleted;
		m_zIngameOverlays.SwitchOn(1);
	}

	//FirstTick
	bFirstTick = false;
}

void SceneHandler::Tick(float fTimeDelta, float fTime)
{	
	//Spiel pausieren

	int iSceneSpeicher = iScene;

	iScene = m_zSteuerung.PauseGame(iScene, &m_zKeyboard);

	if (iSceneSpeicher == Pause && iSceneSpeicher != iScene) {
		m_zHighscore.GoOn(fTime);
	}

	if (iScene == Intro)
	{
		int iSceneSpeicher = iScene; 

		//Todo: IF Animation zuende oder Leertaste

		if (!bAnimationIntroStarted) {
			m_zAnimationIntro.StartAnimation();
			bAnimationIntroStarted = true; 
		}

		iScene = m_zSteuerung.Hauptmenue(iScene, &m_zKeyboard);

		if (iSceneSpeicher != iScene) {
			m_zAnimationIntro.StopAnimation(); 
		}


		m_zAnimationIntro.Run(fTime);
		if (m_zAnimationIntro.IsFinished()) {

			iScene = PreHauptmenue;
		}


		
	
	}


	if (iScene == PreHauptmenue) {

		ULDebug("Bin hier!");
		m_zHauptmenu.SwitchOn();
		m_dMaus.SwitchOn();
		iScene = Hauptmenü;
	}

	//Hauptmenü getickt
	if (iScene == Hauptmenü)
	{

		
		m_zSound.Loop(0);
		m_dMaus.Run();
		m_zExplorerLernpaket.Run();
		m_zProfilhandler.Run();
		m_zExplorerProfil.Run(); 

		m_zHauptmenu.menuTick();
		m_zTastaturGer.Run();
		m_zFragenHandler.Run(fTimeDelta);

		if (m_zHauptmenu.getbGo())
		{
			iScene = Countdown;
			m_dMaus.SwitchOff();
			//m_zLLA.SwitchOn();
		}
	}

	//Countdown runterzählen
	//Wenn Leertaste gedrückt wird, wird iScene auf 1 gesetzt, also das Spiel beginnt
	if (iScene == Countdown)
	{
		if (PlaySoundOnce == true)
		{
			m_zSound.SwitchSounds(0, 4);
			PlaySoundOnce = false;
			m_zAnimationCountdown.StartAnimation(); 
		}

		//iScene = m_zSteuerung.StartGame(iScene, &m_zKeyboard);

		m_zAnimationCountdown.Run(fTime);

		if (m_zAnimationCountdown.IsFinished()) {
			iScene = Meteoriten;
			m_zHighscore.Start(fTimeDelta);
		}


		/*if (iScene == 1) {
			m_zHighscore.Start(fTimeDelta);
		}*/


		MeteoritenSwitch = true;
	}

	//Tick für Spiel
	if (iScene == Meteoriten || iScene == Fragen) 
	{
		if (m_zKeyboard.KeyDown(DIK_F)) {
			m_zHighscore.AddToHighscore(3);
		}


		//Ingame Loop
		m_zSound.SwitchSounds(4, 1, true);

		//Ingame Overlays ausschalten
		m_zIngameOverlays.SwitchOffAll();

		//Steuerung
		m_zSteuerung.Tick(fTimeDelta, m_zRaumschiff.getpRaumschiff(), &m_zKeyboard);

		// Lichter
		m_zLights.Tick(m_zRaumschiff.getpRaumschiff());

		//Skydome bewegen
		m_zSkydome.Tick(fTimeDelta * m_fGeschwindigkeit);

		//Raumschiff bewegen
		m_zRaumschiff.Tick(fTimeDelta* m_fGeschwindigkeit);

		//Raytick
		m_zHitbox.RayTick(&m_zRaumschiff);

		//Camera bewegen
		m_zc.Tick(m_zRaumschiff.getpRaumschiff(), &m_zKeyboard);


		//Lebensanzeige
		m_zLLA.Run();

		//Meteoriten
		if (iScene == Meteoriten)
		{
			m_fGeschwindigkeit = -60.0f;
			MeteoritenTick(fTimeDelta);
		}

		//Frage
		if (iScene == Fragen)
		{
			m_fGeschwindigkeit = -10.0f;
			FrageTick();
		}


		//HighScore
		m_zHighscore.Run(fTime, fTimeDelta);


		//Wenn das Leben auf 0 ist hat man verloren
		//if (m_zLLA.getLebenAnzahl() <= 0)
		//{
		//	iScene = Verloren;
		//}
	} 
	
	//Game Over
	if (iScene == Verloren)
	{
		//Game Over
		m_zIngameOverlays.SwitchOffAll();
		m_zIngameOverlays.SwitchOn(2);
		m_zIngameOverlays.SetLayer(0, 0.9f);

		//Highscoreliste anzeigen
		iScene = m_zSteuerung.Highscore(iScene, &m_zKeyboard);
	}

	//Pause gedrückt
	if (iScene == Pause)
	{
		m_zHighscore.Pause(); 
		m_zSound.Pause(1);
		m_zIngameOverlays.SwitchOn(0);
		m_zIngameOverlays.SetLayer(0, 0.8F);
	}

	//Level Completed
	if (iScene == LevelCompleted)
	{
		//Cameraposition verändern
		m_zc.setFristPerson(false);
		m_zc.setOverlayCockpit()->SwitchOff();

		//Fragen hinter mir ausblenden
		m_zFrageGrafik.SwitchOff();

		//Wenn Leertaste gedrückt wird gehts weiter
		iScene = m_zSteuerung.ContinueGame(iScene, &m_zKeyboard);

		//Switchscene
		SwitchScene();

		//Meteoriten starten
		MeteoritenSwitch = true;
	}

	if (iScene == Highscore)
	{
		//Todo: Highscore Overlay anzeigen
		iScene = m_zSteuerung.Hauptmenue(iScene, &m_zKeyboard);
	}
}