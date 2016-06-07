#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

class CCameraController
{
public:
	CCameraController();
	~CCameraController();

	void Init(CViewport * viewport, CScene * scene);
	void Tick(CPlacement * placement, CDeviceKeyboard * keyboard);
	void CameraPosition(CPlacement * placement);

	bool setFristPerson(bool fp){ return bFirstPerson = fp; };

	COverlay * setOverlayCockpit() { return &m_zoCockpit; };

private:

	//Camera
	CCamera m_zCamera;

	//Placement
	CPlacement m_zpCamera;

	//Material
	CMaterial m_zmCockpit;

	//Overlay
	COverlay m_zoCockpit;

	//Variable
	bool bFirstPerson = false;

};

