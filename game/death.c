#include "../api/api.h"
#ifndef GBA
#include <ez8.h>
#include "../hli/timer.h"
#else
#include "../../lglib/lglib.h"
#endif
#include "../hli/button.h"

const char skull[25][67] = {
"                              ..i:rrr,                  :Ji       ",
"      ,,,,               ,iYfccJr:::rJtfi,            iU,,hr.     ",
"    7977LRQ.           7Qfi,           .7PZc         7Q     ,cE   ",
"    Q :,  ,Qr         RX                   QR      .SM    LMU.Q7  ",
"   Sp       X0c:    ,Q:                     iQ   rhY,    1Q  YQ   ",
"   QL         :hMP. Qi                      .fRiJi     ,71:.rQ:   ",
"    2FQQQX7,     :tQ:i                    .,2:Ri   :JQDM:,:r7     ",
"      ,:.r2QQU:    Q pj                    ::hPb,LQQf:            ",
"            ,iXQDr,Q  R               ,, .,9rF,QQL.               ",
"                ,iYQ: Q:. .  .      ::..  .QPMUF                  ",
"                   .Q9Q  LQQQQf JrJ  RQQQE  QfQ                   ",
"                    QQL QQQQQQQXJQQ QQQQQQQ hQh                   ",
"                   QXM, QQQQQQQpr cRQQQQQQQ  QQF                  ",
"                   .Q    iPZMU    rc.rjLQL   ,Q                   ",
"                    JQ1   .,., :QMQL i,     :Q                    ",
"                 ifh. McQQh1,. QQ.QQ,.PJihMQQhEr.                 ",
"              :jFi     rQQ R7  rr2D0. ,QQQSQQi,,7fL.              ",
"          ,:j17.    .j7:QY,F,    r.    :00QDQL    ,:77:           ",
"    .7YrJcfL.     79X:  p.,SQ2.Y:jrirjLUJSY  Uj:     ,Lt7:.,      ",
"  7R7..,       iphr    .Q .f7Uf1FtYJPJYQ.QQ   ,LSY:     .irii7J   ",
" iQ          J0Y.       ,1.     :, .,:i ,Q:      .LPL      .h cQ. ",
" :Q .7 r.  :Qj            hS:         .j1           i1S    p: rYXr",
"  ,SQ 7j ,DQ,              ,rf2J:::rLtL.              QQ    ,   Q:",
"    YFrUQR7                    :i:ii.                  pthEPp:7Sr ",
"      ,.                                                  L:...   "};

const char gameover[] = "GAMEOVER, LAMER!";

void death(void)
{
	int x, y;
	z_hyperterm_clear();
	z_hyperterm_formatreset();
	z_hyperterm_setfgcolor(3);

	for(x = 0; x < 66; x++) {
		for(y = 0; y < 25; y++) {
			if(y&1)
				z_hyperterm_put_on(skull[y][65-x], 65-x + 7, y);
			else
				z_hyperterm_put_on(skull[y][x], x + 7, y);
		}
	}

	z_hyperterm_setfgcolor(7+8);
#ifndef GBA
	DI();
	z_timer_start(0x800, 5);
	EI();
#endif
	z_hyperterm_goto(40-8, 6);
	for(x = 0; x < 16; x++) {
		z_hyperterm_put(gameover[x]);
#ifndef GBA
		z_timer_makebusy();
		while(z_timer_isbusy());
#else
		IntrVBlankWait();
#endif
	}
	z_hyperterm_goto(40-12, 25);
	z_hyperterm_blinkslow();
	z_hyperterm_putstring("PRESS MIDDLE TO CONTINUE");
	while(!z_button_middle());
}


