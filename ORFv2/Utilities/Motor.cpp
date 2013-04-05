#include "../Includes.h"
#include "Motor.h"

//using namespace math;



Motor::Motor(UINT32 channel, bool isInverted):
	Talon(channel),
	isInverted(isInverted)
{
	Set(0);
}
Motor::~Motor()
{
	Set(0);
}

void Motor::Invert()
{
	isInverted = true;
}
void Motor::Restore()
{
	isInverted = false;
}

void Motor::Set(float value, UINT8 syncGroup)
{
	using namespace math;
	if(isInverted==true)
		Talon::Set(limitMin(-value, g_maxPower), syncGroup);
	else
		Talon::Set(limitMax(value, g_maxPower), syncGroup);
}

float Motor::Get()
{
	if(isInverted==true)
		return -(Talon::Get());
	else
		return Talon::Get();
}

bool Motor::checkIfInverted()
{
	return isInverted;
}
