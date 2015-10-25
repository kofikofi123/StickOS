#ifndef _TERMINAL_H
#define _TERMINAL_H

#include <stdint.h>
#include "Vga.h"
/*



enum Colors {
	Black,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Brown, 
	Light_grey,
	Dark_grey,
	Light_Blue,
	Light_green,
	Light_Cyan,
	Light_red,
	Light_magenta,
	Light_brown,
	White
};

typedef struct {
	uint16_t x;
	uint16_t y;
}__attribute__((packed)) Point;


void init_text_screen(void);
void clear_screen(enum Colors fg, enum Colors bg);
void print_string(const char* string, enum Colors fg, enum Colors bg);
void print_number(uint16_t number, enum Colors fg, enum Colors bg);
void set_position(uint16_t x, uint16_t y);
uint8_t to_color(enum Colors fg, enum Colors bg);
Point get_position(void);
*/

void init_textmode(void);

#endif
