#ifndef __GAMEINFO_H
#define __GAMEINFO_H

void gameinfo_init(void);
void gameinfo_livesincrease(int lives_increase);
void gameinfo_livesdecrease(int lives_decrease);
char gameinfo_getlives(void);
void gameinfo_scoreincrease(int score_increase);
void gameinfo_scoredecrease(int score_decrease);
void gameinfo_getscore(void);
char gameinfo_levelincrease(int level_increase);
char gameinfo_leveldecrease(int level_decrease);
char gameinfo_getlevel(void);
void gameinfo_drawinfo(void);

#endif
