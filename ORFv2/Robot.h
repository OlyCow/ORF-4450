#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "Includes.h"



class Robot : public SimpleRobot
{
public:
	InsightLT		insightLT;
	DecimalData		displayBattery;
	StringData		displayProgram;
	DriverStation	*ds;
		int							startLocation;
		DriverStation::Alliance		alliance;
	//AxisCamera	&camera;
	Task			monitorBatteryTask;

	Robot();
	void RobotInit();
	void Disabled();
	void Autonomous();
	void OperatorControl();


private:
	// Runs as task.
	static void MonitorBattery(int dsPointer);
};



#endif // _ROBOT_H_