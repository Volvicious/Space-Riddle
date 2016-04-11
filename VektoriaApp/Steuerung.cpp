#include "Steuerung.h"


CSteuerung::CSteuerung()
{
}


CSteuerung::~CSteuerung()
{
}

void CSteuerung::Bewegung(CPlacement * placement)
{
	Init(placement);
	Trägheit(fvVertikal, fvHorizontal);
	placement->Translate(CHVector(placement->GetTranslation().GetX() + fvHorizontal, 
		placement->GetTranslation().GetY() + fvVertikal, 
		placement->GetTranslation().GetZ()));

}

void CSteuerung::Init(CPlacement * placement)
{
	if (m_zKeyboard.KeyPressed(DIK_W) && placement->GetTranslation().GetY() < 10.0F)
	{
		fvVertikal += 3.0F / 1000.0F;
	}

	if (m_zKeyboard.KeyPressed(DIK_A) && placement->GetTranslation().GetX() < -10.0F)
	{
		fvHorizontal -= 3.0F / 1000.0F;
	}

	if (m_zKeyboard.KeyPressed(DIK_S) && placement->GetTranslation().GetY() < -10.0F)
	{
		fvVertikal -= 3.0F / 1000.0F;
	}

	if (m_zKeyboard.KeyPressed(DIK_D) && placement->GetTranslation().GetX() < 10.0F)
	{
		fvHorizontal += 3.0F / 1000.0F;
	}

}

void CSteuerung::Trägheit(float fvVertikal, float fvHorizontal)
{
	//Vertikal
	if (m_zKeyboard.KeyPressed(DIK_W) == false && m_zKeyboard.KeyPressed(DIK_S) == false)
	{
		if (fvVertikal > 0)
		{
			fvVertikal -= 3.0F / 1000.0F;

			if (fvVertikal < 0)
			{
				fvVertikal = 0;
			}
		}

		if (fvVertikal < 0)
		{
			fvVertikal += 3.0F / 1000.0F;

			if (fvVertikal > 0)
			{
				fvVertikal = 0;
			}
		}
	}

	//Horizontal
	if (m_zKeyboard.KeyPressed(DIK_A) == false && m_zKeyboard.KeyPressed(DIK_D) == false)
	{
		if (fvHorizontal > 0)
		{
			fvHorizontal -= 3.0F / 1000.0F;

			if (fvHorizontal < 0)
			{
				fvHorizontal = 0;
			}
		}

		if (fvHorizontal < 0)
		{
			fvHorizontal += 3.0F / 1000.0F;

			if (fvHorizontal > 0)
			{
				fvHorizontal = 0;
			}
		}
	}
}
