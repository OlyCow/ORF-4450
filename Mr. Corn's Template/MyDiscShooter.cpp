#include "MyDiscShooter.h"
#include "LCD.h"

MyDiscShooter::MyDiscShooter(MyRobot *MyRobot):
	launchMotor(5),
	angleMotor(8),
	feedSolenoid(1),
	rampRelay(1, Relay::kBothDirections)
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

void MyDiscShooter::ShooterUpDown(float speed)
{
//	LCD::ConsoleLog("MyDiscShooterThrottle.ShooterUpDown-%f", speed);
	
	angleMotor.Set(speed);
}

void MyDiscShooter::RampUp(void)
{
//	LCD::ConsoleLog("MyDiscShooterThrottle.RampUp");

	rampRelay.Set(Relay::kForward);		// up
}

void MyDiscShooter::RampDown(void)
{
//	LCD::ConsoleLog("MyDiscShooterThrottle.RampDown");

	rampRelay.Set(Relay::kReverse);		// down
}

void MyDiscShooter::RampStop(void)
{
//	LCD::ConsoleLog("MyDiscShooterThrottle.RampStop");

	rampRelay.Set(Relay::kOff);		// stop
}
	
void MyDiscShooter::Shoot(void)
{
	LCD::ConsoleLog("MyDiscShooter.Shoot");

	SmartDashboard::PutBoolean("Shoot Disc", true);	
			
	feedSolenoid.Set(true);

	Wait(0.5); // wait long enough for one full revolution of shooter arm motor.
	
	feedSolenoid.Set(false);

	SmartDashboard::PutBoolean("Shoot Disc", false);	

	LCD::ConsoleLog("MyDiscShooter.Shoot-end");
}
