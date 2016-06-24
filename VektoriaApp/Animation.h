#pragma once

#include "Vektoria\Root.h"
#include <list>
#include "StringToChar.h"


using namespace Vektoria;

//----------------------------------
//Animationsklasse um Bilder hintereinander abzuspielen.
//Author: Christoph Fischmann
//Aenderung: 2015-06-01
//----------------------------------

class CAnimation
{
public:
	CAnimation();
	~CAnimation();

	//Beispiel: Init(&mvz, 10, "textures\\OrdnerNameABC", "jpg"); 
	void Init(CViewport * mzv, int iAnzahlBilder, std::string sBilderPfad, std::string sDateityp);

	void InitFlackern(int iAnzahl);


	void Run(float fTime); 

	//Wie lange soll das Bild angezeigt werden?
	void SetTime(int iBildNummer, float fTimeinMilli);

	//Wie lange soll der FadeOut gehen?
	void SetFadeInOut(int iBildnummer, float fTimeinMilli);		


	void StartAnimation(); 
	void StopAnimation(); 
	bool IsFinished(); 

private: 

	void DoingAnimation(); 


	CImage MainImageAnimation; 
	COverlay MainOverlayAnimation; 

	CMaterial * aMaterials; 
	COverlay * aOverlays;
	float * afAnzeigeDauer; 
	float * afFadeOutTimes; 

	int iArraygroesse;

	
	
	bool bAnimationOn;
	bool bAnimationbeendet = false; 
	int iAktuellesBild;

	bool bFadeOutStarted = false;
	
	//float fFadeOutSteps = 0.0F; 
	float fFadeOutTimer = 0.0F;
	float fTransparency = 1.0; 

	float fTimeStart = -1;

	float m_fTimeDelta = -1; 
	





	CStringToChar stc;  



};

