#include "../Includes.h"



void Robot::Test()
{
	this->mode_name = "Test";
	
	
	
	
	
	// This is a test.
	driveBase.drive(1.0, 1.0, 0.0, 0.0);
	driveBase.drive(1.0, 0.0, 0.0, 1.0);
	driveBase.drive(1.0, 0.0, 0.0, -1.0);
	launcher.maxHeight(0.8);
	launcher.shoot(1.0, 4);
	launcher.setRampMotor(0.5);
	Wait(1.0);
	launcher.setRampMotor(0.0);
	Wait(1.0);
	this->OperatorControl();
}
