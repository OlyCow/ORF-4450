#include "Includes.h"
#include "Robot.h"



Robot::Robot():
	ds(DriverStation::GetInstance()),
	cRIO(),
	monitorBatteryTask("MonitorBattery", (FUNCPTR) MonitorBattery)
{
	LCD::ConsoleLog("%s Constructor", g_programName.c_str());
	
	LCD::ConsoleLog("%s Constructor-end", g_programName.c_str());
	
	
	
	
	
	static DriveBase driveBase(this);
	static Launcher launcher(this);
}



void Robot::RobotInit()
{
	LCD::ConsoleLog("RobotInit");
	LCD::PrintLine(1, "Mode: RobotInit");
	
	SmartDashboard::PutString("Program", g_programName);
	SmartDashboard::PutBoolean("Checkbox 1", false);
	
	LCD::ConsoleLog("RobotInit-end");
	
	
	
	
	
	// Start the battery monitoring Task.
	monitorBatteryTask.Start((UINT32) ds);
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
	
	LCD::ConsoleLog("Disabled-end");
	
	
	
	
	
	cRIO->insightBattery.setData(ds->GetBatteryVoltage());
}



void Robot::MonitorBattery(int dsPointer)
{
	DriverStation	*ds;
	ds = (DriverStation*) dsPointer;
	bool			batteryOk = true,
					alarmFlash = false;
	
	LCD::ConsoleLog("Start MonitorBattery");
	SmartDashboard::PutBoolean("Low Battery", false);
	
	// Checks battery voltage every 10 seconds.
	// Drops out when battery goes below the threshold.
	while (batteryOk)
	{
		//LCD::ConsoleLog("Battery Check %f", ds->GetBatteryVoltage());
		if (ds->GetBatteryVoltage() < g_lowBatteryThreshold)
			batteryOk = false;
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
