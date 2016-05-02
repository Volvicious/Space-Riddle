#include "Fog.h"


CFog::CFog()
{
}


CFog::~CFog()
{
}

void CFog::Init(CRoot * root, CScene * scene)
{
	for (int i = 0; i < MAX_FOG; i++)
	{
		//Material
		root->AddMaterial(&m_zmFog[i]);
		m_zmFog[i].MakeTextureDiffuse("textures\\FogPNG.PNG");
		m_zmFog[i].SetAni(4, 3, 3);

		//Geo initialisieren
		m_zFog[i].Init(25.0F, 10.0F, &m_zmFog[i]);

		//Dem Placement das Geo hinzuf�gen
		m_zpFog[i].AddGeo(&m_zFog[i]);
		
		//Transparency vom Fog festlegen
		//OutputDebugString("\n");
		fAnzahl = fAnzahl - (100 / MAX_FOG);
		//OutputDebugString(std::to_string(fAnzahl / 100.0F).c_str());

		//Transparency der Plane
		m_zmFog[i].SetTransparency(fAnzahl / 100.0F);

		//Abstand der Planes festlegen
		fAbstand -= 25;

		//Fog verschieben
		m_zpFog[i].TranslateZDelta(fAbstand);

		//Placement der Szene hinzuf�gen
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