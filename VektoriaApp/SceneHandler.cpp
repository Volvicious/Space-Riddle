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
	m_zFragenHandler.Init(&m_zFilehandlerLernpaket, viewPort, &m_zTastaturGer);

	//Menu
	m_zHauptmenu.Init(viewPort, &m_dMaus, &m_zExplorerLernpaket);

	//Lernpakete
	m_zExplorerLernpaket.Init(viewPort, &m_dMaus, &m_zFilehandlerLernpaket, 
		"textures\\menubild_lernpaketexplorer.jpg", "textures\\TextIcon.gif", "..\\VektoriaApp\\fragen");

	//Leben- & Levelanzeige
	m_zLLA.Init(viewPort);

	//Sound
	m_zSound.Init(scene);

	//0 ist Hauptmenü
	//1 ist Meteoriten
	//2 ist Fragen
	//3 ist Verloren
	//4 ist Pause Menü
	iScene = 0;

	//Geschwindigkeit
	m_fGeschwindigkeit = -40.0f;

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

void SceneHandler::FrageTranslation()
{
	f_PosRaumschiffZ = m_zRaumschiff.getpRaumschiff()->GetTranslation().GetZ();
	f_PosRaumschiffY = 0.0F;
	f_PosRaumschiffX = 0.0F;

	m_zFrageGrafik.Translate(f_PosRaumschiffZ, f_PosRaumschiffX, f_PosRaumschiffY);
}

#pragma endregion

void SceneHandler::MeteoritenTick()
{
	if (MeteoritenSwitch == true)
	{
		//Kamerposition fixen
		m_zc.setFristPerson(false);
		m_zc.setOverlayCockpit()->SwitchOff();
		MeteoritenSwitch = false;
	}

	//Meteoriten erneuern
	m_zMeteoriten.Tick(m_zRaumschiff.getpRaumschiff(), true);

	//Kollision
	//m_zHitbox.HitboxMeteoriten(m_zRaumschiff.getpRaumschiff(), &m_zMeteoriten);

	if (m_zHitbox.Collision() == true)
	{
		m_zLLA.setLebenAnzahl(m_zLLA.getLebenAnzahl() - 1);
		//TODO: Animation

		//Crashsound
		m_zSound.Start(3);
	}


	//Wenn alle Meteoriten vorbei sind
	if (m_zMeteoriten.getiMeteorNummer() == MAX_METEOR)
	{
		iScene = 2;
		SwitchScene();
		FrageSwitch = true;
	}
}

void SceneHandler::SwitchScene()
{
	if (iScene == 1)
	{
		m_zMeteoriten.SwitchOn();
		m_zFrageGrafik.SwitchOff();
	}
	else if (iScene == 2)
	{
		m_zMeteoriten.SwitchOff();
		m_zFrageGrafik.SwitchOn();
	}
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

	//Hitboxen
	m_zHitbox.HitboxFrage(&m_zRaumschiff, &m_zFrageGrafik);

	//Wenn ich an der Frage vorbei bin muss die Szene gewechselt werden
	if (m_zFrageGrafik.getpFrage(1)->GetTranslation().GetZ() >= m_zRaumschiff.getpRaumschiff()->GetTranslation().GetZ())
	{
		m_zLLA.setLevelNummer(m_zLLA.getLevelNummer() + 1);
		iScene = 1;
		//Level completed Bild
		MeteoritenSwitch = true;
		SwitchScene();
	}
}

void SceneHandler::Tick(float fTimeDelta, float fTime)
{	
	//Spiel pausieren
	iScene = m_zSteuerung.PauseGame(iScene, &m_zKeyboard);

	//Hauptmenü getickt
	if (iScene == 0)
	{
		m_dMaus.Run();
		m_zExplorerLernpaket.Run();
		m_zHauptmenu.Tick();
		m_zTastaturGer.Run();
		m_zFragenHandler.Run();

		if (m_zHauptmenu.getbGo())
		{
			iScene = 1;
			m_dMaus.SwitchOff();
			m_zLLA.SwitchOn();
		}
	}

	//Tick für Spiel
	if (3 > iScene > 0) 
	{
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

		//Kollision mit Zeug, damit die Zeile schlauer aussieht
		//Meteoriten
		if (iScene == 1)
		{
			MeteoritenTick();
		}

		//Frage
		if (iScene == 2)
		{
			FrageTick();
		}

		if (m_zLLA.getLebenAnzahl() == 0)
		{
			iScene = 3;
		}
	}

	if (iScene == 3)
	{
		//TODO: Game Over
		//TODO: Highscoreliste anzeigen
	}

	if (iScene == 4)
	{
		//TODO: Pause Menü einblenden
	}
}