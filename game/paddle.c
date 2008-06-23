#include "paddle.h"
#include "gameboard.h"
#include "../API/API.H"
#include "../HLI/HLI.h"

#define PADDLE_STARTWIDTH 7
#define PADDLE_MAXWIDTH 15
#define PADDLE_MINWIDTH 3
#define PADDLE_Y (GAMEFIELD_HEIGHT - 2)

struct
{
	int x;
	int width;
} paddle;

void paddle_fixposition(void)
{
	if(paddle.x < 0) paddle.x = 0;
	if(paddle.x + paddle.width > GAMEFIELD_WIDTH) paddle.x = GAMEFIELD_WIDTH - paddle.width;
}

void paddle_increasewidth(void)
{
	paddle.width+=2;
	if(paddle.width > PADDLE_MAXWIDTH) paddle.width = PADDLE_MAXWIDTH;
}


void paddle_decreasewidth(void)
{
	//int i;
	paddle.width-=2;
	if(paddle.width < PADDLE_MINWIDTH) paddle.width = PADDLE_MINWIDTH;
}

void paddle_reset(void)
{
	paddle.width = PADDLE_STARTWIDTH;
	paddle.x = (GAMEFIELD_WIDTH>>1) - (PADDLE_STARTWIDTH>>1); // x = center_x - width/2
}

void paddle_move(int value)
{
	if(value < 0) {
		z_hyperterm_put_on(' ', paddle.x + 2 + paddle.width, PADDLE_Y + 3);
	}
	else if(value > 0) {
		z_hyperterm_put_on(' ', paddle.x + 3, PADDLE_Y + 3);
	}
	paddle.x += value;
	paddle_fixposition();
}

void paddle_draw(void)
{
	int i;
	z_hyperterm_goto(paddle.x + 3, PADDLE_Y + 3);
	z_hyperterm_setfgcolor(3);
	for(i = 0; i < paddle.width; i++) z_hyperterm_put('#');
}

char paddle_collision(int x, int y)
{
	if(y == PADDLE_Y && x >= paddle.x && x < paddle.x + paddle.width)
		return 1;
	return 0;
}

char paddle_collision_fixed(int x, int y){
	return paddle_collision(x>>8,y>>8);
}
