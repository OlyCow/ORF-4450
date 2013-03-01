#include "../Includes.h"
#include "Modes.h"



void RunMode(Modes mode, bool isLoop)
{
	switch (mode)
	{
	case MODE_INIT:
		InitModeInit();
		do InitModeMain();
		while (isLoop);
		break;

	case MODE_DISABLED:
		DisabledModeInit();
		do DisabledModeMain();
		while (isLoop);
		break;

	case MODE_AUTONOMOUS:
		AutonomousModeInit();
		do AutonomousModeMain();
		while (isLoop);
		break;

	case MODE_TELEOP:
		TeleopModeInit();
		do TeleopModeMain();
		while (isLoop);
		break;

	case MODE_TEST:
		TestModeInit();
		do TestModeMain();
		while (isLoop);
		break;
	}
}
