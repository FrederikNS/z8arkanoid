#include "board.h"

//Does not work, fuckings to the precompiler
//unsigned char board[BOARD_WIDTH*BOARD_HEIGHT*2/8];
unsigned char board[500];

void board_clear(void) {
	int i;
	for(i = 0; i < sizeof(board); i++) board[i] = 0;
}

void board_build_walls(void) {
}