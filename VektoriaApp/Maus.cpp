#include "Maus.h"



CMaus::CMaus()
{
}


CMaus::~CMaus()
{
}

void CMaus::Init(CViewport * m_zv, CFrame * m_zf) {

	m_ziCurser.Init("textures\\cursor.gif");
	m_zoCurser.Init(&m_ziCurser, CFloatRect(0.5F, 0.5F, 0.02F, 0.02F), true);
	m_zf->AddDeviceCursor(&m_zdCursor);
	m_zv->AddOverlay(&m_zoCurser);
	m_zoCurser.SetLayer(0.1F);
}

void CMaus::Run() {
	if (bOn) {


		float fx, fy;

		m_zdCursor.GetFractional(fx, fy, true);

		m_zoCurser.SetRect(CFloatRect(fx - 0.01F, fy - 0.01F, 0.04F, 0.04F));

		if (!m_zdCursor.ButtonPressedLeft()) {
			bKeyDown = false;
		}
		

	}

	

}


void CMaus::SwitchOn() {
	m_zoCurser.SwitchOn();
	bOn = true;
	bKeyDown = true;
}

void CMaus::SwitchOff() {

	m_zoCurser.SwitchOff();
	bOn = false;
}

bool CMaus::IsKeyDown() {
	return bKeyDown;
}

void CMaus::SetKeyDownTrue() {
	bKeyDown = true; 
}



bool CMaus::PickOverlayandLeftKlick(COverlay * ptro) {
	m_zoCurser.SwitchOff();
	if (m_zdCursor.PickOverlay() == ptro && m_zdCursor.ButtonPressedLeft() && !bKeyDown) {
		bKeyDown = true;
		
		m_zoCurser.SwitchOn();
		return true; 
	}
	m_zoCurser.SwitchOn();
	return false;
}

bool CMaus::PickOverlay(COverlay * ptro) {
	m_zoCurser.SwitchOff();
	if (m_zdCursor.PickOverlay() == ptro) {
		m_zoCurser.SwitchOn();
		return true;
	}
	m_zoCurser.SwitchOn();
	return false; 
}


bool CMaus::PickOverlayOrWritingandLeftKlick(CWriting * ptrw) {
	m_zoCurser.SwitchOff();
	if (m_zdCursor.PickOverlayOrWriting() == ptrw && m_zdCursor.ButtonPressedLeft() && !bKeyDown) {
		bKeyDown = true;
		
		m_zoCurser.SwitchOn();
			return true; 
	
	}

	m_zoCurser.SwitchOn();
	return false; 
}

CDeviceCursor * CMaus::getDevicePtr() {

	return &m_zdCursor;
}



