#ifndef _INCLUDES_H_
#define _INCLUDES_H_



#include <WPIlib.h>

#include <iostream>
#include <cstdlib>
#include <exception>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <vector>

#include "InsightLT/InsightLT.h"
using namespace insight;

#include "Utilities/Motor.h"
#include "Utilities/enums.h"
#include "Utilities/global_vars.h"
#include "Utilities/wiring.h"
#include "Utilities/LCD.h"
#include "Utilities/externs.h"

#include "Systems/DriveBase.h"
#include "Systems/Launcher.h"

#include "Robot.h"



// Macro #defines are evil. I'll get rid of these...
// sometime. Though they are handy, I'll admit.
#define CAMERA_IP		"10.44.50.11"
#define LOW_BATTERY		10.0
#define	JSB_TOP_MIDDLE		3
#define JSB_TOP_LEFT		4
#define JSB_TOP_RIGHT		5
#define JSB_TRIGGER			1
#define JSB_TOP_BACK		2
#define JSB_LEFT_FRONT		6
#define JSB_LEFT_REAR		7
#define JSB_RIGHT_FRONT		11
#define JSB_RIGHT_REAR		10
#define JSB_BACK_LEFT		8
#define JSB_BACK_RIGHT		9



#endif // _INCLUDES_H_
