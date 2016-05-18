#include "SceneHandler.h"


SceneHandler::SceneHandler()
{
}


SceneHandler::~SceneHandler()
{
}

void SceneHandler::Init(CViewport * viewPort, CScene * scene, CFrame * frame, CDeviceKeyboard * ptrKeyboard) 
{
	//Wichtig
	b_sollinit = true;
	i_inScene = 1;
	m_zFrage.Init1(scene);
	m_fBeschleunigung = -30.0f;

	m_zc.Init(viewPort, scene); 
	m_zKeyboard = ptrKeyboard;
	m_zSound.Init(scene);

}

void SceneHandler::InitMeteorits(CRoot * root, CScene * scene)
{
	bool Graphics = true;

	if (Graphics == true)
	{
		m_zMeteoriten.Init(root, scene);
	}
	else
	{
		m_zMeteoriten.LowGraphics(root, scene);
	}
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

void SceneHandler::InitFrage()
{
	f_PosRaumschiffZ = m_zRaumschiff.getpRaumschiff()->GetTranslation().GetZ();
	f_PosRaumschiffY = 0.0F;
	f_PosRaumschiffX = 0.0F;

	m_zFrage.Init(f_PosRaumschiffZ, f_PosRaumschiffX, f_PosRaumschiffY);

	b_braucheAntwort = true;

	//Wenn die Antwort 5 ist, wurde keine Antwort erkannt
	i_Antwort = 5;
}

void SceneHandler::Scene_Meteoriten()
{
	//Meteoriten erneuern
	m_zMeteoriten.Tick(m_zRaumschiff.getpRaumschiff(), true);

	//Hitboxen kollision
	m_zHitbox.CollisionMeteorit(&m_zRaumschiff.getpRaumschiff()->GetTranslation(), &m_zMeteoriten);

	//Counter der Meteoriten hochzählen
	if (m_zMeteoriten.getiCounterMeteoriten() == MAX_METEOR)
	{ 
		//Szene ändern wenn alle Meteoriten vorbei sind
		m_zMeteoriten.SwitchOff();
		b_sollinitfrage = true;
		i_inScene = 2;
	}
}

void SceneHandler::SwitchScene()
{
	if (m_zMeteoriten.getiCounterMeteoriten() == MAX_METEOR)
	{
		if (i_inScene == 1)
		{
			m_zMeteoriten.SwitchOff();
			m_zFrage.SwitchOn();
			i_inScene = 2;
		}
		else if (i_inScene == 2)
		{
			m_zFrage.SwitchOff();
			m_zMeteoriten.SwitchOn();
			i_inScene = 1;
		}
	}
}

void SceneHandler::Scene_Frage()
{
	m_zMeteoriten.Tick(m_zRaumschiff.getpRaumschiff(), false);

	//Raumschiffgeschwindigkeit
	if (m_zFrage.GetPlacementFrage() - 20.0f >= m_zRaumschiff.GetZPosition())
	{
		//b_sollinit = true;
		i_inScene = 1;

		//Meteoriten auf 0 setzen
		m_zMeteoriten.SetiCounterZero();

		//Raumschiff auf Position 0 setzen
		m_zRaumschiff.SetZero(m_zMeteoriten.getiCounterZPos());

		//Meteoriten Szene anmachen
		m_zMeteoriten.SwitchOn();
		ULDebug("lkdasflksdjsldkfj");
	}

	if (b_braucheAntwort == true)
	{
		for (int i = 0; i < 4; i++)
		{
			i_Antwort = m_zHitbox.CollisionAntwort(&m_zRaumschiff.getpRaumschiff()->GetTranslation(), &m_zFrage.getPlacement(i), i);

			if (i_Antwort != 5)
			{
				b_braucheAntwort = false;

				if (i_Antwort == 0)
				{
					ULDebug("AntwortA");
				}
				if (i_Antwort == 1)
				{
					ULDebug("AntwortB");
				}
				if (i_Antwort == 2)
				{
					ULDebug("AntwortC");
				}
				if (i_Antwort == 3)
				{
					ULDebug("AntwortD");
				}
			}
		}
	}
}

void SceneHandler::Tick(FLOAT fTimeDelta, CScene * scene)
{	
	//Lichter
	m_zLights.RenewLights(m_zRaumschiff.getpRaumschiff());

	//Skydome bewegen
	m_zSkydome.Tick(fTimeDelta * -40.0F);

	//Raumschiff bewegen
	m_zRaumschiff.Tick(fTimeDelta*-40);

	//Camera bewegen
	m_zc.Tick(m_zRaumschiff.getpRaumschiff(), m_zKeyboard);

	//Frage initialisieren
	if (b_sollinitfrage == true)
	{
		InitFrage();
		
		b_sollinitfrage = false;
	}

	//SwitchScene();

	if (i_inScene == 2)
	{
		Scene_Frage();
	}

	//Meteoriten handeln
	if (i_inScene == 1)
	{
		Scene_Meteoriten();
	}

	//Steuerung
	if (m_bLenkung == true)
	{
		m_zSteuerung.Tick(fTimeDelta, m_zRaumschiff.getpRaumschiff() , m_zKeyboard);
	}
}