#ifndef _MODES_H_
#define _MODES_H_



// (mode=MODE_DISABLED, isLoop=true)
void RunMode(Modes mode, bool isLoop);

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
