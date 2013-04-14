#ifndef _MOTOR_H_
#define _MOTOR_H_



class Motor : public Talon
{
public:
	Motor(UINT32 channel, bool isInverted=false);
	~Motor();
	
	void Flip();
	
	void Invert();
	void Restore();
	
	void Set(float value, UINT8 syncGroup=0);
	
	float Get();
	
	bool checkIfInverted();
	
	
private:
	bool isInverted;
};



#endif // _MOTOR_H_
