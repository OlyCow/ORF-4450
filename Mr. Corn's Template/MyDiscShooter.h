#ifndef __MyDiscShooter_h__
#define __MyDiscShooter_h__

#include <WPILib.h>
#include "MyRobot.h"

class MyDiscShooter
{
private:
	MyRobot 	*myRobot;
	Talon 		launchMotor, angleMotor;
	Solenoid	feedSolenoid;
	Relay		rampRelay;
	DigitalInput shooterSwich;

public:
	MyDiscShooter(MyRobot *myRobot);
	
	virtual ~MyDiscShooter();
	
	void Shoot(void);
	void SetThrottle(float ThrottleValue);
	void RampUp(void);
	void RampDown(void);
	void RampStop(void);
	void ShooterUpDown(float speed);
};

#endif // __MyDiscShooter_h__
