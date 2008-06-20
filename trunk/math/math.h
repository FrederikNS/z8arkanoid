#ifndef __MATH_H
#define __MATH_H

#include "sincoslut.h"
#include "vector.h"
#include "lamemath.h"


#define MIN(a,b) ((a)>(b)?(b):(a))
#define MIN3(a,b,c) MIN(MIN(a,b),c)
#define MAX(a,b) ((a)<(b)?(b):(a))
#define MAX3(a,b,c) MAX(MAX(a,b),c)
#define BETWEEN(l, v, h) (((l) <= (v)) && ((v) < (h)))
#define ABS(a) (((a)<0) ? (-a) : (a))

#define CLAMP(a, b, c) MAX(MIN(c, a), b)

/*
#define FIXED_PRECISION 4
#define FIXED_FRAC 0xF

#define I_TO_F(x) ((x)<<FIXED_PRECISION)
#define F_TO_I(x) ((x)>>FIXED_PRECISION)
#define FRAC(x) ((x)&FIXED_FRAC)
*/
#endif

