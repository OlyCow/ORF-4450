#ifndef __MyRobot_h__
#define __MyRobot_h__

#include <WPILib.h>
#include "InsightLT/InsightLT.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 */ 

#define CAMERA_IP		"10.44.50.11"
#define PROGRAM_NAME	"MyRobot3-1.0"
#define LOW_BATTERY		10.0

using namespace insight;

class MyRobot : public SimpleRobot
{
public:
	RobotDrive 		robotDrive; 	// robot drive system
	Joystick 		leftStick, rightStick; 	// joysticks
	//AxisCamera 	&camera;
	DriverStation 	*ds;
	InsightLT		insightLT;
	DecimalData		displayBattery;
	StringData		displayProgram;
	Task			monitorBatteryTask;
	
	int 					startLocation;
	DriverStation::Alliance alliance;
	
	MyRobot(void);
	
	void RobotInit(void);
	
	void Disabled(void);

	void Autonomous(void);

	void OperatorControl(void);
	
private:
	// Runs as task.
	static void MonitorBattery(int dsPointer);
};

#endif // __MyRobot_h__
