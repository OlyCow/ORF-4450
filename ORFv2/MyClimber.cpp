#include "MyClimber.h"
#include "LCD.h"

MyClimber::MyClimber(MyRobot *MyRobot):
	winchMotor1(7),
	winchMotor2(8),
	angularAdjustmentMotor(6)
{
	LCD::ConsoleLog("MyClimber.constructor");
	
	myRobot = MyRobot;
}
	
MyClimber::~MyClimber()
{
	LCD::ConsoleLog("MyClimber.destructor");
}
	
void MyClimber::Climb(void)
{
	LCD::ConsoleLog("MyClimber.Climb");

	SmartDashboard::PutBoolean("Climb Mode", true);	

//	while (myRobot->IsEnabled() && myRobot->IsOperatorControl())
//	{
//		
//	}

	SmartDashboard::PutBoolean("Climb Mode", false);	

	LCD::ConsoleLog("MyClimber.Climb-end");
}

// turn on/off winch motors. Up/down depends on how the cord is
// wound on the winch spool.

void MyClimber::Winch1Up(void)
{
	winchMotor1.Set(1);
}

void MyClimber::Winch1Down(void)
{
	winchMotor1.Set(-1);
}

void MyClimber::Winch1Stop(void)
{
	winchMotor1.StopMotor();
}

void MyClimber::Winch2Up(void)
{
	winchMotor2.Set(1);
}

void MyClimber::Winch2Down(void)
{
	winchMotor2.Set(-1);
}

void MyClimber::Winch2Stop(void)
{
	winchMotor2.StopMotor();
}

void MyClimber:: AngularAdjustmentMotorOn(bool onIsTrue)
{
	if (onIsTrue)
		angularAdjustmentMotor.Set(1);
	else
		angularAdjustmentMotor.StopMotor();
}

