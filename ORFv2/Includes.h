#ifndef _INCLUDES_H_
#define _INCLUDES_H_



#include <WPIlib.h>

#include <iostream>
#include <exception>
#include <string>

#include "InsightLT/InsightLT.h"

#include "Utilities/enums.h"
#include "Utilities/global_vars.h"
#include "Utilities/LCD.h"
#include "Utilities/wiring.h"

#include "Systems/DriveBase.h"
#include "Systems/Launcher.h"
#include "Systems/Climber.h"

#include "Modes/Autonomous.h"
#include "Modes/Teleop.h"



// Macro #defines are evil. I'll get rid of these...
// sometime. Though they are handy, I'll admit.
#define PROGRAM_NAME	"ORFv2"
#define CAMERA_IP		"10.44.50.11"
#define LOW_BATTERY		10.0



#endif // _INCLUDES_H_
