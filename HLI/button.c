#include <eZ8.h>

/*
 Name: z_buttons_init
 Functionality: Initiates the buttons for use
*/
void z_buttons_init(){
	PDADDR = 0x01;
	PDCTL |= 0xF;
	PDADDR = 0;

	PFADDR = 0x01;
	PFCTL |= 0xF;
	PFADDR = 0;
}

/*
 Name: z_button_right
 Functionality: Returns 1 if the right buttons is pressed, 0 if it's not
*/
char z_button_right(void)
{
	if(0x80!=(0x80&PFIN))
		return 1;
	return 0;
}

/*
 Name: z_button_middle
 Functionality: Returns 1 if the middle buttons is pressed, 0 if it's not
*/
char z_button_middle(void)
{
	if(0x40!=(0x40&PFIN))
		return 1;
	return 0;
}

/*
 Name: z_button_middle
 Functionality: Returns 1 if the left buttons is pressed, 0 if it's not
*/
char z_button_left(void)
{
	if(0x8!=(0x8&PDIN))
		return 1;
	return 0;
}