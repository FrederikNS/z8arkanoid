#include "ball.h"
#include "blocks.h"
#include "paddle.h"
#include "gameboard.h"
#include "powerups.h"
#include "../math/math.h"
#include "../api/hyperterm.h"
#include "../api/debug.h"
#include <stdlib.h> //Used for randomization

/*
Local constants, fields and function prototypes
*/
typedef struct{
	signed int x; //fixed point 1.7.8
	signed int y; //ditto.
	signed int angle;
	int mod; //modulus/ballspeed in 11.5 coords.
	int oldx; //coordinates from the last frame
	int oldy; //--||--
	char active; //is the ball active or not?
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
	mod:	Speed
Note: Gamespace coords
*/

void balls_spawnnew_random_upwards(int x, int y, int mod)
{
	balls_spawnnew(x, y, (-(rand()&63)-32), mod);
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

//splits all balls
void balls_split(void)
{
	//this array keeps track off all balls which
	//are to be split so that the function
	//does not split balls which have spawned
	//from another ball being split in the same
	//function.
	//Not very RAM effective, but it would remain
	//unused anyway. Would be more proper with a
	//bitfield, though.

	char to_split[BALLS_MAX];
	unsigned char i;
	//generate the to_split list
	for(i = 0; i < BALLS_MAX; i++) {
		if(balls[i].active)
			to_split[i] = 1;
		else
			to_split[i] = 0;
	}
	//excecute!
	for(i = 0; i < BALLS_MAX; i++)
		if(to_split[i])
			ball_split(&balls[i]);
}

//returns the amount of active balls in play
char balls_amount()
{
	int i, amount = 0;
	for(i = 0; i < BALLS_MAX; i++) if(balls[i].active) amount++;
	return amount;
}

//scales the length of a ball by a scalar given in 8.8 fixed point
void ball_scalevelocity(unsigned char i, int scale)
{
	balls[i].mod = (balls[i].mod * scale)>>8;
}

//stores the coordinates of the balls
//to use them later in the drawing function.
//keeps balls from flashing.
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

//removes all balls from their old position on the screen
//and draws them all on their new ones,
//with their new animation figures.
void balls_draw(void)
{
	int i;
	ball* b = balls;
	z_hyperterm_setbgcolor(0);
	//sets distinguishable color to signal which powerups are active.
	if(powerups_heavyball() && powerups_bombballs())
		z_hyperterm_setfgcolor(11);
	else if (powerups_heavyball())
		z_hyperterm_setfgcolor(6);
	else if (powerups_bombballs())
		z_hyperterm_setfgcolor(1);
	else
		z_hyperterm_setfgcolor(7);

	//loop through all balls
	for(i = 0; i < BALLS_MAX; i++, b++) {
		if(b->active) {
			if(b->x>>8 != b->oldx || b->y>>8 != b->oldy) {
				z_hyperterm_clearpoint(b->oldx + 3, b->oldy + 3);
			}
			//even if the ball is on its old position, the animation
			//figure might have changed.
			z_hyperterm_goto((b->x>>8) + 3, (b->y>>8) + 3);
			if(b->y&(1<<7)) z_hyperterm_put(220);
			else z_hyperterm_put(223);
		}
	}
}

//deflects the angle of a ball. See repport for how the
//formula was derived.
void ball_deflect(ball* b, int angle)
{
	//int r = rand();
	b->angle = 2 * angle - b->angle;
	//Randomizes the angle a little, commented
	//out as a gameplay choice.
	/*if(r&1) {
		if(r&2)
			b->angle--;
		else
			b->angle++;
	}*/
}


#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1

#include <stdio.h>

//moves a ball and collides it with the sorrounding game objects
//see the repport for details.
void ball_move_and_collide(ball* b)
{
	signed char xdir, ydir; //keeps track of the x and y direction signs.
	//dx: distance to travel to cross into the next screen block on the horizontal axis
	//dy:                                       --||--                  vertical axis.
	//xv_left: distance left to travel on the horizontal axis.
	//yv_left: --||-- for the vertical axis.
	unsigned int dx, dy, xv_left, yv_left;

	//x and y "momentum" for lack of better in the middle of the night
	//used to evaluate which axis that crosses into the next screen block next.
	unsigned long xm, ym;

	//if the ball is inside the paddle,
	//move it on top of it and change its direction
	//to straight up. it's a gameplay choice,
	//keeps it exciting to the last.
	if(paddle_collision_fixed(b->x, b->y)) {
		b->y -= 1<<8;
		b->angle = -64;
	}

	//Calculate the distance to travel on the x and y axis.
	//the ball travels twice as fast on the x axis because
	//the characters on the hyperterm are nearly twice
	//as tall as they are wide.
	xv_left = ABS(z_cos(b->angle)*b->mod)>>4;
	yv_left = ABS(z_sin(b->angle)*b->mod)>>5;

	//Calculate the x and y distance from the pixel to the
	//nearest whole number using the fractional part of the x and y movement vectors,
	//and store the sign of the travelling direction in separate variables.
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
		/*
		The axis which crosses into the next character block the fastest is
		the one who has the biggest  speed/distance to travel  proportion.
		The proportion for the x axis goes as following:
			xv_left / dx
		and for y:
			yv_left / dy
		these two are compared together, the largest one is the direction
		which crosses into a screen block first. The following
		statement if that axis is the x axis:
			xv_left / dx > dy_left / dy
		ARGH! DIVISIONS!
		Luckily, the equation can be refactored to:
			xv_left * dy > dy_left * dx
		which is much nice. However, it has to be stored in longs to avoid
		overflowing the datatype.
		xm and ym are just hacks to do this, they are only used for
		comparrision this single time.

		*/
		xm = (long)xv_left * (long)dy;
		ym = (long)yv_left * (long)dx;
		//make sure nothing is wrong.
		ASSERT(dy, "!dy");
		ASSERT(dx, "!dx");
		ASSERT(!(xm == 0 && ym == 0), "xm & ym = 0");

		if(xm > ym)
		{
			//the ball crosses the x axis before the y axis
			if(xv_left < dx)
			{
				//the ball has so little travelling left to
				//do that it stays inside the current block.
				//just move it and be done with it.
				b->x += xv_left * xdir;
				dx -= xv_left;
				xv_left = 0;
			}
			else if(b->x + dx * xdir < 0 ||
					b->x + dx * xdir >= GAMEFIELD_WIDTH<<8 ||
				    block_hit_fixed(b->x+xdir*dx, b->y) ||
				    paddle_collision_fixed(b->x+xdir*dx, b->y))
			{
				//the block collides with something
				//move it to the edge of the current block,
				//and deflect it

				 //deflect
				ball_deflect(b, 64);

				//move
				b->x += (dx-1)*xdir; //move

				//keep track of the travelling left to do.
				xv_left -= dx-1;

				//reverse the travel direction.
				xdir = -xdir;
				//since the ball is at the very edge of the block
				//block and pointing directly away from
				//that edge on the horizontal axis,
				//it can be asserted that it has to travel
				//exactly 0x100 units to reach the next block.
				dx = 0x100;
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
			//most of the logic from the x axis code is reused here,
			//so read that before reading this.
			//only exception is the collision.
			if(yv_left < dy)
			{
				b->y += yv_left * ydir;
				dy -= yv_left;
				yv_left = 0;
			}
			else if(paddle_collision_fixed(b->x, b->y+ydir*dy))
			{
				//the ball collided with the paddle.

				//deflect it according to where it hit
				//the paddle.
				ball_deflect(b, paddle_getangle(b->x));

				//wrap the angle around.
				b->angle = b->angle&0xFF;

				//make sure that the ball won't fly
				//with an angle close to directly horizontal,
				//because thos are lame for the gameplay.
				if(b->angle > 240)
					b->angle = 240;
				else if(b->angle < 114)
					b->angle = 114;

				//see line 339
				//NOTICE:
				//The code below is an approximation,
				//because the angle has changed to something
				//unknown. dy, dx, yv_left, and xv_left would
				//have to be recalculated to do things properly,
				//and that would be too big a mouthful.
				//But since it only runs for the remainder of
				//the move, it is allright.
				b->y += (dy-1)*ydir;
				yv_left -= dy-1;
				dy = 0x100;
				ydir = -ydir;
			}
			else if((b->y < 0x100 && ydir < 0) || block_hit_fixed(b->x, b->y+ydir*dy))
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
	//if the ball has crosed the lower border,
	//remove it.
	if(b->y >= GAMEFIELD_HEIGHT<<8)
	{
		b->active = 0;
		z_hyperterm_clearpoint(b->oldx + 3, b->oldy + 3);
		return;
	}
}

//moves all balls and collides them with the sorrounding game objects
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

