#include "blocks.h"

//Does not work, fuckings to the precompiler
//unsigned char board[BOARD_WIDTH*BOARD_HEIGHT*2/8];
unsigned char blocks[380];

void blocks_clear(void) {
	int i;
	for(i = 0; i < sizeof(blocks); i++) blocks[i] = 0;
}

//not fixedpoint
char block_coords_in_area(int x, int y)
{
	if(x > 0 && y > 0 && x < BLOCKS_WIDTH && y < BLOCKS_HEIGHT)
		return 1;
	return 0;
}

//local function
unsigned char* block_on(int x, int y) 
{
	//uncomment next 2 lines for fixed point coords
	//x >>= 8;
	//y >>= 8;
	x -= 1; //1 character gap between blocks and walls
	y -= 1; 
	if(block_coords_in_area(x, y))
		return &blocks[BLOCKS_WIDTH*y + x];

	return 0;
}

//fixed point
unsigned char block_value_on(int x, int y)
{
	return *block_on(x, y);
}

void block_setvalue(int x, int y, int value)
{
	if(block_coords_in_area(x, y)) *block_on(x, y) = value;
}

void destroy_block(int x, int y)
{
	block_setvalue(x, y, 0);
}

//BIG MEATY FUNCTION
//return:
//0 - empty block
//1 - normal block, bounce off it
//2 - the block was destroyed! Bounce!

char block_hit(int x, int y)
{
	unsigned char* block = block_on(x, y);
	if(!block || !*block) return 0; //Either the block is empty, or the coords are out of range, so no need for the ball to bounce off.
	
	return 1;
}





