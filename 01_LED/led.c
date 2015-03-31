#include <wiringPi.h>
#include <stdio.h>

#define  LedPin    0

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	printf("linker LedPin : GPIO %d(wiringPi pin)\n",LedPin); //when initialize wiring successfully,print message to screen
	
	pinMode(LedPin, OUTPUT);

	while(1){
			digitalWrite(LedPin, LOW);  //led on
			printf("led on...\n");
			delay(500);
			digitalWrite(LedPin, HIGH);  //led off
			printf("...led off\n");
			delay(500);
	}

	return 0;
}

