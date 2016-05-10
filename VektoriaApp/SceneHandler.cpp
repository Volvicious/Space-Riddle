#include "SceneHandler.h"


SceneHandler::SceneHandler()
{
}


SceneHandler::~SceneHandler()
{
}

void SceneHandler::Init(CScene * scene, CFrame * frame)
{
	//Wichtig
	b_sollinit = true;
	i_inScene = 1;
	m_zFrage.Init1(scene);
	m_fBeschleunigung = -30.0f;

	//Keyboard dem Frame hinzufügen
	frame->AddDeviceKeyboard(&m_zKeyboard);
}

void SceneHandler::InitMeteorits(CScene * scene)
{
	m_zMeteoriten.Init(scene);
}

void SceneHandler::InitRaumschiff(CRoot * root, CScene * scene)
{
	m_zRaumschiff.Init(root, scene);
}

void SceneHandler::InitCamera(CViewport * viewport, CScene * scene)
{
	m_zc.Init(viewport, scene);
}

void SceneHandler::InitFrage()
{
	f_PosRaumschiffZ = m_zRaumschiff.getpRaumschiff()->GetTranslation().GetZ();
	f_PosRaumschiffY = m_zRaumschiff.getpRaumschiff()->GetTranslation().GetY();
	f_PosRaumschiffX = m_zRaumschiff.getpRaumschiff()->GetTranslation().GetX();

	m_zFrage.Init(f_PosRaumschiffZ, f_PosRaumschiffX, f_PosRaumschiffY);

	b_braucheAntwort = true;

	//Wenn die Antwort 5 ist, wurde keine Antwort erkannt
	i_Antwort = 5;
}

void SceneHandler::Scene_Meteoriten()
{
	//Meteoriten erneuern
	m_zMeteoriten.RenewMeteorits(m_zRaumschiff.getpRaumschiff());

	//Hitboxen kollision
	m_zHitbox.CollisionMeteorit(&m_zRaumschiff.getpRaumschiff()->GetTranslation(), &m_zMeteoriten);

	//Counter der Meteoriten hochzählen
	if (m_zMeteoriten.getiCounterMeteoriten() == MAX_METEOR)
	{ 
		//Szene ändern wenn alle Meteoriten vorbei sind
		b_sollinitfrage = true;
		i_inScene = 2;
	}
}

void SceneHandler::Scene_Frage()
{
	//Raumschiffgeschwindigkeit
	if (f_PosRaumschiffZ - 50.0f >= m_zRaumschiff.getpRaumschiff()->GetTranslation().GetY())
	{
		b_sollinit = true;
		i_inScene = 1;
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

void SceneHandler::Tick(FLOAT fTimeDelta, CPlacement * camera, CScene * scene)
{
	//Raumschiff bewegen
	m_zRaumschiff.Tick(fTimeDelta);

	//Camera bewegen
	m_zc.Tick(camera, &m_zKeyboard);

	//Meteoriten erneuern
	m_zMeteoriten.RenewMeteorits(camera);

	if (b_sollinit == true)
	{
		InitMeteorits(scene);
		b_sollinit = false;
	}

	//Frage initialisieren
	if (b_sollinitfrage == true)
	{
		InitFrage();
		b_sollinitfrage = false;
	}
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
		m_zSteuerung.Tick(fTimeDelta, camera, m_zKeyboard);
	}
}