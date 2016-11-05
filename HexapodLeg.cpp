#include "HexapodLeg.h"
#include <Servo.h>

// Default constructor initialises variables to garbage values that are overwritten by the real constructor
HexapodLeg::HexapodLeg()
{
	s_hipLat.attach(2);
	s_hipLon.attach(2);
	s_knee.attach(2);

	p_hipLat = 90;
	p_hipLon = 90;
	p_knee = 90;
}

HexapodLeg::HexapodLeg(int hipLatPin, int hipLonPin, int kneePin, int hipLatPos, int hipLonPos, int kneePos)
{
	s_hipLat.attach(hipLatPin);
	s_hipLon.attach(hipLonPin);
	s_knee.attach(kneePin);

	SetPositions(hipLatPos, hipLonPos, kneePos);
	WriteToServos();
}

HexapodLeg::~HexapodLeg()
{

}

void HexapodLeg::WriteToServos()
{
	s_hipLat.write(p_hipLat);
	s_hipLon.write(p_hipLon);
	s_knee.write(p_knee);
}

void HexapodLeg::SetPositions(int hipLat, int hipLon, int knee)
{
	p_hipLat = hipLat;
	p_hipLon = hipLon;
	p_knee = knee;
}

HexapodLeftLeg::HexapodLeftLeg() : HexapodLeg()
{

}

// Constructor calls parent's constructor as-is
HexapodLeftLeg::HexapodLeftLeg(int hipLatPin, int hipLonPin, int kneePin, int hipLatPos, int hipLonPos, int kneePos)
	: HexapodLeg(hipLatPin, hipLonPin, kneePin, hipLatPos, hipLonPos, kneePos)
{

}

HexapodLeftLeg::~HexapodLeftLeg()
{

}


HexapodRightLeg::HexapodRightLeg() : HexapodLeg()
{
	
}

// Constructor calls parent's constructor as-is
HexapodRightLeg::HexapodRightLeg(int hipLatPin, int hipLonPin, int kneePin, int hipLatPos, int hipLonPos, int kneePos)
	: HexapodLeg(hipLatPin, hipLonPin, kneePin, hipLatPos, hipLonPos, kneePos)
{
	
}

HexapodRightLeg::~HexapodRightLeg()
{

}

/**
 *
 *	For the purpose of simplicity, I define "flexing" as:
 *		Moving the leg forward for hip lateral servos
 *		Moving the leg up for hip longitudinal servos
 *		Bending the leg inward at the knee for knee servos
 *	The functions below reflect this design choice and standardise the control of the legs' servos.
*/


void HexapodLeftLeg::FlexHipLat(int degrees)
{
	p_hipLat += degrees;
	// Add out of bounds checks here
	s_hipLat.write(p_hipLat);
}

void HexapodLeftLeg::FlexHipLon(int degrees)
{
	p_hipLon -= degrees;
	// Add out of bounds checks here
	s_hipLon.write(p_hipLon);
}

void HexapodLeftLeg::FlexKnee(int degrees)
{
	p_knee += degrees;
	// Add out of bounds checks here
	s_knee.write(p_knee);
}

void HexapodLeftLeg::FlexJoints(int hipLatDeg, int hipLonDeg, int kneeDeg)
{
	FlexHipLat(hipLatDeg);
	FlexHipLon(hipLonDeg);
	FlexKnee(kneeDeg);
}

void HexapodRightLeg::FlexHipLat(int degrees)
{
	p_hipLat -= degrees;
	// Add out of bounds checks here
	s_hipLat.write(p_hipLat);
}

void HexapodRightLeg::FlexHipLon(int degrees)
{
	p_hipLon += degrees;
	// Add out of bounds checks here
	s_hipLon.write(p_hipLon);
}

void HexapodRightLeg::FlexKnee(int degrees)
{
	p_knee -= degrees;
	// Add out of bounds checks here
	s_knee.write(p_knee);
}

void HexapodRightLeg::FlexJoints(int hipLatDeg, int hipLonDeg, int kneeDeg)
{
	FlexHipLat(hipLatDeg);
	FlexHipLon(hipLonDeg);
	FlexKnee(kneeDeg);
}