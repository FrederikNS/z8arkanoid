#include "gameboard.h"
#include "../API/API.h"
#include <sio.h>
#define term_goto(line,column) z_hyperterm_goto(column,line)
/*
 *This class is dedicated to draw the initial gameboard and highscore list. 
 *It is after the initiation not to be changed.
 *The rest happens in the blank space.
 *The gameboard is drawn using ASCII art, putting the small pieces together as a frame.
 *
 *Hyperterm size is: 80x23
 *Game area size is: 64x21
 *Game area starts at column 3, ends in column 66. No further.
 *It spans from line 3 to 23. No further.
 *
 *The highscore size is 28x20
 *The name entering area starts from column 27, line 6, and goes 14 lines down to line 20.
 *The name entering area supports five characters, no more.
 *The score area begins at column 37, line 6 and likewise goes 14 lines down to line 20.
 *The score area supports 9 digits, no more.
 *
 *The scoreboard in the right side:
 *Lives count starts at column 69 and ends in column 79. No further.
 *It spans from line 4 to 6. No further.
 *
 *Score count starts at column 69 and ends in column 79. No further.
 *It spans from line 10 to 12. No further.
 *
 *Level count starts at column 60 and ends in column 79. No further.
 *It spans from line 16 to 18. No further.
 */


void gameboard_draw(void) {
	int i;
//Background color, black
	z_hyperterm_setbgcolor(0);
//First line:
	//ReflexBall text, red
	z_hyperterm_setfgcolor(9);
	term_goto(1,30); z_hyperterm_putstring("ReflexBall");
	//Set border colors to purple
	z_hyperterm_setfgcolor(5);
	//Left top cornerpiece
	term_goto(1,1); z_hyperterm_put(0xC9);
	//Leftwards Splitter
	term_goto(1,29); z_hyperterm_put(0xB9);
	//Rightwards Splitter
	term_goto(1,40); z_hyperterm_put(0xCC);
	//Straight line piece
	for(i=0; i<=26; i++) {
		term_goto(1,2+i);
		z_hyperterm_put(0xCD);
	}
	for(i=0; i<=26; i++) {
		term_goto(1,41+i);
		z_hyperterm_put(0xCD);
	}
	term_goto(1,69); z_hyperterm_put(0xCD);
	term_goto(1,70); z_hyperterm_put(0xCD);
	for(i=0;i<=4;i++){
		term_goto(1,72+i);
		z_hyperterm_put(0xCD);
	}
	term_goto(1,78); z_hyperterm_put(0xCD);
	term_goto(1,79); z_hyperterm_put(0xCD);
	//Downwards Splitter
	term_goto(1,68); z_hyperterm_put(0xCB);
	term_goto(1,71); z_hyperterm_put(0xCB);
	term_goto(1,77); z_hyperterm_put(0xCB);
	//Right top corner
	term_goto(1,80); z_hyperterm_put(0xBB);
//Second line:
	//Lives text, red
	z_hyperterm_setfgcolor(9);
	term_goto(2,72); z_hyperterm_putstring("LIVES");
	//Set border colors, purple
	z_hyperterm_setfgcolor(5);
	//Vertical line piece
	for(i=0; i<=20; i++) {
		term_goto(2+i,1);
		z_hyperterm_put(0xBA);
	}
	//Left top cornerpiece
	term_goto(2,2); z_hyperterm_put(0xC9);
	//Upwards Splitter
	term_goto(2,29); z_hyperterm_put(0xCA);
	term_goto(2,40); z_hyperterm_put(0xCA);
	//Rightwards Splitter
	term_goto(2,68); z_hyperterm_put(0xCC);
	term_goto(2,77); z_hyperterm_put(0xCC);
	//Right top corner
	term_goto(2,67); z_hyperterm_put(0xBB);
	//Straight line piece
	for(i=0; i<=25; i++) {
		term_goto(2,3+i);
		z_hyperterm_put(0xCD);
	}
	for(i=0; i<=9; i++) {
		term_goto(2,30+i);
		z_hyperterm_put(0xCD);
	}
	for(i=0; i<=25; i++) {
		term_goto(2,41+i);
		z_hyperterm_put(0xCD);
	}
	term_goto(2,69); z_hyperterm_put(0xCD);
	term_goto(2,70); z_hyperterm_put(0xCD);
	term_goto(2,78); z_hyperterm_put(0xCD);
	term_goto(2,79); z_hyperterm_put(0xCD);
	//Leftwards Splitter
	term_goto(2,71); z_hyperterm_put(0xB9);
	term_goto(2,80); z_hyperterm_put(0xB9);
//Third Line:
	//Vertical line piece
	for(i=0; i<=19; i++) {
		term_goto(3+i,2);
		z_hyperterm_put(0xBA);
	}
	for(i=0; i<=19; i++) {
		term_goto(3+i,67);
		z_hyperterm_put(0xBA);
	}
	//Straight line piece
	term_goto(3,69); z_hyperterm_put(0xCD);
	term_goto(3,70); z_hyperterm_put(0xCD);
	for(i=0;i<=4;i++){
		term_goto(3,72+i);
		z_hyperterm_put(0xCD);
	}
	term_goto(3,78); z_hyperterm_put(0xCD);
	term_goto(3,79); z_hyperterm_put(0xCD);
	//Rightwards Splitter
	term_goto(3,68); z_hyperterm_put(0xCC);
	//Upwards Splitter
	term_goto(3,71); z_hyperterm_put(0xCA);
	term_goto(3,77); z_hyperterm_put(0xCA);
	//Leftwards Splitter
	term_goto(3,80); z_hyperterm_put(0xB9);
//Fourth Line:
	//Vertical line piece
	for(i=0; i<=2; i++) {
		term_goto(4+i,68);
		z_hyperterm_put(0xBA);
	}
	for(i=0; i<=2; i++) {
		term_goto(4+i,80);
		z_hyperterm_put(0xBA);
	}
//Seventh line:
	//Rightwards Splitter
	term_goto(7,68); z_hyperterm_put(0xCC);
	//Downwards Splitter
	term_goto(7,71); z_hyperterm_put(0xCB);
	term_goto(7,77); z_hyperterm_put(0xCB);
	//Straight line piece
	term_goto(7,69); z_hyperterm_put(0xCD);
	term_goto(7,70); z_hyperterm_put(0xCD);
	for(i=0;i<=4;i++){
		term_goto(7,72+i);
		z_hyperterm_put(0xCD);
	}
	term_goto(7,78); z_hyperterm_put(0xCD);
	term_goto(7,79); z_hyperterm_put(0xCD);
	//Leftwards Splitter
	term_goto(7,80); z_hyperterm_put(0xB9);
//Eighth Line:
	//Score text, green
	z_hyperterm_setfgcolor(10);
	term_goto(8,72); z_hyperterm_putstring("SCORE");
	//Set border colors, purple
	z_hyperterm_setfgcolor(5);
	//Rightwards Splitter
	term_goto(8,68); z_hyperterm_put(0xCC);
	term_goto(8,77); z_hyperterm_put(0xCC);
	//Straight line piece
	term_goto(8,69); z_hyperterm_put(0xCD);
	term_goto(8,70); z_hyperterm_put(0xCD);	
	term_goto(8,78); z_hyperterm_put(0xCD);
	term_goto(8,79); z_hyperterm_put(0xCD);
	//Leftwards Splitter
	term_goto(8,71); z_hyperterm_put(0xB9);
	term_goto(8,80); z_hyperterm_put(0xB9);
//Ninth Line:
	//Rightwards Splitter
	term_goto(9,68); z_hyperterm_put(0xCC);
	//Straight line piece
	term_goto(9,69); z_hyperterm_put(0xCD);
	term_goto(9,70); z_hyperterm_put(0xCD);
	for(i=0;i<=4;i++){
		term_goto(9,72+i);
		z_hyperterm_put(0xCD);
	}
	term_goto(9,78); z_hyperterm_put(0xCD);
	term_goto(9,79); z_hyperterm_put(0xCD);
	//Upwards Splitter
	term_goto(9,71); z_hyperterm_put(0xCA);
	term_goto(9,77); z_hyperterm_put(0xCA);
	//Leftwards Splitter
	term_goto(9,80); z_hyperterm_put(0xB9);
//Tenth Line:
	//Vertical line piece
	for(i=0; i<=2; i++) {
		term_goto(10+i,68);
		z_hyperterm_put(0xBA);
	}
	for(i=0; i<=2; i++) {
		term_goto(10+i,80);
		z_hyperterm_put(0xBA);
	}
//Eleventh Line:
//Twelfth Line:
//Thirteenth Line:
	//Rightwards Splitter
	term_goto(13,68); z_hyperterm_put(0xCC);
	//Downwards Splitter
	term_goto(13,71); z_hyperterm_put(0xCB);
	term_goto(13,77); z_hyperterm_put(0xCB);
	//Straight line piece
	term_goto(13,69); z_hyperterm_put(0xCD);
	term_goto(13,70); z_hyperterm_put(0xCD);
	for(i=0;i<=4;i++){
		term_goto(13,72+i);
		z_hyperterm_put(0xCD);
	}
	term_goto(13,78); z_hyperterm_put(0xCD);
	term_goto(13,79); z_hyperterm_put(0xCD);
	//Leftwards Splitter
	term_goto(13,80); z_hyperterm_put(0xB9);
//Fourteenth Line:
	//Level text, blue
	z_hyperterm_setfgcolor(12);
	term_goto(14,72); z_hyperterm_putstring("LEVEL");
	//Set border colors, purple
	z_hyperterm_setfgcolor(5);
	//Rightwards Splitter
	term_goto(14,68); z_hyperterm_put(0xCC);
	term_goto(14,77); z_hyperterm_put(0xCC);
	//Straight line piece
	term_goto(14,69); z_hyperterm_put(0xCD);
	term_goto(14,70); z_hyperterm_put(0xCD);
	term_goto(14,78); z_hyperterm_put(0xCD);
	term_goto(14,79); z_hyperterm_put(0xCD);
	//Leftwards Splitter
	term_goto(14,71); z_hyperterm_put(0xB9);
	term_goto(14,80); z_hyperterm_put(0xB9);
//Fifteenth Line:
	//Rightwards Splitter
	term_goto(15,68); z_hyperterm_put(0xCC);
	//Straight line piece
	term_goto(15,69); z_hyperterm_put(0xCD);
	term_goto(15,70); z_hyperterm_put(0xCD);
	for(i=0;i<=4;i++){
		term_goto(15,72+i);
		z_hyperterm_put(0xCD);
	}
	term_goto(15,78); z_hyperterm_put(0xCD);
	term_goto(15,79); z_hyperterm_put(0xCD);
	//Upwards Splitter
	term_goto(15,71); z_hyperterm_put(0xCA);
	term_goto(15,77); z_hyperterm_put(0xCA);
	//Leftwards Splitter
	term_goto(15,80); z_hyperterm_put(0xB9);
//Sixteenth Line:
	//Vertical line piece
	for(i=0; i<=2; i++) {
		term_goto(16+i,68);
		z_hyperterm_put(0xBA);
	}
	for(i=0; i<=2; i++) {
		term_goto(16+i,80);
		z_hyperterm_put(0xBA);
	}
//Nineteenth Line:
	//Straight line piece
	for(i=0; i<=10; i++) {
		term_goto(19,69+i);
		z_hyperterm_put(0xCD);
	}
	//Bottom Left Corner
	term_goto(19,68); z_hyperterm_put(0xC8);
	//Leftwards Splitter
	term_goto(19,80); z_hyperterm_put(0xB9);
//Twentieth Line:
	for(i=0; i<=2;i++){
		term_goto(20+i,80);
		z_hyperterm_put(0xBA);
	}
//Twentysecond Line:
	term_goto(22,72);z_hyperterm_put(0xB8);z_hyperterm_putstring("2008");
//Twentyfourth Line:
	//Bottom Left Corner
	term_goto(23,1); z_hyperterm_put(0xC8);
	term_goto(23,67); z_hyperterm_put(0xC8);
	//Straight line piece
	for(i=0; i<=11; i++) {
		term_goto(23,68+i);
		z_hyperterm_put(0xCD);
	}
	//Bottom Left Corner
	term_goto(23,2); z_hyperterm_put(0xBC);
	term_goto(23,80); z_hyperterm_put(0xBC);
}

