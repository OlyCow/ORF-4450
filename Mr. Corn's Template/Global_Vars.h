#ifndef _GLOBAL_VARS_H_
#define _GLOBAL_VARS_H_

#include "WPILib.h"
#include "Enums.h"

const int g_InitDiscNum = 3;

const float g_LauncherPower = -0.67;
const double g_LauncherInitTime = 6;

const char g_CameraIP[] = {"10.44.50.11"};

//// Below is a failed attempt at reassigning values to an array.
//int g_LauncherPower[MODE_NUMBER] = { 0 };
//g_LauncherPower[MODE_LEFT] = 0;
//int array[7] = {1,2,3,0,0,0,0};
//array[3] = 50;


#endif //_GLOBAL_VARS_H_
