#include "Fog.h"


CFog::CFog()
{
}


CFog::~CFog()
{
}

void CFog::Init(CRoot * root, CScene * scene)
{
	m_zmFog[0].MakeTextureDiffuse("textures\\Fog1.png");
	m_zmFog[1].MakeTextureDiffuse("textures\\Fog2.png");
	m_zmFog[2].MakeTextureDiffuse("textures\\Fog3.png");
	m_zmFog[3].MakeTextureDiffuse("textures\\Fog4.png");
	m_zmFog[4].MakeTextureDiffuse("textures\\Fog5.png");
	m_zmFog[5].MakeTextureDiffuse("textures\\Fog6.png");

	for (int i = 0; i < MAX_FOG; i++)
	{
		//Material
		root->AddMaterial(&m_zmFog[i]);

		//Geo initialisieren
		m_zFog[i].Init(50.0F, 50.0F, &m_zmFog[i]);

		//Dem Placement das Geo hinzufügen
		m_zpFog[i].AddGeo(&m_zFog[i]);
		
		//Transparency vom Fog festlegen
		OutputDebugString("\n");
		fAnzahl = fAnzahl - (100 / MAX_FOG);
		OutputDebugString(std::to_string(fAnzahl / 100.0F).c_str());

		//Transparency der Plane
		//m_zmFog[i].SetTransparency(fAnzahl / 100.0F);

		//Abstand der Planes festlegen
		fAbstand -= 50;

		//Fog verschieben
		m_zpFog[i].TranslateZDelta(fAbstand);

		//Placement der Szene hinzufügen
		scene->AddPlacement(&m_zpFog[i]);
	}
}

void CFog::Tick(float fGeschwindigkeit)
{
	for (int i = 0; i < MAX_FOG; i++)
	{
		//Fog mitverschieben
		m_zpFog[i].TranslateZDelta(fGeschwindigkeit);
	}

}