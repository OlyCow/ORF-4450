#include "../Includes.h"



void Robot::Test()
{
	this->mode_name = g_testMode;
	ModeStart(true);
	
	
	
	// Should add actual testing code here.
	// Would include testing for as many
	// motors and switches as possible.
	
	this->OperatorControl();
	
	
	
	ModeEnd();
}
