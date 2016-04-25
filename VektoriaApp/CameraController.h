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

	CCamera getCamera(){ return m_zCamera; };
	CPlacement getPlacement() { return m_zpCamera; };

private:

	//Camera
	CCamera m_zCamera;

	//Placement
	CPlacement m_zpCamera;

	//Variable
	bool bFirstPerson = true;

};

