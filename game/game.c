#include "../API/API.h"
#include "../HLI/HLI.h"
#include "game.h"

#include <stdlib.h>
#include <stdio.h>

#ifdef GBA
#include "../../lglib/lglib.h"
#endif

/*
load level
run gameloop
*/


void game_init()
{
	int i;
	paddle_reset();
	balls_init();
	z_hyperterm_formatreset();
	z_hyperterm_setbgcolor(0);
	z_hyperterm_clear();
	gameboard_draw();
	//gameboard_draw_highscore();
	z_hyperterm_goto(0, 0);
	blocks_loadlevel(0);
	blocks_draw();

	for(i = 0; i < 1; i++)
		balls_spawnnew_random_upwards(30,17);
#ifdef GBA
	while(!KEYPRESS_START);
#endif

}

char game_mainloop(void)
{
	static char needsinit = 1;
	if(needsinit) { game_init(); needsinit = 0; }

	if(z_button_right()) paddle_move(1);
	if(z_button_left()) paddle_move(-1);
	if(z_button_middle()) paddle_increasewidth();
	balls_move_and_collide();
	balls_draw();
	paddle_draw();

	return 0; //The game is not done
}
