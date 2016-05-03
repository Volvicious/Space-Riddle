#include "Steuerung.h"

CSteuerung::CSteuerung()
{
}


CSteuerung::~CSteuerung()
{
}

void CSteuerung::Tick(CPlacement * placement, CDeviceKeyboard keyboard)
{
	if (keyboard.KeyPressed(DIK_W) && placement->GetTranslation().GetY() < MAX_TUBE)
	{
		pfvVertikal += 1.0F / 1000.0F;
	}

	if (keyboard.KeyPressed(DIK_A) && placement->GetTranslation().GetX() > MIN_TUBE)
	{
		pfvHorizontal -= 1.0F / 1000.0F;
	}

	if (keyboard.KeyPressed(DIK_S) && placement->GetTranslation().GetY() > MIN_TUBE)
	{
		pfvVertikal -= 1.0F / 1000.0F;
	}

	if (keyboard.KeyPressed(DIK_D) && placement->GetTranslation().GetX() < MAX_TUBE)
	{
		pfvHorizontal += 1.0F / 1000.0F;
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
	//Bremsen Y-Richtung
	if (pfvVertikal > 0)
	{
		if (placement->GetTranslation().GetY() <= MAX_TUBE && placement->GetTranslation().GetY() >= MIN_TUBE)
		{
			pfvVertikal -= 0.5F / 1000.0F;

			if (pfvVertikal < 0)
			{
				pfvVertikal = 0.0f;
			}
		}
	}

	//Bremsen Y-Richtung
	if (pfvVertikal < 0)
	{
		if (placement->GetTranslation().GetY() <= MAX_TUBE && placement->GetTranslation().GetY() >= MIN_TUBE)
		{
			pfvVertikal += 0.5F / 1000.0F;

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
			pfvHorizontal -= 0.5F / 1000.0F;

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
			pfvHorizontal += 0.5F / 1000.0F;

			if (pfvHorizontal > 0)
			{
				pfvHorizontal = 0.0F;
			}
		}
	}


	//Vertikal oben
	if (placement->GetTranslation().GetY() >= MAX_TUBE)
	{
		pfvVertikal -= 3.0F / 1000.0F;

		if (pfvVertikal < (-1.0F / MAX_TUBE))
		{
			pfvVertikal = -1.0F / MAX_TUBE;
		}
	}

	//Vertikal unten
	if (placement->GetTranslation().GetY() <= MIN_TUBE)
	{
		pfvVertikal += 3.0F / 1000.0F;
	}

	//Horizontal links
	if (placement->GetTranslation().GetX() <= MIN_TUBE)
	{
		pfvHorizontal += 3.0F / 1000.0F;
	}

	//Horizontal rechts
	if (placement->GetTranslation().GetX() >= MAX_TUBE)
	{
		pfvHorizontal -= 3.0F / 1000.0F;
	}
}
