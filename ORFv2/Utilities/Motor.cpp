#include "../Includes.h"
#include "Motor.h"



Motor::Motor(UINT32 channel, bool isInverted):
	Talon(channel),
	isInverted(isInverted)
{
	Set(0);
}

void Motor::Invert()
{
	isInverted = true;
}

void Motor::Set(float value, UINT8 syncGroup)
{
	if(isInverted==true)
		Talon::Set(-value, syncGroup);
	else
		Talon::Set(value, syncGroup);
}

float Motor::Get()
{
	if(isInverted==true)
		return -(Talon::Get());
	else
		return Talon::Get();
}
