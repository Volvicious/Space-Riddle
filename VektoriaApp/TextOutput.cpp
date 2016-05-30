#include "TextOutput.h"



CTextOutput::CTextOutput()
{
}

CTextOutput::~CTextOutput()
{
}




void CTextOutput::Init(CViewport * ViewPortPtr, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize) {
	
	writingfont.Init(caPathFont, true);

	writingfont.Fini();
	floatrect.Init(fxPos, fyPos, fxSize, fySize);
	floatrect.Fini();

	writing.Init(floatrect, 100, &writingfont);
	writing.SetLayer(0.2F);
	writing.Fini();
	ViewPortPtr->AddWriting(&writing);

	

}

void CTextOutput::Init(CViewport * ViewPortPtr, char * caPathFont,CFloatRect * floatrect_) {

	writingfont.Init(caPathFont, true);

	writingfont.Fini();
	floatrect.Init(floatrect_->GetXPos(), floatrect_->GetYPos(), floatrect_->GetXSize(), floatrect_->GetYSize());
	floatrect.Fini();
	writing.Init(floatrect, 100, &writingfont);
	writing.Fini();
	ViewPortPtr->AddWriting(&writing);

}

void CTextOutput::Init(CViewport * ViewPortPtr, CTastaturGER * ptrrTastaturGer, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize) {

	writingfont.Init(caPathFont, true);

	writingfont.Fini();
	floatrect.Init(fxPos, fyPos, fxSize, fySize);
	floatrect.Fini();

	writing.Init(floatrect, 100, &writingfont);

	writing.Fini();
	ViewPortPtr->AddWriting(&writing);

	ptrTastaturGer = ptrrTastaturGer;

}

void CTextOutput::Init(COverlay * OverLayPtr, char * caPathFont, float fxPos, float fyPos, float fxSize, float fySize) {

	writingfont.Init(caPathFont, true);

	writingfont.Fini();
	floatrect.Init(fxPos, fyPos, fxSize, fySize);
	floatrect.Fini();

	writing.Init(floatrect, 150 , &writingfont);
	writing.SetLayer(0.2F);
	writing.Fini();

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
	sStringToWrite = s; 
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


				break;
		default:
			break;
		}
	}

}