#ifndef __MyAutonomous_h__
#define __MyAutonomous_h__

#include <WPILib.h>
#include "MyRobot.h"

class MyAutonomous
{
private:
	MyRobot *myRobot;
	Talon launchMotor;
	Solenoid feedSolenoid;
	DigitalInput shooterSwitch;
	Talon angleMotor;
	
public:
	MyAutonomous(MyRobot *myRobot);
	
	virtual ~MyAutonomous();
	
	void shoot(void);
};

#endif // __MyAutonomous_h__
