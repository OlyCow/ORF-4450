#include "../Includes.h"



void Robot::OperatorControl()
{
	this->mode_name = g_teleopMode;
	ModeStart(true);
	cRIO->insight.pauseDisplay();
	this->cRIO->watchdog.SetEnabled(true);
	
	
	
	const float teleopLoopInterval = 0.025; //seconds
	
	float angle = 0;
	float power = 0;
	float rotation = 0;
	
	float launcherPower = 0;
	float heightPower = 0;
	float rampPower = 0;
	
	HeightMode heightMode = HEIGHT_JOYSTICK;
	
	while (this->IsOperatorControl())
	{
		using namespace math;
		
		// Zero-ing variables in case something goes wrong.
		// An extra layer of protection in addition
		// to the watchdog (which is only on during teleop).
		angle = 0;
		angle =
			prune(	cRIO->positionStick.GetDirectionDegrees(),
					float(g_joystickDeadZone)	);
		power = 0;
		power =
			prune(	cRIO->positionStick.GetMagnitude(),
					float(g_joystickDeadZone)	);
		rotation = 0;
		rotation =
			prune(	cRIO->rotateStick.GetX(),
					float(g_joystickDeadZone)	);
		
		if (	cRIO->positionStick.GetRawButton(BUTTON_CENTER)
				==true	)
			power /= 2;
		
		if (	cRIO->rotateStick.GetRawButton(BUTTON_CENTER)
				==true	)
			rotation /= 2;
		
		driveBase.polarSetDriveBase(angle, power, rotation);
		
		
		
		launcherPower = 0;
		if (	cRIO->launcherStick.GetRawButton(BUTTON_LEFT_FRONT)
				==true )
			launcherPower = g_maxPower;
		if (	cRIO->launcherStick.GetRawButton(BUTTON_LEFT_REAR)
				==true )
			launcherPower = 0;
		cRIO->launchMotor.Set(launcherPower);
		
		if (	cRIO->launcherStick.GetRawButton(BUTTON_TRIGGER)
				==true	)
			launcher.shoot(launcherPower);
		
		heightPower = 0;
		heightPower =
			prune(	cRIO->launcherStick.GetY(),
					g_joystickDeadZone	);
		if (heightPower!=0)
			heightMode = HEIGHT_JOYSTICK;
		if (	cRIO->launcherStick.GetRawButton(BUTTON_RIGHT_FRONT)
				==true	)
			heightMode = HEIGHT_MAX;
		if (	cRIO->launcherStick.GetRawButton(BUTTON_RIGHT_REAR)
				==true	)
			heightMode = HEIGHT_MIN;
		switch(heightMode)
		{
		case HEIGHT_MAX:
			heightPower = g_maxPower;
			break;
		case HEIGHT_MIN:
			heightPower = -g_maxPower;
			break;
		}
		if (	cRIO->launcherStick.GetRawButton(BUTTON_CENTER)
				==true	)
			heightPower /= g_fineTuneFactor;
		cRIO->heightMotor.Set(heightPower);
		
		rampPower = 0;
		if (	cRIO->launcherStick.GetRawButton(BUTTON_REAR_LEFT)
				==true	)
			rampPower = g_rampPower;
		if (	cRIO->launcherStick.GetRawButton(BUTTON_REAR_RIGHT)
				==true	)
			rampPower = -g_rampPower;
		cRIO->rampMotor.Set(rampPower);
		
		
		
		// LCD & SmartDashboard stuff. YAY?!
		bool hasFMS = ds->IsFMSAttached();
		SmartDashboard::PutBoolean("FMS Connected", hasFMS);
		launcher.reportLaunchPower();
		driveBase.reportTotalPower();
		driveBase.reportTotalRotation();
		
		string LCD_netOutput = "Total Output: ";
		float frontL = driveBase.getFrontLMotor();
		float frontR = driveBase.getFrontRMotor();
		float rearL = driveBase.getRearLMotor();
		float rearR = driveBase.getRearRMotor();
		float totalPower =	abs(frontL)	+abs(frontR)+
							abs(rearL)	+abs(rearR)+
							abs(launcherPower)+
							abs(heightPower)+
							abs(rampPower);
		LCD_netOutput.append(stringify(totalPower));
		LCD_netOutput.append(" !!!");
		LCD::PrintLine(LINE_NET_OUTPUT, LCD_netOutput);
		
		string LCD_frontMotors = "FrontL motor: ";
		LCD_frontMotors.append(stringify(frontL));
		LCD_frontMotors.append(" | FrontR motor:");
		LCD_frontMotors.append(stringify(frontR));
		LCD::PrintLine(LINE_MOTORS_F, LCD_frontMotors);
		
		string LCD_rearMotors = "RearL motor: ";
		LCD_rearMotors.append(stringify(rearL));
		LCD_rearMotors.append(" | RearR motor:");
		LCD_rearMotors.append(stringify(rearR));
		LCD::PrintLine(LINE_MOTORS_R, LCD_rearMotors);
		
		LCD::ConsoleLogVariable(angle, "angle");
		LCD::ConsoleLogVariable(power, "power");
		LCD::ConsoleLogVariable(rotation, "rotation");
		LCD::ConsoleLogVariable(launcherPower, "launcherPower");
		LCD::ConsoleLogVariable(heightPower, "heightPower");
		LCD::ConsoleLogVariable(rampPower, "rampPower");
		
		if( rand()%THE_ANSWER == 0 )
			LCD::ConsoleLogEasterEgg();
		
		
		
		Wait(teleopLoopInterval);
	}
	
	
	
	this->cRIO->watchdog.SetEnabled(false);
	ModeEnd();
}
