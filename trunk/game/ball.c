#include "ball.h"

#define START_SPEED (1<<8)

typedef struct{
	int x;
	int y;
	int xv;
	int yv;
	char active;
} ball;

ball balls[BALLS_MAX];

//Fuckings to the compiler
int get_inactive_ball(void)
{
	int i;
	for(i = 0; i < BALLS_MAX; i++) if(!balls[i].active) return i;
	return -1;
}

void ball_spawnnew(char x, char y, int xv, int yv)
{
	ball* b;
	int index = get_inactive_ball();
	if(index<0) return;

	b = &balls[index];
	if(!b) return;
	b->active = 1;
	b->x = x;
	b->y = y;
	b->xv = xv;
	b->yv = yv;
}

void ball_spawnnew_random_upwards(char x, char y)
{
	ball* b;
	int index = get_inactive_ball();
	if(index<0) return;

	b = &balls[index];
	b->active = 1;
	b->x = x;
	b->y = y;
	
}

void ball_split(void)
{
	//TODO
}

char ball_isactive(char i)
{
	return balls[i].active;
}

char ball_amount()
{
	int i, amount = 0;
	for(i = 0; i < BALLS_MAX; i++) if(ball_isactive(i)) amount++;
}

char ball_getx(int i)
{
	return balls[i].x;
}

char ball_gety(int i)
{
	return balls[i].y;
}

char ball_setx(char i, int x)
{
	balls[i].x = x;
}

char ball_sety(char i, int y)
{
	balls[i].y = y;
}

char ball_getxv(int i)
{
	return balls[i].xv;
}

char ball_getyv(int i)
{
	return balls[i].yv;
}

char ball_setxv(char i, int xv)
{
	balls[i].xv = xv;
}

char ball_setyv(char i, int yv)´
{
	balls[i].yv = yv;
}

char ball_scalevelocity(char i, int scale)
{
	balls[i].xv = (balls[i].xv * scale)>>8;
	balls[i].yv = (balls[i].yv * scale)>>8;
}

void balls_move(void)
{
	int i;
	//Ignore the fact that some balls are inactive since it doesn't matter.
	for(i = 0; i < BALLS_MAX; i++) {
		balls[i].x += balls[i].xv;
		balls[i].y += balls[i].yv;
	}
}

// |cos -sin|   | x |
// |sin  cos| * | y |

//Directions:
//1: Vertical
//2: Horizontal

void ball_collide(int i, char direction, int anglescale)
{
	ball* b = &balls[i];
	if(direction == 1) {
		b->y -= b->y;
	}
	else {
		b->x -= b->x;
	}
}



