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
	if(paddle.width < PADDLE_MAXWIDTH) {
		paddle.width+=2;
		paddle.x -= 1;
		paddle_fixposition();
	}
}


void paddle_decreasewidth(void)
{
	if(paddle.width > PADDLE_MINWIDTH) {
		z_hyperterm_clearpoint(3 + paddle.x, 3 + PADDLE_Y);
		z_hyperterm_clearpoint(3 + paddle.x+paddle.width-1, 3 + PADDLE_Y);
		paddle.width-=2;
		paddle.x += 1;
	}
}

void paddle_reset(void)
{
	paddle.width = PADDLE_STARTWIDTH;
	paddle.x = (GAMEFIELD_WIDTH>>1) - (PADDLE_STARTWIDTH>>1); // x = center_x - width/2
}

void paddle_moveleft(void)
{
	if(paddle.x > 0) {
		z_hyperterm_put_on(' ', paddle.x+paddle.width+2, PADDLE_Y + 3);
		paddle.x--;
		//z_hyperterm_put_on('#', paddle.x+3, PADDLE_Y + 3);
	}
}

void paddle_moveright(void)
{
	if(paddle.x + paddle.width < GAMEFIELD_WIDTH) {
		z_hyperterm_put_on(' ', paddle.x + 3, PADDLE_Y + 3);
		//z_hyperterm_put_on('#', paddle.x+paddle.width+3, PADDLE_Y + 3);
		paddle.x++;
	}
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


int paddle_getangle(int x) {
	int d = x - (paddle.x << 8); //x is already fixed

	return (d / paddle.width)>>5;
}
