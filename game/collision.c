#include "game.h"

void collission(void)
{
	char i, collide;
	for(i = 0; i < BALLS_MAX; i++) {
		if(ball_isactive(i)) {
			//Blocks
			collide = blocks_hit(ball_getx(i), ball_gety(i));
			//paddle
			if(paddle_collission(ball_getx(i), ball_gety(i)) {

			}
			//out of border
		}
	}
}
