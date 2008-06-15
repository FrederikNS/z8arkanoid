#include "API/API.h"
#include "HLI/HLI.h"

int main(void) {
	int i;
	z_leds_init();
	z_hyperterm_init();

	z_ledstring_putstring("TIS");
	z_hyperterm_putstring("TISSER!\n");
	z_hyperterm_blinkfast();
	z_hyperterm_bold();
	z_hyperterm_underline();
	z_hyperterm_italic();
	z_hyperterm_putstring("TISSER!");

	while(1) z_ledfb_write();
}
