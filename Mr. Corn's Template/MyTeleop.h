#ifndef __MyTeleop_h__
#define __MyTeleop_h__

#include <WPILib.h>
#include "MyRobot.h"

class MyTeleop
{
private:
	MyRobot *myRobot;
	
public:
	MyTeleop(MyRobot *myRobot);
	
	virtual ~MyTeleop();
	
	void OperatorControl(void);
};

#endif // __MyTeleop_h__
