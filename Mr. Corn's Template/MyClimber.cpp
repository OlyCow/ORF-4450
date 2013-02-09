#include "MyClimber.h"
#include "LCD.h"

MyClimber::MyClimber(MyRobot *MyRobot)
{
	LCD::ConsoleLog("MyClimber.constructor");
	
	myRobot = MyRobot;
}
	
MyClimber::~MyClimber()
{
}
	
void MyClimber::Climb(void)
{
	LCD::ConsoleLog("MyClimber.Climb");
	
//	while (myRobot->IsEnabled() && myRobot->IsOperatorControl())
//	{
//		
//	}
	
	LCD::ConsoleLog("MyClimber.Climb-end");
}
