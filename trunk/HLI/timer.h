#ifndef __TIMER_H
#define __TIMER_H

unsigned char z_timer_isbusy(void);
void z_timer_makebusy();
void z_timer_start(unsigned int overflow, unsigned char prescale);
void z_timer_stop();


#endif