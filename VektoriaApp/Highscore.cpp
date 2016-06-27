#include "Highscore.h"



CHighscore::CHighscore()
{
}


CHighscore::~CHighscore()
{
}


void CHighscore::Init(CViewport * mvz) {

	topHighscore.Init(mvz, "fonts\\Nasalization-rg-Red.png", 0.0F, 0.08F, 2.5F, 0.04F);
	topHighscore.SetString("Score:0");

	topChange.Init(mvz, "fonts\\Nasalization-rg-Red.png", 0.0F, 0.06F, 2.5F, 0.04F);
	
	topChange.SetString("");

	bOn = true;

	float fy = 0.4F; 
	for (int i = 0; i < 6; i++) {

		aTextOutputsNamen[i].Init(mvz, "fonts\\Nasalization-rg-Red.png",
			0.5F, 0.0F + fy, 2.0F, 0.02F);
		aTextOutputsNamen[i].SetString("-");
		aTextOutputsNamen[i].SwitchOff(); 
	
		aTextOutputInts[i].Init(mvz, "fonts\\Nasalization-rg-Red.png",
			0.75, 0.0F + fy, 2.0F, 0.02F, 0.19F);
		aTextOutputInts[i].SetString("-");
		aTextOutputInts[i].SwitchOff();
		fy += 0.07F; 
	}



}

void CHighscore::Run(float ftime, float fTimeDelta) {

	if (bOn) {

		if (ftime > fTimeStart + 1) {

			fTimeStart = ftime;
			iHighscore++;
			changeString();
		}

		

		topHighscore.WriteSavedString();
		changeAnimation(ftime, fTimeDelta); 

	}

}

void CHighscore::Start(float fTime) {

	fTimeStart = fTime; 
	bOn = true;
}


void CHighscore::Stop() {

	bOn = false; 

}



void CHighscore::Pause() {

	//fTimePauseSpeicher = fTimeStart;
	fTimeStart = INT_MAX;

	
}

void CHighscore::GoOn(float fTime) {

	fTimeStart = fTime; 
}

void CHighscore::AddHighscore(std::string sName, int iScore) {

	v_NamePunktZahl->push_back(std::pair<std::string, int>(sName, iScore));
	Save();
}

void CHighscore::Save() {

	std::ofstream file("..\\VektoriaApp\\highscore\\highscore.txt");

	std::string s = ""; 

	if (file.is_open()) {

		int i = 0; 
		for (std::vector<std::pair<std::string, int>>::iterator it = v_NamePunktZahl->begin();
		it != v_NamePunktZahl->end(); it++) {
			
			s += it->first;
			s += "\n"; 
			s += std::to_string(it->second);
			s += "\n";

			i++;
		}

		file << s; 

	}

	file.close();

}

void CHighscore::Load() {


	std::ifstream file("..\\VektoriaApp\\highscore\\highscore.txt");
	std::string s;

	std::string sPufferName;
	int iPufferNummer;

	int i = 0;
	bool b = true; 

	while (std::getline(file, s))
	{

		if (s.size()> 0) {

			if (b) {
				sPufferName = s; 
				b = false; 
			}
			else {
				iPufferNummer = std::stoi(s);
				v_NamePunktZahl->push_back(std::pair<std::string, int>(sPufferName, iPufferNummer));
				b = true; 
			}
		}
	}

	file.close();
	Sort(); 
}


void CHighscore::RunHauptMenue() {

	for (int i = 0; i < 6; i++) {
		aTextOutputInts[i].WriteSavedString();
		aTextOutputsNamen[i].WriteSavedString(); 
	}
	//ULDebug(stc.DoStringToChar(aTextOutputsNamen[0].GetString()));

}

void CHighscore::SwitchMenueOff() {
	for (int i = 0; i < 6; i++) {
		aTextOutputsNamen[i].SwitchOff();
		aTextOutputInts[i].SwitchOff();
	}

}

void CHighscore::Sort() {

	std::sort(v_NamePunktZahl->begin(), v_NamePunktZahl->end(),
		[](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2) { return p1.second > p2.second; });

	int i = 0; 
	for (std::vector<std::pair<std::string, int>>::iterator it = v_NamePunktZahl->begin();
	it != v_NamePunktZahl->end(); it++) {
		if (i >= 6) {
			break;
		}
		aTextOutputsNamen[i].SetString( it->first );
		aTextOutputInts[i].SetString(std::to_string(it->second));
		//aTextOutputInts[i].SetString("TESTIEST");

		i++;
	}


}

void CHighscore::PreRunMenue() {
	
	Load();

	for (int i = 0; i < 6; i++) {

		aTextOutputInts[i].SwitchOn();
		aTextOutputsNamen[i].SwitchOn();
		
	}

}

void CHighscore::SetHighscore (int i) {

	iHighscore = i;
	changeString();

}

int CHighscore::GetHighscore () {

	return iHighscore;
}

void CHighscore::AddToHighscore (int i) {

	iHighscore += i;
	changeString();
	if (i > 0) {
	sChange = "+";
	}
	sChange += std::to_string(i);
	bDisplayChange = true; 


}

void CHighscore::SubstractFromHighscore (int i) {
	
	if (i > 0) {
		sChange = "-";
		iHighscore -= i;
	}
	else {
		sChange = "";
		iHighscore += i;
	}

	sChange += std::to_string(i);
	bDisplayChange = true;

}

void CHighscore::changeString() {

	std::string s = "Score:" + std::to_string(iHighscore);
	topHighscore.SetString(s);
}

void CHighscore::changeAnimation(float fTime, float fTimeDelta) {

	if (bDisplayChange) {
		fxSize = 0.0F; 
		fySize = 0.0F; 
		topChange.SetString(sChange);
		bDisplayChange = false; 
	}

	if (fxSize < fxEndSize) {
		fxSize += fxEndSize * fTimeDelta; 
		fySize += fyEndSize *fTimeDelta;
		topChange.SetWritingRect(CFloatRect(fxPos, fyPos, fxSize, fySize));
		fTimeStartChange = fTime; 
	}
	else {

		if (fTime > fTimeStartChange + 1) {
			topChange.SetString("");
		}

	}

	topChange.WriteSavedString(); 

}


