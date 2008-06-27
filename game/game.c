#include "../API/API.h"
#include "../HLI/HLI.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef GBA
#include "../../lglib/lglib.h"
#endif

//prototypes for local functions.

void game_loadlevel(char l);
void game_printfailure(void);


//initializes the game
void game_init()
{
	gameinfo_init();
	game_loadlevel(0);
	gameboard_draw();
}

//restarts a level after death
void game_restartlevel(void)
{
	z_hyperterm_formatreset();
	paddle_reset();
	balls_init();
	gameinfo_drawinfo();
	blocks_draw();
	balls_spawnnew_random_upwards(30,17,(1<<3)+gameinfo_getlevel());
	powerups_reset();
#ifndef GBA
	DI();
	z_timer_start(0xC0, 1);
	EI();
#endif
}

//loads and initializes a new level.
void game_loadlevel(char l) {
	blocks_loadlevel(l);
	game_restartlevel();
}

void game_mainloop(void)
{
	game_init(); //initialize the game
	while(1)
	{
		//move right if the right button is pushed
		if(z_button_right()) paddle_moveright();
		//move left if the left button is pushed
		if(z_button_left()) paddle_moveleft();

		//move and collide all balls
		balls_move_and_collide();

		//draw all balls
		balls_draw();

		//draw the paddle
		paddle_draw();

		//if there are no blocks left, go to the next level
#ifdef GBA
		if(blocks_amount() <= 0 || KEYPRESS_SELECT)
#else
		if(blocks_amount() <= 0)
#endif
		{
			gameinfo_levelincrease(1);
			game_loadlevel(gameinfo_getlevel());
		}
		//if there are no balls left, die!
		else if(balls_amount() <= 0)
		{
			gameinfo_livesdecrease(1);
			gameinfo_drawinfo(); //redraw the scoreboard
			if(gameinfo_getlives() <= 0) break;
			game_printfailure(); //notice the player that he sucks!
			game_restartlevel(); //restar the level
		}
#ifdef GBA
		IntrVBlankWait();
#else
		z_timer_makebusy();
		while(z_timer_isbusy()) rand();
#endif
	}
}

//Nice ANSI graphics generated with Photoshop and Ascgen dotNet

const char youfail[10][66] = {
"    QQQQQQQQQ:       fQQp          LQQ      iQQ            QQM  ",
"    QQ.             QQ.:QQ         7QQ      iQQ            EQp  ",
"    QQ.            7QQ  QQY        LQQ      :QQ            0Qh  ",
"    QQQQQQQQQ      QQ    QQ        7QQ      :QQ            FQj  ",
"    QQY.:iir:     DQQSED2QQQ       LQQ      :QQ            SQf  ",
"    QQ.          .QQcF9Sh7QQr      7QQ      :QQ            :Q:  ",
"    QQi          QQc      LQQ      cQQ      :QQ             ,   ",
"    QQc         QQQ        QQQ     tQQ      7QQQQQQQQQ,    QQQ  ",
"    rL,         7L,        ,7Y     .rr      ,7iLLYLJJt     7hr  ",
"                         (PRESS MIDDLE)                         ",
};

//prints a failure message to the screen and awaits user input
void game_printfailure(void)
{
	int i, y, d;

	z_hyperterm_formatreset();
	z_hyperterm_setfgcolor(15);
	z_hyperterm_setbgcolor(1);

	//this loop draws the message on the screen.
	//it looks animated because it is so horribly slow
	for(i = 0; i < 41; i++) {
		for(y = 0; y < 10; y++) {
			d = y - 8 + i;
			if(y >= 5) d = 10 - y - 8 + i;
			if(d >= 0 && d < 32) {
				z_hyperterm_put_on(youfail[y][32 + d], 32 + d + 3, 3 + y);
				z_hyperterm_put_on(youfail[y][31 - d], 31 - d + 3, 3 + y);
			}
		}
#ifdef GBA
		IntrVBlankWait();
#endif
	}
	while(!z_button_middle());
}
