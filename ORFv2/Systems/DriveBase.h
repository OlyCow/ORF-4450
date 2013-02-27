#ifndef _DRIVEBASE_H_
#define _DRIVEBASE_H_

#include "../Robot.h"



class DriveBase
{
public:
	DriveBase(Robot *robot);
	~DriveBase();
	
	
private:
	Robot *robot;
};



#endif // _DRIVEBASE_H_
