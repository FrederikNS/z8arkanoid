#ifndef __HYPERTERM_H
#define __HYPERTERM_H

void z_hyperterm_init(void);
void z_hyperterm_put(char c);
void z_hyperterm_putstring(char* c);
void z_hyperterm_goto(unsigned char column, unsigned char row);
void z_hyperterm_clear(void);

//Formatting
void z_hyperterm_formatreset(void);
void z_hyperterm_setfgcolor(char c);
void z_hyperterm_setbgcolor(char c);
void z_hyperterm_blinkslow(void);
void z_hyperterm_blinkfast(void);
void z_hyperterm_bold(void);
void z_hyperterm_italic(void);
void z_hyperterm_underline(void);

#endif