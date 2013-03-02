#include "../Includes.h"
#include "DriveBase.h"



DriveBase::DriveBase(Robot *robot):
	robot(robot)
{
	setFrontLMotor(0.0);
	setFrontRMotor(0.0);
	setRearLMotor(0.0);
	setRearRMotor(0.0);
}

DriveBase::~DriveBase()
{
	setFrontLMotor(0.0);
	setFrontRMotor(0.0);
	setRearLMotor(0.0);
	setRearRMotor(0.0);
}



void DriveBase::drive(	float time,		float power,
						float angle,	float rotation	)
{
	float originalPowerFL = getFrontLMotor();
	float originalPowerFR = getFrontRMotor();
	float originalPowerRL = getRearLMotor();
	float originalPowerRR = getRearRMotor();

	polarSetDriveBase(angle, power, rotation, 0);
	Wait(time);

	setFrontLMotor(originalPowerFL);
	setFrontRMotor(originalPowerFR);
	setRearLMotor(originalPowerRL);
	setRearRMotor(originalPowerRR);
}



void DriveBase::rectangularSetDriveBase(	float x,
											float y,
											float rotation,
											float heading	)
{
}
void DriveBase::polarSetDriveBase(	float angle,
									float magnitude,
									float rotation,
									float heading	)
{
}



float DriveBase::getDriveXMagnitude()
{
	return 0;
}

float DriveBase::getDriveYMagnitude()
{
	return 0;
}

float DriveBase::getDriveAngle()
{
	return 0;
}

float DriveBase::getDrivePower()
{
	return 0;
}

float DriveBase::getDriveRotation()
{
	return 0;
}




void DriveBase::setFrontLMotor(float power)
{
	robot->cRIO->driveFrontLMotor.SetSpeed(power);
}
void DriveBase::setFrontRMotor(float power)
{
	robot->cRIO->driveFrontRMotor.SetSpeed(power);
}
void DriveBase::setRearLMotor(float power)
{
	robot->cRIO->driveRearLMotor.SetSpeed(power);
}
void DriveBase::setRearRMotor(float power)
{
	robot->cRIO->driveRearRMotor.SetSpeed(power);
}



float DriveBase::getFrontLMotor()
{
	return robot->cRIO->driveFrontLMotor.Get();
}
float DriveBase::getFrontRMotor()
{
	return robot->cRIO->driveFrontRMotor.Get();
}
float DriveBase::getRearLMotor()
{
	return robot->cRIO->driveRearLMotor.Get();
}
float DriveBase::getRearRMotor()
{
	return robot->cRIO->driveRearRMotor.Get();
}

