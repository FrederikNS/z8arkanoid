#include "../API/API.h"
#include "../HLI/HLI.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef GBA
#include "../../lglib/lglib.h"
#endif

void game_loadlevel(char l);
void game_printfailure(void);

void game_init()
{
	z_hyperterm_formatreset();
	gameinfo_init();
	game_loadlevel(0);
#ifdef GBA
	while(!KEYPRESS_START);
#endif
}

void game_restartlevel(void)
{
	paddle_reset();
	balls_init();
	gameboard_draw();
	gameinfo_drawinfo();
	blocks_draw();
	balls_spawnnew_random_upwards(30,17,(1<<3)+gameinfo_getlevel());
	powerups_reset();
}

void game_loadlevel(char l) {
	paddle_reset();
	balls_init();
	gameboard_draw();
	gameinfo_drawinfo();
	blocks_loadlevel(l);
	blocks_draw();
	balls_spawnnew_random_upwards(30,17,(1<<3)+l);
	powerups_reset();
	DI();
	z_timer_start(0xC0, 1);
	EI();
}

extern void death_drawskull(void);

void game_mainloop(void)
{
	game_init();
	while(1)
	{
		if(z_button_right()) paddle_moveright();
		if(z_button_left()) paddle_moveleft();
		if(z_button_middle()) powerup_spawn();

		balls_move_and_collide();
		balls_draw();
		paddle_draw();

		if(blocks_amount() <= 0)
		{
			gameinfo_levelincrease(1);
			game_loadlevel(gameinfo_getlevel());
		}

		if(balls_amount() <= 0)
		{
			gameinfo_livesdecrease(1);
			if(gameinfo_getlevel() <= 0) break;
			game_printfailure();
			game_restartlevel();
		}
		z_timer_makebusy();
		while(z_timer_isbusy()) z_ledfb_write();
	}
}

const char youfail[15][66] = {
"                                                                ",
"                                                                ",
"                                                                ",
"    QQQQQQQQQ:       fQQp          LQQ      iQQ            QQM  ",
"    QQU.::::i       ,QQQQ.         UQQ      iQQ            QQQ  ",
"    QQ.             QQ.:QQ         7QQ      iQQ            EQp  ",
"    QQ.            7QQ  QQY        LQQ      :QQ            0Qh  ",
"    QQQQQQQQQ      QQ    QQ        7QQ      :QQ            FQj  ",
"    QQY.:iir:     DQQSED2QQQ       LQQ      :QQ            SQf  ",
"    QQ.          .QQcF9Sh7QQr      7QQ      :QQ            :Q:  ",
"    QQi          QQc      LQQ      cQQ      :QQ             ,   ",
"    QQc         QQQ        QQQ     tQQ      7QQQQQQQQQ,    QQQ  ",
"    rL,         7L,        ,7Y     .rr      ,7iLLYLJJt     7hr  ",
"                                                                ",
"                         (PRESS MIDDLE)                         ",
};

void game_printfailure(void)
{
	int i, y, d;

	DI();
	z_timer_start(0x100, 4);
	EI();

	z_hyperterm_clear();
	z_hyperterm_put_on('!', 1, 1);
	z_hyperterm_formatreset();
	z_hyperterm_setfgcolor(15);
	z_hyperterm_setbgcolor(1);

	for(i = 0; i < 41; i++) {
		for(y = 0; y < 15; y++) {
			d = y - 8 + i;
			if(y >= 8) d = 15 - y - 8 + i;
			if(d >= 0 && d < 32) {
				z_hyperterm_put_on(youfail[y][34 + d], 34 + d + 3, 3 + y);
				z_hyperterm_put_on(youfail[y][33 - d], 33 - d + 3, 3 + y);
			}
		}
	}
	while(!z_button_middle());
}