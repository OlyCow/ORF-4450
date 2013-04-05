#include "../Includes.h"



void Robot::Autonomous()
{
	this->mode_name = g_autonomousMode;
	ModeStart(true);
	cRIO->insight.pauseDisplay();
	
	
	
	// CODE
	
	
	
	ModeEnd();
}
