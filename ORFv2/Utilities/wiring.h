#ifndef _WIRING_H_
#define _WIRING_H_

#include <exception>
#include <WPIlib.h>
#include "Utilities/LCD.h"
#include "InsightLT/InsightLT.h"

using namespace insight;



class wiring
{
public:
	RobotDrive		driveSystem;
	Joystick		positionStick, rotateStick, launcherStick;
	
	wiring();
	
	
private:
};



#endif //_WIRING_H_
