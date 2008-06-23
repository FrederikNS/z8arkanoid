#include <eZ8.h>

void z_buttons_init(){
	PDADDR = 0x01;
	PDCTL |= 0xF;
	PDADDR = 0;

	PFADDR = 0x01;
	PFCTL |= 0xF;
	PFADDR = 0;
}

char z_button_right(void)
{
	return 0x80==0x80&PFIN;
}

char z_button_middle(void)
{
	return 0x40==0x40&PFIN;
}

char z_button_left(void)
{
	return 0x8==0x8&PDIN;
}

