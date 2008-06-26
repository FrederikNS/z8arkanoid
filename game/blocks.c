//#include "blocks.h"
#include "../API/API.h"
#include "levels.h"
#include "gameinfo.h"
#include "powerups.h"
#include <stdlib.h> //Used for randomization

/*
 Local constants, fields and function prototypes
 */

char block_coords_in_area(int x, int y);
unsigned char* block_on(int x, int y);
void block_draw(int x, int y);
char block_hit_coord(int x, int y);

enum BLOCK_TYPES {
	NO_BLOCK,            //0
	FAKE_BLOCK,          //1
	REGULAR_BLOCK,       //2
	EXPLOSIVE_BLOCK,     //3
	INVISIBLE_BLOCK,     //4
	INDESTRUCTIBLE_BLOCK,//5
	HARD_BLOCK_1,        //6
	HARD_BLOCK_2,        //7
	HARD_BLOCK_3,        //8
	HIT_INVISIBLE_BLOCK  //9
};

unsigned char blocks[BLOCKS_WIDTH*BLOCKS_HEIGHT];

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

int blocks_counter;

int blocks_amount(void)
{
	return blocks_counter;
}

void blocks_loadlevel(int lvl) {
	int i;
	blocks_counter = 0;
	for(i = 0; i < sizeof(blocks); i++) {
		blocks[i] = levels[lvl][i];
		if(levels[lvl][i] != NO_BLOCK && levels[lvl][i]!=INDESTRUCTIBLE_BLOCK) blocks_counter++;
	}
}

