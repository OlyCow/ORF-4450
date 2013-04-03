#include "../Includes.h"
#include "LCD.h"



DriverStationLCD* LCD::dsLCD = 0;

LCD::LCD()
{
}
LCD::~LCD()
{
}

void LCD::ConsoleLog(char *message, ...)
{
	char messageBuf[128];
		
	va_list vl;
	va_start(vl, message);
	
	vsprintf(messageBuf, message, vl);	
	printf("Robot: %s\n", messageBuf);
}
void LCD::PrintLine(int line, const char *message, ...)
{
	DriverStationLCD::Line lcdLine = SwitchLine(line);
	
	if (dsLCD == 0) InitLCD();
	
	ClearLine(line);
	
	// All this ellipsis stuff is never used.
	// I just can't get rid of it w/out breaking something.
	va_list vl;
	va_start(vl, message);

	dsLCD->VPrintfLine(lcdLine, message, vl);
	dsLCD->UpdateLCD();
}
void LCD::ClearLine(int line)
{
	// 42 spaces.
	const char *blankLine =
			"                                          ";
	DriverStationLCD::Line lcdLine = SwitchLine(line);
	
	if (dsLCD == 0) InitLCD();
		
	dsLCD->PrintfLine(lcdLine, blankLine);		
	dsLCD->UpdateLCD();
}

void LCD::InitLCD()
{
	ConsoleLog("LCD.InitLcd");
	dsLCD = DriverStationLCD::GetInstance();
	ConsoleLog("LCD.InitLcd %d", dsLCD);
	dsLCD->Clear();
}

DriverStationLCD::Line SwitchLine(int line)
{
	switch (line)
	{
	case 1:
		return DriverStationLCD::kUser_Line1;
		break;
	case 2:
		return DriverStationLCD::kUser_Line2;
		break;
	case 3:
		return DriverStationLCD::kUser_Line3;
		break;
	case 4:
		return DriverStationLCD::kUser_Line4;
		break;
	case 5:
		return DriverStationLCD::kUser_Line5;
		break;
	case 6:
		return DriverStationLCD::kUser_Line6;
		break;
	}
}
