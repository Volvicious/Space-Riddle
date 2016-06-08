#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

class CIngameOverlays
{
public:
	CIngameOverlays();
	~CIngameOverlays();

	void Init(CViewport * viewport);
	
	void SwitchOn(int iOverlayNummer);
	void SwitchOff(int iOverlayNummer);
	void SetLayer(int iOverlayNummer, float LayerDistance);

	void SwitchOffAll();

	COverlay * getOverlay(int iOverlayNummer) { return &m_zOverlay[iOverlayNummer]; };

private:

	//Overlays
	CImage m_zImage[10];
	COverlay m_zOverlay[10];

};

