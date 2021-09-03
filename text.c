#ifndef TEXT_C
#define TEXT_C

#include "font.h"
#include "text.h"
#include "draw.h"
#include <xil_printf.h>
#include <math.h>

int cursorX;
int cursorY;
int lineBeginX;
int lineBeginY;

void text_setCursor(int x, int y) {

	cursorX = x;
	cursorY = y;

}

void text_begin(int x, int y) {

	text_setCursor(x,y);

	lineBeginX = cursorX;
	lineBeginY = cursorY;

}

void text_newLine() {

	cursorX = lineBeginX;
	lineBeginY += 7 + CHAR_OFFSET_Y;
	cursorY = lineBeginY;

}

void text_char(int c, Color col) {

	//xil_printf("Ascii: %d\n",c);

	Char *cPtr = myFont[c];

	if(myFont[c] == 0) {
		xil_printf("Character not found.\n");
		return;
	}

	int cW = cPtr->cWidth;

	int cH = cPtr->cHeight;

	int *cAPtr = cPtr->cBitArray;

	int iX = 0;
	int iY;

	int bit;

	for(iY = 0; iY < cH; iY++) {

		bit = myFontWidth;

		cursorX -= iX;

		for(iX = 0; iX < cW; iX++) {

			if(bit & cAPtr[iY]) {

				//xil_printf("Pixel at: %d, %d.\n",cursorX,cursorY);

				draw_pixel(cursorX,cursorY,col);

			}

			bit = bit / 2;

			//xil_printf("Bit: %d\n",bit);

			cursorX++;

		}

		cursorY++;

	}

}

void text_string(char* string, Color col) {

	int stringLength = strlen(string);

	int i;

	for(i = 0; i < stringLength; i++) {

		text_char((int)string[i],col);

		//xil_printf("Next character at: %d, %d.\n",cursorX, cursorY);

		text_setCursor(cursorX+CHAR_OFFSET_X,lineBeginY);

	}

}

void text_int(int value, Color color) {

	char string[10] = "";

	int i, counter;

	if(value < 0) {
		text_string("-",color);
		value = value * -1;
	}

	i = 1;
	counter = 0;

	while(value / i) {
		counter++;
		i = i * 10;
	}

	//string[counter] = '/0';

	counter--;

	i = 10;

	while(counter+1) {

		string[counter] = ((value % i) / (i / 10)) + 48;

		//xil_printf("C: %d, Value: %d\n",counter,(value % i) / (i / 10));

		counter--;

		value = value - value % i;

		i = i * 10;
	}

	//xil_printf("String: %s\n",string);

	text_string(string,color);

}

#endif
