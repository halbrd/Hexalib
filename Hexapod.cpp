#include "Hexapod.h"
#include <Servo.h>
#include <Arduino.h>

Hexapod::Hexapod()
{
	l_FL = HexapodLeftLeg(32, 33, 34, 70, 100, 165);
	l_MR = HexapodRightLeg(42, 43, 44, 100, 72, 25);
	l_BL = HexapodLeftLeg(22, 23, 24, 120, 110, 145);
	l_FR = HexapodRightLeg(37, 38, 39, 120, 80, 25);
	l_ML = HexapodLeftLeg(27, 28, 29, 75, 92, 160);
	l_BR = HexapodRightLeg(47, 48, 49, 90, 70, 30);
}

Hexapod::~Hexapod()
{

}

void Hexapod::WriteAllServos()
{
	l_FL.WriteToServos();
	l_MR.WriteToServos();
	l_BL.WriteToServos();
	l_FR.WriteToServos();
	l_ML.WriteToServos();
	l_BR.WriteToServos();
}

void Hexapod::RestPosition()
{
	l_FL.SetPositions(70, 100, 165);
	l_MR.SetPositions(100, 72, 25);
	l_BL.SetPositions(120, 110, 145);
	l_FR.SetPositions(120, 80, 25);
	l_ML.SetPositions(75, 92, 160);
	l_BR.SetPositions(90, 70, 30);
}

void Hexapod::GoToRestPosition()
{
	RestPosition();
	WriteAllServos();
}

void Hexapod::LeftWalkPosition()
{
	RestPosition();
	l_FL.FlexJoints(-22, 0, 0);
	l_MR.FlexJoints(-22, 0, 0);
	l_BL.FlexJoints(-22, 0, 0);
	l_FR.FlexJoints(22, 0, 0);
	l_ML.FlexJoints(22, 0, 0);
	l_BR.FlexJoints(22, 0, 0);
}

void Hexapod::GoToLeftWalkPosition()
{
	LeftWalkPosition();
	WriteAllServos();
}

void Hexapod::RightWalkPosition()
{
	RestPosition();
	l_FL.FlexJoints(22, 0, 0);
	l_MR.FlexJoints(22, 0, 0);
	l_BL.FlexJoints(22, 0, 0);
	l_FR.FlexJoints(-22, 0, 0);
	l_ML.FlexJoints(-22, 0, 0);
	l_BR.FlexJoints(-22, 0, 0);
}

void Hexapod::GoToRightWalkPosition()
{
	RightWalkPosition();
	WriteAllServos();
}

void Hexapod::G1LeftRotatePosition()
{
	RestPosition();
	l_FL.FlexJoints(22, 0, 0);
	l_MR.FlexJoints(-22, 0, 0);
	l_BL.FlexJoints(22, 0, 0);
	l_FR.FlexJoints(22, 0, 0);
	l_ML.FlexJoints(-22, 0, 0);
	l_BR.FlexJoints(22, 0, 0);
}

void Hexapod::GoToG1LeftRotatePosition()
{
	G1LeftRotatePosition();
	WriteAllServos();
}

void Hexapod::G1RightRotatePosition()
{
	RestPosition();
	l_FL.FlexJoints(-22, 0, 0);
	l_MR.FlexJoints(22, 0, 0);
	l_BL.FlexJoints(-22, 0, 0);
	l_FR.FlexJoints(-22, 0, 0);
	l_ML.FlexJoints(22, 0, 0);
	l_BR.FlexJoints(-22, 0, 0);
}

void Hexapod::GoToG1RightRotatePosition()
{
	G1RightRotatePosition();
	WriteAllServos();
}

