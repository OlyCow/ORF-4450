#ifndef _CLIMBER_H_
#define _CLIMBER_H_

#include "../Robot.h"



class Climber
{
public:
	Climber(Robot *robot);
	~Climber();
	
	
private:
	Robot *robot;
};



#endif // _CLIMBER_H_
