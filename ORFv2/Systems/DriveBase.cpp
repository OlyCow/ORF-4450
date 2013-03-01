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



void DriveBase::drive(float time, float power, float heading)
{
}



void DriveBase::rectangularSetDriveBase(float x, float y, float rotation, float heading)
{
}

void DriveBase::polarSetDriveBase(float angle, float magnitude, float rotation, float heading)
{
}



float DriveBase::getDriveXMagnitude()
{
}

float DriveBase::getDriveYMagnitude()
{
}

float DriveBase::getDriveAngle()
{
}

float DriveBase::getDrivePower()
{
}

float DriveBase::getDriveRotation()
{
}



void DriveBase::setFrontLMotor(float power)
{
}

void DriveBase::setFrontRMotor(float power)
{
}

void DriveBase::setRearLMotor(float power)
{
}

void DriveBase::setRearRMotor(float power)
{
}



float DriveBase::getFrontLMotor()
{
}

float DriveBase::getFrontRMotor()
{
}

float DriveBase::getRearLMotor()
{
}

float DriveBase::getRearRMotor()
{
}

