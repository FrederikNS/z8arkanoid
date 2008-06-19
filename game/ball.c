#include "ball.h"
#include "blocks.h"
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
	b->xv = rand()&0xF - 31;
	b->yv = -rand()&0xF;

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

void balls_move_and_collide(void)
{
	signed char i, dir, xdir, ydir, movdir, collided;
	signed int dx, dy, xv_left, yv_left, fail;
	for(i = 0; i < BALLS_MAX; i++) {
		ball* b = &balls[i];
		if(b->active) {
			xv_left = ABS(b->xv);
			yv_left = ABS(b->yv);

			xdir = LEFT;
			ydir = UP;

			dx = (b->x & 0xFF)+1;
			dy = (b->y & 0xFF)+1;

			if(b->xv > 0) {
				xdir = RIGHT;
				dx = (0xFF- dx)+2;
			}

			if(b->yv > 0) {
				ydir = DOWN;
				dy = (0xFF - dy)+2;
			}
			fail = 0;
			while(xv_left || yv_left)
			{
				if(fail++ > 100) {
					z_hyperterm_goto(0, 3); printf("Sigh");
				}

				if(xv_left * dy > yv_left * dx || (xv_left && !yv_left))
				{
					if(xv_left < dx)
					{
						z_hyperterm_goto(10, 10); z_hyperterm_putstring("xneg   ");
						b->x += xv_left * xdir;
						xv_left = 0;
						dx -= xv_left;
					}
					else if(block_hit((b->x>>8)+((xdir*dx)>>8), b->y>>8) || b->x + dx * xdir < 0 || b->x + dx * xdir >= 64<<8)
					{
						z_hyperterm_goto(10, 9); z_hyperterm_putstring("xmaj bh");
						b->xv = -b->xv;
						break;
					}
					else {
						z_hyperterm_goto(10, 11); z_hyperterm_putstring("xmaj nb");
						b->x += dx * xdir;
						xv_left -= dx;
						dx = 0x100;
					}
				}

				//notice the <= instead of <
				else if(xv_left * dy <= yv_left * dx || (!xv_left && yv_left))
				{
					if(yv_left < dy)
					{
						b->y += yv_left * ydir;
						yv_left = 0;
						dy -= yv_left;
					}
					if(block_hit(b->x>>8, (b->y>>8)+((ydir*dy)>>8)) || b->y + dy * ydir < 0 || b->y + dy * ydir >= 21<<8)
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
/*
			if(b->x < 0) b->x = 0;
			if(b->x >= 64<<8) b->x = (64<<8) - 1;
			if(b->y < 0) b->y = 0;
			if(b->y >= 21<<8) b->y = (21<<8) - 1;
*/
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

void balls_draw(void)
{
	int i;
	ball* b = balls;
	for(i = 0; i < BALLS_MAX; i++, b++) {
		if(b->active) {
			z_hyperterm_goto((b->x>>8) + 3, (b->y>>8) + 3);
			z_hyperterm_put('O');
		}
	}
}

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

