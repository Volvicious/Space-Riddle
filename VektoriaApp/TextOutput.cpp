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

	//writingfont.Fini();

	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 100, &writingfont);
	//writing.SetLayer(0.2F);
	//writing.Fini();
	ViewPortPtr->AddWriting(&writing);
}


void CTextOutput::Init(COverlay * ptroverlay, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize, float iLayer) {

	ULDebug("----------------Wird genutzt 2-----------");

	ptrOverlay = ptroverlay; 

	writingfont.Init(caPathFont, true);
	writingfont.RotateHue(PI);
	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 100, &writingfont);
	
	//writing.SetLayer(0.2F);
	
	ptrOverlay->AddWriting(&writing);

}

void CTextOutput::Init(COverlay * OverLayPtr, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize) {
	ULDebug("----------------Wird genutzt 3-----------");


	writingfont.Init(caPathFont, true);
	//writingfont.RotateHue(.5F);

	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 100 , &writingfont);
	//writing.SetLayer(0.2F);

	OverLayPtr->AddWriting(&writing);
}

void CTextOutput::Init(COverlay * OverLayPtr, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize, int iVisibleChars_) {
	ULDebug("----------------Wird genutzt 4-----------");



	iVisibleChars =  iVisibleChars_; 
	bPrintMiddle = true; 

	writingfont.Init(caPathFont, true);

	writingfont.Fini();
	

	writing.Init(CFloatRect(fxPos, fyPos, fxSize, fySize), 150, &writingfont);
	writing.SetLayer(0.2F);

	OverLayPtr->AddWriting(&writing);
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

			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(6, 11);
				break;

			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(6, 13);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(4, 10);

				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(4, 12);

				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(12, 11);

				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(12, 13);

				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(15, 11);
				break; 

			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(7, 8);

			case'�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(0, 12);

				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(8, 12);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(12, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(2, 11);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(9, 13);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(0, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(8, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(12, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(2, 11);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(9, 11);
				break;

			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(1, 12);

				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(9, 12);

				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(13, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(3, 11);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(10, 13);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(1, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(9, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(13, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(3, 11);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(10, 11);
				break;

			

			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(2, 12);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(10, 12);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(14, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(4, 11);
				break;
			case  '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(11, 13);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(2, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(10, 10);
				break;
			case  '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(14, 10);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(4, 11);
				break;
			case '�':
				writing.m_writingchars.m_apwritingchar[i]->m_pmaterial->SetPic(11, 11);
				break;
		
		default:
			break;
		}
	}

}