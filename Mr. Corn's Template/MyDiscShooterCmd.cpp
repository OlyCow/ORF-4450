#include "MyDiscShooterCmd.h"
#include "LCD.h"

MyDiscShooterCmd::MyDiscShooterCmd(MyRobot *MyRobot)
{
	LCD::ConsoleLog("MyDiscShooterCmd.constructor");
	
	myRobot = MyRobot;
}
	
MyDiscShooterCmd::~MyDiscShooterCmd()
{
	LCD::ConsoleLog("MyDiscShooterCmd.destructor");
}

// Called when first scheduled to execute.

void MyDiscShooterCmd::Initialize(void)
{
	LCD::ConsoleLog("MyDiscShooterCmd.Initialize");
	
	exCount = 0;
	
	SmartDashboard::PutBoolean("Shoot Disc", true);	

	LCD::ConsoleLog("MyDiscShooterCmd.Initialize-end");
}

// Called when scheduler wants to end execution of this command.

void MyDiscShooterCmd::End(void)
{
	LCD::ConsoleLog("MyDiscShooterCmd.End");

	SmartDashboard::PutBoolean("Shoot Disc", false);	

	LCD::ConsoleLog("MyDiscShooterCmd.End-end");
}

// Called when execution is interrupted.

void MyDiscShooterCmd::Interrupted(void)
{
	LCD::ConsoleLog("MyDiscShooterCmd.Interrupted");

	End();
	
	LCD::ConsoleLog("MyDiscShooterCmd.Interrupted-end");
}

// Decides when the command is completed. Scheduler checks this
// to determine if it should keep calling Execute.

bool MyDiscShooterCmd::IsFinished(void)
{
	bool	done = false;
	
	LCD::ConsoleLog("MyDiscShooterCmd.IsFinished");
	
	if (exCount > 5) 
	{
		done = true;

		SmartDashboard::PutBoolean("Shoot Disc", false);	
	}
	
	LCD::ConsoleLog("MyDiscShooterCmd.IsFinished-end");
	
	return done;
}

// This is where the work is done. Execute called each time
// the scheduler is run.

void MyDiscShooterCmd::Execute(void)
{
	LCD::ConsoleLog("MyDiscShooterCmd.execute");
	
	exCount += 1;
	
	LCD::ConsoleLog("MyDiscShooterCmd.execute-end");
}
