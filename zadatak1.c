#include <unistd.h>  
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <lcd.h>
#include <errno.h>

const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;    

const char PCF8591 = 0x48; // adresa
int fd, adcVal;

int main() 
{
	int lcd_h;
	float voltage = 0;
	
 	if (wiringPiSetup () == -1) exit (1);
 	fd = wiringPiI2CSetup(PCF8591);
	lcd_h = lcdInit(2,16,4,RS,EN,D0,D1,D2,D3,D0,D1,D2,D3);
 	while (1) 
	{
 		// procitaj trimer pot sa AIN3 ulaza
 		wiringPiI2CReadReg8(fd, PCF8591 + 3) ; // dummy
 		adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 3) ;
		
		voltage = adcVal * ( 3.3 / 255.0);

		lcdPosition(lcd_h,0,0);
		lcdPrintf(lcd_h,"%.1f", voltage );

 		delay(500);
 	}

 	return 0;
}
