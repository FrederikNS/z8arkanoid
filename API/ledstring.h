#ifndef __LEDSTRING_H
#define __LEDSTRING_H

void z_ledstring_putchar(char value, int block);
void z_ledstring_putstring(char* string);
//void z_ledstring_putstring_rightaligned(char* string); //maybe useful
//void z_ledstring_putscrolling_string(char* string, int frame);

#endif