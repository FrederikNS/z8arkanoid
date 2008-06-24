/*
 *  levels.c
 *
 *
 *  Created by Frederik Sabroe on 22/06/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "levels.h"

//const char (*levels[])[][] = {};



const char levels[][BLOCKS_HEIGHT*BLOCKS_WIDTH] = {
/*
 |                              |                              |
 |               |              |              |               |
 |       |       |       |      |      |       |       |       |
 |   |   |   |   |   |   |   |  |  |   |   |   |   |   |   |   |
 | | | | | | | | | | | | | | | ||| | | | | | | | | | | | | | | |*/
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,2,2,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,3,0,0,0,0,0,0,0,
 0,0,0,3,3,3,3,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,3,3,3,3,0,0,0,
 3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,
 3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,
 0,0,0,3,3,3,3,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,3,3,3,3,0,0,0,
 0,0,0,0,0,0,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,3,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,2,2,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},


{4,4,4,4,4,4,4,3,4,4,3,4,4,3,4,3,3,4,3,4,4,3,4,4,3,4,4,4,4,4,4,4,
 3,3,3,3,3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3,3,3,3,3,
 3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,3,3,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
 6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
 
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,1,1,1,1,1,
 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,
 5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,
 5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,
 3,3,3,3,3,3,3,3,3,3,3,1,1,1,2,2,2,2,1,1,1,3,3,3,3,3,3,3,3,3,3,3,
 2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
 2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
 1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
 1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},

/*Empty Level
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},*/
};