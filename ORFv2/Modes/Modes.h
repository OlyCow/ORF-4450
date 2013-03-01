#ifndef _MODES_H_
#define _MODES_H_



void RunMode(Modes mode=MODE_DISABLED, bool isLoop=true);

void InitModeInit();
void InitModeMain();
void DisabledModeInit();
void DisabledModeMain();
void AutonomousModeInit();
void AutonomousModeMain();
void TeleopModeInit();
void TeleopModeMain();
void TestModeInit();
void TestModeMain();



#endif // _MODES_H_
