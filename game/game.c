#include "../API/API.h"
#include "../HLI/HLI.h"
#include "game.h"

#include <stdlib.h>
#include <stdio.h>

/*
load level
run gameloop
*/


void game_init()
{
	paddle_reset();
	balls_init();
	z_hyperterm_formatreset();
	z_hyperterm_setbgcolor(0);
	z_hyperterm_clear();
	draw_gameboard();
	//ball_spawnnew(10, 10, -50, -50);
	ball_spawnnew(12, 3, 70, 31);
}

char game_mainloop()
{
	static char needsinit = 1;
	if(needsinit) { game_init(); needsinit = 0; }

/*	paddle_draw();
	z_hyperterm_goto(ball_getx(0)>>8 + 2, ball_gety(0)>>8 + 2);
	z_hyperterm_put('O');

*/
	//* move balls, move paddle
	if(z_button_right()&1) paddle_movehorizontally(1<<8);
	if(z_button_left()&4) paddle_movehorizontally(-1<<8);
	balls_clear();
	balls_move_and_collide();
	balls_draw();
	z_hyperterm_goto(0, 0);
	printf("Ball 0: %d,\t %d,\t %d,\t %d. \nBall 1: %d,\t %d,\t %d,\t %d",
		ball_getx(0)>>8, ball_gety(0)>>8, ball_getxv(0), ball_getyv(0),
		ball_getx(1)>>8, ball_gety(1)>>8, ball_getxv(1), ball_getyv(1));
/*
	//* collide balls with paddle and block, remove destructable blocks
	//  and reflect off indestructable blocks and the paddle
	//* remove balls that are out of the game area
	//* if no balls are left, die and lose a life.
*/
	//Draw stuff
	//paddle_draw();

	return 0; //The game is not done
}