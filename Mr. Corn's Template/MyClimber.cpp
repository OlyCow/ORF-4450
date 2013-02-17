#include "MyClimber.h"
#include "LCD.h"

MyClimber::MyClimber(MyRobot *MyRobot)
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
