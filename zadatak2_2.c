#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

const char PCF8591 = 0x48; // adresa
int fd, adcVal;
int i;

int main() 
{
	
 	if (wiringPiSetup () == -1) exit (1);
 	fd = wiringPiI2CSetup(PCF8591);

 	while (1) 
	{
 		

		for( i = 0 ; i <= 255 ; i ++ ) 
		{
			wiringPiI2CWriteReg8(fd,PCF8591,i);
			delay(10);	
			if(i == 255)
			{
				for( i ; i > 0 ; i-- )
				{

					wiringPiI2CWriteReg8(fd,PCF8591,i);
					delay(10);
				}
			}
		}
 	}

 	return 0;
}
