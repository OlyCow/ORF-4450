#ifndef __LCD_h__
#define __LCD_h__

#include <WPILib.h>

class LCD
{
private:
	static DriverStationLCD *dsLcd;

	static void InitLcd();
	
public:
	LCD(void);
	
	virtual ~LCD();
	
	static void ConsoleLog(char *message, ...);
	
	static void Print(INT32 line, INT32 column, const char *message, ...);
	
	static void PrintLine(INT32 line, const char *message, ...);
	
	static void ClearLine(INT32 line);
};

#endif // __LCD_h__
