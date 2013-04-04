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
	ClearModeLEDs();
	
	
	SmartDashboard::PutNumber(	"Launch Speed",
								launcher.getLaunchMotor() );
	SmartDashboard::PutNumber(	"Total Power",
								driveBase.getDrivePower() );
	SmartDashboard::PutNumber(	"Total Rotation",
								driveBase.getDriveRotation() );
	
	bool hasFMS = ds->IsFMSAttached();
	SmartDashboard::PutBoolean("FMS Connected", hasFMS);
	SmartDashboard::PutBoolean("Feeding Disc", false);
	
	//THIS IS A TEST!
	SmartDashboard::GetBoolean("Test: bool input");
	SmartDashboard::GetString("Test: string input");
	SmartDashboard::GetNumber("Test: double input");
	
	
	monitorBatteryTask.Start((UINT32) ds);
	
	ModeEnd();
}

void Robot::Disabled()
{
	this->mode_name = "Disabled";
	ModeStart();
	ClearModeLEDs();
	SmartDashboard::PutBoolean(g_disabledMode, true);


	SmartDashboard::PutNumber(	"Launch Speed",
								launcher.getLaunchMotor() );
	SmartDashboard::PutNumber(	"Total Power",
								driveBase.getDrivePower() );
	SmartDashboard::PutNumber(	"Total Rotation",
								driveBase.getDriveRotation() );

	bool hasFMS = ds->IsFMSAttached();
	SmartDashboard::PutBoolean("FMS Connected", hasFMS);
	SmartDashboard::PutBoolean("Feeding Disc", false);
	
	
	cRIO->insightBattery.setData(ds->GetBatteryVoltage());
	ModeEnd();
}

void Robot::ClearModeLEDs()
{
	SmartDashboard::PutBoolean(g_disabledMode, false);
	SmartDashboard::PutBoolean(g_autonomousMode, false);
	SmartDashboard::PutBoolean(g_teleopMode, false);
	SmartDashboard::PutBoolean(g_testMode, false);
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
	ClearModeLEDs();
	
	driveBase.zeroMotors();
	launcher.zeroMotors();
	
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
