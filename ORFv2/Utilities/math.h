#ifndef _MATH_H_
#define _MATH_H_



namespace math
{
	template <typename Type>
	Type limit(Type input, Type lowLimit, Type highLimit);
	template <typename Type>
	Type limitMax(Type input, Type limiter);
	template <typename Type>
	Type limitMin(Type input, Type limiter);
	
	long double PI();
	long double E();
	long double PHI();
	
	template <typename Type>
	Type degToRad(Type degrees);
	template <typename Type>
	Type degToGrad(Type degrees);
	template <typename Type>
	Type radToDeg(Type radians);
	template <typename Type>
	Type radToGrad(Type gradians);
	template <typename Type>
	Type gradToDeg(Type gradians);
	template <typename Type>
	Type gradToRad(Type radians);
	
	template <typename Type>
	Type prune(Type input, Type deadZone);
	
	template <typename Type>
	Type normalize(	Type input,
					Type currentHigh,
					Type normalizedHigh	);
	
	template <typename Type>
	void rotateVector(Type x, Type y, Type degrees);
	
	template <typename Type>
	string stringify(Type input);
}



#endif // _MATH_H_
