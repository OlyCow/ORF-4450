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
	Task			monitorBattery,
					monitorStatus;
	string			mode_name;

	Robot();
	void RobotInit();
	void Disabled();
	void Autonomous();
	void OperatorControl();
	void Test();


private:
	void ClearModeLEDs();
	void ModeStart(bool useSmartDashboard);
	void ModeEnd();
	// Runs as task.
	static void MonitorBattery(int dsPointer);
	static void MonitorStatus(int dsPointer);
};



#endif // _ROBOT_H_
