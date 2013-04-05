#include "../Includes.h"
#include "wiring.h"



wiring::wiring():	
	positionStick(1),
	rotateStick(2),
	launcherStick(3),
	
	driveFrontLMotor	(1, MOTOR_NORMAL),
	driveFrontRMotor	(2, MOTOR_INVERTED),
	driveRearLMotor		(3, MOTOR_NORMAL),
	driveRearRMotor		(4, MOTOR_INVERTED),
	launchMotor	(5, MOTOR_NORMAL),
	heightMotor	(9, MOTOR_NORMAL),
	rampMotor	(6, MOTOR_NORMAL),
	feederMotor	(7, MOTOR_NORMAL),
	
	topHeightLimitSwitch(3),
	bottomHeightLimitSwitch(1),
	feederLimitSwitch(2),

	insight(insight::TWO_ONE_LINE_ZONES),
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
