#include "LLAnzeige.h"



CLLAnzeige::CLLAnzeige()
{
}


CLLAnzeige::~CLLAnzeige()
{
}

void CLLAnzeige::Init(CViewport * mzv) {
	mzv->AddOverlay(&m_zoAnzeige);
	
	m_ziLebensBackground.Init("textures\\lebensanzeige\\lebensanzeigeleer.png");
	m_zoLebensbackground.Init(&m_ziLebensBackground, CFloatRect(.85F, 0.0F, 0.15F, 0.1F));
	m_zoLebensbackground.SetLayer(.19F);
	m_zoAnzeige.AddOverlay(&m_zoLebensbackground);
	iLebenAnzahl = 10;
	iLevelNummer = 1;
	
	top.Init(&m_zoAnzeige, "fonts\\Nasalization-rg-Red.png", 0.4F, 0.3F, 2.0F, .03F, 0.01F);


	/*font.Init("fonts\\Nasalization-rg-Red.png", true);
	writing.Init(CFloatRect(0.0F, 0.0F, 2.0F, 0.2F), 100, &font);
	m_zoAnzeige.AddWriting(&writing);*/

	for (int i = 0; i < 11; i++) {


		std::string s = "textures\\lebensanzeige\\lebensanzeige";
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
	bIsOn = false; 

}
