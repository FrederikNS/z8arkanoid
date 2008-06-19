#include "blocks.h"
#include "../API/API.h"

//Does not work, fuckings to the precompiler
//unsigned char board[BOARD_WIDTH*BOARD_HEIGHT*2/8];
unsigned char blocks[32][10];
const char NO_BLOCK = 0;
const char REGULAR_BLOCK = 1;
const char EXPLOSIVE_BLOCK = 2;
const char INVISIBLE_BLOCK = 3;
const char INDESTRUCTIBLE_BLOCK = 4;
const char HARD_BLOCK = 5;

void blocks_clear(void) {
	int i;
	for(x=0;x<32;x++){
		for(y=0;y<10;y++){
			blocks[x][y] = 0;
		}
	}
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
	//x -= 1; //1 character gap between blocks and walls
	//y -= 1; 
	if(block_coords_in_area(x, y))
		return &blocks[x][y];
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

void block_draw(char x, char y){
	z_hyperterm_goto(i*2+3,j+3);
	switch(blocks[i][j]){
		case INVISIBLE_BLOCK:
		case NO_BLOCK:
			z_hyperterm_setfgcolor(0);
			z_hyperterm_put(0x20);
			z_hyperterm_put(0x20);
			break;
		case REGULAR_BLOCK:
			z_hyperterm_setfgcolor(15);
			z_hyperterm_put(0xB2);
			z_hyperterm_put(0xB2);
			break;
		case EXPLOSIVE:
			z_hyperterm_setfgcolor(1);
			z_hyperterm_put(0xCF);
			z_hyperterm_put(0xCF);
			break;
		case INDESTRUCTIBLE_BLOCK:
			z_hyperterm_setfgcolor(4);
			z_hyperterm_put(0xDB);
			z_hyperterm_put(0xDB);
			break;
		case HARD_BLOCK_1:
			z_hyperterm_setfgcolor(8);
			z_hyperterm_put(0xDB);
			z_hyperterm_put(0xDB);
			break;
		case HARD_BLOCK_2:
			z_hyperterm_setfgcolor(7);
			z_hyperterm_put(0xDB);
			z_hyperterm_put(0xDB);
			break;
		case HARD_BLOCK_3:
			z_hyperterm_setfgcolor(15);
			z_hyperterm_put(0xDB);
			z_hyperterm_put(0xDB);
			break;
	}
	
}

void block_draw_all() {
	int x;
	int y;
	for(x=0;x<32;x++){
		for(y=0;y<10;y++){
			block_draw(x,y);
		}
	}
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





