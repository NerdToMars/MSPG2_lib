#ifndef GPIO
#define GPIO
#define OUTPUT	0
#define INPUT	1
#define H	1
#define L	0

#include "msp430g2553.h"
extern void pinMode(unsigned char port,unsigned int pin,unsigned char mode);
extern void DigitalWrite(unsigned char port,unsigned int pin,unsigned char mode);

#endif
