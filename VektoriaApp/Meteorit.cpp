#include "Meteorit.h"

CMeteorit::CMeteorit()
{
	srand(time(0));
}


CMeteorit::~CMeteorit()
{
}

void CMeteorit::Init(CScene * scene, CSound * sound)
{
	float ri = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	m_zMeteorit.Init(ri, NULL, 10.0, 10.0);
	iCounterStart = 0;
	iCounterEnd = MAX_METEOR / 2;

	audio.Init3D("sounds\\3D_Sounds\\Passing_Object.wav", 3.0F);
	if (audio.m_b3D){
		ULDebug("3D ist true");
	}
	else{
		ULDebug("3D ist false");
	}

	for (int i = 0; i < MAX_METEOR; i++)
	{
		float xi = rand() % 19 + (-9);
		float yi = rand() % 19 + (-9);
		float zi = i * -5;

		//Meteorit erstellen
		
		

		m_azp[i].AddGeo(&m_zMeteorit);
		//m_azp[i].AddAudio(sound->getAudioPointr(2)); 
		//audio.Init3D("sounds\\3D_Sounds\\Passing_Object.wav", 3.0F);
		//m_azp[i].AddAudio(&audio);
		//audio.SetVolume(1.0F);
		//audio.Loop();

		

		

		//audio[2].SetRadius(3.0F);
		//audio.Fini();
		
		//mcs->AddAudio(&audio[2]);
		//audio[2].Loop(2);
		
		/*audio[2].Init("sounds\\3D_Sounds\\Passing_Object.wav", 5.0F);
		m_azp[i].AddAudio(sound->getAudioPointr(2));
		audio[2].Loop(2);*/
		
		//audio[2].SetRadius(5.0F);
		//audio[2].Fini();

		//Meteorit verschieben
		m_azp[i].Translate(xi, yi, zi);

		//Die Anzahl der anzuzeigenden Meteoriten am Anfang festlegen
		if (i > MAX_METEOR / 2)
		{
			m_azp[i].SwitchOff();
		}
	}

	m_pzpStart = &m_azp[0];
	m_pzpEnd = &m_azp[MAX_METEOR / 2];

	//Meteoriten in Scene laden
	for (int i = 0; i < MAX_METEOR; i++)
	{
		scene->AddPlacement(&m_azp[i]);
	}
	audio.SetVolume(1.0F);
	audio.Loop();

}

void CMeteorit::RenewMeteorits(CPlacement * pRaumschiff)
{
	//Start und Ende müssen jeweils um eins hochgezählt werden
	iCounterEnd = iCounterStart + MAX_METEOR / 2;

	//Wenn das Ende des Arrays erreicht wird, wird von neuem durchgezählt
	iCounterStart %= MAX_METEOR;
	iCounterEnd %= MAX_METEOR;

	m_zvRaumschiff = pRaumschiff->GetTranslation();
	m_zvMeteorit = m_azp[iCounterStart].GetTranslation();

	//Alten Meteoriten deaktivieren und neuen aktivieren
	if (m_zvMeteorit.GetZ() >= m_zvRaumschiff.GetZ() + 15.0F)
	{
		++iCounterStart;
		m_azp[iCounterStart].SwitchOff();
		m_azp[iCounterEnd].SwitchOn();
	}

}

