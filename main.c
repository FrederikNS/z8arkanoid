#include "API/API.h"
#include "HLI/HLI.h"¨
#include "cracktro/cracktro.h"
#include "game/game.h"
#include <ez8.h>

int main(void) {
	int i;
	int pos = 0;
	char autoscroll = 0;
	DI();
	z_leds_init();
	z_hyperterm_init();
	z_timer_start(0x1000, 4);
	z_buttons_init();
	EI();
//	cracktro();
	z_hyperterm_formatreset();
	z_hyperterm_goto(1,1);
	z_hyperterm_putstring("RAOOAORRR");
	
	while(1) {
//		z_ledstring_putscrollingstring("Kode saelges, kontakt 30706510   ", pos);
//		if(z_buttons_read()&1) { pos--; autoscroll = 0; }
//		if(z_buttons_read()&2) { if(autoscroll) autoscroll = 0; else autoscroll = 1; }
//		if(z_buttons_read()&4) { pos++; autoscroll = 0; }
		if(z_buttons_read()&1) { z_ledstring_putchar('1',3); } else z_ledfb_clear_block(3);
		if(z_buttons_read()&2) { z_ledstring_putchar('2',2); } else z_ledfb_clear_block(2);
		if(z_buttons_read()&4) { z_ledstring_putchar('3',1); } else z_ledfb_clear_block(1);

		if(autoscroll) pos++;

		game_mainloop();

		z_timer_makebusy();
		while(z_timer_isbusy()) z_ledfb_write();
	}
}
