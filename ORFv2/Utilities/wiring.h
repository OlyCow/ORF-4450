#ifndef _WIRING_H_
#define _WIRING_H_

#include "../Includes.h"



class wiring
{
public:
	// Will get rid of this stuff soon.
	RobotDrive		driveSystem;
	
	Joystick		positionStick,
					rotateStick,
					launcherStick;
	
	Talon			driveFrontLMotor,
					driveFrontRMotor,
					driveRearLMotor,
					driveRearRMotor,
					launchMotor,
					heightMotor,
					rampMotor,
					feederMotor;
	
	DigitalInput	topHeightLimitSwitch,
					bottomHeightLimitSwitch,
					feederLimitSwitch;
	
	wiring();
	~wiring();
	
	
private:
};



#endif // _WIRING_H_
