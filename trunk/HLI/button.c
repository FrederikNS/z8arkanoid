#include <eZ8.h>

void z_buttons_init(){
	PDADDR = 0x01;
	PDCTL |= 0xF;
	PDADDR = 0;

	PFADDR = 0x01;
	PFCTL |= 0xF;
	PFADDR = 0;
}

char z_buttons_read(){
	return ~(((0x80 & PFIN)>>7)|((0x40 & PFIN)>>5)|((0x8 & PDIN)>>1));
}

char z_button_right(void)
{
	return z_buttons_read()&1;
}

char z_button_middle(void)
{
	return (z_buttons_read()&2);
}

char z_button_left(void)
{
	return (z_buttons_read()&4);
}

