#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

//make led_n on
void led_on(int n)
{
	digitalWrite(n, LOW);
}

//make led_n off
void led_off(int n)
{
	digitalWrite(n, HIGH);
}

int main(int argc, char *argv[])
{
	int PinNum, PinStatus;

	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	PinNum = atoi(argv[1]);    //Converts a string into integer
	PinStatus = atoi(argv[2]);
	pinMode(PinNum, OUTPUT);
	digitalWrite(PinNum, PinStatus);

	return 0;
}

