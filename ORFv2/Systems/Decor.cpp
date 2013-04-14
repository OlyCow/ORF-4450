#include "../Includes.h"
#include "Decor.h"

using namespace math;



Decor::Decor(Robot *robot):
	robot(robot),
	keyname("Decal ")
{
	clear();
}

void Decor::flow(float length, float speed)
{
	for (int i=1; i<=g_decorNumber+length; i++)
	{
		if (i<=g_decorNumber)
		{
			SmartDashboard::PutBoolean
				(keyname.append(stringify(i)), true );
		}
		if (i>length)
		{
			SmartDashboard::PutBoolean
				(keyname.append(stringify(i-length)), false);
		}
		Wait(speed);
	}
}
void Decor::flash(float length, float gap, int number)
{
	for(int i=0; i<number; i++)
	{
		for (int i=1; i<=g_decorNumber; i++)
				SmartDashboard::PutBoolean(	keyname.append(stringify(i)),
											true );
		Wait(length);
		for (int i=1; i<=g_decorNumber; i++)
				SmartDashboard::PutBoolean(	keyname.append(stringify(i)),
											false );
		Wait(gap);
	}
}

void Decor::clear()
{
	for (int i=1; i<=g_decorNumber; i++)
		SmartDashboard::PutBoolean(	keyname.append(stringify(i)),
									false );
}

