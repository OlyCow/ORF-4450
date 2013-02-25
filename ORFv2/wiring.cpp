#include <exception>
#include <WPIlib.h>
#include "LCD.h"
#include "wiring.h"
#include "InsightLT/InsightLT.h"

using namespace insight;



wiring::wiring():
	insightLT(insight::TWO_ONE_LINE_ZONES),
	displayBattery("Battery: "),
	displayProgram("Pgm: "),
	ds(DriverStation::GetInstance()),
	// robotdrive(frontL, rearL, frontR, rearR)
	driveSystem(1, 3, 2, 4),
	positionStick(1),
	rotateStick(2),
	launcherStick(3),
	monitorBatteryTask("MonitorBattery", (FUNCPTR) MonitorBattery)
{
}
