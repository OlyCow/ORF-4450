#include "WPILib.h"

class RobotDemo : public SimpleRobot
{
	RobotDrive myRobot;
	Joystick stick;

public:
	RobotDemo(void):
		myRobot(1, 2),	// these must be initialized in the same order
		stick(1)		// as they are declared above.
	{
		myRobot.SetExpiration(0.1);
	}


	void Autonomous(void)
	{
		myRobot.SetSafetyEnabled(false);
	}

	void OperatorControl(void)
	{
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
		}
	}
	
	void Test()
	{
	}
};

START_ROBOT_CLASS(RobotDemo);

