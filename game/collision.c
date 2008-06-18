#include "game.h"

void collission(void)
{
	char i, block_collide;
	for(i = 0; i < BALLS_MAX; i++) {
		if(ball_isactive(i)) {
			//Blocks
			block_collide = blocks_hit(ball_getx(i), ball_gety(i));
			if(block_collide) {
				ball_collide(i, block_collide, 0);
			}
			//paddle
			if(paddle_collission(ball_getx(i), ball_gety(i)) {

			}
			//out of border
		}
	}
}

