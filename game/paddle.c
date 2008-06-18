#include "paddle.h"
#include "../API/API.H"
#include "../HLI/HLI.h"

#define PADDLE_STARTWIDTH 7
#define PADDLE_MAXWIDTH 16
#define PADDLE_MINWIDTH 3
#define PADDLE_Y 20

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
	if(++paddle.width > PADDLE_MAXWIDTH) paddle.width = PADDLE_MAXWIDTH;
}


int paddl_decreasewidth(void)
{
	if(--paddle.width < PADDLE_MINWIDTH) paddle.width = PADDLE_MINWIDTH;
}

void paddle_reset(void)
{
	paddle.width = PADDLE_STARTWIDTH;
	paddle.x = 40<<8 - PADDLE_STARTWIDTH<<7; // x = center_x - width/2
}

int paddle_movehorizontally(int value)
{
	paddle.x += value;
	if(paddle.x < 0) paddle.x = 0;
	if(paddle.x>>8 + paddle.width > 78) paddle.x = (78 - paddle.width)<<8;
}

void paddle_draw(void)
{
	int i;
	z_hyperterm_goto(2 + paddle.x >> 8, PADDLE_Y+1);
	for(i = 0; i < paddle.width; i++)
		z_hyperterm_put('#');
}

char paddle_collission(int x, int y)
{
	if(y > PADDLE_Y<<8 && y < (PADDLE_Y+1)<<8 && x > paddle.x && x < paddle.x + paddle.width<<8)
		return 1;
	return 0;
}