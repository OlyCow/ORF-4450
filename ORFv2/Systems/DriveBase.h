#ifndef _DRIVEBASE_H_
#define _DRIVEBASE_H_

#include "../Robot.h"



class DriveBase
{
public:
	DriveBase(Robot *ORFius);
	~DriveBase();
	
	
private:
	Robot *ORFius;
};



#endif // _DRIVEBASE_H_
