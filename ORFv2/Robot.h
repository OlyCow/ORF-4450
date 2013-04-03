#ifndef _ROBOT_H_
#define _ROBOT_H_



class Robot : public SimpleRobot
{
public:
	DriverStation	*ds;
		int							startLocation;
		DriverStation::Alliance		alliance;
	AxisCamera		&camera;
	wiring			*cRIO;
	Task			monitorBatteryTask;
	string			mode_name;

	Robot();
	void RobotInit();
	void Disabled();
	void Autonomous();
	void OperatorControl();
	void Test();


private:
	void ModeStart();
	void ModeEnd();
	// Runs as task.
	static void MonitorBattery(int dsPointer);
};



#endif // _ROBOT_H_
