#ifndef __BALL_H
#define __BALL_H

#define BALLS_MAX 4

void balls_init(void);

void ball_spawnnew(int x, int y, int xv, int yv);
void ball_spawnnew_random_upwards(int x, int y);
void ball_split(void);

char ball_isactive(char i);
char ball_amount();

int ball_getx(int i);
int ball_gety(int i);
void ball_setx(char i, int x);
void ball_sety(char i, int y);

int ball_getxv(int i);
int ball_getyv(int i);
void ball_setxv(char i, int xv);
void ball_setyv(char i, int yv);
void ball_scalevelocity(char i, int scale);

//void balls_move(void);
void balls_move_and_collide(void);
void balls_draw(void);
void balls_store_coords(void);
void balls_clear_stored_coords(void);

#endif