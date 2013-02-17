#include "MyAutonomous.h"
#include "LCD.h"
#include "Enums.h"
#include "Global_Vars.h"

MyAutonomous::MyAutonomous(MyRobot *MyRobot):
	launchMotor(5),
	feedSolenoid(1),
	shooterSwich(1),
	angleMotor(9),
	DFL(1),
	DBL(2),
	DBR(3),
	DFR(4)
	
{
	LCD::ConsoleLog("MyAutonomous.constructor");
	
	myRobot = MyRobot;
}
	
MyAutonomous::~MyAutonomous()
{
	LCD::ConsoleLog("MyAutonomous.destructor");
}

void MyAutonomous::backup(void)
{
	myRobot->robotDrive.SetSafetyEnabled(false);
	
}

void MyAutonomous::shoot()
{
	myRobot->robotDrive.SetSafetyEnabled(false);
	
	launchMotor.Set(g_LauncherPower);
	Wait(g_LauncherInitTime);
	
	//switch (g_AutonomousMode)
	//{
	//case MODE_LEFT:
	//case MODE_RIGHT:
	//case MODE_CENTER:
	
		for (int i = 0; i < g_InitDiscNum; i++)
		{
			feedSolenoid.Set(true);
			Wait(0.4);
			while(shooterSwich.Get()==0)
				Wait(0.1);
			feedSolenoid.Set(false);
			Wait(3.0);
		}
		launchMotor.Set(0);
//		angleMotor.Set(-0.5);
//		Wait(0.75);
//		angleMotor.Set(0.0);
//		break;
//	default:
//		break;
//	}
}
	
void MyAutonomous::reposition()
{
	myRobot->robotDrive.SetSafetyEnabled(false);
	switch (g_AutonomousMode)
	{
	case MODE_LEFT:
		break;
	case MODE_RIGHT:
		break;
	case MODE_CENTER:
		break;
	default:
		break;
	}
}
