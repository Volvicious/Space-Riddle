#pragma once

#include "Vektoria\Root.h"

using namespace Vektoria;

class CRaumschiff
{
public:
	CRaumschiff();
	~CRaumschiff();

	void Init(CScene * scene);

private:
	CGeo * m_zRaumschiff;
	CFileWavefront m_filewavefront;
	CPlacement m_zpRaumschiff;
	
};

