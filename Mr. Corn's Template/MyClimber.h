#ifndef __MyClimber_h__
#define __MyClimber_h__

#include <WPILib.h>
#include "MyRobot.h"

class MyClimber
{
private:
	MyRobot *myRobot;
	Jaguar	winchMotor1;
	Jaguar	winchMotor2;
	Talon	angularAdjustmentMotor;

public:
	MyClimber(MyRobot *myRobot);
	
	virtual ~MyClimber();
	
	void Climb(void);
	void Winch1Up(void);
	void Winch1Down(void);
	void Winch1Stop(void);
	void Winch2Up(void);
	void Winch2Down(void);
	void Winch2Stop(void);
	void AngularAdjustmentMotorOn(bool onIsTrue);
};

#endif // __MyClimber_h__
