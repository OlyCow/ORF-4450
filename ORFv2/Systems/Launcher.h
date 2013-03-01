#ifndef _LAUNCHER_H_
#define _LAUNCHER_H_

#include "../Robot.h"



class Launcher
{
public:
	Launcher(Robot *robot);
	~Launcher();
	
	void shoot(float power=g_maxPower, int shots=1);
	void maxHeight(float power=g_halfPower);
	void minHeight(float power=g_halfPower);
	
	void setLaunchPower(float power);
	void setHeightMotor(float power);
	void setRampMotor(float power);
	
	bool getTopLimitSwitch();
	bool getBottomLimitSwitch();
	bool getFeederLimitSwitch();
	
	float getLaunchMotorPower();
	float getHeightMotorPower();
	float getRampMotorPower();

	float getFeederMotorPower();
	
	
private:
	Robot *robot;

	void setFeederMotor(float power);

	void feedDiscs(	int discNumber=1,
					float interval=g_shootInterval );
};



#endif // _LAUNCHER_H_
