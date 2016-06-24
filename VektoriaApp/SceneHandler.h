
#pragma once
#include "Vektoria\Root.h"
#include "Meteorit.h"
#include "Hitbox.h"
#include "FrageGrafik.h"
#include "Raumschiff.h"
#include "CameraController.h"
#include "Steuerung.h"
#include "LightTunnel.h"
#include "SkyDome.h"
#include "Sound.h"

#include "MainMenu.h"
#include "TextOutput.h"
#include "TastaturGER.h"
#include "FragenHandler.h"
#include "FileHandler.h"
#include "Frage.h"
#include "FrageText.h"
#include "Maus.h"
#include "Explorer.h"
#include "LLAnzeige.h"
#include "IngameOverlays.h"

#include "Highscore.h"
#include "Animation.h"


using namespace Vektoria;

class SceneHandler
{
public:

	SceneHandler();
	~SceneHandler();

	void Init(CViewport * viewport, CScene * scene, CFrame * frame);
	void InitRaumschiff(CRoot * root, CScene * scene);
	void InitMeteorits(CRoot * root, CScene * scene);
	void InitCamera(CViewport * viewport, CScene * scene);
	void InitLights(CScene * scene);
	void InitSkyDome(CRoot * root, CScene * scene);
	void InitHitbox(CScene * scene);
	void InitFrageGrafik(CRoot * root, CScene * scene);
	void InitOverlays(CViewport * viewport);


	void Tick(float fTimeDelta, float fTime);
	void FrageTranslation();
	void MeteoritenTick(float fTimeDelta);
	void FrageTick(float fTimeDelta);
	void SwitchScene();

private:

	//Objekte
	CMeteorit m_zMeteoriten;
	CSkyDome m_zSkydome;
	CLightTunnel m_zLights;
	CHitbox m_zHitbox;
	CFrageGrafik m_zFrageGrafik;
	CRaumschiff m_zRaumschiff;
	CCameraController m_zc;
	CSteuerung m_zSteuerung;

	//Sound
	CSound m_zSound;

	//Overlays
	CIngameOverlays m_zIngameOverlays;

	// Zeux von Chris
	CMainmenu m_zHauptmenu;

	CTastaturGER m_zTastaturGer;
	
	CFragenHandler m_zFragenHandler;
	CProfilHandler m_zProfilhandler;

	CFileHandler m_zFilehandlerLernpaket;
	CFileHandler m_zFilehandlerProfil;

	CExplorer m_zExplorerLernpaket;
	CExplorer m_zExplorerProfil;

	CMaus m_dMaus;
	CDeviceKeyboard m_zKeyboard;

	CLLAnzeige m_zLLA; 
	CAnimation m_zAnimationIntroVideo; 
	CAnimation m_zAnimation321; 

	CHighscore m_zHighscore; 

	//Szenen
	enum Szene{ PreHauptmenue = -1, Hauptmenü = 0, Meteoriten = 1, 
		Fragen = 2, Verloren = 3, Pause = 4, Countdown = 5,
		LevelCompleted = 6, Highscore = 7, Intro = 8};

	//Lokale Variablen
	float f_PosRaumschiffZ;
	float f_PosRaumschiffY;
	float f_PosRaumschiffX;
	float m_fGeschwindigkeit;

	bool PlaySoundOnce = true;
	int iScene;
	bool FrageSwitch = false;
	bool MeteoritenSwitch = false;
	bool bFirstPerson = true;
	bool bFirstTick = true;

	int nummer;

	int iLeben = 10;
};

