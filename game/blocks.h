#ifndef __BLOCKS_H
#define __BLOCKS_H

#define BLOCKS_WIDTH 32
#define BLOCKS_HEIGHT 10

void blocks_clear(void);
void block_draw_all(void);
char block_hit_fixed(int x, int y);
char block_hit(int x, int y);

#endif

