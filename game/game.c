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
	int i;
	paddle_reset();
	balls_init();
	z_hyperterm_formatreset();
	z_hyperterm_setbgcolor(0);
	z_hyperterm_clear();
	gameboard_draw();
	//gameboard_draw_highscore();
	for(i = 0; i < BALLS_MAX; i++)
		ball_spawnnew_random_upwards(10,10);
}

char game_mainloop()
{
	static char needsinit = 1;
	if(needsinit) { game_init(); needsinit = 0; }

	paddle_draw();


	//* move balls, move paddle
	if(z_button_right()) paddle_move(1);
	if(z_button_left()) paddle_move(-1);
	if(z_button_middle()) paddle_increasewidth();
	balls_move_and_collide();
	balls_draw();
	z_hyperterm_goto(0, 0);
//	printf("Ball 0: %d,\t %d,\t %d,\t %d. \nBall 1: %d,\t %d,\t %d,\t %d",
//		ball_getx(0)>>8, ball_gety(0)>>8, ball_getxv(0), ball_getyv(0),
//		ball_getx(1)>>8, ball_gety(1)>>8, ball_getxv(1), ball_getyv(1));
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
