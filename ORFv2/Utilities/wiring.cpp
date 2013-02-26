#include "../Includes.h"
#include "wiring.h"



wiring::wiring():
	// robotdrive(frontL, rearL, frontR, rearR)
	driveSystem(1, 3, 2, 4),
	positionStick(1),
	rotateStick(2),
	launcherStick(3)
{
}
