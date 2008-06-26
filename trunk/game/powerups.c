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

enum POWERUPS {
	POWERUP_HEAVY = 1,
	POWERUP_REVEAL = 2,
	POWERUP_BOMB_BALLS = 4
} POWERUPSs;

unsigned char powerups;

void powerups_reset(void)
{
	powerups = 0;
}

char powerups_heavyball(void)
{
	return powerups & POWERUP_HEAVY;
}

char powerups_bombballs(void)
{
	return powerups & POWERUP_BOMB_BALLS;
}

char powerups_reveal(void)
{
	return powerups & POWERUP_REVEAL;
}

void powerup_spawn(void)
{
	char r;
	while(1) {
		r = rand()&7;
		if(r == 0 && powerups_heavyball()) {}
		else if(r == 1 && powerups_reveal()) {}
		else if(r == 2 && powerups_bombballs()) {}
		else if(r == 3 && paddle_ismaxwidth()) {}
		else if(r > 5) {}
		else break;
	}
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