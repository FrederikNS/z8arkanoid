#ifndef __LEDFRAMEBUFFER_H
#define __LEDFRAMEBUFFER_H

void z_ledfb_write(void);
void z_ledfb_set_column(int column, int value);
void z_ledfb_put_dot(int x, int y);
void z_ledfb_clear_dot(int x, int y);
void z_ledfb_clear_block(int block);

#endif