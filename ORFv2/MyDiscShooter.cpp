#include "MyDiscShooter.h"
#include "LCD.h"

MyDiscShooter::MyDiscShooter(MyRobot *MyRobot):
	launchMotor(5),
	angleMotor(9),
	feedSolenoid(1),
	rampRelay(1, Relay::kBothDirections),
	shooterSwich(1)
{
	LCD::ConsoleLog("MyDiscShooter.constructor");
	
	myRobot = MyRobot;
}
	
MyDiscShooter::~MyDiscShooter()
{
	LCD::ConsoleLog("MyDiscShooter.destructor");
}

void MyDiscShooter::SetThrottle(float ThrottleValue)//									Set Throttle
{
	launchMotor.Set((ThrottleValue-1)/2);
}

void MyDiscShooter::ShooterUpDown(float speed)//										Shoot Angle
{	
	angleMotor.Set(speed);
}

void MyDiscShooter::RampUp(void)//														Reload Ramp Up
{

	rampRelay.Set(Relay::kForward);
}

void MyDiscShooter::RampDown(void)//													Reload Ramp Down
{
	rampRelay.Set(Relay::kReverse);
}

void MyDiscShooter::RampStop(void)//													Reload Ramp Stop
{
	rampRelay.Set(Relay::kOff);
}
	
void MyDiscShooter::Shoot(void)//														Shoot a Frisbee
{
	LCD::ConsoleLog("MyDiscShooter.Shoot");

	SmartDashboard::PutBoolean("Shoot Disc", true);	
			
	feedSolenoid.Set(true);

	Wait(0.4);
	
	while(shooterSwich.Get()==0)
	{
	Wait(0.1);
	}
	feedSolenoid.Set(false);

	SmartDashboard::PutBoolean("Shoot Disc", false);	

	LCD::ConsoleLog("MyDiscShooter.Shoot-end");
}
