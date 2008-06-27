#include "timer.h"
#include <ez8.h>

#define TIMER_IDLE 0
#define TIMER_BUSY 1

unsigned char timer_status = TIMER_IDLE;

/*
 Name: z_timer_setstatus
 Functionality: Sets the status of the timer
*/
//intern
void z_timer_setstatus(unsigned char status)
{
    timer_status = status;
}

/*
 Name: z_timer_isbusy
 Functionality: Returns the timers current status
*/
unsigned char z_timer_isbusy(void)
{
	return timer_status;
}

/*
 Name: z_timer_makebusy
 Functionality: Sets the timer to busy
*/
void z_timer_makebusy()
{
	z_timer_setstatus(TIMER_BUSY);
}

/*
 Name: z_timer_interrupt
 Functionality: Interrupts the timer, setting it to idle
*/
#pragma interrupt
void z_timer_interrupt()
{
	z_timer_setstatus(TIMER_IDLE);
}

/*
 Name: z_timer_start
 Functionality: Starts the timer
*/
void z_timer_start(unsigned int overflow, unsigned char prescale)
{
	SET_VECTOR(TIMER0, z_timer_interrupt);
 	T0H		= (overflow>>8)&0xFF;	// Timer High
	T0L 	= overflow&0xFF;	// Timer Low
//	T0RH 	= 0xFF;	// Reload Compare High
//	T0RL 	= 0xFF;	// Reload Compare Low
	T0CTL 	= 0x81|prescale<<3;	// Continous/Prescale
	IRQ0ENH |= 0x20;	// Set Interrupt Priority Nominal
	IRQ0ENL &= 0xDF;	// Set Interrupt Priority Nominal*/
}
