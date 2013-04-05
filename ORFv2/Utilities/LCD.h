#ifndef _LCD_H_
#define _LCD_H_

#include "../Includes.h"



class LCD
{
public:
	LCD();
	~LCD();
	
	static void ConsoleLog(char *message, ...);
	static void ConsoleLog(string message, ...);
	static void PrintLine(int line, const char *message, ...);
	static void PrintLine(int line, string message, ...);
	static void ClearLine(int line);
	
	static void PrintEasterEgg();
	
	
private:
	static DriverStationLCD *dsLCD;

	static void InitLCD();

	static DriverStationLCD::Line SwitchLine(int line);
};



#endif // _LCD_H_
