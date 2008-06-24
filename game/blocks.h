#ifndef __BLOCKS_H
#define __BLOCKS_H

#define BLOCKS_WIDTH 32
#define BLOCKS_HEIGHT 10

void blocks_clear(void);
int block_counter(void);
int blocks_left(void);
void blocks_draw(void);
void blocks_loadlevel(int lvl);
char block_hit(int x, int y);
char block_hit_fixed(int x, int y);
char block_coords_in_area(int x, int y);
unsigned char* block_on(int x, int y);
char block_hit_coord(int x, int y);

#endif
