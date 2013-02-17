#include "MyRobot.h"
#include "LCD.h"
#include "MyAutonomous.h"
#include "MyTeleop.h"
#include <exception>

//	camera(AxisCamera::GetInstance(CAMERA_IP)),

// MyRobot class constructor. Called when instance of MyRobot is created.

MyRobot::MyRobot(void):
	robotDrive(1, 2),	// these must be initialized in the same order
	stick(1),			// as they are declared.
	stick2(2),
	ds(DriverStation::GetInstance()),
	insightLT(insight::TWO_ONE_LINE_ZONES),
	displayBattery("Battery: "),
	displayProgram("Pgm: "),
	monitorBatteryTask("MonitorBattery", (FUNCPTR) MonitorBattery)
{
	try
	{
		LCD::ConsoleLog("%s Constructor", PROGRAM_NAME);

		robotDrive.SetExpiration(0.1);

		// Set the InsightLT display.
		insightLT.registerData(displayProgram, 1);
		displayProgram.setData(PROGRAM_NAME);
		insightLT.registerData(displayBattery, 2);

		LCD::ConsoleLog("%s Constructor-end", PROGRAM_NAME);
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Constructor Exception: %s", e->what());
	}
}
	
// Called when MyRobot class started by cRio.

void MyRobot::RobotInit(void)
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

void MyRobot::Disabled(void)
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

// Called by cRio when driver station enables autonomous mode.

void MyRobot::Autonomous(void)
{
	MyAutonomous autonomous(this);
	
	try
	{
		LCD::ConsoleLog("Autonomous");
		LCD::PrintLine(1, "Mode: Autonomous");
		SmartDashboard::PutBoolean("Disabled", false);	
		SmartDashboard::PutBoolean("Autonomous Mode", true);	
		insightLT.pauseDisplay();

		// Make available the alliance (red/blue) and staring position as
		// set on the driver station or FMS.
		
		alliance = ds->GetAlliance();
		startLocation = ds->GetLocation();

		LCD::ConsoleLog("Auto Start: %d, Alliance: %d", startLocation, alliance);

		// Start autonomous process contained in the MyAutonomous class.
		
		autonomous.DoAutonomous();
		
		SmartDashboard::PutBoolean("Autonomous Mode", false);	
		LCD::ConsoleLog("Autonomous-end");
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Autonomous Exception: %s", e->what());
	}
}

// Called by cRio when driver station enables teleop mode.

void MyRobot::OperatorControl(void)
{
	MyTeleop teleOp(this);

	try
	{
		LCD::ConsoleLog("OperatorControl");
		SmartDashboard::PutBoolean("Disabled", false);	
		SmartDashboard::PutBoolean("Teleop Mode", true);	
		insightLT.pauseDisplay();

		alliance = ds->GetAlliance();
		startLocation = ds->GetLocation();

		LCD::ConsoleLog("Teleop Start: %d, Alliance: %d", startLocation, alliance);

		// Start operator control process contained in the MyTeleop class.

		teleOp.OperatorControl();
		
		LCD::ConsoleLog("OperatorControl-end");
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("OperatorControl Exception: %s", e->what());
	}
}

// Runs as a Task in separate thread from our MyRobot class. Runs until our
// program is terminated from the cRio.

void MyRobot::MonitorBattery(int dsPointer)
{
	DriverStation 	*ds;
	bool			batteryOk = true, alarmFlash = false;
	
	try
	{
		LCD::ConsoleLog("Start MonitorBattery");

		ds = (DriverStation*) dsPointer;

		SmartDashboard::PutBoolean("Low Battery", false);
		
		// Check battery voltage every 10 seconds. Drop out when battery
		// goes below the threshold.
		
		while (batteryOk)
		{
			//LCD::ConsoleLog("Battery Check %f", ds->GetBatteryVoltage());

			if (ds->GetBatteryVoltage() < LOW_BATTERY) batteryOk = false;
		
			Wait(10.0);
		}

		// flash the battery warning led on driverstation.
		
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

START_ROBOT_CLASS(MyRobot);

