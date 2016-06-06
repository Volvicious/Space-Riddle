#include "SceneHandler.h"


SceneHandler::SceneHandler()
{
}


SceneHandler::~SceneHandler()
{
}

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
	m_zFrageGrafik.Init(scene);
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

	//0 ist Hauptmen�
	//1 ist Meteoriten
	//2 ist Fragen
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

void SceneHandler::InitHitbox(CRaumschiff * raumschiff, CFrageGrafik * frage, CMeteorit * meteor, CScene * scene)
{
	m_zHitbox.Init(raumschiff, frage, meteor, scene);
}

void SceneHandler::FrageTranslation()
{
	f_PosRaumschiffZ = m_zRaumschiff.getpRaumschiff()->GetTranslation().GetZ();
	f_PosRaumschiffY = 0.0F;
	f_PosRaumschiffX = 0.0F;

	m_zFrageGrafik.Translate(f_PosRaumschiffZ, f_PosRaumschiffX, f_PosRaumschiffY);
}

void SceneHandler::MeteoritenTick()
{
	//Meteoriten erneuern
	m_zMeteoriten.Tick(m_zRaumschiff.getpRaumschiff(), true);

	//Kollision
	m_zHitbox.HitboxMeteoriten(&m_zMeteoriten);

	//Wenn alle Meteoriten vorbei sind
	if (m_zMeteoriten.getiCounterMeteoriten() == MAX_METEOR)
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

	//Hitboxen
	m_zHitbox.HitboxFrage(&m_zFrageGrafik);

	//Wenn ich an der Frage vorbei bin muss die Szene gewechselt werden
	if (m_zFrageGrafik.getpFrage(1)->GetTranslation().GetZ() >= m_zRaumschiff.getpRaumschiff()->GetTranslation().GetZ())
	{
		m_zLLA.setLevelNummer(m_zLLA.getLevelNummer() + 1);
		iScene = 1;
		SetZero();
		SwitchScene();
	}

}

void SceneHandler::SetZero()
{
	m_zRaumschiff.SetZero();
	m_zSkydome.SetZero();
	m_zLights.SetZero();
	m_zMeteoriten.SetiCounterZero();
}

void SceneHandler::Tick(float fTimeDelta, float fTime)
{	
	//Hauptmen� getickt
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

	//Tick f�r Spiel
	if (iScene > 0) 
	{
		//Steuerung
		m_zSteuerung.Tick(fTimeDelta, m_zRaumschiff.getpRaumschiff(), &m_zKeyboard);

		// Lichter
		m_zLights.RenewLights(m_zRaumschiff.getpRaumschiff());

		//Skydome bewegen
		m_zSkydome.Tick(fTimeDelta * m_fGeschwindigkeit);

		//Raumschiff bewegen
		m_zRaumschiff.Tick(fTimeDelta* m_fGeschwindigkeit);

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
		else if (iScene == 2)
		{
			FrageTick();
		}
	}
}