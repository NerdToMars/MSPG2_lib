#include "gpio.h"

/***********************************************************************//***
 * function: set pin mode as input output
 * param: port : the port of the P1,P2,P3.....;
 * 		  pin  : the pin of the port like BIT1,BIT2.....;
 * 		  mode : 0->output;   1->input;
 * return: null
 * write by elliot huang June 22
 */

void pinMode(unsigned char port,unsigned int pin,unsigned char mode)
{
	switch(port)
	{
	case 1:
		if(mode==OUTPUT){P1SEL &= ~ pin;P1DIR |= pin;}
		else{P1SEL &= ~pin;P1DIR &= ~pin;} ;
		break;
	case 2:
		if(mode==OUTPUT){P2SEL &= ~ pin;P1DIR |= pin;}
		else{P2SEL &= ~ pin;P1DIR &= ~pin;};
		break;
#ifdef __MSP430G2553
	case 3:
		if(mode==OUTPUT){P3SEL &= ~ pin;P3DIR |= pin;}
		else{P3SEL &= ~ pin;P3DIR &= ~pin;}
		break;
#endif
	}
}

/*****************************************************************************//*
 * function : set the pin output high or low
 * parm :mode H or L;
 * return :null
 * write by H.Elliot June 22
 */
void DigitalWrite(unsigned char port,unsigned int pin,unsigned char mode)
{
	switch(port)
		{
		case 1: P1SEL &= ~ pin;P1DIR |= pin;
				if(mode==H){P1OUT |= pin; }
				else{P1OUT &= ~pin;} ;
				break;
		case 2: P2SEL &= ~pin;P1DIR |= pin;
				if(mode==H){P2OUT |= pin;}
				else{P2OUT &= ~pin;};
				break;
#ifdef __MSP430G2553
		case 3:
			if(mode==OUTPUT){P3SEL &= ~ pin;P3DIR |= pin;}
			else{P3SEL &= ~ pin;P3DIR &= ~pin;}
			break;
#endif
		}
}
