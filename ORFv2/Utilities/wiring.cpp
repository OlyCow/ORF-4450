#include "../Includes.h"
#include "wiring.h"



wiring::wiring():
	// Will get rid of this stuff soon.
	// robotdrive(frontL, rearL, frontR, rearR)
	driveSystem(1, 3, 2, 4),
	
	positionStick(1),
	rotateStick(2),
	launcherStick(3),
	
	driveMotorFrontL(1),
	driveMotorFrontR(2),
	driveMotorRearL(3),
	driveMotorRearR(4),
	launchMotor(5),
	heightMotor(9),
	rampMotor(6),
	feederMotor(7),
	
	topHeightLimitSwitch(3),
	bottomHeightLimitSwitch(1),
	feederLimitSwitch(2)

// This zero-ing is just to be safe.
{
	driveMotorFrontL.Set(0);
	driveMotorFrontR.Set(0);
	driveMotorRearL.Set(0);
	driveMotorRearR.Set(0);
	
	launchMotor.Set(0);
	heightMotor.Set(0);
	rampMotor.Set(0);
	feederMotor.Set(0);
}



wiring::~wiring()
// This zero-ing is just to be safe.
{
	driveMotorFrontL.Set(0);
	driveMotorFrontR.Set(0);
	driveMotorRearL.Set(0);
	driveMotorRearR.Set(0);
	
	launchMotor.Set(0);
	heightMotor.Set(0);
	rampMotor.Set(0);
	feederMotor.Set(0);
}
