#include "../Includes.h"



void Robot::Autonomous()
{
	this->mode_name = g_autonomousMode;
	ModeStart(true);
	cRIO->insight.pauseDisplay();
	
	bool hasFMS = ds->IsFMSAttached();
	SmartDashboard::PutBoolean("FMS Connected", hasFMS);
	launcher.reportLaunchPower();
	
	LCD::ConsoleLog("Initializing launcher motor...");
	launcher.setLaunchMotor(g_maxPower);
	launcher.reportLaunchPower();
	
	Wait(g_launchInitTime);
	LCD::ConsoleLog("Shooting frisbees...");
	launcher.reportLaunchPower();
	
	launcher.shoot(g_maxPower, 3); // 3 frisbees
	launcher.reportLaunchPower();
	
	LCD::ConsoleLog("Awaiting teleop...");
	
	ModeEnd();
}
