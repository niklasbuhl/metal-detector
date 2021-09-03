#ifndef TEXT_H
#define TEXT_H

#include "font.h"
#include "color.h"

#define CHAR_OFFSET_X 2
#define CHAR_OFFSET_Y 4
#define CHAR_HEIGHT 7

void text_setCursor(int x, int y);
void text_newLine();
void text_begin(int x, int y);
void text_char(int c, Color col);
void text_string(char* string, Color col);
void text_int(int value, Color color);

#endif
