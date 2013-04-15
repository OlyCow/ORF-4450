#include "../Includes.h"



void Robot::Autonomous()
{
	this->mode_name = g_autonomousMode;
	ModeStart(true);
	cRIO->insight.pauseDisplay();
	
	LCD::ConsoleLog("Initializing launcher motor...");
	launcher.setLaunchMotor(g_maxPower);
	
	Wait(g_launchInitTime);
	LCD::ConsoleLog("Shooting frisbees...");
	launcher.shoot(g_pyramidLaunchPowerHigh, 3); // 3 frisbees
	
	LCD::ConsoleLog("Awaiting teleop...");
	ModeEnd();
}
