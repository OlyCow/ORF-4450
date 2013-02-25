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
	Talon DFL;
	Talon DBL;
	Talon DBR;
	Talon DFR;
	
public:
	MyAutonomous(MyRobot *myRobot);
	virtual ~MyAutonomous();
	
	// The entire autonomous program (high-level) should
	// be in here. Use lower-level functions to construct it.
	void AutonomousProgram();
	
	// Lower level functions.
	// shoot() should be in MyDiscShooter...
	void shoot();
};

#endif // __MyAutonomous_h__
