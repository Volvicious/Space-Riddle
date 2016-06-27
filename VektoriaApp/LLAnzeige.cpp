#include "LLAnzeige.h"



CLLAnzeige::CLLAnzeige()
{
}


CLLAnzeige::~CLLAnzeige()
{
}

void CLLAnzeige::Init(CViewport * mzv) {

	mzv->AddOverlay(&m_zoAnzeige);
	
	iLebenAnzahl = 10;
	iLevelNummer = 1;
	

	font.Init("fonts\\Nasalization-rg-Red.png", true);
	writing.Init(CFloatRect(0.0F, 0.0F, 2.0F, 0.2F), 100, &font);
	writing.RotateHue(PI / 4);
	//m_zoAnzeige.AddWriting(&writing);
	

	top.Init(&m_zoAnzeige, "fonts\\Nasalization-rg-Red.png", 0.85F, 0.0F, 2.0F, .03F, 0.01F);


	for (int i = 0; i < 11; i++) {


		std::string s = "textures\\lebensanzeige\\Lebensanzeige";
		s += std::to_string(i); 
		s += ".png";
		char * temp = (char*)s.c_str();

		LebensImages[i].Init(temp);
		
		LebensOverlays[i].Init(&LebensImages[i], CFloatRect(.85F, 0.0F, 0.15F, 0.1F));
		m_zoAnzeige.AddOverlay(&LebensOverlays[i]);
		LebensOverlays[i].SetLayer(0.18F);
		LebensOverlays[i].SwitchOff();

		
	}

	


	LebensOverlays[iLebenAnzahl].SwitchOn();
	//m_zoAnzeige.SwitchOff();
	//COverlay * ptrOver = &m_zoAnzeige;
	//ptrOver->AddWriting(&writing);

	//m_zoAnzeige.AddWriting(&writing);

	//top.Init(mzv, "fonts\\Nasalization-rg-Red.png", 0.4F, 0.3F, 2.0F, .03F);

	setLevelNummer(iLevelNummer);

	m_zoAnzeige.SwitchOff(); 
	
	
}

void CLLAnzeige::Run() {

	if (bIsOn) {

		//writing.PrintF("Test");
		top.WriteSavedString();		
	}



}


void CLLAnzeige::setLevelNummer(int i) {

	iLevelNummer = i;
	
	std::string s = "";
	if (i < 10) {
		s += "0";
		s += std::to_string(i);
	}
	else {

		s += std::to_string(i); 
	}

	top.SetString(s);
}

int CLLAnzeige::getLevelNummer() {

	return iLevelNummer; 
}

void CLLAnzeige::setLebenAnzahl(int i) {
	

	if (i >= 0 && i <= 10) {
		LebensOverlays[iLebenAnzahl].SwitchOff();
		iLebenAnzahl = i;
		LebensOverlays[i].SwitchOn();
	}

	if (i < 0) {
		LebensOverlays[iLebenAnzahl].SwitchOff(); 
		iLebenAnzahl = 0; 
		LebensOverlays[0].SwitchOn();
	}

	if (i > 10) {
		LebensOverlays[iLebenAnzahl].SwitchOff();
		iLebenAnzahl = 10;
		LebensOverlays[10].SwitchOn();
	}

}

int CLLAnzeige::getLebenAnzahl() {
	return iLebenAnzahl; 
}

void CLLAnzeige::SwitchOn() {

	m_zoAnzeige.SwitchOn();
	bIsOn = true; 

}
void CLLAnzeige::SwitchOff() {

	m_zoAnzeige.SwitchOff();
	top.SwitchOff();
	bIsOn = false; 

}
