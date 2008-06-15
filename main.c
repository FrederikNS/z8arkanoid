#include "API/API.h"
#include "HLI/HLI.h"

int main(void) {
	int i;
	z_leds_init();
/*	z_ledstring_putchar('A',0);
	z_ledstring_putchar('A',1);
	z_ledstring_putchar('A',2);*/
/*	z_ledstring_putchar('A',3);
	z_ledfb_set_column(0, 1);
	z_ledfb_set_column(1, 3);
	z_ledfb_set_column(2, 7);*/
	z_ledstring_putstring("TIS");
	//for(i = 0; i < 20; i++) z_ledfb_set_column(i, 0xFF);
	while(1) z_ledfb_write();
}