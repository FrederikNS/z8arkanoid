#ifndef __PADDLE_H
#define __PADDLE_H

void paddle_increasewidth(void);
void paddle_decreasewidth(void);
void paddle_reset(void);
void paddle_move(int value);
void paddle_draw(void);
char paddle_collision(int x, int y);
char paddle_collision_fixed(int x, int y);

#endif