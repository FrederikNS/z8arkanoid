#include "paddle.h"
#include "../API/API.H"
#include "../HLI/HLI.h"

#define PADDLE_STARTWIDTH 7
#define PADDLE_MAXWIDTH 15
#define PADDLE_MINWIDTH 3
#define PADDLE_Y 22
#define LEFTBOUND_X = 0
#define RIGHTBOUND_X = 64

struct
{
	int x;
	int width;
} paddle;

int paddle_getx(void)
{
	return paddle.x;
}

int paddle_increasewidth(void)
{
	paddle.width+=2;
	if(paddle.width > PADDLE_MAXWIDTH) paddle.width = PADDLE_MAXWIDTH;
	if(paddle.x + paddle.width -1 > 64) paddle.x = 64 - paddle.width+1;
}


int paddle_decreasewidth(void)
{
	int i;
	paddle.width-=2;
	if(paddle.width < PADDLE_MINWIDTH) paddle.width = PADDLE_MINWIDTH;
	z_hyperterm_goto(paddle.x+paddle.width+1, PADDLE_Y);
	for(i=0;i<=1;i++){
		z_hyperterm_put(' ');
	}
}

void paddle_reset(void)
{
	paddle.width = PADDLE_STARTWIDTH;
	paddle.x = 32 - (PADDLE_STARTWIDTH>>1); // x = center_x - width/2
}

int paddle_move(int value)
{
	paddle.x += value;
	if(paddle.x < 1) paddle.x = 1;
	if(paddle.x + paddle.width -1 > 64) paddle.x = 64 - paddle.width + 1;
	if(value<0){
		z_hyperterm_goto(paddle.x+paddle.width+1, PADDLE_Y);
		z_hyperterm_put(' ');
	}
	else{
		z_hyperterm_goto(paddle.x-value-2, PADDLE_Y);
		z_hyperterm_put(' ');
	}
}

void paddle_draw(void)
{
	int i;
	z_hyperterm_goto(paddle.x+2, PADDLE_Y+2);
	for(i = 0; i < paddle.width; i++)
		z_hyperterm_put('#');
}

char paddle_collision(int x, int y)
{
	if(y > PADDLE_Y && y < (PADDLE_Y+1) && x > paddle.x && x < paddle.x + paddle.width)
		return 1;
	return 0;
}

char paddle_collision_fixed(int x, int y){
	return paddle_collision(x>>8,y>>8);
}
