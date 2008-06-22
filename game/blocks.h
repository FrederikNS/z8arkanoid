#ifndef __BLOCKS_H
#define __BLOCKS_H

#define BLOCKS_WIDTH 32
#define BLOCKS_HEIGHT 10

void blocks_clear(void);
//local function
char block_coords_in_area(int x, int y);
unsigned char* block_on(int x, int y);
unsigned char block_value_on(int x, int y);
void block_setvalue(int x, int y, int value);
void block_draw(char x, char y);
void block_draw_all(void);
void destroy_block(int x, int y);
char block_hit_screen_coord(int x, int y);
char block_hit(int x, int y);

#endif
