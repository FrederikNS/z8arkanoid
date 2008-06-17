#ifndef __BALL_H
#define __BALL_H

void ball_spawnnew(char x, char y, int xv, int yv);
void ball_spawnnew_random_upwards(char x, char y);
void ball_split(void);

char ball_isactive(char i);
char ball_amount();

char ball_getx(int i);
char ball_gety(int i);
char ball_setx(char i, int x);
char ball_sety(char i, int y);

char ball_getxv(int i);
char ball_getyv(int i);
char ball_setxv(char i, int xv);
char ball_setyv(char i, int yv);
char ball_scalevelocity(char i, int scale);

void balls_move(void);

#endif