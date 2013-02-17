#include "MyAutonomous.h"
#include "LCD.h"

MyAutonomous::MyAutonomous(MyRobot *MyRobot)
{
	LCD::ConsoleLog("MyAutonomous.constructor");
	
	myRobot = MyRobot;
}
	
MyAutonomous::~MyAutonomous()
{
	LCD::ConsoleLog("MyAutonomous.destructor");
}
	
void MyAutonomous::DoAutonomous(void)
{
	LCD::ConsoleLog("MyAutonomous.DoAutonomous");

	LCD::PrintLine(4, "All: %d, Start=%d", myRobot->alliance, myRobot->startLocation);

	myRobot->robotDrive.SetSafetyEnabled(false);
	
	//while (IsEnabled() && IsAutonomous())
	//{
		LCD::ConsoleLog("doing autonomous task");

		//myRobot->robotDrive.Drive(0.5, 0.0); 	// drive forwards half speed
		
		Solenoid *s[8];
		
		for (int i = 0; i < 8; i++)
			s[i] = new Solenoid(i + 1); // allocate the Solenoid objects
		
		for (int i = 0; i < 8; i++)
		{
			s[i]->Set(true); // turn them all on
		}
		
		Wait(1.0);
		
		for (int i = 0; i < 8; i++)
		{
			s[i]->Set(false); // turn them each off in turn
			Wait(1.0);
		}
		
		for (int i = 0; i < 8; i++)
		{
			s[i]->Set(true); // turn them back on in turn
			Wait(1.0);
			delete s[i]; // delete the objects
		}
	
		Wait(2.0); 					// for 2 second
		
		LCD::ConsoleLog("out of autonomous wait");
		
		myRobot->robotDrive.Drive(0.0, 0.0); 	// stop robot
	//}

	LCD::ConsoleLog("MyAutonomous.DoAutonomous-end");
}
