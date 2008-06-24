#include "ball.h"
#include "blocks.h"
#include "paddle.h"
#include "gameboard.h"
#include "../math/math.h"
#include "../api/hyperterm.h"
#include <stdlib.h> //Used for randomization

/*
Local constants, fields and function prototypes
*/
typedef struct{
	int x;
	int y;
	int angle;
	int mod;
	int oldx;
	int oldy;
	char active;
} ball;

ball balls[BALLS_MAX];

int ball_get_inactive(void);
void balls_store_coords(void);
void ball_split(ball* b);

/*
Functions
*/

/*
Name: balls_init
Functionality: initializes the memory reserved for the balls
*/

void balls_init(void)
{
	int i;
	for(i = 0; i < BALLS_MAX; i++) balls[i].active = 0;
}

/*
Name: balls_get_inactive
Functionality: Returns the index of an inactive ball. Returns -1 if there are no inactive balls.
Note: Remember to check for the negative value and act accordingly.
*/

int balls_get_inactive(void)
{
	int i;
	for(i = 0; i < BALLS_MAX; i++) if(!balls[i].active) return i;
	return -1;
}

/*
Name: ball_spawnnew
Functionality: Spawns a new ball at the given x,y coordinate with the movementvector (xv, yv)
Arguments:
	x,y:	Gamespace coordinates for the new ball
	xv, yv:	Movement vector for the new ball in fixed point.
Note: x,y are in gamespace coords, xv/yv are in fixed point.
*/

void balls_spawnnew(int x, int y, int angle, int mod)
{
	balls_spawnnew_fixed(x<<8, y<<8, angle, mod);
}

/*
Name: ball_spawnnew_fixed
Note: Same as ball_spawnnew, but with start coords already given in fixed point
*/

void balls_spawnnew_fixed(int x, int y, int angle, int mod)
{
	ball* b;
	int index = balls_get_inactive();
	if(index<0) return;

	b = &balls[index];

	b->active = 1;
	b->x = x;
	b->y = y;
	b->angle = angle;
	b->mod = mod;
}

/*
Name: balls_spawnnew_random_upwards
Functionality: Spawns a ball moving upwards in a random direction
Arguments:
	x,y:	Gamespace coordinates for the new ball
Note: Gamespace coords
*/

void balls_spawnnew_random_upwards(int x, int y)
{
	balls_spawnnew(x, y, -(rand()&127), 1<<8);
}

/*
Name: ball_split
Functionality: Splits a ball into two
Note: Does not split if there are too many balls on the screen.
*/

void ball_split(ball* b)
{
	if(balls_amount() >= BALLS_MAX)
		return;
	balls_spawnnew_fixed(b->x, b->y, b->angle + 10, b->mod);
	b->angle -= 10;
}

/*
Name:
Functionality:
Arguments:
Note:
*/

char balls_amount()
{
	int i, amount = 0;
	for(i = 0; i < BALLS_MAX; i++) if(balls[i].active) amount++;
	return amount;
}

/*
Name:
Functionality:
Arguments:
Note:
*/

void ball_scalevelocity(unsigned char i, int scale)
{
	balls[i].mod = (balls[i].mod * scale)>>8;
}

#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1

/*
Name:
Functionality:
Arguments:
Note:
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

/*
Name:
Functionality:
Arguments:
Note:
*/

void balls_draw(void)
{
	int i;
	ball* b = balls;
	z_hyperterm_setfgcolor(7);
	z_hyperterm_setbgcolor(0);
	for(i = 0; i < BALLS_MAX; i++, b++) {
		if(b->active) {
			if(b->x>>8 != b->oldx || b->y>>8 != b->oldy) {
				z_hyperterm_goto((b->x>>8) + 3, (b->y>>8) + 3);
				if(b->y&(1<<7)) z_hyperterm_put(220);
				else z_hyperterm_put(223);
				z_hyperterm_clearpoint(b->oldx + 3, b->oldy + 3);
			}
		}
	}
}

void ball_deflect(ball* b, int angle)
{
	b->angle = 2 * angle - b->angle;
	b->angle += (rand()&7) - 4;
}

void ball_move_and_collide(ball* b)
{
	signed char xdir, ydir;
	unsigned int dx, dy, xv_left, yv_left;
	unsigned int xm, ym; //x and y "momentum" for lack of better in the middle of the night

	//Calculate the distance to travel on the x and y axis.
	xv_left = ABS((z_cos(b->angle)*b->mod)>>8);
	yv_left = ABS((z_sin(b->angle)*b->mod)>>8);

	//Calculate the x and y distance from the pixel to the
	//nearest whole number and store the sign of the travelling direction
	if(z_cos(b->angle) > 0) {
		xdir = RIGHT;
		dx = 0x100 - (b->x & 0xFF);
	}
	else {
		xdir = LEFT;
		dx = (b->x & 0xFF)+1;
	}

	if(z_sin(b->angle) > 0) {
		ydir = DOWN;
		dy = 0x100 - (b->y & 0xFF);
	}
	else {
		ydir = UP;
		dy = (b->y & 0xFF)+1;
	}

	//While there is still travelling left on either the x or y axis, do:
	while(xv_left || yv_left)
	{
		xm = xv_left * dy;
		ym = yv_left * dx;

		if(xm > ym)
		{
			//the ball crosses the x axis before the y axis
			if(xv_left < dx)
			{
				//the ball has so little travelling left to do that it stays inside the current block.
				//just move it and be done with it.
				b->x += xv_left * xdir;
				dx -= xv_left;
				xv_left = 0;
			}
			else if(b->x + dx * xdir < 0 || b->x + dx * xdir >= GAMEFIELD_WIDTH<<8 || block_hit_fixed(b->x+xdir*dx, b->y) || paddle_collision_fixed(b->x+xdir*dx, b->y))
			{
				//the block collides with something
				//move it to the edge, reverse the x-direction
				ball_deflect(b, 64);
				b->x += (dx-1)*xdir;
				xv_left -= dx-1;
				dx = 0x100;
				xdir = -xdir;
			}
			else
			{
				//the ball did not collide with anything.
				//move it to the next block
				b->x += dx * xdir;
				xv_left -= dx;
				dx = 0x100;
			}
		}
		else
		{
			//the ball crosses the y axis before the x axis
			if(yv_left < dy)
			{
				b->y += yv_left * ydir;
				dy -= yv_left;
				yv_left = 0;
			}
			else if(paddle_collision_fixed(b->x, b->y+ydir*dy))
			{
				ball_deflect(b, paddle_getangle(b->x));
				b->y += (dy-1)*ydir;
				yv_left -= dy-1;
				dy = 0x100;
				ydir = -ydir;
			}
			else if(b->y + dy * ydir < 0 || b->y + dy * ydir >= GAMEFIELD_HEIGHT<<8 || block_hit_fixed(b->x, b->y+ydir*dy))
			{
				ball_deflect(b, 0);
				b->y += (dy-1)*ydir;
				yv_left -= dy-1;
				dy = 0x100;
				ydir = -ydir;
			}
			else
			{
				b->y += dy*ydir;
				yv_left -= dy;
				dy = 0x100;
			}
		}
	}
}

/*
Name:
Functionality:
Arguments:
Note:
*/

void balls_move_and_collide(void)
{
	unsigned char i;
	balls_store_coords();

	for(i = 0; i < BALLS_MAX; i++) {
		ball* b = &balls[i];
		if(b->active) {
			ball_move_and_collide(b);
		}
	}
}

