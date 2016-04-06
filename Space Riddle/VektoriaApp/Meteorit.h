#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

class CMeteorit
{
public:
	CMeteorit();
	~CMeteorit();

	CPlacement getPlacement(){ return m_zpMeteorit; };

private:
	// Hier ist Platz für die Vektoriaobjekte:
	CScene m_zs;
	CMaterial m_zMaterialMeteorit;
	CPlacement m_zpMeteorit;
	CGeoSphere m_zMeteorit;

};

