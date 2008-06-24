#include "gameinfo.h"
#include "blocks.h"
#include "../API/API.h"
#include <stdio.h>
#define term_goto(line,column) z_hyperterm_goto(column,line)
#define ESC 0x1B
#define LEVEL_MAX 2
#define LEVEL_MIN 0
#define LIVES_MAX 10
#define LIVES_MIN 0
int score;
char lives;
char level;

void gameinfo_init(void){
	score = 0;
	lives = 2;
	level = 0;
	gameinfo_drawinfo();
}

void gameinfo_livesincrease(int lives_increase){
	lives += lives_increase;
	if(lives>LIVES_MAX) lives = LIVES_MAX;
	gameinfo_drawinfo();
}

void gameinfo_livesdecrease(int lives_decrease){
	lives -= lives_decrease;
	if(lives>LIVES_MIN) lives = LIVES_MIN;
	gameinfo_drawinfo();
}			  

char gameinfo_getlives(void){
	return lives;
}

void gameinfo_scoreincrease(int score_increase){
	score += score_increase;
	gameinfo_drawinfo();
}

void gameinfo_scoredecrease(int score_decrease){
	score -= score_decrease;
	gameinfo_drawinfo();
}

int gameinfo_getscore(void){
	return score;
}

char gameinfo_levelincrease(int level_increase){
	level += level_increase;
	if(level>LEVEL_MAX) level = LEVEL_MAX;
	gameinfo_drawinfo();
	return level;
}

char gameinfo_leveldecrease(int level_decrease){
	level -= level_decrease;
	if(level>LEVEL_MIN) level = LEVEL_MIN;
	gameinfo_drawinfo();
	return level;
}

char gameinfo_getlevel(void){
	return level;
}

void gameinfo_drawinfo(void) {
//Drawing the lives:
	term_goto(5,71);
	z_hyperterm_setfgcolor(9);
	printf("%d%c",lives,0x20);
//Drawing the score:
	term_goto(11,71);
	z_hyperterm_setfgcolor(10);
	printf("%d%c",score,0x20);
//Drawing the level:
	term_goto(17,71);
	z_hyperterm_setfgcolor(12);
	printf("%d%c",level+1,0x20);
}
