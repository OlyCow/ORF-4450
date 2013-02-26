#ifndef _GLOBAL_VARS_H_
#define _GLOBAL_VARS_H_

#include <string>
#include "WPILib.h"
#include "Enums.h"

const int g_InitDiscNum = 3;

const float g_LauncherPower = -0.67;
const float g_LowBattery = 10.0;

const double g_LauncherInitTime = 6;
const double g_LauncherRecoverTime = 3.0;

const char g_CameraIP[] = {"10.44.50.11"};

const string g_ProgramName = "MyRobot3-1.0";
//// Below is a failed attempt at reassigning values to an array.
//int g_LauncherPower[MODE_NUMBER] = { 0 };
//g_LauncherPower[MODE_LEFT] = 0;
//int array[7] = {1,2,3,0,0,0,0};
//array[3] = 50;



// And lastly, *shudder* the #defines.
// If they're commented out, they are deprecated.
#define PROGRAM_NAME		"MyRobot3-1.0"
//#define CAMERA_IP			"10.44.50.11"
//#define LOW_BATTERY			10.0
#define	JSB_TOP_MIDDLE		3
#define JSB_TOP_LEFT		4
#define JSB_TOP_RIGHT		5
#define JSB_TRIGGER			1
#define JSB_TOP_BACK		2
#define JSB_LEFT_FRONT		6
#define JSB_LEFT_REAR		7
#define JSB_RIGHT_FRONT		11
#define JSB_RIGHT_REAR		10
#define JSB_BACK_LEFT		8
#define JSB_BACK_RIGHT		9

#endif //_GLOBAL_VARS_H_
