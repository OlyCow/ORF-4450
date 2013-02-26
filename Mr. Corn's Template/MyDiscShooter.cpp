#include "MyDiscShooter.h"
#include "LCD.h"

MyDiscShooter::MyDiscShooter(MyRobot *MyRobot):
	launchMotor(5),
	angleMotor(9),
	feederRamp(6),
	shootMotor(7),
	//rampRelay(1, Relay::kBothDirections),
	shooterSwitch(1),
	shooterAngleSwitch(2)
{
	LCD::ConsoleLog("MyDiscShooter.constructor");
	
	myRobot = MyRobot;
	
	angleMotor.Set(0);
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
	float tempSpeed = 0;
	
	//LCD::ConsoleLog("angle motor input speed = %f", speed );
	
	if(speed > 0.3)	// this .3 created a dead zone around controller zero.
	{
		//LCD::ConsoleLog("switch = %d", shooterAngleSwitch.Get() );

		if(shooterAngleSwitch.Get()==1)
			tempSpeed = 0;		// limit switch closed, stop motor.
		else
			tempSpeed = 0.3;	// fixed speed of motor.
	}
	else if (speed < -0.3)
		tempSpeed = -0.25;
	
	//LCD::ConsoleLog("tempSpeed = %f", tempSpeed);
	
	angleMotor.Set(tempSpeed);
}

void MyDiscShooter::RampUp(void)//														Reload Ramp Up
{
	feederRamp.Set(0.5);
}

void MyDiscShooter::RampDown(void)//													Reload Ramp Down
{
	feederRamp.Set(-0.5);
}

void MyDiscShooter::RampStop(void)//													Reload Ramp Stop
{
	feederRamp.Set(0);
}
	
void MyDiscShooter::Shoot(void)//														Shoot a Frisbee
{
	myRobot->robotDrive.SetSafetyEnabled(false);
	
	LCD::ConsoleLog("MyDiscShooter.Shoot");

	SmartDashboard::PutBoolean("Shoot Disc", true);	
			
	shootMotor.Set(1);

	Wait(0.4);
	
	while(shooterSwitch.Get()==0)
	{
		Wait(0.1);
	}
	
	shootMotor.Set(0);

	SmartDashboard::PutBoolean("Shoot Disc", false);	

	LCD::ConsoleLog("MyDiscShooter.Shoot-end");
	
	myRobot->robotDrive.SetSafetyEnabled(true);
}

void MyDiscShooter::ShootHalf(void)//														Shoot a Frisbee
{
	myRobot->robotDrive.SetSafetyEnabled(false);
	
	LCD::ConsoleLog("MyDiscShooter.ShootHalf");

	SmartDashboard::PutBoolean("Shoot Disc", true);	
	
		shootMotor.Set(0.25);
		Wait(2);
		shootMotor.Set(0);
	
	while(shooterSwitch.Get()==0)
	{
		shootMotor.Set(0.25);
		Wait(0.1);
	}
	
	shootMotor.Set(0);

	SmartDashboard::PutBoolean("Shoot Disc", false);	

	LCD::ConsoleLog("MyDiscShooter.ShootHalf-end");
	
	myRobot->robotDrive.SetSafetyEnabled(true);
}
