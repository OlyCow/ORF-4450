#include "MyDiscShooter.h"
#include "LCD.h"

MyDiscShooter::MyDiscShooter(MyRobot *MyRobot)
{
	LCD::ConsoleLog("MyDiscShooter.constructor");
	
	myRobot = MyRobot;
}
	
MyDiscShooter::~MyDiscShooter()
{
	LCD::ConsoleLog("MyDiscShooter.destructor");
}
	
void MyDiscShooter::Shoot(void)
{
	LCD::ConsoleLog("MyDiscShooter.Shoot");

	SmartDashboard::PutBoolean("Shoot Disc", true);	

//	while (myRobot->IsEnabled() && myRobot->IsOperatorControl())
//	{
//		
//	}

	SmartDashboard::PutBoolean("Shoot Disc", false);	

	LCD::ConsoleLog("MyDiscShooter.Shoot-end");
}
