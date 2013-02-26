#ifndef _WIRING_H_
#define _WIRING_H_

#include "../Includes.h"



class wiring
{
public:
	RobotDrive		driveSystem;
	Joystick		positionStick, rotateStick, launcherStick;
	
	wiring();
	
	
private:
};



#endif //_WIRING_H_
