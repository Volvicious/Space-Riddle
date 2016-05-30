#pragma once
#include "Vektoria\Root.h"
#include "Meteorit.h"

using namespace Vektoria;
class CLevel
{
public:
	CLevel();
	~CLevel();
	void Init(CScene * scene, CFrame * frame);
	void Tick(FLOAT fTimeDelta,CPlacement * camera);

private:

	//Objekte
	CMaterial m_zMaterialKugel;
	CGeoSphere m_zgSphere;
	CPlacement m_zpSphere;
	CGeoTube m_zTube;
	bool bFirstPerson = true;
	CMeteorit m_zMeteoriten;
	CDeviceKeyboard m_zKeyboard;
	CHitbox m_zHitbox;
	CHVector m_vMetroritenvektor;
	FLOAT m_fTestAbstand;
	FLOAT m_fGeschwindigkeit;
	FLOAT m_fBeschleunigung;
	CHVector m_cameraPos;
};

