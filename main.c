#include "API/API.h"
#include "HLI/HLI.h"¨
#include "game/game.h"
#include "game/death.h"
#include <ez8.h>

int main(void) {
	DI();
	z_leds_init();
	z_hyperterm_init();
	z_buttons_init();
	EI();
	while(1) {
		game_mainloop();
		death();
	}
}
