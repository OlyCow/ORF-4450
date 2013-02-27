#include "Includes.h"
#include "Robot.h"



Robot::Robot():
	insightLT(TWO_ONE_LINE_ZONES),
	displayBattery("Battery: "),
	displayProgram("Pgm: "),
	ds(DriverStation::GetInstance()),
	cRIO(),
	monitorBatteryTask("MonitorBattery", (FUNCPTR) MonitorBattery)
{
	try
	{
		LCD::ConsoleLog("%s Constructor", PROGRAM_NAME);

		cRIO->driveSystem.SetExpiration(g_expiration);

		// Set the InsightLT display.
		insightLT.registerData(displayProgram, 1);
		displayProgram.setData(PROGRAM_NAME);
		insightLT.registerData(displayBattery, 2);

		cRIO->driveSystem.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		cRIO->driveSystem.SetInvertedMotor(RobotDrive::kRearRightMotor, true);

		LCD::ConsoleLog("%s Constructor-end", PROGRAM_NAME);
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Constructor Exception: %s", e->what());
	}
}


void Robot::RobotInit(void)
{
	try
	{
		LCD::ConsoleLog("RobotInit");
		LCD::PrintLine(1, "Mode: RobotInit");

		SmartDashboard::PutString("Program", PROGRAM_NAME);	
		SmartDashboard::PutBoolean("Checkbox 1", false);	
		
		// Start the battery monitoring Task.
		
		monitorBatteryTask.Start((UINT32) ds);
		
		
		
		LCD::ConsoleLog("RobotInit-end");
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("RobotInit Exception: %s", e->what());
	}
}


// Called by cRio when driver station disables the robot and at
// start-up, after constructor and Init method.
void Robot::Disabled(void)
{
	try
	{
		LCD::ConsoleLog("Disabled");
		LCD::PrintLine(1, "Mode: Disabled");
		
		// Reset driver station LEDs.
		
		SmartDashboard::PutBoolean("Disabled", true);	
		SmartDashboard::PutBoolean("Autonomous Mode", false);	
		SmartDashboard::PutBoolean("Teleop Mode", false);	
		SmartDashboard::PutBoolean("End Wait", false);	
		SmartDashboard::PutBoolean("Arcade Drive", false);	
		SmartDashboard::PutBoolean("Shoot Disc", false);	
		SmartDashboard::PutBoolean("Climb Mode", false);	
		SmartDashboard::PutBoolean("FMS", ds->IsFMSAttached());	

		// the following loads current battery voltage into the
		// InsightLT display. We can plug in the InsightLT when robot is
		// disabled to check voltage. Display turned off on entry to
		// other modes.
		insightLT.startDisplay();
		displayBattery.setData(ds->GetBatteryVoltage());

		LCD::ConsoleLog("Disabled-end");
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Disabled Exception: %s", e->what());
	}
}


void Robot::Autonomous()
{
}


void Robot::OperatorControl()
{
}


void Robot::MonitorBattery(int dsPointer)
{
	DriverStation 	*ds;
	bool			batteryOk = true, alarmFlash = false;

	try
	{
		LCD::ConsoleLog("Start MonitorBattery");

		ds = (DriverStation*) dsPointer;

		SmartDashboard::PutBoolean("Low Battery", false);


		// Checks battery voltage every 10 seconds.
		// Drops out when battery goes below the threshold.
		while (batteryOk)
		{
			//LCD::ConsoleLog("Battery Check %f", ds->GetBatteryVoltage());
			if (ds->GetBatteryVoltage() < LOW_BATTERY) batteryOk = false;
			Wait(10.0);
		}

		
		// Flashes the battery warning LED on driverstation.
		while (true)
		{
			if (alarmFlash)
				alarmFlash = false;
			else
				alarmFlash = true;

			SmartDashboard::PutBoolean("Low Battery", alarmFlash);

			Wait(1.0);
		}
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Monitor Battery Exception: %s", e->what());
	}
}



START_ROBOT_CLASS(Robot);
