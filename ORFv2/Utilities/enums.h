#ifndef _ENUMS_H_
#define _ENUMS_H_

#include "../Includes.h"



enum Buttons
{
	BUTTON_TRIGGER		= 1,
	BUTTON_CENTER		= 3,
	BUTTON_REAR			= 2,
	BUTTON_LEFT			= 4,
	BUTTON_RIGHT		= 5,
	BUTTON_LEFT_FRONT	= 6,
	BUTTON_LEFT_REAR	= 7,
	BUTTON_REAR_LEFT	= 8,
	BUTTON_REAR_RIGHT	= 9,
	BUTTON_RIGHT_FRONT	= 11,
	BUTTON_RIGHT_REAR	= 10,
};

enum MotorConnection
{
	MOTOR_NORMAL	= 0,	//isInverted = false
	MOTOR_INVERTED	= 1,	//isInverted = true
};

enum LineNumber
{
	LINE_MODE		= 1,
	LINE_BATTERY	= 2,
};



#endif // _ENUMS_H_
