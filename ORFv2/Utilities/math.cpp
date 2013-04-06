#include "../Includes.h"
#include "math.h"

using namespace math;



template <typename Type>
Type limit(Type input, Type lowLimit, Type highLimit)
{
	if (input<lowLimit)
		return limitMax(input, lowLimit);
	else if (input>highLimit)
		return limitMin(input, highLimit);
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

long double math::PI()
{
	// One of Ramanujan's approximations.
	// Accurate to 9 digits.
	return pow((2143/22),(1/4));
}
long double math::E()
{
	// Courtesy of Wolfram Mathworld.
	// Accurate to 10 digits.
	return pow((150 - 907335/571787),(1/5));
}
long double math::PHI()
{
	// This is the definition of phi.
	// Consequently, extremely accurate.
	return (1+sqrt(5)) / 2;
}

template <typename Type>
Type degToRad(Type degrees)
{
	return degrees*180/PI();
}
template <typename Type>
Type degToGrad(Type degrees)
{
	return degrees*10/9;
}
template <typename Type>
Type radToDeg(Type radians)
{
	return radians*PI()/180;
}
template <typename Type>
Type radToGrad(Type gradians)
{
	return gradians*PI()/200;
}
template <typename Type>
Type gradToDeg(Type gradians)
{
	return gradians*9/10;
}
template <typename Type>
Type gradToRad(Type radians)
{
	return radians*200/PI();
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
	return (input/currentHigh)*normalizedHigh;
}

template <typename Type>
void rotateVector(Type x, Type y, Type degrees)
{
	//This is what the matrices tells us.
	x =		x*cos(degToRad(degrees)) -
			y*sin(degToRad(degrees));
	y =		x*sin(degToRad(degrees)) +
			y*cos(degToRad(degrees));
}

template <typename Type>
string stringify(Type input)
{
	ostringstream convertStream;
	convertStream << input;
	//stringstream does auto-formatting :)
	return convertStream.str();
}

string getEasterEgg()
{
	string easter_egg = "";
	ifstream readStream("../Utilities/easter_egg.txt");
	readStream.seekg(0, ios::end);
	int fileSize = readStream.tellg();
	
	do
	{
		string incompleteLine = "";
		readStream.seekg(rand()%fileSize, ios::beg);
		getline(readStream, incompleteLine);
		if (readStream.eof())
			continue;
		else
		{
			getline(readStream, easter_egg);
			break;
		}
	}
	while (readStream.eof());
	
	readStream.close();
	
	return easter_egg;
}
