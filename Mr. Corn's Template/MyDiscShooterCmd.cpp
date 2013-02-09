#include "MyDiscShooterCmd.h"
#include "LCD.h"

MyDiscShooterCmd::MyDiscShooterCmd(MyRobot *MyRobot)
{
	LCD::ConsoleLog("MyDiscShooterCmd.constructor");
	
	//super("MyDiscShooterCmd");
	
	myRobot = MyRobot;
}
	
MyDiscShooterCmd::~MyDiscShooterCmd()
{
}
	
void MyDiscShooterCmd::Initialize(void)
{
	LCD::ConsoleLog("MyDiscShooterCmd.Initialize");
	
	exCount = 0;
	
	LCD::ConsoleLog("MyDiscShooterCmd.Initialize-end");
}

void MyDiscShooterCmd::End(void)
{
	LCD::ConsoleLog("MyDiscShooterCmd.End");
	
	LCD::ConsoleLog("MyDiscShooterCmd.End-end");
}

void MyDiscShooterCmd::Interrupted(void)
{
	LCD::ConsoleLog("MyDiscShooterCmd.Interrupted");
	
	LCD::ConsoleLog("MyDiscShooterCmd.Interrupted-end");
}

bool MyDiscShooterCmd::IsFinished(void)
{
	bool	done = false;
	
	LCD::ConsoleLog("MyDiscShooterCmd.IsFinished");
	
	if (exCount > 5) done = true;
	
	LCD::ConsoleLog("MyDiscShooterCmd.IsFinished-end");
	
	return done;
}

void MyDiscShooterCmd::Execute(void)
{
	LCD::ConsoleLog("MyDiscShooterCmd.execute");
	
	exCount += 1;
	
	LCD::ConsoleLog("MyDiscShooterCmd.execute-end");
}
