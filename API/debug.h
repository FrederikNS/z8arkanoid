#ifndef __DEBUG_H
#define __DEBUG_H

//#ifdef DEBUG
#define ASSERT(x, r) if(!(x)) { z_hyperterm_goto(1, 1); z_hyperterm_putstring(r); }
//#else
//#define ASSERT(x, r)
//#endif

#endif