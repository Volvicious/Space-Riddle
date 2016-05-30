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

	for (int i = 0; i < 11; i++) {


		std::string s = "textures\\lebensanzeige\\lebensanzeige";
		s += std::to_string(i); 
		s += ".png";
		char * temp = (char*)s.c_str();

		LebensImages[i].Init(temp);
		
		LebensOverlays[i].Init(&LebensImages[i], CFloatRect(.845F, 0.0F, 0.15F, 0.1F));
		m_zoAnzeige.AddOverlay(&LebensOverlays[i]);
		LebensOverlays[i].SetLayer(0.25F);
		LebensOverlays[i].SwitchOff();

		
	}
	LebensOverlays[iLebenAnzahl].SwitchOn();
	m_zoAnzeige.SetLayer(0.25F);
	m_zoAnzeige.SwitchOff();

	top.Init(&m_zoAnzeige, "fonts\\Nasalization-rg-White.png", 0.855F, 0.03F, 3.0F, .06F);
	setLevelNummer(iLevelNummer);


}

void CLLAnzeige::Run() {

	if (bIsOn) {

		top.WriteSavedString();		
		/*ULDebug("Bin hier drin.");
		ULDebug(stc.DoStringToChar(top.GetString()));*/ 

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
