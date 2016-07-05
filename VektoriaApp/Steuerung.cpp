#include "Steuerung.h"

CSteuerung::CSteuerung()
{
}


CSteuerung::~CSteuerung()
{
}

void CSteuerung::Tick(float fTimeDelta, CPlacement * placement, CDeviceKeyboard * keyboard)
{
	

	//Special Animation, sonst "Normale Lenkung"
	if (! m_RAnimation.Run(placement, keyboard, fTimeDelta) ) {

		if (keyboard->KeyPressed(DIK_W))
		{
			pfvVertikal += (2.0F / 10.0F) * fTimeDelta;
		}

		if (keyboard->KeyPressed(DIK_A) && placement->GetTranslation().GetX() > MIN_TUBE)
		{
			pfvHorizontal -= (2.0F / 10.0F) * fTimeDelta;
		}

		if (keyboard->KeyPressed(DIK_S) && placement->GetTranslation().GetY() > MIN_TUBE)
		{
			pfvVertikal -= (2.0F / 10.0F) * fTimeDelta;
		}

		if (keyboard->KeyPressed(DIK_D) && placement->GetTranslation().GetX() < MAX_TUBE)
		{
			pfvHorizontal += (2.0F / 10.0F) * fTimeDelta;
		}

		//Raumschiff wird bewegt
		CHVector vec = CHVector(placement->GetTranslation().GetX() + pfvHorizontal,
			placement->GetTranslation().GetY() + pfvVertikal,
			placement->GetTranslation().GetZ());

		//Raumschiff Neigung
		placement->RotateZ(-pfvHorizontal*2);
		placement->RotateXDelta(pfvVertikal+0.05F);
		placement->TranslateDelta(vec);
	}
	else{

		if (keyboard->KeyPressed(DIK_D) && placement->GetTranslation().GetX() < MAX_TUBE)
		{
			pfvHorizontal = (20.0F) * fTimeDelta;
		}

		if (keyboard->KeyPressed(DIK_A) && placement->GetTranslation().GetX() > MIN_TUBE)
		{
			pfvHorizontal = -(20.0F) * fTimeDelta;
		}


	}


	//Inertia jetzt in der If, weil wenn das Raumschiff auserhalb ist, sollte die Geschwindigkeit konstant auf "zurueckschieben" bleiben...
	if (!SoftBorder(fTimeDelta, placement)){
		Inertia(fTimeDelta, placement);
	}

	
}

int CSteuerung::StartGame(int iScene, CDeviceKeyboard * keyboard)
{
	if (keyboard->KeyDown(DIK_SPACE))
	{
		iScene = 1;
	}

	return iScene;
}

int CSteuerung::PauseGame(int iScene, CDeviceKeyboard * keyboard)
{
	//Außer in Frage und Hauptmenue (wegen Eingabe)
	if (keyboard->KeyDown(DIK_P)&& iScene != 0 && iScene != 2 && iScene != 6)
	{
		if (iScene != 4)
		{
			SceneSpeicher = iScene;
			iScene = 4;
		}
		else if (iScene == 4)
		{
			iScene = SceneSpeicher;
		}
	}

	return iScene;
}

int CSteuerung::ContinueGame(int iScene, CDeviceKeyboard * keyboard)
{
	if (keyboard->KeyDown(DIK_SPACE))
	{
		iScene = 1;
	}

	return iScene;
}

int CSteuerung::Highscore(int iScene, CDeviceKeyboard * keyboard)
{
	if (keyboard->KeyDown(DIK_SPACE))
	{
		iScene = 7;
	}

	return iScene;
}

int CSteuerung::Hauptmenue(int iScene, CDeviceKeyboard * keyboard)
{
	if (keyboard->KeyDown(DIK_SPACE))
	{
		iScene = 0;
	}

	return iScene;
}

void CSteuerung::Inertia(float fTimeDelta, CPlacement * placement)
{
	//Bremsen Y-Richtung
	if (pfvVertikal > 0)
	{
		if (placement->GetTranslation().GetY() <= MAX_TUBE && placement->GetTranslation().GetY() >= MIN_TUBE)
		{
			pfvVertikal -= 0.5F / 10.0F * fTimeDelta;
		}
	}

	//Bremsen Y-Richtung
	if (pfvVertikal < 0)
	{
		if (placement->GetTranslation().GetY() <= MAX_TUBE && placement->GetTranslation().GetY() >= MIN_TUBE)
		{
			pfvVertikal += 0.5F / 10.0F * fTimeDelta;

			//Bremst bis die Geschwindigkeit 0 ist
			if (pfvVertikal > 0)
			{
				pfvVertikal = 0.0f;
			}
		}
	}

	//Bremsen X-Richtung
	if (pfvHorizontal > 0)
	{
		if (placement->GetTranslation().GetX() <= MAX_TUBE && placement->GetTranslation().GetX() >= MIN_TUBE)
		{
			pfvHorizontal -= 0.5F / 10.0F * fTimeDelta;

			//Bremst bis die Geschwindkeit 0 ist
			if (pfvHorizontal < 0)
			{
				pfvHorizontal = 0.0F;
			}
		}
	}

	//Bremsen X-Richtung
	if (pfvHorizontal < 0)
	{
		if (placement->GetTranslation().GetX() <= MAX_TUBE && placement->GetTranslation().GetX() >= MIN_TUBE)
		{
			pfvHorizontal += 0.5F / 10.0F * fTimeDelta;

			//Bremst bis die Geschwindigkeit 0 ist
			if (pfvHorizontal > 0)
			{
				pfvHorizontal = 0.0F;
			}
		}
	}
}



bool CSteuerung::SoftBorder(float fTimeDelta, CPlacement * placement) {

	float fDistance = sqrt((placement->GetTranslation().GetX()*
		placement->GetTranslation().GetX() + placement->GetTranslation().GetY()*
		placement->GetTranslation().GetY()));

	if (fDistance >= 15.0F && !bFadeSoft) {
		bFadeSoft = true;
		fFadeVer = -pfvVertikal * 0.5F; 
		fFadeHor = -pfvHorizontal * 0.5F;

	}

	if (bFadeSoft) {
		
		pfvVertikal = fFadeVer; 
		pfvHorizontal = fFadeHor;

		if (fDistance <= 14.8F) {
			bFadeSoft = false; 
		}

	}
	
	return bFadeSoft;

}
