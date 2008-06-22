#include "blocks.h"
#include "../API/API.h"
#include "levels.h"

//Does not work, fuckings to the precompiler
//unsigned char board[BOARD_WIDTH*BOARD_HEIGHT*2/8];
unsigned char blocks[BLOCKS_WIDTH*BLOCKS_HEIGHT];

enum BLOCK_TYPES_ {
	NO_BLOCK,            //0
	FAKE_BLOCK,          //1
	REGULAR_BLOCK,       //2
	EXPLOSIVE_BLOCK,     //3
	INVISIBLE_BLOCK,     //4
	INDESTRUCTIBLE_BLOCK,//5
	HARD_BLOCK_1,        //6
	HARD_BLOCK_2,        //7
	HARD_BLOCK_3         //8
} BLOCK_TYPES;

void blocks_clear(void) {
	int x, y;
	for(x=0;x<BLOCKS_WIDTH;x++){
		for(y=0;y<BLOCKS_HEIGHT;y++){
			block_destroy(x,y);
			block_draw_all();
		}
	}
}

void blocks_load(int lvl) {
	int i;
	for(i=0;i<BLOCKS_WIDTH*BLOCKS_HEIGHT;i++){
		blocks[i] = level[lvl][i];
	}
}

//not fixedpoint
char block_coords_in_area(int x, int y){
	if(x > 0 && y > 0 && x < BLOCKS_WIDTH && y < BLOCKS_HEIGHT)
		return 1;
	return 0;
}

//local function
unsigned char* block_on(int x, int y) {
	//uncomment next 2 lines for fixed point coords
	//x >>= 8;
	//y >>= 8;
	//x -= 1; //1 character gap between blocks and walls
	//y -= 1;
	if(block_coords_in_area(x, y))
		return &blocks[x+y*BLOCKS_WIDTH];
	return 0;
}

//fixed point
unsigned char block_value_on(int x, int y){
	return *block_on(x, y);
}

void block_setvalue(int x, int y, int value){
	if(block_coords_in_area(x, y)) *block_on(x, y) = value;
}

//FIX
void block_draw(char x, char y){
	z_hyperterm_goto((x<<2)+3,y+3);
	switch(block_value_on(x,y)){
		case INVISIBLE_BLOCK:
		case NO_BLOCK:
			z_hyperterm_setfgcolor(0);
			z_hyperterm_put(0x28);
			z_hyperterm_put(0x28);
			break;
		case FAKE_BLOCK:
		case REGULAR_BLOCK:
			z_hyperterm_setfgcolor(12);
			z_hyperterm_put(0xB2);
			z_hyperterm_put(0xB2);
			break;
		case EXPLOSIVE_BLOCK:
			z_hyperterm_setfgcolor(1);
			z_hyperterm_put(0xCF);
			z_hyperterm_put(0xCF);
			break;
		case INDESTRUCTIBLE_BLOCK:
			z_hyperterm_setfgcolor(11);
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
	for(x=0;x<BLOCKS_WIDTH;x++){
		for(y=0;y<BLOCKS_HEIGHT;y++){
			block_draw(x,y);
		}
	}
}

void block_destroy(int x, int y) {
	block_setvalue(x, y, NO_BLOCK);
}

//BIG MEATY FUNCTION
//return:
//8 - empty block
//1 - normal block, bounce off it
//2 - the block was destroyed! Bounce!

char block_hit_fixed(int x, int y){
	return block_hit(x>>8,y>>8);
}

char block_hit(int x, int y){
	return block_hit_coord((x-3)>>1,y-3);
}

char block_hit_coord(int x, int y) {
	unsigned char* block = block_on(x, y);
	if(!block || !*block) return 0; //Either the block is empty, or the coords are out of range, so no need for the ball to bounce off.
	switch(block_value_on(x,y)){
		case HARD_BLOCK_1:
		case REGULAR_BLOCK:
			block_destroy(x,y);
			break;
		case EXPLOSIVE_BLOCK:
			block_hit_coord(x-1,y-1);
			block_draw(x-1,y-1);
			block_hit_coord(x-1,y);
			block_draw(x-1,y);
			block_hit_coord(x-1,y+1);
			block_draw(x-1,y+1);
			block_hit_coord(x,y-1);
			block_draw(x,y-1);
			block_destroy(x,y);
			block_draw(x,y);
			block_hit_coord(x,y+1);
			block_draw(x,y+1);
			block_hit_coord(x+1,y-1);
			block_draw(x+1,y-1);
			block_hit_coord(x+1,y);
			block_draw(x+1,y);
			block_hit_coord(x+1,y+1);
			block_draw(x+1,y+1);
			break;
		case INDESTRUCTIBLE_BLOCK:
			break;
		case HARD_BLOCK_2:
			block_setvalue(x,y,HARD_BLOCK_1);
			break;
		case HARD_BLOCK_3:
			block_setvalue(x,y,HARD_BLOCK_2);
			break;
		case FAKE_BLOCK:
			block_destroy(x,y);
		default:
			return 0;
			break;
	}
	return 1;
}