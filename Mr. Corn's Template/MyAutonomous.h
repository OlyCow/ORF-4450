#ifndef __MyAutonomous_h__
#define __MyAutonomous_h__

#include <WPILib.h>
#include "MyRobot.h"

class MyAutonomous
{
private:
	MyRobot *myRobot;
	
public:
	MyAutonomous(MyRobot *myRobot);
	
	virtual ~MyAutonomous();
	
	void DoAutonomous(void);
};

#endif // __MyAutonomous_h__
