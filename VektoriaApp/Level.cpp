#include "Level.h"


CLevel::CLevel()
{
}


CLevel::~CLevel()
{
}
void CLevel::Init(CScene * scene, CFrame * frame){

	m_zMaterialKugel.MakeTextureDiffuse("textures\\Textur.jpg");
	m_zgSphere.Init(0.5F, &m_zMaterialKugel, 50, 50);

	m_zMeteoriten.Init(scene);
	m_zpSphere.AddGeo(&m_zgSphere);
	scene->AddPlacement(&m_zpSphere);
	frame->AddDeviceKeyboard(&m_zKeyboard);
}

void CLevel::Tick(FLOAT fTimeDelta, CPlacement * camera){
	m_zpSphere.TranslateZDelta(-25.0F * fTimeDelta);
	m_zMeteoriten.RenewMeteorits(&m_zpSphere);

	//kollision
	for (int i = 0; i < 24; i++)
	{
		int m_iposMet = m_zMeteoriten.m_azp[m_zMeteoriten.iCounterStart].GetTranslation().GetZ();
		int m_iposRau = m_zpSphere.GetTranslation().GetZ();
		if (m_iposMet - m_iposRau >= 0){
			m_zHitbox.CollisionDetection(&m_zMeteoriten.m_azp[m_zMeteoriten.iCounterStart + i].GetTranslation(), &m_zpSphere, &m_zMeteoriten.iCounterStart);
		}
	}


	//steuerung
	if (m_zKeyboard.KeyPressed(DIK_W))
	{
		m_zpSphere.TranslateYDelta(8.0F * fTimeDelta);
	}

	if (m_zKeyboard.KeyPressed(DIK_A))
	{
		m_zpSphere.TranslateXDelta(-8.0F * fTimeDelta);
	}

	if (m_zKeyboard.KeyPressed(DIK_S))
	{
		m_zpSphere.TranslateYDelta(-8.0F * fTimeDelta);
	}

	if (m_zKeyboard.KeyPressed(DIK_D))
	{
		m_zpSphere.TranslateXDelta(8.0F * fTimeDelta);
	}


	//first person ändern
	if (m_zKeyboard.KeyDown(DIK_C))
	{
		if (bFirstPerson == true) {
			bFirstPerson = false;
		}
		else{
			bFirstPerson = true;
		}
	}
	//jeden tick camera nachziehen
	if (bFirstPerson == true){
		m_cameraPos = m_zpSphere.GetTranslation();
		camera->Translate(m_cameraPos);

	}
	else{
		m_cameraPos = m_zpSphere.GetTranslation();
		m_cameraPos.SetZ(m_cameraPos.GetZ() + 15.0F);

		camera->Translate(m_cameraPos);
	}
			
	



	
}