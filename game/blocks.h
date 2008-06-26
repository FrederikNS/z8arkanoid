#ifndef __BLOCKS_H
#define __BLOCKS_H

#define BLOCKS_WIDTH 32
#define BLOCKS_HEIGHT 10

void blocks_clear(void);
int block_counter(void);
int blocks_left(void);
void blocks_draw(void);
void blocks_loadlevel(int lvl);
void blocks_randomizedlevel(void);
char block_hit(int x, int y);
char block_hit_fixed(int x, int y);
int blocks_amount(void);
void blocks_reveal_all(void);

#endif
