#include "TextOutput.h"



CTextOutput::CTextOutput()
{
}


CTextOutput::~CTextOutput()
{
}


void CTextOutput::Init(CViewport * ViewPortPtr) {

	ImageBackground.Init("textures\\blue_image.jpg");
	OverlayBackGround.InitFull(&ImageBackground);
	//ViewPortPtr->AddOverlay(&OverlayBackGround);
	OverlayBackGround.SetLayer(0.5F);

	writingfont.Init("fonts\\LucidaConsoleBlackF.png", true);
	writingfont.Fini();
	floatrect.Init(0.1F, 0.1F, 1.0F, .02F);
	floatrect.Fini();

	writing.Init(floatrect, 100, &writingfont);
	writing.SetLayer(0.4F);
	//writing.AddOverlay(&OverlayBackGround);
	writing.Fini();

	ViewPortPtr->AddWriting(&writing);

}
//

void CTextOutput::Write(std::string s){

	writing.PrintF("%s", s.c_str());
}

void CTextOutput::WriteFromTastatur(CTastaturGER * TastaturGer) {

	std::string s = TastaturGer->GetString();
	char temp[1024];
	strcpy(temp, s.c_str());
	
	writing.PrintString(temp);


}
