#ifndef __MyRobot_h__
#define __MyRobot_h__

#include <WPILib.h>
#include "InsightLT/InsightLT.h"



using namespace insight;

class MyRobot : public SimpleRobot
{
public:
	RobotDrive 		robotDrive;
	Joystick 		leftStick, rightStick, rotateStick;
	//AxisCamera		&camera;
	DriverStation 	*ds;
	InsightLT		insightLT;
	DecimalData		displayBattery;
	StringData		displayProgram;
	Task			monitorBatteryTask;
	
	int 					startLocation;
	DriverStation::Alliance alliance;
	
	MyRobot();
	
	void RobotInit();
	void Disabled();
	void Autonomous();
	void OperatorControl();
	
private:
	// This is a task.
	static void MonitorBattery(int dsPointer);
};

#endif //__MyRobot_h__
