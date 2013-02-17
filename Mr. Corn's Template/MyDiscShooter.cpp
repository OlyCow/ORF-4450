#include "MyDiscShooter.h"
#include "LCD.h"

MyDiscShooter::MyDiscShooter(MyRobot *MyRobot):
	launchMotor(5),
	shootMotor(9)
{
	LCD::ConsoleLog("MyDiscShooter.constructor");
	
	myRobot = MyRobot;
}
	
MyDiscShooter::~MyDiscShooter()
{
	LCD::ConsoleLog("MyDiscShooter.destructor");
}

// Set motor speed for launcher wheel.

void MyDiscShooter::SetThrottle(float ThrottleValue)
{
//	LCD::ConsoleLog("MyDiscShooterThrottle.SetThrottle- %f", (ThrottleValue-1)/2);
//	LCD::ConsoleLog("Straight Throttle Value- %f", ThrottleValue);
	
	launchMotor.Set((ThrottleValue-1)/2);
}
	
void MyDiscShooter::Shoot(void)
{
	LCD::ConsoleLog("MyDiscShooter.Shoot");

	SmartDashboard::PutBoolean("Shoot Disc", true);	
			
	shootMotor.Set(1);

	Wait(0.5); // wait long enough for one full revolution of shooter arm motor.
	
	shootMotor.StopMotor();

	SmartDashboard::PutBoolean("Shoot Disc", false);	

	LCD::ConsoleLog("MyDiscShooter.Shoot-end");
}
