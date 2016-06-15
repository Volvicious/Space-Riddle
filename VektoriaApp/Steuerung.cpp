#include "Steuerung.h"

CSteuerung::CSteuerung()
{
}


CSteuerung::~CSteuerung()
{
}

void CSteuerung::Tick(float fGeschwindigkeit, CPlacement * placement, CDeviceKeyboard * keyboard)
{
	if (keyboard->KeyPressed(DIK_W) && placement->GetTranslation().GetY() < MAX_TUBE)
	{
		pfvVertikal += 3.0F / 10.0F * fGeschwindigkeit;
	}

	if (keyboard->KeyPressed(DIK_A) && placement->GetTranslation().GetX() > MIN_TUBE)
	{
		pfvHorizontal -= 3.0F / 10.0F * fGeschwindigkeit;
	}

	if (keyboard->KeyPressed(DIK_S) && placement->GetTranslation().GetY() > MIN_TUBE)
	{
		pfvVertikal -= 3.0F / 10.0F * fGeschwindigkeit;
	}

	if (keyboard->KeyPressed(DIK_D) && placement->GetTranslation().GetX() < MAX_TUBE)
	{
		pfvHorizontal += 3.0F / 10.0F * fGeschwindigkeit;
	}

	//Trägheit
	Inertia(fGeschwindigkeit, placement);

	//Raumschiff wird bewegt
	placement->Translate(CHVector(placement->GetTranslation().GetX() + pfvHorizontal, 
		placement->GetTranslation().GetY() + pfvVertikal, 
		placement->GetTranslation().GetZ()));

	//Geschwindigkeit reseten
	MaxTube(fGeschwindigkeit, placement);

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
	if (keyboard->KeyDown(DIK_RETURN))
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
