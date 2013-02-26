#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <exception>
#include <WPILib.h>
#include "LCD.h"
#include "wiring.h"
#include "InsightLT/InsightLT.h"
using namespace insight;



class Robot : public SimpleRobot
{
public:
	wiring	cRIO;

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
