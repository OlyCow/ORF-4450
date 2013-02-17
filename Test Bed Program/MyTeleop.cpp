#include <WPILib.h>
#include "MyTeleop.h"
#include "LCD.h"
#include "MyDiscShooter.h"
#include "MyDiscShooterCmd.h"
#include "MyClimber.h"

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
	int 			encoderRaw = 0, encoderValue = 0;
	bool 			checkBox1 = false, shootEnabled = false, arcadeDrive = false, arcadeEnabled = false;
	MyDiscShooter	shooter(myRobot);
	MyClimber		climber(myRobot);
	JoystickButton	topButton(&myRobot->stick, Joystick::kDefaultTopButton);
	Encoder			driveLeftEncoder(1, 2, false, Encoder::k4X);
	int				encoderDirection;
	
	MyDiscShooterCmd	*discShooterCmd;
	
	LCD::ConsoleLog("MyTeleop.OperatorControl");
	LCD::PrintLine(1, "Mode: OperatorControl");

	LCD::PrintLine(4, "All: %d, Start=%d", myRobot->alliance, myRobot->startLocation);

	// Sets command based disc shooter class to run when button pressed, as separate
	// task from this one in the Command execution scheme. This depends on the command
	// scheduler running and that is done below in the While loop.
	// button class whenpressed requires a pointer to the command class instance we
	// want to run so we use new to create the instance and return a pointer to
	// that instance.
	
	discShooterCmd = new MyDiscShooterCmd(myRobot);
	
	topButton.WhenPressed(discShooterCmd);
	//topButton.WhenPressed(new MyDiscShooterCmd(myRobot));
	
	myRobot->robotDrive.SetSafetyEnabled(true);
	
	driveLeftEncoder.Start();

	// Driving loop runs until teleop is over or climbing phase started.
	
	while (myRobot->IsEnabled() && myRobot->IsOperatorControl())
	{
		// Scheduler required to cause any 'commands' to run. If we don't use any commands,
		// comment out following stmt.
		Scheduler::GetInstance()->Run();

		// the following code toggles the arcade drive flag on or off each time the right
		// trigger is released.
		
		if (myRobot->stick2.GetTrigger(myRobot->stick.kRightHand)) 
			arcadeEnabled = true;
		else if (arcadeEnabled)
		//if (!myRobot->stick2.GetTrigger(myRobot->stick.kRightHand) && arcadeEnabled) 
		{	
			arcadeEnabled = false;

			if (arcadeDrive)
				arcadeDrive = false;
			else
				arcadeDrive = true;
		
			SmartDashboard::PutBoolean("Arcade Drive", arcadeDrive);
		}
		
		if (arcadeDrive)	
			myRobot->robotDrive.ArcadeDrive(myRobot->stick2); // drive with arcade style (use right stick with trigger)
		else
			myRobot->robotDrive.TankDrive(myRobot->stick, myRobot->stick2); // drive tank style with both sticks

		//LCD::ConsoleLog("left trigger=%d", myRobot->stick.GetTrigger(myRobot->stick.kLeftHand));
		
		// This logic shoots disk on trigger release.
		
		if (myRobot->stick.GetTrigger(myRobot->stick.kLeftHand)) 
			shootEnabled = true;
		else if (shootEnabled)
		{
			shootEnabled = false;
			shooter.Shoot();
		}

		// Starts climbing process, drops out of driving loop when climb done.
		
		if (myRobot->stick2.GetButton(myRobot->stick2.kTopButton))
		{
			climber.Climb();
			break; 					// ends the While loop
		}
		
		Wait(0.020);				// wait for a motor update time
		
		// read encoder example.
		
		encoderValue = driveLeftEncoder.Get();
		encoderRaw = driveLeftEncoder.GetRaw();

		if (driveLeftEncoder.GetDirection())
			encoderDirection = 1; // forward
		else
			encoderDirection = 0; // backward

		// example display info to dashboard lcd.
		LCD::PrintLine(2, "Encoder Value: %d %d", encoderValue, encoderDirection);
		LCD::PrintLine(3, "Encoder   Raw: %d", encoderRaw);
		
		// example on how to read a value from the dashboard.
		checkBox1 = SmartDashboard::GetBoolean("Checkbox 1");

		LCD::PrintLine(5, "Checkbox1 Value=%d", checkBox1);
	}
	
	// wait for teleop period to end.

	LCD::PrintLine(1, "Mode: End Wait");
	LCD::ConsoleLog("MyTeleop.OperatorControl-endwait");
	SmartDashboard::PutBoolean("End Wait", true);	
	
	myRobot->robotDrive.SetSafetyEnabled(false);
	
	while (myRobot->IsEnabled() && myRobot->IsOperatorControl()) Wait(0.020);
	
	// delete pointer to MyDiscShooterCmd object we created earlier.
	// this releases the object instance.
	
	delete discShooterCmd;
	
	LCD::ConsoleLog("MyTeleop.OperatorControl-end");
}
