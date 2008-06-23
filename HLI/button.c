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
	if(0x80==(0x80&PFIN))
		return 1;
	return 0
}

char z_button_middle(void)
{
	if(0x40==(0x40&PFIN))
		return 0;
	return 1;
}

char z_button_left(void)
{
	if(0x8==(0x8&PDIN))
		return 1;
		return 0;
}

