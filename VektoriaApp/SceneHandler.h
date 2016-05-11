#pragma once
#include "Vektoria\Root.h"
#include "Meteorit.h"
#include "Hitbox.h"
#include "Frage.h"
#include "Raumschiff.h"
#include "CameraController.h"
#include "Steuerung.h"
#include "LightTunnel.h"
#include "SkyDome.h"

using namespace Vektoria;

class SceneHandler
{
public:

	SceneHandler();
	~SceneHandler();

	void Init(CViewport * viewport, CScene * scene, CFrame * frame, CDeviceKeyboard * ptrKeyboard);
	void InitRaumschiff(CRoot * root, CScene * scene);
	void InitMeteorits(CScene * scene);
	void InitCamera(CViewport * viewport, CScene * scene);
	void InitLights(CScene * scene);
	void InitSkyDome(CRoot * root, CScene * scene);

	void InitFrage();
	void Scene_Meteoriten();
	void Scene_Frage();

	CRaumschiff * getRaumschiffptr() { return &m_zRaumschiff; };

	void Tick(FLOAT fTimeDelta, CScene * scene);

private:

	//Objekte
	CMeteorit m_zMeteoriten;
	CDeviceKeyboard * m_zKeyboard;

	CSkyDome m_zSkydome;
	CLightTunnel m_zLights;
	CHitbox m_zHitbox;
	CHVector m_cameraPos;
	CFrage m_zFrage;
	CRaumschiff m_zRaumschiff;
	CCameraController m_zc;
	CSteuerung m_zSteuerung;

	//Sonstiges
	CHVector m_vMetroritenvektor;
	FLOAT f_PosRaumschiffZ;
	FLOAT f_PosRaumschiffY;
	FLOAT f_PosRaumschiffX;
	FLOAT m_fTestAbstand;
	FLOAT m_fGeschwindigkeit;
	FLOAT m_fBeschleunigung;


	bool b_istKollidiert;
	bool bFirstPerson = true;
	int i_Antwort;


	int i_inScene;
	bool b_braucheAntwort = true;
	bool b_sollinit = false;
	bool b_sollinitfrage = false;
	bool m_bLenkung = true;
};

