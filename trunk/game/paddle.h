#ifndef __PADDLE_H
#define __PADDLE_H

int paddle_getx(void);
int paddle_increasewidth(void);
int paddl_decreasewidth(void);
void paddle_reset(void);
int paddle_movehorizontally(int value);
void paddle_draw(void);
char paddle_collission(int x, int y);

#endif