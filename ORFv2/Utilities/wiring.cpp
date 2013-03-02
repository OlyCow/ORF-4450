#include "../Includes.h"
#include "wiring.h"



wiring::wiring():
	// Will get rid of this stuff soon.
	// robotdrive(frontL, rearL, frontR, rearR)
	driveSystem(1, 3, 2, 4),
	
	positionStick(1),
	rotateStick(2),
	launcherStick(3),
	
	driveFrontLMotor(1),
	driveFrontRMotor(2),
	driveRearLMotor(3),
	driveRearRMotor(4),
	launchMotor(5),
	heightMotor(9),
	rampMotor(6),
	feederMotor(7),
	
	topHeightLimitSwitch(3),
	bottomHeightLimitSwitch(1),
	feederLimitSwitch(2),

	insight(TWO_ONE_LINE_ZONES),
	insightProgram(g_programHeader),
	insightBattery(g_batteryHeader)

// This zero-ing is just to be safe.
{
	driveFrontLMotor.Set(0);
	driveFrontRMotor.Set(0);
	driveRearLMotor.Set(0);
	driveRearRMotor.Set(0);
	
	launchMotor.Set(0);
	heightMotor.Set(0);
	rampMotor.Set(0);
	feederMotor.Set(0);
	
	insight.startDisplay();
	insight.registerData(insightProgram, 1);
	insight.registerData(insightBattery, 2);
	insightProgram.setData(g_programName);
	insightBattery.setPrecision(3);
}



wiring::~wiring()
// This zero-ing is just to be safe.
{
	driveFrontLMotor.Set(0);
	driveFrontRMotor.Set(0);
	driveRearLMotor.Set(0);
	driveRearRMotor.Set(0);
	
	launchMotor.Set(0);
	heightMotor.Set(0);
	rampMotor.Set(0);
	feederMotor.Set(0);
}
