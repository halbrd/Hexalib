#ifndef HEXAPODLEG_H
#define HEXAPODLEG_H

#include <Servo.h>

class HexapodLeg
{
protected:
	Servo s_hipLat;		// Hip servo that controls lateral movement
	Servo s_hipLon;		// Hip servo that controls longitudinal movement
	Servo s_knee;		// Self-explanitory

	int p_hipLat = 0;	// Positions of respective servos, initialized to zero but modified by the constructor
	int p_hipLon = 0;
	int p_knee = 0;

public:
	HexapodLeg();		// Default constructor required for declarations (does nothing special)
	HexapodLeg(int hipLatPin, int hipLonPin, int kneePin, int hipLatPos, int hipLonPos, int kneePos);
	~HexapodLeg();

	void WriteToServos();
	void SetPositions(int hipLat, int hipLon, int knee);		// Set positions of all servos in leg

	// These functions are pure virtual, since the two subclasses need to specify their own functions
	virtual void FlexJoints(int hipLatDeg, int hipLonDeg, int kneeDeg) = 0;		// Shorthand way to modify entire leg
	virtual void FlexHipLat(int degrees) = 0;
	virtual void FlexHipLon(int degrees) = 0;
	virtual void FlexKnee(int degrees) = 0;
};

class HexapodLeftLeg : public HexapodLeg
{
public:
	HexapodLeftLeg();	// Default constructor required for declarations (does nothing special)
	HexapodLeftLeg(int hipLatPin, int hipLonPin, int kneePin, int hipLatPos, int hipLonPos, int kneePos);
	~HexapodLeftLeg();

	void FlexHipLat(int degrees);
	void FlexHipLon(int degrees);
	void FlexKnee(int degrees);
	void FlexJoints(int hipLatDeg, int hipLonDeg, int kneeDeg);
};

class HexapodRightLeg : public HexapodLeg
{
public:
	HexapodRightLeg();	// Default constructor required for declarations (does nothing special)
	HexapodRightLeg(int hipLatPin, int hipLonPin, int kneePin, int hipLatPos, int hipLonPos, int kneePos);
	~HexapodRightLeg();

	void FlexHipLat(int degrees);
	void FlexHipLon(int degrees);
	void FlexKnee(int degrees);
	void FlexJoints(int hipLatDeg, int hipLonDeg, int kneeDeg);
};

#endif
