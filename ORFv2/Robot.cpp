#include "Includes.h"
#include "Robot.h"



Robot::Robot():
	ds(DriverStation::GetInstance()),
	camera(AxisCamera::GetInstance(g_cameraIP.c_str())),
	cRIO(),
	monitorBatteryTask("MonitorBattery", (FUNCPTR) MonitorBattery)
{
	this->mode_name = "Constructor";
	ModeStart();
	
	static DriveBase driveBase(this);
	static Launcher launcher(this);
	
	ModeEnd();
}

void Robot::RobotInit()
{
	this->mode_name = "RobotInit";
	ModeStart();
	
	// Start the battery monitoring Task.
	monitorBatteryTask.Start((UINT32) ds);
	
	
	
	
	
	SmartDashboard::PutString("Program", g_programName);
	SmartDashboard::PutBoolean("Checkbox 1", false);
	
	
	
	
	
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
	
	string LCD = "Program: ";
	LCD.append(g_programName);
	LCD.append(" -- Mode: ");
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
	LCD::ConsoleLog("Start: MonitorBattery");
	
	DriverStation	*ds;
	ds = (DriverStation*) dsPointer;
	
	bool batteryOK		= true;
	bool isAlarmLEDOn	= false;
	float voltage		= ds->GetBatteryVoltage();
	string message		= "Voltage: ";
	
	SmartDashboard::PutBoolean("Low Battery", !(batteryOK));
	
	
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
	
	while (true)
	{
		LCD::ConsoleLog("***WARNING***: LOW BATTERY!!!");
		isAlarmLEDOn = true;
		SmartDashboard::PutBoolean("Low Battery", isAlarmLEDOn);
		Wait(1.0);
		isAlarmLEDOn = false;
		SmartDashboard::PutBoolean("Low Battery", isAlarmLEDOn);
		Wait(1.0);
	}
}



START_ROBOT_CLASS(Robot);
