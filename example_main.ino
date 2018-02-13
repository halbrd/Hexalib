/*
 *	This is an example of how you might use the library.
 *
 *	This code would make the hexapod walk forward a short distance, pivot left
 *	in place roughly 90 degrees, walk forward, pivot right, walk forward, and
 *	so on, in a "square wave" pattern (https://i.imgur.com/Nqqvj6m.png)
 *
 */

#include <Hexapod.h>
#include <HexapodLeg.h>

#include <Servo.h>

Hexapod* hex;

void setup()
{
	hex = new Hexapod();

	delay(5000);
}

void loop()
{
	hex->Walk(FW, 6, 3);
	hex->Rotate(L, 5, 3);
	hex->Walk(FW, 6, 3);
	hex->Rotate(R, 5, 3);
	hex->Walk(FW, 6, 3);
	hex->Rotate(R, 5, 3);
	hex->Walk(FW, 6, 3);
	hex->Rotate(L, 5, 3);
}
