#include "../API/API.h"
#include "../HLI/HLI.h"
#include "game.h"

/*
load level
run gameloop
*/


void game_init()
{
	paddle_reset();
}

char game_mainloop()
{
	static char needsinit = 1;
	if(needsinit) { game_init(); needsinit = 0; }

	//* move balls, move paddle
	if(z_button_right()&1) paddle_movehorizontally(1<<8);
	if(z_button_left()&4) paddle_movehorizontally(-1<<8);
	balls_mov();
		
	//* collide balls with paddle and block, remove destructable blocks
	//  and reflect off indestructable blocks and the paddle
	//* remove balls that are out of the game area
	//* if no balls are left, die and lose a life.
	
	//Draw stuff
	paddle_draw();

	return 0; //The game is not done
}