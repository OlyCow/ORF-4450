#include <exception>
#include <WPIlib.h>
#include "Utilities/LCD.h"
#include "wiring.h"
#include "InsightLT/InsightLT.h"

using namespace insight;



wiring::wiring():
	// robotdrive(frontL, rearL, frontR, rearR)
	driveSystem(1, 3, 2, 4),
	positionStick(1),
	rotateStick(2),
	launcherStick(3)
{
}
