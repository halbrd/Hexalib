#ifndef HEXAPOD_H
#define HEXAPOD_H

#include "HexapodLeg.h"
#include <Servo.h>

enum WalkDirection { FW, BW };
enum RotateDirection { L, R };

class Hexapod
{
protected:
	HexapodLeftLeg l_FL;
	HexapodRightLeg l_MR;
	HexapodLeftLeg l_BL;
	HexapodRightLeg l_FR;
	HexapodLeftLeg l_ML;
	HexapodRightLeg l_BR;

	static const int _slowSpeed = 1;
	static const int _fastSpeed = _slowSpeed * 3;

public:
	Hexapod();
	~Hexapod();

	// Movement //
	void WriteAllServos();
	// Static positions
	void RestPosition();
	void GoToRestPosition();

	void LeftWalkPosition();
	void GoToLeftWalkPosition();

	void RightWalkPosition();
	void GoToRightWalkPosition();

	void G1LeftRotatePosition();
	void GoToG1LeftRotatePosition();

	void G1RightRotatePosition();
	void GoToG1RightRotatePosition();	
	// Travelling
	//void WalkForward(int steps, int delayTime);	// Deprecated
	//void WalkBackward(int steps, int delayTime);	// Deprecated
	void Walk(WalkDirection direction, int steps, int delayTime);
	void Rotate(RotateDirection direction, int steps, int delayTime);
	void RotateLeft(int degrees);                   // Currently unimplemented
	void RotateRight(int degrees);                  // Currently unimplemented
};

#endif
