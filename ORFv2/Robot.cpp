#include "Includes.h"
#include "Robot.h"



Robot::Robot():
	ds(DriverStation::GetInstance()),
	cRIO(),
	monitorBatteryTask("MonitorBattery", (FUNCPTR) MonitorBattery)
{
	LCD::ConsoleLog("%s Constructor", g_programName.c_str());
	
	static DriveBase driveBase(this);
	static Launcher launcher(this);

	cRIO->driveSystem.SetExpiration(g_expiration);

	cRIO->driveSystem.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	cRIO->driveSystem.SetInvertedMotor(RobotDrive::kRearRightMotor, true);

	LCD::ConsoleLog("%s Constructor-end", g_programName.c_str());
}



void Robot::RobotInit()
{
	LCD::ConsoleLog("RobotInit");
	LCD::PrintLine(1, "Mode: RobotInit");

	SmartDashboard::PutString("Program", g_programName);
	SmartDashboard::PutBoolean("Checkbox 1", false);

	// Start the battery monitoring Task.
	monitorBatteryTask.Start((UINT32) ds);

	LCD::ConsoleLog("RobotInit-end");
}



void Robot::Disabled()
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

	// The following loads current battery voltage into the
	// InsightLT display. We can plug in the InsightLT when robot is
	// disabled to check voltage. Display turned off on entry to
	// other modes.
	cRIO->insightBattery.setData(ds->GetBatteryVoltage());

	LCD::ConsoleLog("Disabled-end");
}



void Robot::MonitorBattery(int dsPointer)
{
	DriverStation	*ds;
	bool			batteryOk = true,
					alarmFlash = false;

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

	
	// Flashes the battery warning LED on driver station.
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



START_ROBOT_CLASS(Robot);
