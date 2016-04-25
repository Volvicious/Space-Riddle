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

	//Camera placement hinzuf�gen
	m_zpCamera.AddCamera(&m_zCamera);

	//Camera der Szene hinzuf�gen
	scene->AddPlacement(&m_zpCamera);

	//Material hinzuf�gen
	m_zmCockpit.MakeTextureSprite("textures\\Cockpit.png");

	//Overlay hinzuf�gen
	m_zoCockpit.Init(&m_zmCockpit, CFloatRect(0, 0, 1, 1));

	//Overplay dem Viewport zuweisen
	viewport->AddOverlay(&m_zoCockpit);
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
			m_zoCockpit.SwitchOff();
			bFirstPerson = false;
		}
		else
		{
			m_zpCamera.Translate(m_zpCamera.GetTranslation()= placement->GetTranslation());
			m_zoCockpit.SwitchOn();
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
