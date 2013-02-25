#ifndef __MyDiscShooterCmd_h__
#define __MyDiscShooterCmd_h__

#include <WPILib.h>
#include "MyRobot.h"

class MyDiscShooterCmd : public Command
{
private:
	MyRobot *myRobot;
	int		exCount;
	
public:
	MyDiscShooterCmd(MyRobot *myRobot);
	
	virtual ~MyDiscShooterCmd();
	
	void Initialize(void);
	
	void Execute(void);
	
	void End(void);
	
	void Interrupted(void);
	
	bool IsFinished(void);
};

#endif // __MyDiscShooterCmd_h__
