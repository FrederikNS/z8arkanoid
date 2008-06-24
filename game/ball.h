#ifndef __BALL_H
#define __BALL_H

#define BALLS_MAX 16

void balls_init(void);

void balls_spawnnew(int x, int y, int xv, int yv);
void balls_spawnnew_fixed(int x, int y, int angle, int mod);
void balls_spawnnew_random_upwards(int x, int y);

char balls_amount(void);

void ball_scalevelocity(unsigned char i, int scale);

void balls_move_and_collide(void);
void balls_draw(void);

#endif