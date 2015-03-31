#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>

#define  Pin0  0

static volatile int globalCounter = 0 ;

void exInt0_ISR(void)  //GPIO0 interrupt service routine 
{
	++globalCounter;
}

int main (void)
{
  if(wiringPiSetup() < 0){
  	fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
	return 1;
  }

  wiringPiISR(Pin0, INT_EDGE_FALLING, &exInt0_ISR);

   while(1){
	printf("Current pluse number is : %d\n", globalCounter);
  }

  return 0;
}