/*void Hexapod::WalkForward(int steps, int delayTime)
{
	for (int h = 0; h < steps; h++)
	{
		// Group 1 step
		if (h%2 == 0)
		{
			GoToLeftWalkPosition();

			for (int i = 0; i < 45; i++)
			{
				// Leg up
				if (i < 15)
				{
					l_FL.FlexHipLon(0-_fastSpeed);
					l_MR.FlexHipLon(0-_fastSpeed);
					l_BL.FlexHipLon(0-_fastSpeed);
				}
				// Leg forward
				else if (i < 30)
				{
					l_FL.FlexHipLat(_fastSpeed);
					l_MR.FlexHipLat(_fastSpeed);
					l_BL.FlexHipLat(_fastSpeed);
				}
				// Leg down
				else if (i < 45)
				{
					l_FL.FlexHipLon(_fastSpeed);
					l_MR.FlexHipLon(_fastSpeed);
					l_BL.FlexHipLon(_fastSpeed);
				}

				l_FR.FlexHipLat(0-_slowSpeed);
				l_ML.FlexHipLat(0-_slowSpeed);
				l_BR.FlexHipLat(0-_slowSpeed);
				
				WriteAllServos();
				delay(delayTime);
			}
		}

		// Group 2 step
		else
		{
			GoToRightWalkPosition();

			for (int i = 0; i < 45; i++)
			{
				// Leg up
				if (i < 15)
				{
					l_FR.FlexHipLon(0-_fastSpeed);
					l_ML.FlexHipLon(0-_fastSpeed);
					l_BR.FlexHipLon(0-_fastSpeed);
				}
				// Leg forward
				else if (i < 30)
				{
					l_FR.FlexHipLat(_fastSpeed);
					l_ML.FlexHipLat(_fastSpeed);
					l_BR.FlexHipLat(_fastSpeed);
				}
				// Leg down
				else if (i < 45)
				{
					l_FR.FlexHipLon(_fastSpeed);
					l_ML.FlexHipLon(_fastSpeed);
					l_BR.FlexHipLon(_fastSpeed);
				}

				l_FL.FlexHipLat(0-_slowSpeed);
				l_MR.FlexHipLat(0-_slowSpeed);
				l_BL.FlexHipLat(0-_slowSpeed);

				WriteAllServos();
				delay(delayTime);
			}
		}
	}

	GoToRestPosition();
}

void Hexapod::WalkBackward(int steps, int delayTime)
{
	for (int h = 0; h < steps; h++)
	{
		// Group 1 step
		if (h%2 == 0)
		{
			GoToRightWalkPosition();

			for (int i = 0; i < 45; i++)
			{
				// Leg up
				if (i < 15)
				{
					l_FL.FlexHipLon(0-_fastSpeed);
					l_MR.FlexHipLon(0-_fastSpeed);
					l_BL.FlexHipLon(0-_fastSpeed);
				}
				// Leg forward
				else if (i < 30)
				{
					l_FL.FlexHipLat(0-_fastSpeed);
					l_MR.FlexHipLat(0-_fastSpeed);
					l_BL.FlexHipLat(0-_fastSpeed);
				}
				// Leg down
				else if (i < 45)
				{
					l_FL.FlexHipLon(_fastSpeed);
					l_MR.FlexHipLon(_fastSpeed);
					l_BL.FlexHipLon(_fastSpeed);
				}

				l_FR.FlexHipLat(_slowSpeed);
				l_ML.FlexHipLat(_slowSpeed);
				l_BR.FlexHipLat(_slowSpeed);
				
				WriteAllServos();
				delay(delayTime);
			}
		}

		// Group 2 step
		else
		{
			GoToLeftWalkPosition();

			for (int i = 0; i < 45; i++)
			{
				// Leg up
				if (i < 15)
				{
					l_FR.FlexHipLon(0-_fastSpeed);
					l_ML.FlexHipLon(0-_fastSpeed);
					l_BR.FlexHipLon(0-_fastSpeed);
				}
				// Leg forward
				else if (i < 30)
				{
					l_FR.FlexHipLat(0-_fastSpeed);
					l_ML.FlexHipLat(0-_fastSpeed);
					l_BR.FlexHipLat(0-_fastSpeed);
				}
				// Leg down
				else if (i < 45)
				{
					l_FR.FlexHipLon(_fastSpeed);
					l_ML.FlexHipLon(_fastSpeed);
					l_BR.FlexHipLon(_fastSpeed);
				}

				l_FL.FlexHipLat(_slowSpeed);
				l_MR.FlexHipLat(_slowSpeed);
				l_BL.FlexHipLat(_slowSpeed);

				WriteAllServos();
				delay(delayTime);
			}
		}
	}

	GoToRestPosition();
}*/

