#include "../Includes.h"
#include "LCD.h"



DriverStationLCD* LCD::dsLCD = 0;

LCD::LCD()
{
	InitLCD();
	for (int i=0; i<6; i++)
		ClearLine(i);
}
LCD::~LCD()
{
	for (int i=0; i<6; i++)
		ClearLine(i);
}

template <typename Type>
void LCD::ConsoleLogVariable(Type variable, string name)
{
	string output = "(";
	// Not using decltype() because it doesn't return char.
	output.append(typeid(variable).name());
	output.append(") ");
	
	output.append(name);
	output.append(" = ");
	
	output.append(math::stringify(variable));
	
	LCD::ConsoleLog(output);
}

void LCD::ConsoleLog(char *message, ...)
{
	char messageBuf[128];
		
	va_list vl;
	va_start(vl, message);
	
	vsprintf(messageBuf, message, vl);	
	printf("Robot: %s\n", messageBuf);
}
void LCD::ConsoleLog(string message, ...)
{
	// This stuff is just to pass into the next function.
	// Kicking the proverbial ball down the road.
	va_list vl;
	va_start(vl, message);
	
	LCD::ConsoleLog((char *)message.c_str(), vl);
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
void LCD::PrintLine(int line, string message, ...)
{
	// This stuff is just to pass into the next function.
	// Kicking the proverbial ball down the road.
	va_list vl;
	va_start(vl, message);
	
	LCD::PrintLine(line, message.c_str(), vl);
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

void LCD::ConsoleLogEasterEgg()
{
	LCD::ConsoleLog(math::getEasterEgg());
}
void LCD::PrintEasterEgg()
{
	LCD::PrintLine(LINE_EASTER_EGG, math::getEasterEgg());
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
	DriverStationLCD::Line output =
			DriverStationLCD::kMain_Line6;
	
	switch (line)
	{
	case 1:
		output = DriverStationLCD::kUser_Line1;
		break;
	case 2:
		output = DriverStationLCD::kUser_Line2;
		break;
	case 3:
		output = DriverStationLCD::kUser_Line3;
		break;
	case 4:
		output = DriverStationLCD::kUser_Line4;
		break;
	case 5:
		output = DriverStationLCD::kUser_Line5;
		break;
	case 6:
		output = DriverStationLCD::kUser_Line6;
		break;
	}
	
	return output;
}
