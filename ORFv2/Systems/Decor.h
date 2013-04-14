#ifndef _DECOR_H_
#define _DECOR_H_

#include "../Robot.h"



class Decor
{
public:
	Decor(Robot *robot);
	
	void flow(float speed, float length);
	void flash(float speed, float gap, int number);
	
	void clear();
	
	
private:
	Robot *robot;
	string keyname;
};



#endif // _DECOR_H_
