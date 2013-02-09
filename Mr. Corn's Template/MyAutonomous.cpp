#include "MyAutonomous.h"
#include "LCD.h"

MyAutonomous::MyAutonomous(MyRobot *MyRobot)
{
	LCD::ConsoleLog("MyAutonomous.constructor");
	
	myRobot = MyRobot;
}
	
MyAutonomous::~MyAutonomous()
{
}
	
void MyAutonomous::DoAutonomous(void)
{
	LCD::ConsoleLog("MyAutonomous.DoAutonomous");

	LCD::PrintLine(4, "All: %d, Start=%d", myRobot->alliance, myRobot->startLocation);

	myRobot->robotDrive.SetSafetyEnabled(false);
	
	//while (IsEnabled() && IsAutonomous())
	//{
		LCD::ConsoleLog("doing autonomous task");

		myRobot->robotDrive.Drive(0.5, 0.5); 	// drive forwards half speed
	
		Wait(2.0); 					// for 2 second
		
		LCD::ConsoleLog("out of autonomous wait");
		
		myRobot->robotDrive.Drive(0.0, 0.0); 	// stop robot
	//}

	LCD::ConsoleLog("MyAutonomous.DoAutonomous-end");
}
