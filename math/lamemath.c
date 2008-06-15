#include "lamemath.h"

int z_lame_mod(int n, int denom) {
	while(n >= denom) n -= denom;
	return n;
}

int z_lame_div(int n, int denom) {
	int result = 0;
	while(n >= denom) n -=denom, result++;
	return result;
}
