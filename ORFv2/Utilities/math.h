#ifndef _MATH_H_
#define _MATH_H_



namespace math
{
	template <typename Type>
	Type limitMax(Type number, Type limiter);
	template <typename Type>
	Type limitMin(Type number, Type limiter);
	template <typename Type>
	Type prune(Type number, Type deadZone);
}



#endif // _MATH_H_
