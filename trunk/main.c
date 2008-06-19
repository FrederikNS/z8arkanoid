#include "API/API.h"
#include "HLI/HLI.h"¨
#include "game/game.h"
#include <ez8.h>

int main(void) {
	DI();
	z_leds_init();
	z_hyperterm_init();
	z_timer_start(0x1000, 2);
	z_buttons_init();
	EI();
	while(1) {
		game_mainloop();
		z_timer_makebusy();
		while(z_timer_isbusy()) z_ledfb_write();
	}
}
