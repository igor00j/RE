#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

const char PCF8591 = 0x48; // adresa
int fd, adcVal;

int main() 
{
	
 	if (wiringPiSetup () == -1) exit (1);
 	fd = wiringPiI2CSetup(PCF8591);

 	while (1) 
	{
 		/*// procitaj trimer pot sa AIN3 ulaza

 		adcVal = wiringPiI2CReadReg8(fd, PCF8591) ;
		*/

		for(int i = 0 ; i < 255 ; i ++ ) 
		{
			wiringPiI2CWriteReg8(fd,PCF8591,i);
			delay(10);
		}
		

 	}

 	return 0;
}
