#ifndef _LAUNCHER_H_
#define _LAUNCHER_H_



class Launcher
{
private:
	Robot Robot;
	wiring *cRIO;
	// Add variables you might need here.
	
	
public:
	Launcher(Robot *Robot);
	~Launcher();
	
	void shoot(float power=1.00, int shots=1);
	void maxHeight();
	void minHeight();
	
	void setLaunchPower(float power);
	void setHeightMotor(float power);
	void setRampMotor(float power);
	
	void setFeederMotor(float power);
	
	// Whatever this will be called. Need to ask Ian about this.
	// These will be the "getters" for the switches.
	//bool getLimitSwitch();
};



#endif // _LAUNCHER_H_
