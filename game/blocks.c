#include "blocks.h"
#include "../API/API.h"
#include "levels.h"

/*
Local constants, fields and function prototypes
*/

char block_coords_in_area(int x, int y);
unsigned char* block_on(int x, int y);
void block_setvalue(int x, int y, int value);
void block_draw(char x, char y);
char block_hit_coord(int x, int y);

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


unsigned char blocks[BLOCKS_WIDTH*BLOCKS_HEIGHT];

/*
Functions
*/

/*
Name: blocks_clear
Functionality: clears all blocks.
Note: Does not remove the blocks from the screen.
*/

void blocks_clear(void)
{
	int i;
	for(i = 0; i < sizeof(blocks); blocks[i++] = 0);
}

/*
Name: blocks_loadlevel
Functionality: Loads a level into the block memory
Arguments:
	lvl:	Level number, from levels.c
Note: Lvl is zero-indexed.
*/

void blocks_loadlevel(int lvl) {
	int i;
	for(i=0;i<BLOCKS_WIDTH*BLOCKS_HEIGHT;i++) {
		blocks[i] = levels[lvl][i];
	}
}

/*
Name: blocks_coords_in_area
Functionality: Returns true (1) if the given coordinates are inside the block-area.
Arguments:
	x, y: coordinates in block coords.
Note: block coords
*/

char block_coords_in_area(int x, int y) {
	if(x >= 0 && y >= 0 && x < BLOCKS_WIDTH && y < BLOCKS_HEIGHT)
		return 1;
	return 0;
}

/*
Name: block_on
Functionality: Returns a pointer to the memory address holding the value of the block on x, y
Arguments:
	x, y: coordinates in block coords.
Note: block coords
*/
unsigned char* block_on(int x, int y) {
	if(block_coords_in_area(x, y))
		return &blocks[x+y*BLOCKS_WIDTH];
	return 0;
}
<<<<<<< .mine

//fixed point
unsigned char block_value_on(int x, int y){
	return *block_on(x, y);
}

void block_setvalue(int x, int y, int value){
	if(block_coords_in_area(x, y)) *block_on(x, y) = value;
}

void block_draw(char x, char y){
	z_hyperterm_goto((x<<1)+3,y+3);
	switch(block_value_on(x,y)){
=======
/*
Name: block_draw
Functionality: Draws the block on the given coordinates to the screen.
Arguments:
	x, y: coordinates in block coords.
Note: block coords
*/
void block_draw(char x, char y) {
	z_hyperterm_goto((x<<1)+3,y+3);
	switch(*block_on(x,y)){
>>>>>>> .r47
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

/*
Name: blocks_draw
Functionality: Draws all blogs to the screen
*/

void blocks_draw() {
	int x;
	int y;
	for(x=0;x<BLOCKS_WIDTH;x++){
		for(y=0;y<BLOCKS_HEIGHT;y++){
			block_draw(x,y);
		}
	}
}

/*
Name: block_hit_fixed
Functionality: hits the block on the given coordinate.
Returns: true if the block is/was solid enough to give bounce-back. Used for balls.
Arguments:
	x, y: coordinates for the block in gamespace fixed point
*/

<<<<<<< .mine
char block_hit_fixed(int x, int y){
=======
char block_hit_fixed(int x, int y) {
>>>>>>> .r47
	return block_hit(x>>8,y>>8);
}

/*
Name: block_hit
Functionality: hits the block on the given coordinate.
Returns: true if the block is/was solid enough to give bounce-back. Used for balls.
Arguments:
	x, y: coordinates for the block in gamespace integers
*/

char block_hit(int x, int y){
	return block_hit_coord(x>>1,y);
}

/*
Name: block_hit
Functionality: hits the block on the given coordinate.
Returns: true if the block is/was solid enough to give bounce-back. Used for balls.
Arguments:
	x, y: coordinates for the block in blockspace fixed point
Note: block coords
*/

char block_hit_coord(int x, int y) {
	unsigned char* block = block_on(x, y);
	if(!block || !*block) return 0; //Either the block is empty, or the coords are out of range, so no need for the ball to bounce off.
	switch(*block){
		case HARD_BLOCK_1:
		case REGULAR_BLOCK:
			*block = 0;
			break;
		case EXPLOSIVE_BLOCK:
			block_hit_coord(x-1,y-1);
			block_hit_coord(x-1,y);
			block_hit_coord(x-1,y+1);
			block_hit_coord(x,y-1);
			*block = 0;
			block_hit_coord(x,y+1);
			block_hit_coord(x+1,y-1);
			block_hit_coord(x+1,y);
			block_hit_coord(x+1,y+1);
			break;
		case INDESTRUCTIBLE_BLOCK:
			break;
		case HARD_BLOCK_2:
			//block_setvalue(x,y,HARD_BLOCK_1);
			*block = HARD_BLOCK_1;
			break;
		case HARD_BLOCK_3:
			//block_setvalue(x,y,HARD_BLOCK_2);
			*block = HARD_BLOCK_2;
			break;
		case FAKE_BLOCK:
			//block_destroy(x,y);
			*block = 0;
		default:
			return 0;
			break;
	}
	block_draw(x,y);
	return 1;
}