void Hexapod::Walk(WalkDirection direction, int steps, int delayTime)
{
	/*	The changes needed to turn the forward walking algorithm into a backward walking algorithm are:
			1. Swap the pre-step walking positions
			2. Invert the lateral movement
		My solution to #1 is an inline ternary statement:
			(direction == FW) ? GoToLeftWalkPosition() : GoToRightWalkPosition();
		My solution to #2 is multiplying the degree of rotation in the lateral movement by a variable
		that can be 1 or -1 (this variable is the below directionMod). */

	int directionMod = (direction == FW) ? 1 : -1;

	for (int h = 0; h < steps; h++)
	{
		// Group 1 step
		if (h%2 == 0)
		{
			(direction == FW) ? GoToLeftWalkPosition() : GoToRightWalkPosition();

			for (int i = 0; i < 45; i++)
			{
				// Legs up
				if (i < 15)
				{
					l_FL.FlexHipLon(_fastSpeed * -1);
					l_MR.FlexHipLon(_fastSpeed * -1);
					l_BL.FlexHipLon(_fastSpeed * -1);
				}
				// Legs lateral
				else if (i < 30)
				{
					l_FL.FlexHipLat(_fastSpeed * directionMod);
					l_MR.FlexHipLat(_fastSpeed * directionMod);
					l_BL.FlexHipLat(_fastSpeed * directionMod);
				}
				// Legs down
				else if (i < 45)
				{
					l_FL.FlexHipLon(_fastSpeed);
					l_MR.FlexHipLon(_fastSpeed);
					l_BL.FlexHipLon(_fastSpeed);
				}

				// Alternate legs lateral
				l_FR.FlexHipLat(_slowSpeed * directionMod * -1);
				l_ML.FlexHipLat(_slowSpeed * directionMod * -1);
				l_BR.FlexHipLat(_slowSpeed * directionMod * -1);
				
				WriteAllServos();
				delay(delayTime);
			}
		}

		// Group 2 step
		else
		{
			(direction == FW) ? GoToRightWalkPosition() : GoToLeftWalkPosition();

			for (int i = 0; i < 45; i++)
			{
				// Legs up
				if (i < 15)
				{
					l_FR.FlexHipLon(_fastSpeed * -1);
					l_ML.FlexHipLon(_fastSpeed * -1);
					l_BR.FlexHipLon(_fastSpeed * -1);
				}
				// Legs lateral
				else if (i < 30)
				{
					l_FR.FlexHipLat(_fastSpeed * directionMod);
					l_ML.FlexHipLat(_fastSpeed * directionMod);
					l_BR.FlexHipLat(_fastSpeed * directionMod);
				}
				// Legs down
				else if (i < 45)
				{
					l_FR.FlexHipLon(_fastSpeed);
					l_ML.FlexHipLon(_fastSpeed);
					l_BR.FlexHipLon(_fastSpeed);
				}

				// Alternate legs lateral
				l_FL.FlexHipLat(_slowSpeed * directionMod * -1);
				l_MR.FlexHipLat(_slowSpeed * directionMod * -1);
				l_BL.FlexHipLat(_slowSpeed * directionMod * -1);

				WriteAllServos();
				delay(delayTime);
			}
		}
	}

	GoToRestPosition();
}

void Hexapod::Rotate(RotateDirection direction, int steps, int delayTime)
{
	int directionMod = (direction == L) ? 1 : -1;

	for (int h = 0; h < steps; h++)
	{
		// Group 1 step
		if (h%2 == 0)
		{
			(direction == L) ? GoToG1LeftRotatePosition() : GoToG1RightRotatePosition();

			for (int i = 0; i < 45; i++)
			{
				// Legs up
				if (i < 15)
				{
					l_FL.FlexHipLon(_fastSpeed * -1);
					l_MR.FlexHipLon(_fastSpeed * -1);
					l_BL.FlexHipLon(_fastSpeed * -1);
				}
				// Legs lateral
				else if (i < 30)
				{
					l_FL.FlexHipLat(_fastSpeed * directionMod * -1);
					l_MR.FlexHipLat(_fastSpeed * directionMod);
					l_BL.FlexHipLat(_fastSpeed * directionMod * -1);
				}
				// Legs down
				else if (i < 45)
				{
					l_FL.FlexHipLon(_fastSpeed);
					l_MR.FlexHipLon(_fastSpeed);
					l_BL.FlexHipLon(_fastSpeed);
				}

				// Alternate legs lateral
				l_FR.FlexHipLat(_slowSpeed * directionMod * -1);
				l_ML.FlexHipLat(_slowSpeed * directionMod);
				l_BR.FlexHipLat(_slowSpeed * directionMod * -1);
				
				WriteAllServos();
				delay(delayTime);
			}
		}

		// Group 2 step
		else
		{
			(direction == L) ? GoToG1RightRotatePosition() : GoToG1LeftRotatePosition();

			for (int i = 0; i < 45; i++)
			{
				// Legs up
				if (i < 15)
				{
					l_FR.FlexHipLon(_fastSpeed * -1);
					l_ML.FlexHipLon(_fastSpeed * -1);
					l_BR.FlexHipLon(_fastSpeed * -1);
				}
				// Legs lateral
				else if (i < 30)
				{
					l_FR.FlexHipLat(_fastSpeed * directionMod);
					l_ML.FlexHipLat(_fastSpeed * directionMod * -1);
					l_BR.FlexHipLat(_fastSpeed * directionMod);
				}
				// Legs down
				else if (i < 45)
				{
					l_FR.FlexHipLon(_fastSpeed);
					l_ML.FlexHipLon(_fastSpeed);
					l_BR.FlexHipLon(_fastSpeed);
				}

				// Alternate legs lateral
				l_FL.FlexHipLat(_slowSpeed * directionMod);
				l_MR.FlexHipLat(_slowSpeed * directionMod * -1);
				l_BL.FlexHipLat(_slowSpeed * directionMod);

				WriteAllServos();
				delay(delayTime);
			}
		}
	}

	GoToRestPosition();
}