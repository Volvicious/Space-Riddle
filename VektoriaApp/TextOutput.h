#pragma once
#include "Vektoria\Root.h"
#include "TastaturGER.h"

using namespace Vektoria; 
class CTextOutput
{
public:
	CTextOutput();
	~CTextOutput();

	COverlay OverlayBackGround; // Hintergrund
	CImage ImageBackground;

	CWritingFont writingfont;
	CWritingChar writingchar; 
	CFloatRect floatrect;
	CWriting writing;

	void Init(CViewport * ViewPortPtr);
	void Write(std::string s);
	void WriteFromTastatur(CTastaturGER * TastaturGer);
	void WriteTest();


};
//

