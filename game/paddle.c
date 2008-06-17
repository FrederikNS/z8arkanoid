#include "paddle.h"

struct {
	int x;
	int y;
} paddle;

int paddle_getx(void) {
	return paddle.x;
}

int paddle_gety(void) {
	return paddle.y;
}

int paddle_movehorizontally(int value) 
{
}
