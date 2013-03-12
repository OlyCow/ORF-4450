#include "../Includes.h"



void Robot::OperatorControl()
{
	DriveBase driveBase(this);
	Launcher launcher(this);
	cRIO->insight.pauseDisplay();
	alliance = ds->GetAlliance();
	startLocation = ds->GetLocation();
	
	// This is (more than?) a test.
	float angle = 0;
	float power = 0;
	float rotation = 0;
	
	float launcherPower = 0;
	float heightPower = 0;
	float rampPower = 0;
	
	while (this->IsOperatorControl())
	{
		using namespace math;
		
		// Zero-ing in case something goes wrong.
		// Might use the watchdog instead.
		angle = 0;
		power = 0;
		rotation = 0;
		
		angle =
			prune(	cRIO->positionStick.GetDirectionDegrees(),
					float(g_joystickDeadZone)	);
		power =
			prune(	cRIO->positionStick.GetMagnitude(),
					float(g_joystickDeadZone)	);
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
		
		launcherPower =
			prune(	cRIO->launcherPowerStick.GetY(),
					float(g_joystickDeadZone)	);
		
		if (	cRIO->launcherPowerStick.GetRawButton(BUTTON_CENTER)
				==true	)
			launcherPower /= 2;
		
		cRIO->launchMotor.Set(launcherPower);
		
		if (	cRIO->launcherPowerStick.GetRawButton(BUTTON_TRIGGER)
				==true	)
			launcher.shoot(launcherPower);
		
		
		
		heightPower = 0;
		
		heightPower =
			prune(	cRIO->launcherHeightStick.GetY(),
					g_joystickDeadZone	);
		
		if (	cRIO->launcherHeightStick.GetRawButton(BUTTON_CENTER)
				==true	)
			heightPower /= 2;
		
		cRIO->heightMotor.Set(heightPower);
		
		if (	cRIO->launcherHeightStick.GetRawButton(BUTTON_LEFT)
				==true	)
			launcher.minHeight(g_halfPower);
		
		if (	cRIO->launcherHeightStick.GetRawButton(BUTTON_RIGHT)
				==true	)
			launcher.maxHeight(g_halfPower);
		
		
		
		rampPower = 0;
		
		rampPower =
			prune(	cRIO->launcherHeightStick.GetX(),
					g_rampJoystickThreshold	);
		
		if ((	cRIO->launcherHeightStick.GetRawButton(BUTTON_CENTER)
				==true	)&&( heightPower==0 )	)
			rampPower /= 2;
		
		cRIO->rampMotor.Set(rampPower);
		
		
		
		Wait(g_teleopLoopInterval);
	}
}
