#include "MyRobot.h"
#include "LCD.h"
#include "MyAutonomous.h"
#include "MyTeleop.h"
#include <exception>

//	camera(AxisCamera::GetInstance(CAMERA_IP)),

MyRobot::MyRobot(void):
	robotDrive(1, 2),	// these must be initialized in the same order
	stick(1),		// as they are declared above.
	stick2(2),
	driveleftencoder(1, 2, true, 2), //setup encoder
	ds(DriverStation::GetInstance())
{
	try
	{
		LCD::ConsoleLog("RobotDemo Constructor");

		robotDrive.SetExpiration(0.1);

		//camera.WriteMaxFPS(10);

		LCD::ConsoleLog("RobotDemo Constructor-end");
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Exception: %s", e->what());
	}
}
	
void MyRobot::RobotInit(void)
{
	LCD::ConsoleLog("RobotInit");

	try
	{
		SmartDashboard::PutBoolean("End Wait", false);	
		SmartDashboard::PutBoolean("Arcade Drive", false);	

		LCD::PrintLine(1, "Mode: RobotInit");
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Exception: %s", e->what());
	}
}
	
void MyRobot::Disabled(void)
{
	try
	{
		LCD::ConsoleLog("Disabled");
		LCD::PrintLine(1, "Mode: Disabled");
		SmartDashboard::PutBoolean("End Wait", false);	
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Exception: %s", e->what());
	}
}

void MyRobot::Autonomous(void)
{
	MyAutonomous autonomous(this);
	
	try
	{
		LCD::ConsoleLog("Autonomous");
		LCD::PrintLine(1, "Mode: Autonomous");

		alliance = ds->GetAlliance();
		startLocation = ds->GetLocation();

		LCD::ConsoleLog("Auto Start: %d, Alliance: %d", startLocation, alliance);

		autonomous.DoAutonomous();

		LCD::ConsoleLog("Autonomous-end");
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Exception: %s", e->what());
	}
}

void MyRobot::OperatorControl(void)
{
	MyTeleop teleOp(this);

	try
	{
		LCD::ConsoleLog("OperatorControl");

		alliance = ds->GetAlliance();
		startLocation = ds->GetLocation();

		LCD::ConsoleLog("Teleop Start: %d, Alliance: %d", startLocation, alliance);

		teleOp.OperatorControl();

		LCD::ConsoleLog("OperatorControl-end");
	}
	catch (exception *e)
	{
		LCD::ConsoleLog("Exception: %s", e->what());
	}
}

START_ROBOT_CLASS(MyRobot);

