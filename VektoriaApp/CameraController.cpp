#include "CameraController.h"


CCameraController::CCameraController()
{
}


CCameraController::~CCameraController()
{
}

void CCameraController::Init(CViewport * viewport, CScene * scene)
{
	//Camera initialisieren
	m_zCamera.Init(QUARTERPI);

	//Camera dem Viewport geben
	viewport->InitFull(&m_zCamera);

	//Camera placement hinzufügen
	m_zpCamera.AddCamera(&m_zCamera);

	//Camera der Szene hinzufügen
	scene->AddPlacement(&m_zpCamera);
}

void CCameraController::Tick(CPlacement * placement, CDeviceKeyboard * keyboard)
{
	CameraPosition(placement);

	//Switch von 1stPerson zu 3rdPerson und vice versa
	if (keyboard->KeyDown(DIK_C))
	{
		if (bFirstPerson == true)
		{
			m_zpCamera.Translate(m_zpCamera.GetTranslation() = placement->GetTranslation());
			m_zpCamera.TranslateZDelta(15.0F);
			bFirstPerson = false;
		}
		else
		{
			m_zpCamera.Translate(m_zpCamera.GetTranslation()= placement->GetTranslation());
			bFirstPerson = true;
		}
	}
}


void CCameraController::CameraPosition(CPlacement * placement)
{
	m_zpCamera.Translate(m_zpCamera.GetTranslation() = placement->GetTranslation());

	if (bFirstPerson == false)
		m_zpCamera.TranslateZDelta(15.0F);
}
