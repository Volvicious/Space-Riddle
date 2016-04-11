#include "Steuerung.h"


CSteuerung::CSteuerung()
{
}


CSteuerung::~CSteuerung()
{
}

void CSteuerung::Tick(CPlacement * placement, CDeviceKeyboard keyboard)
{
	if (keyboard.KeyPressed(DIK_W) && placement->GetTranslation().GetY() < 10.0F)
	{
		pfvVertikal += 3.0F / 1000.0F;
	}

	if (keyboard.KeyPressed(DIK_A) && placement->GetTranslation().GetX() > -10.0F)
	{
		pfvHorizontal -= 3.0F / 1000.0F;
	}

	if (keyboard.KeyPressed(DIK_S) && placement->GetTranslation().GetY() > -10.0F)
	{
		pfvVertikal -= 3.0F / 1000.0F;
	}

	if (keyboard.KeyPressed(DIK_D) && placement->GetTranslation().GetX() < 10.0F)
	{
		pfvHorizontal += 3.0F / 1000.0F;
	}

	//Trägheit
	Inertia(placement);

	//Raumschiff wird bewegt
	placement->Translate(CHVector(placement->GetTranslation().GetX() + pfvHorizontal, 
		placement->GetTranslation().GetY() + pfvVertikal, 
		placement->GetTranslation().GetZ()));

}

void CSteuerung::Inertia(CPlacement * placement)
{
	//Bremsen
	if (pfvVertikal > 0)
	{
		if (placement->GetTranslation().GetY() <= 10.0F && placement->GetTranslation().GetY() >= -10.0F)
		{
			pfvVertikal -= 0.5F / 1000.0F;

			if (pfvVertikal < 0)
			{
				pfvVertikal = 0.0f;
			}
		}
	}

	//Bremsen 
	if (pfvVertikal < 0)
	{
		if (placement->GetTranslation().GetY() <= 10.0F && placement->GetTranslation().GetY() >= -10.0F)
		{
			pfvVertikal += 0.5F / 1000.0F;

			if (pfvVertikal > 0)
			{
				pfvVertikal = 0.0f;
			}
		}
	}


	//Vertikal oben
	if (placement->GetTranslation().GetY() >= 10.0F)
	{
		pfvVertikal -= 3.0F / 1000.0F;

		if (pfvVertikal < (-1.0F / 10.0F))
		{
			pfvVertikal = -1.0F / 10.0F;
		}
	}

	//Vertikal unten
	if (placement->GetTranslation().GetY() <= -10.0F)
	{
		pfvVertikal += 3.0F / 1000.0F;
	}

	//Horizontal links
	if (placement->GetTranslation().GetX() <= -10.0F)
	{
		pfvHorizontal += 3.0F / 1000.0F;
	}

	//Horizontal rechts
	if (placement->GetTranslation().GetX() >= 10.0F)
	{
		pfvHorizontal -= 3.0F / 1000.0F;
	}
}
