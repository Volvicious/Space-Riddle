#include "IngameOverlays.h"


CIngameOverlays::CIngameOverlays()
{
}


CIngameOverlays::~CIngameOverlays()
{
}

void CIngameOverlays::Init(CViewport * viewport)
{
	m_zImage[Pause].Init("textures\\PauseOverlay.png");
	m_zOverlay[Pause].InitFull(&m_zImage[0]);

	m_zImage[LevelCompleted].Init("textures\\LevelCompleted.png");
	m_zOverlay[LevelCompleted].InitFull(&m_zImage[1]);

	m_zImage[Verloren].Init("textures\\GameOver.png");
	m_zOverlay[Verloren].InitFull(&m_zImage[2]);

	//Overlays den Viewports hinzufügen
	for (int i = 0; i < 10; i++)
	{
		m_zOverlay[i].SwitchOff();
		viewport->AddOverlay(&m_zOverlay[i]);
	}
}

void CIngameOverlays::SwitchOn(int iOverlayNummer)
{
	m_zOverlay[iOverlayNummer].SwitchOn();
}

void CIngameOverlays::SwitchOff(int iOverlayNummer)
{
	m_zOverlay[iOverlayNummer].SwitchOff();
}

void CIngameOverlays::SwitchOffAll()
{
	for (int i = 0; i < 10; i++)
	{
		m_zOverlay[i].SwitchOff();
	}
}

void CIngameOverlays::SetLayer(int iOverlayNummer, float LayerDistance)
{
	m_zOverlay[iOverlayNummer].SetLayer(LayerDistance);
}
