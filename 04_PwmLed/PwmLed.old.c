/**********************************************************************
* Filename    : pwmLed.c
* Description : Make a breathing led.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/

#include <wiringPi.h>
#include <stdio.h>

#define LedPin    1

int main(void)
{
	int i;

	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(LedPin, PWM_OUTPUT);//pwm output mode

	while(1){
		for(i=0;i<1024;i++){
			pwmWrite(LedPin, i);
			delay(2);
		}
		delay(1000);
		for(i=1023;i>=0;i--){
			pwmWrite(LedPin, i);
			delay(2);
		}
	}

	return 0;
}

