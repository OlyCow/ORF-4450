#ifndef _GLOBAL_VARS_H_
#define _GLOBAL_VARS_H_

#include "../Includes.h"



const int THE_ANSWER = 42;

const int g_decorNumber = 25; //number on the Dashboard



const float g_expiration = 0.15; //seconds

const float g_teleopLoopInterval = 0.02; //seconds

const float g_joystickDeadZone = 0.05; //% power
const float g_joystickDeadZone_rotation = 0.1; //% power

const float g_fineTuneFactor = 4;

const float g_maxPower = 1.00; //% power
const float g_halfPower = 0.50; //% power
const float g_rampPower = 0.65; //% power
const float g_feederPower = 1.00; //% power

const float g_pyramidLaunchPowerHigh = 0.79; //% power
const float g_pyramidLaunchPowerMid = 0.75; //% power
const float g_crossCourtLaunchPowerHigh = 1.00; //% power
const float g_crossCourtLaunchPowerMid = 1.00; //% power


const float g_shootInterval = 3.0; //seconds

const float g_launchInitRequired = 0.1; //% power
const float g_launchInitTime = 1.5; //seconds

const float g_lowBatteryThreshold = 10.0; //volts

const float g_LEDFlashDuration = 1.0; //seconds



// For the Smart Dashboard "LEDs".
const string g_disabledMode		= "Disabled";
const string g_autonomousMode	= "Auto";
const string g_teleopMode		= "Teleop";
const string g_testMode			= "Test";

const string g_programHeader = "Program: ";
const string g_batteryHeader = "Battery: ";

const string g_programName = "ORFv2";

const string g_robotIP = "10.44.50.2";
const string g_cameraIP = "10.44.50.11";

const string g_pathToMinecraft = "minecraft.txt";
const string g_pathToJokes = "jokes.txt";
const string g_pathToPuns = "puns.txt";



#endif // _GLOBAL_VARS_H_
