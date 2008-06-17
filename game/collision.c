#include "game.h"

void collission(void)
{
	int i, collide;
	for(i = 0; i < BALLS_MAX; i++) {
		if(ball_isactive(i)) {
			//Blocks
			collide = blocks_hit(ball_getx(i), ball_gety(i));
			//paddle
			if(ball_gety(i) > PADDLE_Y<<8 && ball_gety(i) < (PADDLE_Y+1)<<8) {

			}
			//out of border
		}
	}
}
