#include <ez8.h>
#include "led.h"
#include "../math/lamemath.h"

/*
 Name: z_leds_init
 Functionality: Initiates the leds for use
*/
void z_leds_init(void)
{
	PEAF = 0x00;		//PE Alt func = Port
	PGAF = 0x00;		//PG Alt func = Port

	PEOC = 0x00;    	// PE Out Ctrl = push-pull
	PGOC = 0x00;    	// PG Out Ctrl = push-pull

	PEADDR = 0x01;    	// PA Data Dir = output: updated
	PECTL= 0X00;     // OUTPUT	           : updated

	PGADDR = 0x01;    	// PA Data Dir = output: updated
	PGCTL= 0X00;     // OUTPUT	           : updated
}

/*
 Name: z_leds_set_column
 Functionality: Sets a column in the array to the defined bits
*/
void z_leds_set_column(int column, int value)
{
	//int xf = 4-column%5;
	int xf = 4-z_lame_mod(column, 5);
	PEOUT = (1<<xf)^0x1F;
	PGOUT = value&0x7F;
	//switch(column/5) {
	switch(z_lame_div(column, 5)) {
		case 0: PEOUT |= 0x80; break;
		case 1: PGOUT |= 0x80; break;
		case 2: PEOUT |= 0x20; break;
		case 3: PEOUT |= 0x40; break;
		default: break;
	}
}

/*
 Name: z_leds_clear_block
 Functionality: Turns all the leds on a block off
*/
void z_leds_clear_block(int block) {
	//Make sure that bits are low
	PEOUT = 0;
	PGOUT = 0;
	switch (block) {
		case 0: PEOUT = 0x80; break;
		case 1: PGOUT = 0x80; break;
		case 2: PEOUT = 0x20; break;
		case 3: PEOUT = 0x40; break;
	}
}

/*
 Name: z_leds_clear_all
 Functionality: Turns all the led on the blocks off
*/
void z_leds_clear_all(void)
{
	PEOUT = 0;
	PGOUT = 0;
	PEOUT = 0xD;
	PGOUT = 0x80;

}