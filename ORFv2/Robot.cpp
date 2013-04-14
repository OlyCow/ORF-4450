#include "Includes.h"
#include "Robot.h"



Robot::Robot():
	ds(DriverStation::GetInstance()),
	camera(AxisCamera::GetInstance(g_cameraIP.c_str())),
	cRIO(),
	monitorBatteryTask("MonitorBattery", (FUNCPTR) MonitorBattery)
{
	this->mode_name = "Constructor";
	ModeStart(false);
	
	static DriveBase driveBase(this);
	static Launcher launcher(this);
	
	ModeEnd();
}

void Robot::RobotInit()
{
	this->mode_name = "RobotInit";
	ModeStart(false);
	
	
	launcher.reportLaunchPower();
	driveBase.reportTotalPower();
	driveBase.reportTotalRotation();
	
	bool hasFMS = ds->IsFMSAttached();
	SmartDashboard::PutBoolean("FMS", hasFMS);
	SmartDashboard::PutBoolean("Feed Disc", false);
	
	SmartDashboard::PutString("Program:", g_programName);
	SmartDashboard::PutString("Robot IP:", g_robotIP);
	
	
	srand(time(0));
	
	monitorBatteryTask.Start((UINT32) ds);
	
	ModeEnd();
}

void Robot::Disabled()
{
	this->mode_name = g_disabledMode;
	ModeStart(true);


	launcher.reportLaunchPower();
	driveBase.reportTotalPower();
	driveBase.reportTotalRotation();

	bool hasFMS = ds->IsFMSAttached();
	SmartDashboard::PutBoolean("FMS", hasFMS);
	SmartDashboard::PutBoolean("Feed Disc", false);
	
	
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

void Robot::ModeStart(bool useSmartDashboard)
{
	string console = "Start: ";
	console.append(this->mode_name);
	LCD::ConsoleLog(console);
	
	string LCD = "Program: ";
	LCD.append(g_programName);
	LCD.append(" -- Mode: ");
	LCD.append(this->mode_name);
	LCD::PrintLine(LINE_MODE, LCD);
	
	ClearModeLEDs();
	if (useSmartDashboard == true)
	{
		SmartDashboard::PutBoolean(mode_name, true);
	}
	
	alliance = ds->GetAlliance();
	startLocation = ds->GetLocation();
}
void Robot::ModeEnd()
{
	ClearModeLEDs();
	
	driveBase.zeroMotors();
	launcher.zeroMotors();
	
	string console = "End: ";
	console.append(this->mode_name);
	LCD::ConsoleLog(console);
	
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
		
		LCD::PrintLine(LINE_BATTERY, message);
		if (rand()%12==0) //12*5= once per 60 sec
			LCD::PrintEasterEgg();
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
