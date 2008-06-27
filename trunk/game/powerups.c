#include <stdlib.h>
#include "paddle.h"
#include "ball.h"
#include "blocks.h"
#include "gameinfo.h"

/*
POWERS:
0 heavy balls
1 reveal hidden blocks
2 bomb balls
3 increase width
4 split
5 extra life
*/

//This variable is a tiny bitfield which keeps track of which powerups that are running.
unsigned char powerups;
//enums defining the bitfield
enum POWERUPS {
	POWERUP_HEAVY = 1,
	POWERUP_REVEAL = 2,
	POWERUP_BOMB_BALLS = 4
} POWERUPSs;

//Resets all powerups by clearing all bits in the bitfield
void powerups_reset(void)
{
	powerups = 0;
}

//returns true if the powerup "heavy ball" is active
char powerups_heavyball(void)
{
	return powerups & POWERUP_HEAVY;
}

//returns true if the powerup "bomb balls" is active
char powerups_bombballs(void)
{
	return powerups & POWERUP_BOMB_BALLS;
}

//returns true if the powerup "reveal all hidden blocks" has been fired in this level
char powerups_reveal(void)
{
	return powerups & POWERUP_REVEAL;
}

//spawns a new, random powerup
void powerup_spawn(void)
{
	char r;
	//this loop keeps generating a new random powerup index until it isn't either
	//a) out of range, or
	//b) the index of a powerup which can only be fired once per level,
	//which has already been fired.
	while(1) {
		r = rand()&7;
		if(r == 0 && powerups_heavyball()) {}
		else if(r == 1 && powerups_reveal()) {}
		else if(r == 2 && powerups_bombballs()) {}
		else if(r == 3 && paddle_ismaxwidth()) {}
		else if(r > 5) {}
		else break;
	}
	//put the new powerup in play. r corresponds to a number from the list in
	//the beginning of the file.
	if(r == 0) powerups |= POWERUP_HEAVY;
	else if(r == 1) {
		powerups |= POWERUP_REVEAL;
		blocks_reveal_all();
	}
	else if(r == 2) powerups |= POWERUP_BOMB_BALLS;
	else if(r == 3) paddle_increasewidth();
	else if(r == 4) balls_split();
	else if(r == 5) gameinfo_livesincrease(1);
}