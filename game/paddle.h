#ifndef __PADDLE_H
#define __PADDLE_H

int paddle_getx(void);
int paddle_increasewidth(void);
int paddle_decreasewidth(void);
void paddle_reset(void);
int paddle_move(int value);
void paddle_draw(void);
char paddle_collision(int x, int y);
char paddle_collision_fix(int x, int y);

#endif