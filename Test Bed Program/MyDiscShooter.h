#ifndef __MyDiscShooter_h__
#define __MyDiscShooter_h__

#include <WPILib.h>
#include "MyRobot.h"

class MyDiscShooter
{
private:
	MyRobot *myRobot;
	
public:
	MyDiscShooter(MyRobot *myRobot);
	
	virtual ~MyDiscShooter();
	
	void Shoot(void);
};

#endif // __MyDiscShooter_h__
