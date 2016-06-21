#include "Steuerung.h"

CSteuerung::CSteuerung()
{
}


CSteuerung::~CSteuerung()
{
}

void CSteuerung::Tick(float fGeschwindigkeit, CPlacement * placement, CDeviceKeyboard * keyboard)
{


	//Tr�gheit

	SoftBorder(fGeschwindigkeit, placement);

	//Special Animation
	if (! m_RAnimation.Run(placement, keyboard, fGeschwindigkeit) ) {

		if (keyboard->KeyPressed(DIK_W) && placement->GetTranslation().GetY() < MAX_TUBE)
		{
			pfvVertikal += (2.0F / 10.0F) * fGeschwindigkeit;
		}

		if (keyboard->KeyPressed(DIK_A) && placement->GetTranslation().GetX() > MIN_TUBE)
		{
			pfvHorizontal -= (2.0F / 10.0F) * fGeschwindigkeit;
		}

		if (keyboard->KeyPressed(DIK_S) && placement->GetTranslation().GetY() > MIN_TUBE)
		{
			pfvVertikal -= (2.0F / 10.0F) * fGeschwindigkeit;
		}

		if (keyboard->KeyPressed(DIK_D) && placement->GetTranslation().GetX() < MAX_TUBE)
		{
			pfvHorizontal += (2.0F / 10.0F) * fGeschwindigkeit;
		}

		//Raumschiff wird bewegt
		CHVector vec = CHVector(placement->GetTranslation().GetX() + pfvHorizontal,
			placement->GetTranslation().GetY() + pfvVertikal,
			placement->GetTranslation().GetZ());

		placement->RotateZ(-pfvHorizontal*2);
		placement->RotateXDelta(pfvVertikal*2+0.05F);
		placement->TranslateDelta(vec);

			/*placement->Translate(CHVector(placement->GetTranslation().GetX() + pfvHorizontal,
				placement->GetTranslation().GetY() + pfvVertikal,
				placement->GetTranslation().GetZ())); */

	}

	//Geschwindigkeit reseten
	//MaxTube(fGeschwindigkeit, placement);
	Inertia(fGeschwindigkeit, placement);
	
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
	if (keyboard->KeyDown(DIK_P))
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

void CSteuerung::Inertia(float fGeschwindigkeit, CPlacement * placement)
{
	//Bremsen Y-Richtung
	if (pfvVertikal > 0)
	{
		if (placement->GetTranslation().GetY() <= MAX_TUBE && placement->GetTranslation().GetY() >= MIN_TUBE)
		{
			pfvVertikal -= 0.5F / 10.0F * fGeschwindigkeit;
		}
	}

	//Bremsen Y-Richtung
	if (pfvVertikal < 0)
	{
		if (placement->GetTranslation().GetY() <= MAX_TUBE && placement->GetTranslation().GetY() >= MIN_TUBE)
		{
			pfvVertikal += 0.5F / 10.0F * fGeschwindigkeit;

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
			pfvHorizontal -= 0.5F / 10.0F * fGeschwindigkeit;

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
			pfvHorizontal += 0.5F / 10.0F * fGeschwindigkeit;

			//Bremst bis die Geschwindigkeit 0 ist
			if (pfvHorizontal > 0)
			{
				pfvHorizontal = 0.0F;
			}
		}
	}
}

void CSteuerung::MaxTube(float fGeschwindigkeit, CPlacement * placement)
{
	//Vertikal oben
	if (placement->GetTranslation().GetY() >= MAX_TUBE && pfvVertikal > 0)
	{
		pfvVertikal = 0.0F;
	}

	//Vertikal unten
	if (placement->GetTranslation().GetY() <= MIN_TUBE && pfvVertikal < 0)
	{
		pfvVertikal = 0.0F;
	}

	//Horizontal links
	if (placement->GetTranslation().GetX() <= MIN_TUBE && pfvHorizontal < 0)
	{
		pfvHorizontal = 0.0F;
	}

	//Horizontal rechts
	if (placement->GetTranslation().GetX() >= MAX_TUBE && pfvHorizontal > 0)
	{
		pfvHorizontal = 0.0F;
	}
}

void CSteuerung::SoftBorder(float fGeschwindigkeit, CPlacement * placement) {

	//Vertikal oben

	bFadeOben = placement->GetTranslation().GetY() >= MAX_TUBE + 2;

	//Vertikal unten
	bFadeUnten = placement->GetTranslation().GetY() <= MIN_TUBE -2;

	//Horizontal links
	bFadeLinks = placement->GetTranslation().GetX() <= MIN_TUBE -2;

	//Horizontal rechts
	bFadeRechts = placement->GetTranslation().GetX() >= MAX_TUBE + 2;

	if (bFadeOben) {
		pfvVertikal = -10.5F * fGeschwindigkeit;
		bFadeOben = placement->GetTranslation().GetY() >= MAX_TUBE;
	}

	if (bFadeUnten) {
		pfvVertikal = 10.5F * fGeschwindigkeit;
		bFadeUnten = placement->GetTranslation().GetY() <= MIN_TUBE;
	}

	if (bFadeLinks) {
		pfvHorizontal = 10.5F * fGeschwindigkeit;
		bFadeLinks = placement->GetTranslation().GetX() <= MIN_TUBE;
	}

	if (bFadeRechts) {
		pfvHorizontal = -10.5F * fGeschwindigkeit;
		bFadeRechts = placement->GetTranslation().GetX() >= MAX_TUBE;
	}


}
