#include "ball.h"
#include "blocks.h"
#include "paddle.h"
#include "../math/math.h"
#include "../api/hyperterm.h"

#include <stdlib.h>
#include <stdio.h>

#define START_SPEED (1<<8)

typedef struct{
	int x;
	int y;
	int xv;
	int yv;
	int oldx;
	int oldy;
	char active;
} ball;

ball balls[BALLS_MAX];

void balls_init(void)
{
	int i;
	for(i = 0; i < BALLS_MAX; i++) balls[i].active = 0;
}

//Fuckings to the compiler
int get_inactive_ball(void)
{
	int i;
	for(i = 0; i < BALLS_MAX; i++) if(!balls[i].active) return i;
	return -1;
}

void ball_spawnnew(int x, int y, int xv, int yv)
{
	ball* b;
	int index = get_inactive_ball();
	if(index<0) return;

	b = &balls[index];
	if(!b) return;
	b->active = 1;
	b->x = x<<8;
	b->y = y<<8;
	b->xv = xv;
	b->yv = yv;
	//z_hyperterm_goto(5,5);
	//printf("%d, %d, %d, %d", b->x, b->y, b->xv, b->yv);
}

void ball_spawnnew_random_upwards(int x, int y)
{
	ball* b;
	int index = get_inactive_ball();
	if(index<0) return;

	b = &balls[index];
	b->active = 1;
	b->x = x<<8;
	b->y = y<<8;
	b->xv = z_cos(rand());
	b->yv = z_sin(rand());
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

int ball_getx(int i)
{
	return balls[i].x;
}

int ball_gety(int i)
{
	return balls[i].y;
}

void ball_setx(char i, int x)
{
	balls[i].x = x;
}

void ball_sety(char i, int y)
{
	balls[i].y = y;
}

int ball_getxv(int i)
{
	return balls[i].xv;
}

int ball_getyv(int i)
{
	return balls[i].yv;
}

void ball_setxv(char i, int xv)
{
	balls[i].xv = xv;
}

void ball_setyv(char i, int yv)
{
	balls[i].yv = yv;
}

void ball_scalevelocity(char i, int scale)
{
	balls[i].xv = (balls[i].xv * scale)>>8;
	balls[i].yv = (balls[i].yv * scale)>>8;
}
/*
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
*/

#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1
#define VERT 1
#define HORI 0

#define ASSERT(x, r) if(!(x)) {z_hyperterm_goto(1,1); printf(r);while(1);}

void balls_move_and_collide(void)
{
	signed char i, xdir, ydir;
	unsigned int dx, dy, xv_left, yv_left, fail;
	unsigned long int xm, ym; //x and y "momentum" for lack of better in the middle of the night

	balls_store_coords();

	for(i = 0; i < BALLS_MAX; i++) {
		ball* b = &balls[i];
		if(b->active) {
			//Calculate the distance to travel on the x and y axis.
			xv_left = ABS(b->xv);
			yv_left = ABS(b->yv);

			//Calculate the x and y distance from the pixel to the
			//nearest whole number (i.e, no fractional bits)
			if(b->xv > 0) {
				xdir = RIGHT;
				dx = 0x100 - (b->x & 0xFF);
			} else {
				xdir = LEFT;
				dx = (b->x & 0xFF)+1;
			}

			if(b->yv > 0) {
				ydir = DOWN;
				dy = 0x100 - (b->y & 0xFF);
			} else {
				ydir = UP;
				dy = (b->y & 0xFF)+1;
			}

			//failure counter - shouldn't go above 4-5 for most balls
			fail = 0;

			//While there is still travelling left on either the x or y axis, do:
			while(xv_left || yv_left)
			{
				xm = xv_left * dy;
				ym = yv_left * dx;

				//If the failure counter goes over 100, we're fucked.
				if(fail++ > 100) {
					z_hyperterm_goto(0, 0); z_hyperterm_putstring(" -_-' ");
					z_hyperterm_goto(1, 24); printf("    %lu, %lu    %u,%u    %u,%u            ", xm, ym, dx, dy, xv_left, yv_left);
					break;
				}

/*				ASSERT(xm >= 0, "XM !!!");
				ASSERT(ym >= 0, "YM !!!");


				ASSERT(dx >= 0, "dx < 0");
				ASSERT(dx <= 0x100, "dx > 0x100");
				ASSERT(dy >= 0, "dy < 0");
				ASSERT(dy <= 0x100, "dy > 0x100");
				ASSERT(yv_left >= 0, "neg yleft");
				ASSERT(xv_left >= 0, "neg xleft");*/

				//the ball crosses the x axis before the y axis
				if(xm > ym || !dy)
				{
					//the ball has so little travelling left to do that it stays inside the current block.
					//just move it and be fone with it.
					if(xv_left < dx)
					{
						b->x += xv_left * xdir;
						dx -= xv_left;
						xv_left = 0;
					}
					//the block collides with something
					//reverse the x-direction and break the loop
					else if(block_hit((b->x+xdir*dx)>>8, b->y>>8) || b->x + dx * xdir < 0 || b->x + dx * xdir >= 64<<8 || paddle_collission(b->x+xdir*dx, b->y))
					{
						b->xv = -b->xv;
						break;
					}
					//the block did not collide with anything.
					//move it to the next block
					else {
						b->x += dx * xdir;
						xv_left -= dx;
						dx = 0x100;
					}
				}

				//the ball crosses the y axis before the x axis
				else
				{
					if(yv_left < dy)
					{
						b->y += yv_left * ydir;
						dy -= yv_left;
						yv_left = 0;
					}
					else if(block_hit(b->x>>8, (b->y+ydir*dy)>>8) || b->y + dy * ydir < 0 || b->y + dy * ydir >= 21<<8 || paddle_collission(b->x, b->y+ydir*dy))
					{
						b->yv = -b->yv;
						break;
					}
					else {
						b->y += dy*ydir;
						yv_left -= dy;
						dy = 0x100;
					}
				}
			}

			if(b->x < 0) b->x = 0;
			if(b->x >= 64<<8) b->x = (64<<8) - 1;
			if(b->y < 0) b->y = 0;
			if(b->y >= 21<<8) b->y = (21<<8) - 1;

		}
	}
}

/*
void balls_move_and_collide(void)
{
	int i;
	ball* b = balls;
	for(i = 0; i < BALLS_MAX; i++, b++) {
		if(b->active) {

		}
	}
}
*/

void balls_store_coords(void)
{
	int i;
	ball* b = balls;
	for(i = 0; i < BALLS_MAX; i++, b++) {
		if(b->active) {
			b->oldx = b->x>>8;
			b->oldy = b->y>>8;
		}
	}
}

void balls_draw(void)
{
	int i;
	ball* b = balls;
	for(i = 0; i < BALLS_MAX; i++, b++) {
		if(b->active) {
			if(b->x>>8 != b->oldx || b->y>>8 != b->oldy) {
				z_hyperterm_goto((b->x>>8) + 3, (b->y>>8) + 3);
				if(b->y&(1<<7)) z_hyperterm_put(220);
				else z_hyperterm_put(223);
				z_hyperterm_goto((b->oldx) + 3, (b->oldy) + 3);
				z_hyperterm_put(' ');
			}
		}
	}
}
/*
void balls_clear(void)
{
	int i;
	ball* b = balls;
	for(i = 0; i < BALLS_MAX; i++, b++) {
		if(b->active) {
			z_hyperterm_goto((b->x>>8) + 3, (b->y>>8) + 3);
			z_hyperterm_put(' ');
		}
	}
}
*/

