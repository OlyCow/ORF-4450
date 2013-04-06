#include "../Includes.h"
#include "DriveBase.h"

using namespace math;



DriveBase::DriveBase(Robot *robot):
	robot(robot)
{
	zeroMotors();
}
DriveBase::~DriveBase()
{
	zeroMotors();
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
	rotateVector(x, y, heading);
	
	float powerFL = 0;
	float powerFR = 0;
	float powerRL = 0;
	float powerRR = 0;
	
	// Forward and backward
	powerFL = limitMax(powerFL+y, g_maxPower);
	powerFR = limitMax(powerFR+y, g_maxPower);
	powerRL = limitMax(powerRL+y, g_maxPower);
	powerRR = limitMax(powerRR+y, g_maxPower);
	
	// Left and right
	powerFL = limitMin(powerFL-x, -g_maxPower);
	powerFR = limitMax(powerFR+x, g_maxPower);
	powerRL = limitMax(powerRL+x, g_maxPower);
	powerRR = limitMin(powerRR-x, -g_maxPower);
	
	// Clockwise and counter-clockwise
	powerFL = limitMin(powerFL-rotation, -g_maxPower);
	powerFR = limitMax(powerFR+rotation, g_maxPower);
	powerRL = limitMin(powerRL-rotation, -g_maxPower);
	powerRR = limitMax(powerRR+rotation, g_maxPower);
	
	setFrontLMotor(powerFL);
	setFrontRMotor(powerFR);
	setRearLMotor(powerRL);
	setRearRMotor(powerRR);
}
void DriveBase::polarSetDriveBase(	float angle, //in degrees!
									float power,
									float rotation,
									float heading	)
{
	float x = 0;
	float y = 0;
	
	x = power*cos(degToRad(angle));
	y = power*sin(degToRad(angle));
	
	rectangularSetDriveBase(x, y, rotation, heading);
}

void DriveBase::zeroMotors()
{
	setFrontLMotor(0.0);
	setFrontRMotor(0.0);
	setRearLMotor(0.0);
	setRearRMotor(0.0);
}

float DriveBase::getDriveXMagnitude()
{
	float xMagnitude = 0.0;
	xMagnitude =	getFrontLMotor() +
					getFrontRMotor() +
					getRearLMotor() +
					getRearRMotor();
	xMagnitude /= 4; //there are 4 motors
	return xMagnitude;
}
float DriveBase::getDriveYMagnitude()
{
	float yMagnitude = 0.0;
	yMagnitude =	-getFrontLMotor() +
					getFrontRMotor() +
					getRearLMotor() -
					getRearRMotor();
	yMagnitude /= 4; //there are 4 motors
	return yMagnitude;
}
float DriveBase::getDriveAngle() //in degrees
{
	float angle = 0.0;
	float x = getDriveXMagnitude();
	float y = getDriveYMagnitude();
	angle = radToDeg(atan2(x,y));
	return angle;
}
float DriveBase::getDrivePower()
{
	float power = 0.0;
	float x = getDriveXMagnitude();
	float y = getDriveYMagnitude();
	power = sqrt( x*x + y*y );
	return power;
}
float DriveBase::getDriveRotation()
{
	float rotation = 0.0;
	rotation =	-getFrontLMotor() +
				getFrontRMotor() +
				getRearLMotor() -
				getRearRMotor();
	rotation /= 4; //there are 4 motors
	return rotation;
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

