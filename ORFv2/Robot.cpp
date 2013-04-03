#include "Includes.h"
#include "Robot.h"



Robot::Robot():
	ds(DriverStation::GetInstance()),
	camera(AxisCamera::GetInstance(g_cameraIP.c_str())),
	cRIO(),
	monitorBatteryTask("MonitorBattery", (FUNCPTR) MonitorBattery)
{
	this->mode_name = "Constructor";
	
	
	
	
	
	LCD::ConsoleLog("%s Constructor", g_programName.c_str());
	LCD::ConsoleLog("%s Constructor-end", g_programName.c_str());
	
	
	
	
	
	static DriveBase driveBase(this);
	static Launcher launcher(this);
}

void Robot::RobotInit()
{
	this->mode_name = "RobotInit";
	ModeStart();
	
	
	SmartDashboard::PutString("Program", g_programName);
	SmartDashboard::PutBoolean("Checkbox 1", false);
	
	LCD::ConsoleLog("RobotInit-end");
	
	
	
	
	
	// Start the battery monitoring Task.
	monitorBatteryTask.Start((UINT32) ds);
	
	ModeEnd();
}

void Robot::Disabled()
{
	this->mode_name = "Disabled";
	ModeStart();
	
	
	
	
	
	// Reset driver station LEDs.
	SmartDashboard::PutBoolean("Disabled", true);
	SmartDashboard::PutBoolean("Autonomous Mode", false);
	SmartDashboard::PutBoolean("Teleop Mode", false);
	SmartDashboard::PutBoolean("End Wait", false);
	SmartDashboard::PutBoolean("Arcade Drive", false);
	SmartDashboard::PutBoolean("Shoot Disc", false);
	SmartDashboard::PutBoolean("Climb Mode", false);
	SmartDashboard::PutBoolean("FMS", ds->IsFMSAttached());
	
	
	
	
	
	cRIO->insightBattery.setData(ds->GetBatteryVoltage());
	ModeEnd();
}

void Robot::ModeStart()
{
	string console = "Start: ";
	console.append(this->mode_name);
	LCD::ConsoleLog( (char*)console.c_str() );
	
	string LCD = "Mode: ";
	LCD.append(this->mode_name);
	LCD::PrintLine(LINE_MODE, LCD.c_str());
}
void Robot::ModeEnd()
{
	string console = "End: ";
	console.append(this->mode_name);
	LCD::ConsoleLog( (char*)console.c_str() );
	
	LCD::ClearLine(LINE_MODE);
}

void Robot::MonitorBattery(int dsPointer)
{
	DriverStation	*ds;
	ds = (DriverStation*) dsPointer;
	bool batteryOK = true;
	bool alarmFlash = false;
	float voltage = ds->GetBatteryVoltage();
	string message = "Voltage: ";
	
	
	
	
	
	LCD::ConsoleLog("Start MonitorBattery");
	SmartDashboard::PutBoolean("Low Battery", false);
	
	
	
	
	
	// Checks battery voltage every 5 seconds.
	// Drops out when battery goes below the threshold.
	while (batteryOK)
	{
		voltage = ds->GetBatteryVoltage();
		if (voltage < g_lowBatteryThreshold)
			batteryOK = false;
		message.append(math::stringify(voltage));
		
		LCD::PrintLine(LINE_BATTERY, message.c_str());
		Wait(5.0);
	}
	
	// Flashes the battery warning "LED" on driver station.
	
	
	
	
	
	SmartDashboard::PutBoolean("Low Battery", alarmFlash);
	
	
	
	
	
	while (true)
	{
		alarmFlash = true;
		Wait(1.0);
		alarmFlash = false;
		Wait(1.0);
	}
}



START_ROBOT_CLASS(Robot);
