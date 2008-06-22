#include "hyperterm.h"
#include <ez8.h>
#include <sio.h>

//for convinience
#define ESC 0x1B
//#define PUT(x) z_hyperterm_put(x) //more proper
#define PUT(x) putch(x) //less proper
#define CSI() PUT(ESC); PUT('[');
#define SGR_TERMINATE() PUT('m');

void z_hyperterm_put(char c)
{
	putch(c);
}

void z_hyperterm_putstring(char* c)
{
	while(*c) PUT(*c++);
}

void z_hyperterm_init(void)
{
	//Evil double-speed. Seems to work.
	init_uart(_UART0, _DEFFREQ, _DEFBAUD*2);
	z_hyperterm_formatreset();
	z_hyperterm_hidecurser();
}

void z_hyperterm_goto(unsigned char column, unsigned char row)
{
	//printf("%c[%d;%dH",ESC,row,column);
	CSI();
	printf("%d",row);
	PUT(';');
	printf("%d",column);
	PUT('H');
}

void z_hyperterm_clear(void)
{
	CSI();
	PUT('2');
	PUT('J');
}

void z_hyperterm_formatreset(void)
{
	CSI();
	PUT('0');
	SGR_TERMINATE();
}

void z_hyperterm_setfgcolor(char c)
{
	CSI();
	if(c>7)
	{
		c-=8;
		PUT('1');
		PUT(';');
	}
	else
	{
		PUT('22');
		PUT(';');
	}
	PUT('3');
	PUT(c+'0');
	SGR_TERMINATE();
}

void z_hyperterm_setbgcolor(char c)
{
	CSI();
	PUT('4');
	PUT(c+'0');
	SGR_TERMINATE();
}

void z_hyperterm_blinkslow(void)
{
	CSI();
	PUT('5');
	SGR_TERMINATE();
}

void z_hyperterm_blinkfast(void)
{
	CSI();
	PUT('6');
	SGR_TERMINATE();
}

void z_hyperterm_bold(void)
{
	CSI();
	PUT('1');
	SGR_TERMINATE();
}

void z_hyperterm_italic(void)
{
	CSI();
	PUT('3');
	SGR_TERMINATE();
}

void z_hyperterm_underline(void)
{
	CSI();
	PUT('4');
	SGR_TERMINATE();
}

void z_hyperterm_hidecurser(void)
{
	CSI();
	z_hyperterm_putstring("?25l");
}

void z_hyperterm_clearpoint(int x, int y)
{
	z_hyperterm_put_on(' ', x, y);
}

void z_hyperterm_put_on(char c, int x, int y)
{
	z_hyperterm_goto(x, y);
	z_hyperterm_put(c);
}
