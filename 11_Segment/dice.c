#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define   SDI   0   //serial data input
#define   RCLK  1   //memory clock input(STCP)
#define   SRCLK 2   //shift register clock input(SHCP)

#define   TouchPin  3

unsigned char SegCode[6] = {0x06,0x5b,0x4f,0x66,0x6d,0x7d};

unsigned char flag = 0;

void init(void)
{
	pinMode(SDI, OUTPUT); //make P0 output
	pinMode(RCLK, OUTPUT); //make P1 output
	pinMode(SRCLK, OUTPUT); //make P2 output

	digitalWrite(SDI, 0);
	digitalWrite(RCLK, 0);
	digitalWrite(SRCLK, 0);
}

void hc595_shift(unsigned char dat)
{
	int i;

	for(i=0;i<8;i++){
		digitalWrite(SDI, 0x80 & (dat << i));
		digitalWrite(SRCLK, 1);
		delay(1);
		digitalWrite(SRCLK, 0);
	}

		digitalWrite(RCLK, 1);
		delay(1);
		digitalWrite(RCLK, 0);
}

void randomISR(void)
{
	flag = 1;
}

int main(void)
{
	int i, num;

	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	init();
	
	if(wiringPiISR(TouchPin, INT_EDGE_FALLING, &randomISR)){
		fprintf(stderr, "Unable to setup ISR : %s\n", strerror(errno));	
		return 1;
	}

	srand(time(NULL));
	
	while(1){
		if(flag == 1){
			num = rand() % 7;
			hc595_shift(SegCode[num]);
			delay(2000);
			flag = 0;
		}

		for(i=0;i<6;i++){	
			num = rand() % 7;
			hc595_shift(SegCode[num]);
			delay(60);
		}
	}

	return 0;
}

