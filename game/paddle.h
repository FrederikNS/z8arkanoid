#ifndef __PADDLE_H
#define __PADDLE_H

void paddle_increasewidth(void);
void paddle_decreasewidth(void);
void paddle_reset(void);
void paddle_moveleft(void);
void paddle_moveright(void);
char paddle_collision(int x, int y);
char paddle_collision_fixed(int x, int y);
void paddle_draw(void);
int paddle_getangle(int x);
char paddle_ismaxwidth(void);

#endif