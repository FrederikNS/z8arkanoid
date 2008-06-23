#include "gameinfo.h"
#include "../API/API.h"
#define term_goto(line,column) z_hyperterm_goto(column,line)
#define ESC 0x1B
#include <stdio.h>
int score;
int lives;
int level;

void gameinfo_init(void){
score = 0;
lives = 2;
level = 2;
gameinfo_drawinfo();
}

void gameinfo_livesincrease(int lives_increase){
	lives += lives_increase;
	gameinfo_drawinfo();
}

void gameinfo_livesdecrease(int lives_decrease){
	lives -= lives_decrease;
	gameinfo_drawinfo();
	z_hyperterm_put(' ');
}			  

int gameinfo_getlives(void){
	return lives;
}

void gameinfo_scoreincrease(int score_increase){
	score += score_increase;
	gameinfo_drawinfo();
}

void gameinfo_scoredecrease(int score_decrease){
	score -= score_decrease;
	gameinfo_drawinfo();
	z_hyperterm_put(' ');
}

int gameinfo_levelincrease(int level_increase){
	level += level_increase;
	gameinfo_drawinfo();
	return level;
}

int gameinfo_leveldecrease(int level_decrease){
	level -= level_decrease;
	gameinfo_drawinfo();
	z_hyperterm_put(' ');
	return level;
}

int gameinfo_getlevel(void){
	return level;
}

void gameinfo_drawinfo(void) {
//Drawing the lives:
	term_goto(5,71);
	z_hyperterm_setfgcolor(9);
	printf("%d",lives);
//Drawing the score:
	term_goto(11,71);
	z_hyperterm_setfgcolor(10);
	printf("%d",score);
//Drawing the level:
	term_goto(17,71);
	z_hyperterm_setfgcolor(12);
	printf("%d",level);
}
