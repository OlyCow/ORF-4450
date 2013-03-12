#include "../Includes.h"
#include "math.h"

using namespace math;



template <typename Type>
Type limit(Type input, Type limiter)
{
	if (input>0)
		limitMax(input, limiter);
	else if (input<0)
		limitMin(input, limiter);
	else
		return 0;
}

template <typename Type>
Type limitMax(Type input, Type limiter)
{
	if (input<limiter)
		return input;
	else
		return limiter;
}

template <typename Type>
Type limitMin(Type input, Type limiter)
{
	if (input>limiter)
		return input;
	else
		return limiter;
}

template <typename Type>
Type prune(Type input, Type deadZone)
{
	if (input>deadZone)
		return input;
	else
		return 0;
}

template <typename Type>
Type normalize(	Type input,
				Type currentHigh,
				Type normalizedHigh	)
{
	;
}

template <typename Type>
Type rotateVector(Type x, Type y, Type degrees)
{
	;
}
