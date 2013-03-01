#ifndef _DRIVEBASE_H_
#define _DRIVEBASE_H_

#include "../Robot.h"



class DriveBase
{
public:
	DriveBase(Robot *robot);
	~DriveBase();
	
	void drive();

	void polarSetDriveBase(	float angle,
							float magnitude,
							float rotation,
							float heading	);
	void rectangularSetDriveBase(	float x,
									float y,
									float rotation,
									float heading	);

	void setFrontLMotor(float power);
	void setFrontRMotor(float power);
	void setRearLMotor(float power);
	void setRearRMotor(float power);

	float getFrontLMotor();
	float getFrontRMotor();
	float getRearLMotor();
	float getRearRMotor();

	
private:
	Robot *robot;
};



#endif // _DRIVEBASE_H_
