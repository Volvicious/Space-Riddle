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

	//Material hinzufügen
	m_zmCockpit.MakeTextureSprite("textures\\Cockpit2.png");
	//m_zmCockpit.SetAni(3, 2, 1200);

	//Overlay hinzufügen
	m_zoCockpit.Init(&m_zmCockpit, CFloatRect(0, 0, 1, 1));

	//Overlay deaktivieren
	m_zoCockpit.SwitchOff();

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
			m_zpCamera.TranslateYDelta(1.5F);
			placement->SwitchOn();
			m_zoCockpit.SwitchOff();
			bFirstPerson = false;
		}
		else
		{
			m_zpCamera.Translate(m_zpCamera.GetTranslation()= placement->GetTranslation());
			m_zoCockpit.SwitchOn();
			placement->SwitchOff();
			bFirstPerson = true;
		}
	}
}

void CCameraController::CameraPosition(CPlacement * placement)
{
	m_zpCamera.Translate(m_zpCamera.GetTranslation() = placement->GetTranslation());

	if (bFirstPerson == false)
	{
		placement->SwitchOn();
		m_zpCamera.TranslateZDelta(15.0F);
		m_zpCamera.TranslateYDelta(1.5F);
	}
}
