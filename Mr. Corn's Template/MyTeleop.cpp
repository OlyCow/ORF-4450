#include <WPILib.h>
#include "MyTeleop.h"
#include "LCD.h"
#include "MyDiscShooter.h"
#include "MyDiscShooterCmd.h"
#include "MyClimber.h"

// Joystick button numbers.

#define	JSB_TOP_MIDDLE		3
#define JSB_TOP_LEFT		4
#define JSB_TOP_RIGHT		5
#define JSB_TRIGGER			1
#define JSB_TOP_BACK		2
#define JSB_LEFT_FRONT		6
#define JSB_LEFT_REAR		7
#define JSB_RIGHT_FRONT		11
#define JSB_RIGHT_REAR		10
#define JSB_BACK_LEFT		8
#define JSB_BACK_RIGHT		9

MyTeleop::MyTeleop(MyRobot *MyRobot)
{
	LCD::ConsoleLog("MyTeleop.constructor");
	
	myRobot = MyRobot;
}
	
MyTeleop::~MyTeleop()
{
	LCD::ConsoleLog("MyTeleop.destructor");
}
	
void MyTeleop::OperatorControl(void)
{
	bool 			shootEnabled = false;
	float			magnitude = 0, direction = 0, rotation = 0;
	MyDiscShooter	shooter(myRobot);
	MyClimber		climber(myRobot);
	JoystickButton	leftTopButton(&myRobot->leftStick, Joystick::kDefaultTopButton);
	JoystickButton	leftTrigger(&myRobot->leftStick, Joystick::kDefaultTriggerButton);
	
	//MyDiscShooterCmd	*discShooterCmd;
	
	LCD::ConsoleLog("MyTeleop.OperatorControl");
	LCD::PrintLine(1, "Mode: OperatorControl");

	LCD::PrintLine(4, "All: %d, Start=%d", myRobot->alliance, myRobot->startLocation);

	// Sets command based disc shooter class to run when button pressed, as separate
	// task from this one in the Command execution scheme. This depends on the command
	// scheduler running and that is done below in the While loop.
	// button class whenpressed requires a pointer to the command class instance we
	// want to run so we use new to create the instance and return a pointer to
	// that instance.
	
	//discShooterCmd = new MyDiscShooterCmd(myRobot);
	
	//leftTrigger.WhenPressed(discShooterCmd);
	
	myRobot->robotDrive.SetSafetyEnabled(true);

	// Driving loop runs until teleop is over or climbing phase started.
	
	while (myRobot->IsEnabled() && myRobot->IsOperatorControl())
	{
		// Scheduler required to cause any 'commands' to run. If we don't use any commands,
		// comment out following stmt.
		//Scheduler::GetInstance()->Run();

		// set driving parameters.
	
		magnitude = myRobot->rightStick.GetMagnitude();
		direction = myRobot->rightStick.GetDirectionDegrees();
		rotation = myRobot->rotateStick.GetX();

		
		LCD::PrintLine(3, "m=%f d=%f r=%f", magnitude, direction, rotation);
		LCD::PrintLine(4, "r=%f", rotation);
				
		myRobot->robotDrive.MecanumDrive_Polar(magnitude, direction, rotation);
		
		// This logic shoots disk on trigger release.
		
		if (myRobot->leftStick.GetTrigger(myRobot->leftStick.kLeftHand)) 
			shootEnabled = true;
		else if (shootEnabled)
		{
			shootEnabled = false;
			shooter.Shoot();
		}

		// turn on/off climber Angular Adjustment (window) motor.
		
		if (myRobot->leftStick.GetRawButton(JSB_TOP_LEFT))
			climber.AngularAdjustmentMotorOn(true);
		else	
			climber.AngularAdjustmentMotorOn(false);

		// The design assumes operation of the climbing winches would be
		// manually by JS buttons.
		
		if (myRobot->leftStick.GetRawButton(JSB_LEFT_FRONT))
			climber.Winch2Up();
		else if (myRobot->leftStick.GetRawButton(JSB_LEFT_REAR))
			climber.Winch2Down();
		else	
			climber.Winch2Stop();
		
		// control shooter ramp deployment.
		
		if (myRobot->leftStick.GetRawButton(JSB_TOP_MIDDLE))
			shooter.RampUp();
		else if (myRobot->leftStick.GetRawButton(JSB_TOP_BACK))
			shooter.RampDown();	
		else	
			shooter.RampStop();
		
		// set shooter throttle value each loop.
		
		shooter.SetThrottle(myRobot->leftStick.GetThrottle());
		
		shooter.ShooterUpDown(myRobot->leftStick.GetY());

		// Starts climbing process, drops out of driving loop when climb done.
		
//		if (myRobot->rightStick.GetButton(myRobot->rightStick.kTopButton))
//		{
//			climber.Climb();
//			break; 					// ends the While loop
//		}
		
		Wait(0.020);				// wait for a motor update time
	}
	
	// wait for teleop period to end.

	LCD::PrintLine(1, "Mode: End Wait");
	LCD::ConsoleLog("MyTeleop.OperatorControl-endwait");
	SmartDashboard::PutBoolean("End Wait", true);	
	
	myRobot->robotDrive.SetSafetyEnabled(false);
	
	while (myRobot->IsEnabled() && myRobot->IsOperatorControl()) Wait(0.020);
	
	// delete pointer to MyDiscShooterCmd object we created earlier.
	// this releases the object instance.
	
	//delete discShooterCmd;
	
	LCD::ConsoleLog("MyTeleop.OperatorControl-end");
}
