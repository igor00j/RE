#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

#define SLABO 1
#define DNEVNO 2
#define NOCNO 3

const char PCF8591 = 0x48; // adresa
int fd, adcVal;

char LED[] = {25,26,27,28};
char i;

int main() 
{
	double voltage;
 	if (wiringPiSetup () == -1) exit (1);
 	fd = wiringPiI2CSetup(PCF8591);
	
	pinMode(25,OUTPUT);
	pinMode(26,OUTPUT);
	pinMode(27,OUTPUT);

 	while (1) 
	{
 		// procitaj trimer pot sa AIN3 ulaza
 		wiringPiI2CReadReg8(fd, PCF8591+4) ; // dummy
 		adcVal = wiringPiI2CReadReg8(fd, PCF8591+4) ;
		printf("Pot ADC vrednost = %d \n", adcVal);
		
		voltage = adcVal * ( 3.3 / 255.0);
		printf("Voltage = %.1f \n", voltage);
		
		if(adcVal < 85)
		{
			printf("ovde sam1");
			digitalWrite(25,1);
			digitalWrite(26,1);
			digitalWrite(27,1);
		}
		else if(adcVal < 170)
		{
			printf("ovde sam2");
			digitalWrite(25,1);
			digitalWrite(26,1);
			digitalWrite(27,0);
		}
		else
		{
			digitalWrite(25,1);
			digitalWrite(26,0);
			digitalWrite(27,0);
		}


 		delay(100);
 	}

 	return 0;
}
