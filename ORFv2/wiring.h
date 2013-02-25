#ifndef _WIRING_H_
#define _WIRING_H_

#include <exception>
#include <WPIlib.h>
#include "LCD.h"
#include "InsightLT/InsightLT.h"

using namespace insight;



class wiring
{
public:
	InsightLT		insightLT;
	DecimalData		displayBattery;
	StringData		displayProgram;
	DriverStation	*ds;
		int							startLocation;
		DriverStation::Alliance		alliance;
	//AxisCamera	&camera;
	RobotDrive		driveSystem;
	Joystick		positionStick, rotateStick, launcherStick;
	Task			monitorBatteryTask;
	
	wiring();
	
	
private:
};



#endif //_WIRING_H_
