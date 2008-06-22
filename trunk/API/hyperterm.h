#ifndef __HYPERTERM_H
#define __HYPERTERM_H

void z_hyperterm_init(void);
void z_hyperterm_put(char c);
void z_hyperterm_put_on(char c, int x, int y);
void z_hyperterm_clear_point(char c, int x, int y);
void z_hyperterm_clearpoint(int x, int y);
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
void z_hyperterm_hidecurser(void);

/*
=============COLOR TABLE===============
Value Color(fg&bg) Value Color(fg only)
0     Black        8     Dark Gray
1     Red          9     Light Red
2     Green        10    Light Green
3     Brown        11    Yellow
4     Blue         12    Light Blue
5     Purple       13    Light Purple
6     Cyan         14    Light Cyan
7     Light Gray   15    White
=======================================
*/
enum COLOR
{
	COLOR_BLACK,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BROWN,
	COLOR_BLUE,
	COLOR_PURPLE,
	COLOR_CYAN,
	COLOR_LIGHTGRAY,
	COLOR_DARKGRAY,
	COLOR_LIGHTRED,
	COLOR_LIGHTGREEN,
	COLOR_YELLOW,
	COLOR_LIGHTBLUE,
	COLOR_LIGHTPURPLE,
	COLOR_WHITE
};

#endif