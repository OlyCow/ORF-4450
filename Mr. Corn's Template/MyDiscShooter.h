#ifndef __MyDiscShooter_h__
#define __MyDiscShooter_h__

#include <WPILib.h>
#include "MyRobot.h"

class MyDiscShooter
{
private:
	MyRobot *myRobot;
	Talon 	launchMotor, shootMotor;
	
public:
	MyDiscShooter(MyRobot *myRobot);
	
	virtual ~MyDiscShooter();
	
	void Shoot(void);
	void SetThrottle(float ThrottleValue);
};

#endif // __MyDiscShooter_h__
