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
	CCamera m_zCamera;
	CPlacement m_zpCamera;
	bool bFirstPerson = true;

};

