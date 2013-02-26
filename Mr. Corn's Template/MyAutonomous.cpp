#include "MyAutonomous.h"
#include "LCD.h"

MyAutonomous::MyAutonomous(MyRobot *MyRobot):
	launchMotor(5),
	feedSolenoid(1),
	shooterSwitch(1),
	angleMotor(9)
{
	LCD::ConsoleLog("MyAutonomous.constructor");
	
	myRobot = MyRobot;
}
	
MyAutonomous::~MyAutonomous()
{
	LCD::ConsoleLog("MyAutonomous.destructor");
}

void MyAutonomous::shoot()
{
	myRobot->robotDrive.SetSafetyEnabled(false);
	
	launchMotor.Set(-0.65);
	Wait(6);
	
		for (int i = 0; i < 3;i++)
		{
			feedSolenoid.Set(true);
			Wait(0.4);
			while(shooterSwitch.Get()==0)
				Wait(0.1);
			feedSolenoid.Set(false);
			Wait(3.0);
		}
		launchMotor.Set(0);
//		angleMotor.Set(-0.5);
//		Wait(0.75);
//		angleMotor.Set(0.0);

//	}
}
