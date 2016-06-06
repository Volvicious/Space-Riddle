
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
	void InitHitbox(CRaumschiff * raumschiff, CFrageGrafik * frage, CMeteorit * meteor, CScene * scene);


	void Tick(float fTimeDelta, float fTime);
	void FrageTranslation();
	void MeteoritenTick();
	void FrageTick();
	void SwitchScene();
	void SetZero();

private:

	//Objekte
	CMeteorit m_zMeteoriten;
	CDeviceKeyboard m_zKeyboard;

	CSkyDome m_zSkydome;
	CLightTunnel m_zLights;
	CHitbox m_zHitbox;
	CHVector m_cameraPos;
	CFrageGrafik m_zFrageGrafik;
	CRaumschiff m_zRaumschiff;
	CCameraController m_zc;
	CSteuerung m_zSteuerung;

	//Sound
	CSound m_zSound;

	// Testzeux von Chris
	CMainMenu m_zHauptmenu;

	CTastaturGER m_zTastaturGer;
	CTextOutput m_zTextoutput;

	CTextOutput m_zTextoutputFrage;
	CFragenHandler m_zFragenHandler;

	CFileHandler m_zFilehandlerLernpaket;
	CFileHandler m_zFilehandlerProfil;

	CExplorer m_zExplorerLernpaket;
	CExplorer m_zExplorerProfil; 

	CMaus m_dMaus;

	CLLAnzeige m_zLLA; 


	//Sonstiges
	CHVector m_vMetroritenvektor;



	//Lokale Variablen
	float f_PosRaumschiffZ;
	float f_PosRaumschiffY;
	float f_PosRaumschiffX;
	float m_fTestAbstand;
	float m_fGeschwindigkeit;
	float m_fBeschleunigung;

	int iScene;
	bool FrageSwitch = false;


	bool b_istKollidiert;
	bool bFirstPerson = true;


	bool b_braucheAntwort = true;
	bool b_sollinit = false;
	bool b_sollinitfrage = false;
	bool m_bLenkung = true;
};

