#include "Includes.h"
#include "Robot.h"



Robot::Robot():
	ds(DriverStation::GetInstance()),
	camera(AxisCamera::GetInstance(g_cameraIP.c_str())),
	cRIO(),
	monitorBattery("MonitorBattery", (FUNCPTR) MonitorBattery),
	monitorStatus("MonitorStatus", (FUNCPTR) MonitorStatus)
{
	this->mode_name = "Constructor";
	ModeStart(false);
	
	static DriveBase driveBase(this);
	static Launcher launcher(this);
	static Decor decor(this);
	
	ModeEnd();
}

void Robot::RobotInit()
{
	this->mode_name = "RobotInit";
	ModeStart(false);
	
	
	bool hasFMS = ds->IsFMSAttached();
	SmartDashboard::PutBoolean("FMS", hasFMS);
	SmartDashboard::PutBoolean("Feed Disc", false);
	
	SmartDashboard::PutString("Program:", g_programName);
	SmartDashboard::PutString("Robot IP:", g_robotIP);
	
	monitorBattery.Start((UINT32) ds);
	monitorStatus.Start((UINT32) ds);
	
	srand(time(0));
	
	
	ModeEnd();
}

void Robot::Disabled()
{
	this->mode_name = g_disabledMode;
	ModeStart(true);

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
	float voltage		= ds->GetBatteryVoltage();
	string message		= "Voltage: ";
	
	SmartDashboard::PutBoolean("Low Battery", !(batteryOK));
	
	
	while (true)
	{
		voltage = ds->GetBatteryVoltage();
		if (voltage < g_lowBatteryThreshold)
			batteryOK = false;
		message.append(math::stringify(voltage));
		
		LCD::PrintLine(LINE_BATTERY, message);
		if (rand()%12==0) //12*5= once per 60 sec
			LCD::PrintEasterEgg();
		
		if (batteryOK == false)
		{
			LCD::ConsoleLog("***WARNING***: LOW BATTERY!!!");
			SmartDashboard::PutBoolean("Low Battery", true);
			Wait(g_LEDFlashDuration);
			SmartDashboard::PutBoolean("Low Battery", false);
			Wait(g_LEDFlashDuration);
		}
		
		Wait(100*g_teleopLoopInterval);
	}
}
void Robot::MonitorStatus(int dsPointer)
{
	LCD::ConsoleLog("Start: MonitorStatus");
		
	DriverStation	*ds;
	ds = (DriverStation*) dsPointer;
	
	while (true)
	{
		SmartDashboard::PutNumber(	"Launcher Power",
									launcher.getLaunchMotor() );
		SmartDashboard::PutNumber(	"Linear Output",
									driveBase.getDrivePower() );
		SmartDashboard::PutNumber(	"Rotation Output",
									driveBase.getDriveRotation() );
		SmartDashboard::PutBoolean("FMS", ds->IsFMSAttached());
		Wait(g_teleopLoopInterval);
	}
}



START_ROBOT_CLASS(Robot);