void blocks_randomizedlevel(void) {
	int i;
	for(i=0;i<BLOCKS_WIDTH*BLOCKS_HEIGHT;i++){
		blocks[i] = rand()&7;
		if(blocks[i] == 6) blocks[i] = 8;
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
/*
 Name: block_draw
 Functionality: Draws the block on the given coordinates to the screen.
 Arguments:
 x, y: coordinates in block coords.
 Note: block coords
 */

char blocks_colors[10] = {
	0,	2,	12,	1,	0,
	5,	8,	7,	15,	14
};

char blocks_symbols[10] = {
	0x20,	0xDB,	0xB2,	0xDB,	0x20,
	0xCF,	0xDB,	0xDB,	0xDB,	0xDB,
};

void block_draw(int x, int y) {
	unsigned char val = *block_on(x,y);
	z_hyperterm_goto((x<<1)+3,y+3);
	z_hyperterm_setfgcolor(blocks_colors[val]);
	z_hyperterm_put(blocks_symbols[val]);
	z_hyperterm_put(blocks_symbols[val]);
}

/*
 Name: blocks_draw
 Functionality: Draws all blogs to the screen
 */

void blocks_draw(void) {
	int x;
	int y;
	unsigned char* b = block_on(0, 0);
	for(y = 0; y < BLOCKS_HEIGHT; y++) {
		z_hyperterm_goto(3,y+3);
		for(x = 0; x < BLOCKS_WIDTH; x++, b++) {
			z_hyperterm_setfgcolor(blocks_colors[*b]);
			z_hyperterm_put(blocks_symbols[*b]);
			z_hyperterm_put(blocks_symbols[*b]);
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


char block_hit_fixed(int x, int y) {
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
	char collide = 1;
	if(!block || !*block) return 0; //Either the block is empty, or the coords are out of range, so no need for the ball to bounce off.
	switch(*block){
		case REGULAR_BLOCK:
			*block = NO_BLOCK;
			gameinfo_scoreincrease(10);
			break;
		case EXPLOSIVE_BLOCK:
			*block = NO_BLOCK;
			block_explode_on(x, y);
			break;
		case INVISIBLE_BLOCK:
			*block = REGULAR_BLOCK;
			break;
		case HARD_BLOCK_1:
			gameinfo_scoreincrease(15);
			*block = NO_BLOCK;
			break;
		case INDESTRUCTIBLE_BLOCK:
			break;
		case HARD_BLOCK_2:
			*block = HARD_BLOCK_1;
			gameinfo_scoreincrease(20);
			break;
		case HARD_BLOCK_3:
			*block = HARD_BLOCK_2;
			gameinfo_scoreincrease(30);
			break;
		case HIT_INVISIBLE_BLOCK:
			*block = NO_BLOCK;
			gameinfo_scoreincrease(10);
			break;
		case FAKE_BLOCK:
			*block = NO_BLOCK;
			block_draw(x,y);
			gameinfo_scoreincrease(10);
			collide = 0;
			break;
	}

	if(powerups_heavyball()) {
		if(*block == INDESTRUCTIBLE_BLOCK) {
			gameinfo_scoreincrease(25);
			*block = NO_BLOCK;
			block_draw(x,y);
			return 0;
		}
		*block = NO_BLOCK;
	}

	if(!*block) blocks_counter--;
	block_draw(x,y);

	if(powerups_heavyball())
		return 0;

	return collide;
}

void block_explode_on(int x, int y)
{
	block_hit_coord(x-1,y-1);
	block_hit_coord(x-1,y);
	block_hit_coord(x-1,y+1);
	block_hit_coord(x,y-1);
	block_hit_coord(x,y);
	block_hit_coord(x,y+1);
	block_hit_coord(x+1,y-1);
	block_hit_coord(x+1,y);
	block_hit_coord(x+1,y+1);
}

void blocks_reveal_all(void)
{
	int i;
	for(i = 0; i < sizeof(blocks); i++)
		if(blocks[i] == INVISIBLE_BLOCK)
			blocks[i] = HIT_INVISIBLE_BLOCK;
	blocks_draw();
}

/*
void block_draw(int x, int y) {
	z_hyperterm_goto((x<<1)+3,y+3);
	switch(*block_on(x,y)){
		case INVISIBLE_BLOCK:
		case NO_BLOCK:
			z_hyperterm_setfgcolor(0);
			z_hyperterm_put(0x20);
			z_hyperterm_put(0x20);
			break;
		case FAKE_BLOCK:
			z_hyperterm_setfgcolor(2);
			z_hyperterm_put(0xDB);
			z_hyperterm_put(0xDB);
			break;
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
			z_hyperterm_setfgcolor(5);
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
		case HIT_INVISIBLE_BLOCK:
			z_hyperterm_setfgcolor(14);
			z_hyperterm_put(0xDB);
			z_hyperterm_put(0xDB);
			break;
	}
}
*/

/*
char hitmutationtable[10] =
{
	NO_BLOCK,				//No block turns into no block
	NO_BLOCK,				//Fake blocks just disappear too
	NO_BLOCK,				//Same for regular blocks
	NO_BLOCK,				//guess what happens to explosive blocks!
	HIT_INVISIBLE_BLOCK,	//Invisible blocks go visible
	INDESTRUCTIBLE_BLOCK,	//Indestructable blocks stay... indestructable!
	NO_BLOCK,				//Hard block 1 becomes no block
	HARD_BLOCK_1,			//Hard block 2 becomes 1
	HARD_BLOCK_2,			//Oi, there's a system! Hard block 3 becomes hard block 2
	NO_BLOCK,				//Previously invisible blocks end their lives here
};

char hitcollision[10] =
{
	0, 0, 1, 1, 1,
	1, 1, 1, 1, 1,
};


char block_hit_coord(int x, int y) {
	unsigned char* block = block_on(x, y);
	unsigned char oldval;
	if(!block) return 0;
	if(!*block) return 0;

	oldval = *block;

	*block = hitmutationtable[*block];
	if(oldval == EXPLOSIVE_BLOCK) {
		block_hit_coord(x-1,y-1);
		block_hit_coord(x-1,y);
		block_hit_coord(x-1,y+1);
		block_hit_coord(x,y-1);
		block_hit_coord(x,y+1);
		block_hit_coord(x+1,y-1);
		block_hit_coord(x+1,y);
		block_hit_coord(x+1,y+1);
	}
//	if(!*block)
//		--blocks_counter;
	block_draw(x,y);
	return hitcollision[oldval];
}*/