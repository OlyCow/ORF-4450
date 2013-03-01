#include "../Includes.h"
#include "Launcher.h"



Launcher::Launcher(Robot *robot):
	robot(robot)
{
}



void Launcher::shoot(float power, int shots)
{
	float originalLaunchPower = getLaunchMotorPower();
	setLaunchPower(power);
	feedDiscs(shots);
	setLaunchPower(originalLaunchPower);
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



void Launcher::setLaunchPower(float power)
{
	robot->cRIO->launchMotor.SetSpeed(power);
}

void Launcher::setHeightMotor(float power)
{
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



float Launcher::getLaunchMotorPower()
{
	return robot->cRIO->launchMotor.Get();
}

float Launcher::getHeightMotorPower()
{
	return robot->cRIO->heightMotor.Get();
}

float Launcher::getRampMotorPower()
{
	return robot->cRIO->rampMotor.Get();
}



float Launcher::getFeederMotorPower()
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

