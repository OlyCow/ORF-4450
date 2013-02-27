#ifndef _LAUNCHER_H_
#define _LAUNCHER_H_

#include "../Robot.h"



class Launcher
{
public:
	Launcher(Robot *ORFius);
	~Launcher();
	
	void shoot(float power=1.00, int shots=1);
	void maxHeight();
	void minHeight();
	
	void setLaunchPower(float power);
	void setHeightMotor(float power);
	void setRampMotor(float power);
	
	bool getTopLimitSwitchState();
	bool getBottomLimitSwitchState();
	bool getFeederLimitSwitchState();
	
	float getLaunchMotorPower();
	float getHeightMotorPower();
	float getRampMotorPower();
	
	float getFeederMotorPower();
	
	
private:
	Robot *ORFius;
	
	void setFeederMotor(float power);
};



#endif // _LAUNCHER_H_
