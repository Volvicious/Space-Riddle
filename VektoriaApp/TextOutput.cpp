
#include "TextOutput.h"



CTextOutput::CTextOutput()
{
}

CTextOutput::~CTextOutput()
{
}




void CTextOutput::Init(CViewport * ViewPortPtr, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize) {
	
	ULDebug("----------------Wird genutzt 1-----------");
	writingfont.Init(caPathFont, true);
	writingfont.RotateHue(3.5F);
	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 100, &writingfont);
	writing.SetLayer(0.2F);
	

	ViewPortPtr->AddWriting(&writing);
}


void CTextOutput::Init(COverlay * ptroverlay, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize, float iLayer) {


	ptrOverlay = ptroverlay; 
	writingfont.Init(caPathFont, true);
	writingfont.RotateHue(3.5F);;
	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 100, &writingfont);
	
	writing.SetLayer(0.2F);
	
	ptrOverlay->AddWriting(&writing);

}

void CTextOutput::Init(CViewport * PtrView, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize, float iLayer) {


	writingfont.Init(caPathFont, true);
	writingfont.RotateHue(3.5F);
	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 100, &writingfont);

	writing.SetLayer(iLayer);
	PtrView->AddWriting(&writing);

}

void CTextOutput::Init(COverlay * OverLayPtr, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize) {

	writingfont.Init(caPathFont, true);
	writingfont.RotateHue(3.5F);
	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 100 , &writingfont);
	writing.SetLayer(0.2F);

	OverLayPtr->AddWriting(&writing);
}

void CTextOutput::Init(COverlay * OverLayPtr, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize, int iVisibleChars_) {


	iVisibleChars =  iVisibleChars_; 
	bPrintMiddle = true; 

	writingfont.Init(caPathFont, true);
	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 150, &writingfont);
	writing.SetLayer(0.2F);

	OverLayPtr->AddWriting(&writing);
}

void CTextOutput::Init(CViewport * viewPort, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize, int iVisibleChars_) {


	iVisibleChars = iVisibleChars_;
	bPrintMiddle = true;
	writingfont.RotateHue(3.5F);

	writingfont.Init(caPathFont, true);
	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 150, &writingfont);
	writing.SetLayer(0.2F);

	viewPort->AddWriting(&writing);
}




void CTextOutput::SwitchOn() {
	writing.SwitchOn(); 
}

void CTextOutput::SwitchOff() {

	writing.SwitchOff(); 
}

CWriting * CTextOutput::getWritingPtr() {
	return &writing;
}


void CTextOutput::SetString(std::string s) {

	if (bPrintMiddle) {

		sStringToWrite = ""; 
		int j = (iVisibleChars - s.size()) / 2;
		for (int i = 0; i < j; i++){
			sStringToWrite += " ";
		}
		sStringToWrite += s;
		
	}
	else {
		sStringToWrite = s;
	}

	
}

std::string CTextOutput::GetString() {

	return sStringToWrite;
}


void CTextOutput::WriteFromTastatur() {
	
	Write(ptrTastaturGer->GetStringPtr());

}


void CTextOutput::WriteFromTastatur(CTastaturGER * TastaturGer) {

	Write (TastaturGer->GetStringPtr());
}

void CTextOutput::Write(std::string * s ) {

	writing.PrintF("%s", s->c_str());
	Workaround(s);
}

void CTextOutput::Write(std::string  s) {

	writing.PrintF("%s", s.c_str());
	Workaround(&s);
}

void CTextOutput::WriteSavedString() {

	Write(sStringToWrite);
}

void CTextOutput::WriteTest() {

	writing.PrintFloat(123.2F);


}

CFloatRect CTextOutput::GetWritingRect() {

	return writing.GetRect();
}


void CTextOutput::SetWritingRect(CFloatRect rect) {
	writing.SetRect(rect);
}

void CTextOutput::Workaround(std::string * s) {

	for (int i = 0; i < s->length(); i++) {

		switch (s->at(i)) {

			case 'Ö':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(6, 11);
				break;

			case 'ö':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(6, 13);
				break;
			case 'Ä':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(4, 10);

				break;
			case 'ä':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(4, 12);

				break;
			case 'Ü':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(12, 11);

				break;
			case 'ü':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(12, 13);

				break;
			case 'ß':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(15, 11);
				break; 

			case '§':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(7, 8);

			case'à':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(0, 12);

				break;
			case 'è':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(8, 12);
				break;
			case 'ì':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(12, 10);
				break;
			case 'ò':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(2, 11);
				break;
			case 'ù':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(9, 13);
				break;
			case 'À':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(0, 10);
				break;
			case 'È':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(8, 10);
				break;
			case 'Ì':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(12, 10);
				break;
			case 'Ò':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(2, 11);
				break;
			case 'Ù':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(9, 11);
				break;

			case 'á':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(1, 12);

				break;
			case 'é':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(9, 12);

				break;
			case 'í':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(13, 10);
				break;
			case 'ó':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(3, 11);
				break;
			case 'ú':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(10, 13);
				break;
			case 'Á':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(1, 10);
				break;
			case 'É':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(9, 10);
				break;
			case 'Í':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(13, 10);
				break;
			case 'Ó':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(3, 11);
				break;
			case 'Ú':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(10, 11);
				break;

			

			case 'â':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(2, 12);
				break;
			case 'ê':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(10, 12);
				break;
			case 'î':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(14, 10);
				break;
			case 'ô':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(4, 11);
				break;
			case  'û':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(11, 13);
				break;
			case 'Â':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(2, 10);
				break;
			case 'Ê':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(10, 10);
				break;
			case  'Î':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(14, 10);
				break;
			case 'Ô':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(4, 11);
				break;
			case 'Û':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(11, 11);
				break;
		
		default:
			break;
		}
	}

}