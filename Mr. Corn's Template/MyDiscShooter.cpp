#include "MyDiscShooter.h"
#include "LCD.h"

MyDiscShooter::MyDiscShooter(MyRobot *MyRobot)
{
	LCD::ConsoleLog("MyDiscShooter.constructor");
	
	myRobot = MyRobot;
}
	
MyDiscShooter::~MyDiscShooter()
{
}
	
void MyDiscShooter::Shoot(void)
{
	LCD::ConsoleLog("MyDiscShooter.Shoot");
	
//	while (myRobot->IsEnabled() && myRobot->IsOperatorControl())
//	{
//		
//	}

	LCD::ConsoleLog("MyDiscShooter.Shoot-end");
}
