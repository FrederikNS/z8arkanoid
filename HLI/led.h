#ifndef __LED_H
#define __LED_H

void z_leds_init(void);
void z_leds_set_column(int column, int value);
void z_leds_clear_block(int block);
void z_leds_clear_all(void);

#endif