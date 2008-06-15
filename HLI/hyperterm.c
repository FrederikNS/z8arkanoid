#include "hyperterm.h"

//for convinience
#define ESC 0x1B
//#define PUT(x) z_hyperterm_put(x) //more proper
#define PUT(x) putch(x) //less proper

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
	_init_uart(_UART0, _DEFFREQ, _DEFBAUD);
}

void z_hyperterm_goto(unsigned char x, unsigned char y)
{
	//printf("%c[%d;%dH",ESC,x,y);
	PUT(ESC);
	PUT('[');
	printf("%d",x);
	PUT(';');
	printf("%d",y);
	PUT('H');
}
