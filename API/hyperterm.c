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
	init_uart(_UART0, _DEFFREQ, _DEFBAUD);
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
	PUT('3');
	if(c>9)
	{
		PUT('1');
		PUT(c+'0'-10);
	}
	else
	{
		PUT(c+'0');
	}
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
