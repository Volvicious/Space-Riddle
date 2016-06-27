#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

//----------------------------------
//Klasse fuer Maus um Device Maus Zentral zu verwalten.
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

class CMaus
{
public:
	CMaus();
	~CMaus();


	void Init(CViewport * m_zv, CFrame * m_zf);
	void Run();												//resetet doppelklickschutz
	void SwitchOn(); 
	void SwitchOff();

	bool IsKeyDown();										//fuer manuelle Spielereien
	void SetKeyDownTrue();									//fuer manuelle Spielereien

	bool PickOverlayandLeftKlick(COverlay * ptro);			// pickoverlay, leftklick, doppelklickschutz: alles in einem 
	bool PickOverlay(COverlay * ptro);						//alles in einem				
	bool PickOverlayOrWritingandLeftKlick(CWriting * ptrw);	//// pickoverlay, leftklick, doppelklickschutz 
	CDeviceCursor * getDevicePtr();
	COverlay * getMausOverlay(); 

private:

	CDeviceCursor m_zdCursor;
	CImage m_ziCurser;
	COverlay m_zoCurser;

	
	
	//Hilfsvar:
	bool bOn = false; 

	bool bKeyDown = true; 

};

