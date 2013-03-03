#include "../Includes.h"
#include "math.h"

using namespace math;



template <typename Type>
Type limitMax(Type input, Type limiter)
{
	if(input<limiter)
		return input;
	else
		return limiter;
}

template <typename Type>
Type limitMin(Type input, Type limiter)
{
	if(input>limiter)
		return input;
	else
		return limiter;
}

template <typename Type>
Type prune(Type input, Type deadZone)
{
	if(input>deadZone)
		return input;
	else
		return 0;
}
