#ifndef _DRIVEBASE_H_
#define _DRIVEBASE_H_

#include "../Robot.h"



class DriveBase
{
public:
	DriveBase(Robot *robot);
	~DriveBase();
	
	void drive(	float time,
				float power,
				float angle,
				float rotation=0	);

	void rectangularSetDriveBase(	float x,
									float y,
									float rotation,
									float heading=0	);
	void polarSetDriveBase(	float angle, //in degrees!
							float power,
							float rotation,
							float heading=0	);

	void zeroMotors();
	
	float getDriveXMagnitude();
	float getDriveYMagnitude();
	float getDriveAngle();	//in degrees
	float getDrivePower();
	float getDriveRotation();

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
