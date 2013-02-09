#ifndef __MyRobot_h__
#define __MyRobot_h__

#include <WPILib.h>
#include <string.h> // for sprintf()
//#include "LCD.h"
//#include "MyAutonomous.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 

#define CAMERA_IP "10.44.50.11"

class MyRobot : public SimpleRobot
{
public:
	RobotDrive 	robotDrive; // robot drive system
	Joystick 	stick, stick2; // joysticks
	Encoder 	driveleftencoder;
	//AxisCamera 	&camera;
	DriverStation *ds;
		
	char 	buffer[80];	// for displaying the current encoder value
	int 	encoder_value;	// the current cumulative encoder value
	DriverStation::Alliance alliance;
	int 	startLocation;
	
	MyRobot(void);
	
	void RobotInit(void);
	
	void Disabled(void);

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void);

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void);
};

#endif // __MyRobot_h__
