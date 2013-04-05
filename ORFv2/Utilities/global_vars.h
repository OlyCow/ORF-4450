#ifndef _GLOBAL_VARS_H_
#define _GLOBAL_VARS_H_

#include "../Includes.h"



const int THE_ANSWER = 42;

const float g_expiration = 0.10; //seconds

const float g_joystickDeadZone = 0.01; //% power

const float g_fineTuneFactor = 4;

const float g_maxPower = 1.00; //% power
const float g_halfPower = 0.50; //% power
const float g_feederPower = 0.50; //% power

const float g_shootInterval = 3.0; //seconds

const float g_launchInitRequired = 0.2; //% power
const float g_launchInitTime = 1.0; //seconds

const float g_lowBatteryThreshold = 10.0; //volts



// For the Smart Dashboard "LEDs".
const string g_disabledMode		= " Disabled ";
const string g_autonomousMode	= "Autonomous";
const string g_teleopMode		= "  Teleop  ";
const string g_testMode			= "   Test   ";

const string g_programHeader = "Program: ";
const string g_batteryHeader = "Battery: ";

const string g_programName = "ORFv2";

const string g_cameraIP = "10.44.50.11";



#endif // _GLOBAL_VARS_H_
