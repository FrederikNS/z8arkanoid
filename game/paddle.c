#include "paddle.h"
#include "gameboard.h"
#include "../API/API.H"
#include "../HLI/HLI.h"

#define PADDLE_STARTWIDTH 13
#define PADDLE_MAXWIDTH 21
#define PADDLE_MINWIDTH 9
#define PADDLE_Y (GAMEFIELD_HEIGHT - 2)

//Keep the paddle data nice and tidy in a structure fpr itself
struct
{
	int x;
	int width;
} paddle;

//this function fixes the paddle's position in case it
//is out of range of what it should be.
void paddle_fixposition(void)
{
	if(paddle.x < 0)
		paddle.x = 0;
	if(paddle.x + paddle.width > GAMEFIELD_WIDTH)
		paddle.x = GAMEFIELD_WIDTH - paddle.width;
}

//returns true if the paddle is the maximum allowed width
char paddle_ismaxwidth(void)
{
	if(paddle.width == PADDLE_MAXWIDTH) return 1;
	return 0;
}

//increases the width of the paddle by two units.
void paddle_increasewidth(void)
{
	if(!paddle_ismaxwidth()) {
		paddle.width+=2;
		paddle.x -= 1; //center the paddle again.
		paddle_fixposition(); //make sure everything is within bounds.
	}
}

//decreases the width of the paddle by two units.
void paddle_decreasewidth(void)
{
	if(paddle.width > PADDLE_MINWIDTH) {
		//the sides of the paddles has to be removed graphically because
		//paddle_draw doesn't do this automatically.
		z_hyperterm_clearpoint(3 + paddle.x, 3 + PADDLE_Y);
		z_hyperterm_clearpoint(3 + paddle.x+paddle.width-1, 3 + PADDLE_Y);
		paddle.width-=2;
		paddle.x += 1; //centers the paddle
	}
}

//puts the paddle into its initial state
void paddle_reset(void)
{
	int i;
	//clear the old position off the screen
	z_hyperterm_goto(paddle.x + 3, PADDLE_Y + 3);
	for(i = 0; i < paddle.width; i++) z_hyperterm_put(' ');
	paddle.width = PADDLE_STARTWIDTH; //reset the width
	//put the paddle in the middle of the game field. Notice the fancy shifting tricks.
	paddle.x = (GAMEFIELD_WIDTH>>1) - (PADDLE_STARTWIDTH>>1); // x = center_x - width/2
}

void paddle_moveleft(void)
{
	//the paddle can only move left if it has space to move on.
	if(paddle.x > 0) {
		//clear the rightmost part of the paddle so that it
		//doesn't get left behind on the screen.
		z_hyperterm_put_on(' ', paddle.x+paddle.width+2, PADDLE_Y + 3);
		paddle.x--;
		//z_hyperterm_put_on('#', paddle.x+3, PADDLE_Y + 3);
	}
}

void paddle_moveright(void)
{
	//the paddle can only move left if it has space to move on.
	if(paddle.x + paddle.width < GAMEFIELD_WIDTH) {
		//clear the leftmost position to avoid screen artefacts.
		z_hyperterm_put_on(' ', paddle.x + 3, PADDLE_Y + 3);
		//z_hyperterm_put_on('#', paddle.x+paddle.width+3, PADDLE_Y + 3);
		paddle.x++;
	}
}

void paddle_draw(void)
{
	int i;
	z_hyperterm_goto(paddle.x + 3, PADDLE_Y + 3);
	z_hyperterm_setfgcolor(3);
	for(i = 0; i < paddle.width; i++) z_hyperterm_put('#');
}

//returns true if the given coordinates are inside the paddle.
char paddle_collision(int x, int y)
{
	//check the position against the bounds of the paddle
	if(y == PADDLE_Y && x >= paddle.x && x < paddle.x + paddle.width)
		return 1;
	return 0;
}

//same as the last function, but with fixed point arguments
char paddle_collision_fixed(int x, int y){
	return paddle_collision(x>>8,y>>8);
}

//returns the angle of the paddle for the given fixed point x position.
int paddle_getangle(int x) {
	//d is the diference between the center of the paddle and the given x position
	int d = x - (paddle.x << 8) - (paddle.width<<7);
	//interpolates the angle. Scaled and tweaked to get the optimal gameplay.
	return (d / paddle.width)>>3;
}
