/**********************************************************************
* Filename    : timer555.c
* Description : Count the pluses procude by NE555.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
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
