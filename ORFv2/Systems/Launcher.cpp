#include "../Includes.h"
#include "Launcher.h"



Launcher::Launcher(Robot *robot):
	robot(robot)
{
	setLaunchMotor(0.0);
	setHeightMotor(0.0);
	setRampMotor(0.0);
	setFeederMotor(0.0);
}

Launcher::~Launcher()
{
	setLaunchMotor(0.0);
	setHeightMotor(0.0);
	setRampMotor(0.0);
	setFeederMotor(0.0);
}



void Launcher::shoot(float power, int shots)
{
	float originalLaunchPower = getLaunchMotor();
	if (power-originalLaunchPower>g_launchInitRequired)
		Wait(g_launchInitTime);
	setLaunchMotor(power);
	feedDiscs(shots);
	setLaunchMotor(originalLaunchPower);
}
void Launcher::maxHeight(float power)
{
	setHeightMotor(0);
	while(getTopLimitSwitch()==false)
		setHeightMotor(power);
	setHeightMotor(0);
}
void Launcher::minHeight(float power)
{
	setHeightMotor(0);
	while(getBottomLimitSwitch()==false)
		setHeightMotor(-power);
	setHeightMotor(0);
}



void Launcher::setLaunchMotor(float power)
{
	robot->cRIO->launchMotor.SetSpeed(power);
}
void Launcher::setHeightMotor(float power)
{
	if( (getTopLimitSwitch()||getBottomLimitSwitch()) ==true )
		robot->cRIO->heightMotor.SetSpeed(0);
	else
		robot->cRIO->heightMotor.SetSpeed(power);
}
void Launcher::setRampMotor(float power)
{
	robot->cRIO->rampMotor.SetSpeed(power);
}



void Launcher::setFeederMotor(float power)
{
	robot->cRIO->feederMotor.SetSpeed(power);
}



bool Launcher::getTopLimitSwitch()
{
	return robot->cRIO->topHeightLimitSwitch.Get();
}
bool Launcher::getBottomLimitSwitch()
{
	return robot->cRIO->bottomHeightLimitSwitch.Get();
}
bool Launcher::getFeederLimitSwitch()
{
	return robot->cRIO->feederLimitSwitch.Get();
}



float Launcher::getLaunchMotor()
{
	return robot->cRIO->launchMotor.Get();
}
float Launcher::getHeightMotor()
{
	return robot->cRIO->heightMotor.Get();
}
float Launcher::getRampMotor()
{
	return robot->cRIO->rampMotor.Get();
}



float Launcher::getFeederMotor()
{
	return robot->cRIO->feederMotor.Get();
}



void Launcher::feedDiscs(int discNumber, float interval)
{
	setFeederMotor(0);

	if (discNumber==1)
		interval = 0;

	for (int i=1; i<=discNumber; i++)
	{
		while(getFeederLimitSwitch()==0)
			setFeederMotor(g_feederPower);
		Wait(interval);
		setFeederMotor(0);
	}
}

