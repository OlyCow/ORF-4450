#ifndef _MATH_H_
#define _MATH_H_



namespace math
{
	template <typename Type>
	Type limit(Type input, Type limiter);
	
	template <typename Type>
	Type limitMax(Type input, Type limiter);
	
	template <typename Type>
	Type limitMin(Type input, Type limiter);
	
	template <typename Type>
	Type prune(Type input, Type deadZone);
	
	template <typename Type>
	Type normalize(	Type input,
					Type currentHigh,
					Type normalizedHigh	);
	
	template <typename Type>
	Type rotateVector(Type x, Type y, Type degrees);
}



#endif // _MATH_H_
