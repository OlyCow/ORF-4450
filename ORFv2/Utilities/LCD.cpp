#include "../Includes.h"
#include "LCD.h"



DriverStationLCD* LCD::dsLcd = 0;

LCD::LCD(void)
{
}
	
LCD::~LCD()
{
}
	
void LCD::InitLcd()
{
	ConsoleLog("LCD.InitLcd");
	dsLcd = DriverStationLCD::GetInstance();
	ConsoleLog("LCD.InitLcd %d", dsLcd);
	dsLcd->Clear();
}
	
void LCD::ConsoleLog(char *message, ...)
{
	char messageBuf[128];
		
	va_list vl;
	va_start(vl, message);
	
	vsprintf(messageBuf, message, vl);
		
	printf("robot: %s\n", messageBuf);
}
	
void LCD::Print(INT32 line, INT32 column, const char *message, ...)
{
	DriverStationLCD::Line lcdLine;
		
	if (dsLcd == 0) InitLcd();
		
	switch (line)
	{
		case 1:
			lcdLine = DriverStationLCD::kUser_Line1;
			break;

		case 2:
			lcdLine = DriverStationLCD::kUser_Line2;
			break;

		case 3:
			lcdLine = DriverStationLCD::kUser_Line3;
			break;

		case 4:
			lcdLine = DriverStationLCD::kUser_Line4;
			break;

		case 5:
			lcdLine = DriverStationLCD::kUser_Line5;
			break;

		case 6:
			lcdLine = DriverStationLCD::kUser_Line6;
			break;
	}
	
	va_list vl;
	va_start(vl, message);
	
	dsLcd->VPrintf(lcdLine, column, message, vl);
		
	dsLcd->UpdateLCD();
}
	
void LCD::PrintLine(INT32 line, const char *message, ...)
{
	DriverStationLCD::Line lcdLine;
	
	//consoleLog("printLine %d, %d", line, dsLcd);
	
	if (dsLcd == 0) InitLcd();
	
	ClearLine(line);

	switch (line)
	{
		case 1:
			lcdLine = DriverStationLCD::kUser_Line1;
			break;

		case 2:
			lcdLine = DriverStationLCD::kUser_Line2;
			break;

		case 3:
			lcdLine = DriverStationLCD::kUser_Line3;
			break;

		case 4:
			lcdLine = DriverStationLCD::kUser_Line4;
			break;

		case 5:
			lcdLine = DriverStationLCD::kUser_Line5;
			break;

		case 6:
			lcdLine = DriverStationLCD::kUser_Line6;
			break;
	}
		
	va_list vl;
	va_start(vl, message);
	
	//consoleLog("printLine %d, %d: %s", line, dsLcd, message);

	dsLcd->VPrintfLine(lcdLine, message, vl);
		
	dsLcd->UpdateLCD();
}

void LCD::ClearLine(INT32 line)
{
	const char *blankLine = "                                          ";
	DriverStationLCD::Line lcdLine;
	
	//consoleLog("clearLine %d, %d", line, dsLcd);
		
	if (dsLcd == 0) InitLcd();

	switch (line)
	{
	case 1:
		lcdLine = DriverStationLCD::kUser_Line1;
		break;

	case 2:
		lcdLine = DriverStationLCD::kUser_Line2;
		break;

	case 3:
		lcdLine = DriverStationLCD::kUser_Line3;
		break;

	case 4:
		lcdLine = DriverStationLCD::kUser_Line4;
		break;

	case 5:
		lcdLine = DriverStationLCD::kUser_Line5;
		break;

	case 6:
		lcdLine = DriverStationLCD::kUser_Line6;
		break;
	}
		
	dsLcd->PrintfLine(lcdLine, blankLine);		
		
	dsLcd->UpdateLCD();
}
