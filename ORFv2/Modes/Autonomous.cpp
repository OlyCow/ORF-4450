#include "../Includes.h"



void Robot::Autonomous()
{
	this->mode_name = "Autonomous";
	ModeStart();
	
	ClearModeLEDs();
	SmartDashboard::PutBoolean(g_autonomousMode, true);

	cRIO->insight.pauseDisplay();
	alliance = ds->GetAlliance();
	startLocation = ds->GetLocation();
	
	
	
	
	
	ModeEnd();
}
