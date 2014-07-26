#include <msp430.h> 

/*
 * main.c
 */
#include"LIB/gpio.h"
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	while (1)
	{
		DigitalWrite(1,BIT6,H);
	}
	return 0;
}
