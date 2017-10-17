/**********************************************************************
* Filename    : PwmLed.c
* Description : Make a breathing led with soft PWM.
* Author      : Cavon
* E-mail      : service@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2017/10/17
**********************************************************************/

#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define LedPin    1

int main(void)
{
	int i;

	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1;
	}

	softPwmCreate(LedPin, 0, 100);

	while(1){
		for(i=0;i<=100;i++){
			softPwmWrite(LedPin, i);
			delay(20);
		}
		delay(1000);
		for(i=100;i>=0;i--){
			softPwmWrite(LedPin, i);
			delay(20);
		}
	}

	return 0;
}

