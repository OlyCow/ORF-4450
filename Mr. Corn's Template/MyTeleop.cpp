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
}
	
void MyTeleop::OperatorControl(void)
{
	int 			encoder_raw = 0;
	bool 			checkBox1 = false, climbing = false, shootEnabled = false;
	MyDiscShooter	shooter(myRobot);
	MyClimber		climber(myRobot);
	JoystickButton	topButton(&myRobot->stick, Joystick::kDefaultTopButton);
	
	LCD::ConsoleLog("MyTeleop.OperatorControl");
	LCD::PrintLine(1, "Mode: OperatorControl");

	LCD::PrintLine(4, "All: %d, Start=%d", myRobot->alliance, myRobot->startLocation);

	topButton.WhenPressed(new MyDiscShooterCmd(myRobot));
	
	myRobot->robotDrive.SetSafetyEnabled(true);
	
	myRobot->driveleftencoder.Start();

	SmartDashboard::PutBoolean("Checkbox 1", false);	
	SmartDashboard::PutBoolean("End Wait", false);	

	while (myRobot->IsEnabled() && myRobot->IsOperatorControl() && !climbing)
	{
		// Scheduler required to cause any 'commands' to run. If don't use any commands,
		// comment out following stmt.
		Scheduler::GetInstance()->Run();
		
		if(myRobot->stick2.GetTrigger(myRobot->stick2.kRightHand))
		{
			//LCD::ConsoleLog("arcade drive");
			myRobot->robotDrive.ArcadeDrive(myRobot->stick2); // drive with arcade style (use right stick with trigger)
			SmartDashboard::PutBoolean("Arcade Drive", true);
		}
		else
		{
			//LCD::ConsoleLog("tank drive");
			myRobot->robotDrive.TankDrive(myRobot->stick, myRobot->stick2); // drive tank both
			SmartDashboard::PutBoolean("Arcade Drive", false);	
		}

		//LCD::ConsoleLog("left trigger=%d", myRobot->stick.GetTrigger(myRobot->stick.kLeftHand));
		
		if (myRobot->stick.GetTrigger(myRobot->stick.kLeftHand)) shootEnabled = true;
		
		if (!myRobot->stick.GetTrigger(myRobot->stick.kLeftHand) && shootEnabled) 
		{
			shootEnabled = false;
			shooter.Shoot();
		}

		if (myRobot->stick2.GetButton(myRobot->stick2.kTopButton))
		{
			climber.Climb();
			break;
		}
		
		Wait(0.020);				// wait for a motor update time
		
		myRobot->encoder_value = myRobot->driveleftencoder.GetRaw();

		LCD::PrintLine(2, "Encoder Value: %d", myRobot->encoder_value);
		LCD::PrintLine(3, "Encoder   Raw: %d", encoder_raw);
		
		checkBox1 = SmartDashboard::GetBoolean("Checkbox 3");

		LCD::PrintLine(5, "Checkbox3 Value=%d", checkBox1);
	}
	
	// wait for teleop period to end.

	LCD::PrintLine(1, "Mode: End Wait");
	LCD::ConsoleLog("MyTeleop.OperatorControl-endwait");
	SmartDashboard::PutBoolean("End Wait", true);	
	
	myRobot->robotDrive.SetSafetyEnabled(false);
	
	while (myRobot->IsEnabled() && myRobot->IsOperatorControl()) Wait(0.010);
	
	LCD::ConsoleLog("MyTeleop.OperatorControl-end");
}
