#include "../Includes.h"
#include "math.h"

using namespace math;



//template <typename Type>
float limit(float input, float limiter)
{
	if (input>0)
		return limitMax(input, limiter);
	else if (input<0)
		return limitMin(input, limiter);
	else
		return 0;
}

//template <typename Type>
float limitMax(float input, float limiter)
{
	if (input<limiter)
		return input;
	else
		return limiter;
}

//template <typename Type>
float limitMin(float input, float limiter)
{
	if (input>limiter)
		return input;
	else
		return limiter;
}

template <typename Type>
Type prune(Type input, Type deadZone)
{
	if (input > deadZone)
		return input;
	else if (input < -deadZone)
		return input;
	else
		return 0;
}

template <typename Type>
Type normalize(	Type input,
				Type currentHigh,
				Type normalizedHigh	)
{
}

template <typename Type>
void rotateVector(Type x, Type y, Type degrees)
{
}

template <typename Type>
string stringify(Type input)
{
	ostringstream convertStream;
	convertStream << input;
	return convertStream.str();
}
