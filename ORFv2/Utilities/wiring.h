#ifndef _WIRING_H_
#define _WIRING_H_

#include "../Includes.h"



class wiring
{
public:	
	Watchdog		watchdog;
	
	Joystick		positionStick,
					rotateStick,
					launcherStick;
	
	Motor			driveFrontLMotor,
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
	
	insight::InsightLT		insight;
	insight::StringData		insightProgram;
	insight::DecimalData	insightBattery;
	
	wiring();
	~wiring();
	
	
private:
};



#endif // _WIRING_H_