void gameboard_draw_highscore(void) {
	int i;
	z_hyperterm_clear();
	gameboard_draw();
//First line highscore
	//Set the border
	//Printing the left directed arrows, yellow
	z_hyperterm_setfgcolor(11);
	for(i=0;i<=9;i++){
		term_goto(3,21+i);
		z_hyperterm_put(0xAE);
	}
	//Printing "HIGHSCORE"
	term_goto(3,30); z_hyperterm_putstring("HIGHSCORE");
	//Printing the right directed arrows, yellow
	z_hyperterm_setfgcolor(11);
	for(i=0;i<=9;i++){
		term_goto(3,39+i);
		z_hyperterm_put(0xAF);
	}
//Fourth line highscore
	//Drawing "NAME"
	z_hyperterm_setfgcolor(9);
	term_goto(4,26); z_hyperterm_putstring("NAME");
	//Drawing "SCORE"
	z_hyperterm_setfgcolor(10);
	term_goto(4,39); z_hyperterm_putstring("SCORE");
//Fifth line highscore
	//Drawing the seperator
	z_hyperterm_setfgcolor(11);
	for(i=0;i<=27;i++){
		term_goto(5,21+i);
		z_hyperterm_put(0x23);
	}
//Twentythird line highscore
	//Drawing the left directed arrows, yellow
	for(i=0;i<=11;i++){
		term_goto(23,21+i);
		z_hyperterm_put(0xAE);
	}
	//Drawing "TOP15"
	term_goto(23,32); z_hyperterm_putstring("TOP15");
	//Drawing the right directed arrows, yellow
	z_hyperterm_setfgcolor(11);
	for(i=0;i<=11;i++){
		term_goto(23,37+i);
		z_hyperterm_put(0xAF);
	}
//21sh COLUMN highscore
	//Drawing the verticals
	for(i=0;i<=18;i++){
		term_goto(4+i,21);
		z_hyperterm_put(0x23);
	}
//22nd COLUMN highscore
	//Drawing the position numbers
	for(i=0;i<=5;i++){
		z_hyperterm_setfgcolor(i+10);
		term_goto(16+i,22);
		z_hyperterm_put('1');
	}
//23rd COLUMN highscore
	//Drawing the position numbers
	for(i=1;i<=15;i++){
		z_hyperterm_setfgcolor(i);
		term_goto(6+i,23);
		if(i<10){
			printf("%d",i);
		}
		else {
			printf("%d",i-10);
		}
		z_hyperterm_put('.');
	}
//34th COLUMN highscore
	//Drawing the verticals, yellow
	z_hyperterm_setfgcolor(11);
	for(i=0;i<=18;i++){
		term_goto(4+i,34);
		z_hyperterm_put(0x23);
	}
//49th COLUMN highscore
	//Drawing the verticals
	for(i=0;i<=18;i++){
		term_goto(4+i,48);
		z_hyperterm_put(0x23);
	}
}
