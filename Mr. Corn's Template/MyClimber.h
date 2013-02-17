#ifndef __MyClimber_h__
#define __MyClimber_h__

#include <WPILib.h>
#include "MyRobot.h"

class MyClimber
{
private:
	MyRobot *myRobot;
	
public:
	MyClimber(MyRobot *myRobot);
	
	virtual ~MyClimber();
	
	void Climb(void);
};

#endif // __MyClimber_h__
