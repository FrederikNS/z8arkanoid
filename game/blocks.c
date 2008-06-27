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
void block_explode_on(int x, int y);
char block_hit_coord_inner(int x, int y, char explode);

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
	HIT_INVISIBLE_BLOCK,  //9
	POWERUP_BLOCK		 //10
};

unsigned char blocks[BLOCKS_WIDTH*BLOCKS_HEIGHT];

//a counter which keeps track on the amount of blocks
//left in the current level.
int blocks_counter;

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

//returns the amount of blocks which has to be destroyed
//to go to the next level (or loop if you are on the last
//level, no-lifer)
int blocks_amount(void)
{
	return blocks_counter;
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
	blocks_counter = 0;
	for(i = 0; i < sizeof(blocks); i++) {
		blocks[i] = levels[lvl][i];
		//if the block is neither nothing, nor indestructible, then add it to the counter
		//which keeps track of how many blocks that are left until the next level
		if(levels[lvl][i] != NO_BLOCK &&
		  levels[lvl][i]!=INDESTRUCTIBLE_BLOCK)
			blocks_counter++;
	}
}

//Generates a random level. No real world applicatoin.
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
	//checks the coords against the boundaries of the blocks.
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

//a list of block colors, each index number corresponds to
//a block, as defined by the enum BLOCK_TYPES
const char blocks_colors[11] = {
	0,	2,	12,	1,	0,
	5,	8,	7,	15,	14,
	6
};

//a list of block symbols, each index number corresponds to
//a block, as defined by the enum BLOCK_TYPES
const char blocks_symbols[11] = {
	0x20,	0xDB,	0xB2,	0xDB,	0x20,
	0xCF,	0xDB,	0xDB,	0xDB,	0xDB,
	'*'
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

char block_hit(int x, int y)
{
	return block_hit_coord(x>>1,y);
}

/*
 Name: block_hit_coord
 Functionality: hits the block on the given coordinate.
 Returns: true if the block is/was solid enough to give bounce-back. Used for balls.
 Arguments:
 x, y: coordinates for the block in blockspace fixed point
 Note: block coords. block_hit_coord itself is actually just a wrapper function made
 	to be called only as the initial hit, and not my explosions and such,
 	in order to make the exploding ball powerup work as intended.
*/

char block_hit_coord(int x, int y)
{
	return block_hit_coord_inner(x, y, powerups_bombballs());
}

char block_hit_coord_inner(int x, int y, char explode)
{
	unsigned char* block = block_on(x, y);
	//keeps track of wether a ball which hits the block should collide.
	char collide = 1;
	//If the block is empty, or the coords are out of range,
	//there is no need for the ball to bounce off.
	if(!block || !*block) return 0;
	//act according to which block that was hit.
	//awards points, destroys and degrades blocks,
	//and changes the collide and explode variables
	//to implement the different features of each block.
	switch(*block){
		case REGULAR_BLOCK:
			*block = NO_BLOCK;
			gameinfo_scoreincrease(10);
			break;
		case EXPLOSIVE_BLOCK:
			*block = NO_BLOCK;
			explode = 1; //explode!
			gameinfo_scoreincrease(15);
			break;
		case INVISIBLE_BLOCK:
			*block = REGULAR_BLOCK;
			gameinfo_scoreincrease(20);
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
		case POWERUP_BLOCK:
			powerup_spawn();
			*block = NO_BLOCK;
			gameinfo_scoreincrease(10);
			break;
	}

	//heavy balls destroys everything
	if(powerups_heavyball()) {
		if(*block == INDESTRUCTIBLE_BLOCK) {
			//return before the block counter gets decreased
			//so that things don't fuck up
			gameinfo_scoreincrease(25);
			*block = NO_BLOCK;
			block_draw(x,y);
			return 0;
		}
		*block = NO_BLOCK;
	}
	//decrease the block counter if the block was destroyed
	//after being hit
	if(!*block) blocks_counter--;

	//redraw the block
	block_draw(x,y);

	//explode if necesarry!
	if(explode) block_explode_on(x, y);

	//if balls are heavy, nothing will collide with them.
	if(powerups_heavyball())
		return 0;

	//else return the normal collide var.
	return collide;
}

//hits all 8 blocks around the given coordinates,
void block_explode_on(int x, int y)
{
	block_hit_coord_inner(x - 1, y - 1, 0);
	block_hit_coord_inner(x - 1, y, 0);
	block_hit_coord_inner(x - 1, y + 1, 0);
	block_hit_coord_inner(x, y - 1, 0);
	//block_hit_coord_inner(x, y, 0);
	block_hit_coord_inner(x, y + 1, 0);
	block_hit_coord_inner(x + 1, y - 1, 0);
	block_hit_coord_inner(x + 1, y, 0);
	block_hit_coord_inner(x + 1, y + 1, 0);
}

//reveals all blocks by changing all invisible blocks
//to visible blocks.
void blocks_reveal_all(void)
{
	int i;
	for(i = 0; i < sizeof(blocks); i++)
		if(blocks[i] == INVISIBLE_BLOCK)
			blocks[i] = HIT_INVISIBLE_BLOCK;
	blocks_draw(); //update the blocks.
}
