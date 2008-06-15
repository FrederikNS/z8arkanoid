#include "ledframebuffer.h"
#include "../HLI/led.h"

char ledfb[20];

void z_ledfb_set_column(int column, int value)
{
	ledfb[column] = value;
}

void z_ledfb_write(void)
{
	int i, j;
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 4; j++) {
			z_leds_set_column(j*5+i, ledfb[j*5+i]);
		}
	}
}

void z_ledfb_put_dot(int x, int y)
{
	ledfb[x] |= 1<<y;
}

void z_ledfb_clear_dot(int x, int y)
{
	ledfb[x] &= ~(1<<y);
}
