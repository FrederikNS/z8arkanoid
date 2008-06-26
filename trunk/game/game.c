#include "../API/API.h"
#include "../HLI/HLI.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef GBA
#include "../../lglib/lglib.h"
#endif

void game_loadlevel(char l);

void game_init()
{
	gameinfo_init();
	game_loadlevel(0);
#ifdef GBA
	while(!KEYPRESS_START);
#endif

}

void game_loadlevel(char l) {
	paddle_reset();
	balls_init();
	gameboard_draw();
	gameinfo_drawinfo();
	blocks_loadlevel(l);
	blocks_draw();
	balls_spawnnew_random_upwards(30,17,(1<<3)+l);
	gameinfo_drawinfo();
	powerups_reset();
}


char game_mainloop(void)
{
	static char needsinit = 1;
	if(needsinit) { game_init(); needsinit = 0; }

	if(z_button_right()) paddle_moveright();
	if(z_button_left()) paddle_moveleft();
	if(z_button_middle()) {
		powerup_spawn();
	}
#ifdef GBA
	if(KEYPRESS_DOWN) paddle_decreasewidth();
#endif
	balls_move_and_collide();
	balls_draw();
	paddle_draw();
	if(blocks_amount() <= 0) {
		gameinfo_levelincrease(1);
		game_loadlevel(gameinfo_getlevel());
	}
	return 0; //The game is not done
}
