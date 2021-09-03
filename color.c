#ifndef COLOR_C
#define COLOR_C

#include "color.h"
#include "display.h"
#include <stdio.h>
#include <xil_types.h>

Color red = {"Red",255,0,0};
Color green = {"Green",0,255,0};
Color blue = {"Blue",0,0,255};
Color purple ={"Purple",255,0,255};
Color yellow = {"Yellow",255,255,0};
Color turquoise = {"Turquoise",0,255,255};
Color white = {"White",255,255,255};
Color black = {"Black",0,0,0};
Color grey = {"Grey",123,123,123};

void colorPixel(long a, Color c) {

	if(a < 0 || a >= (displayWidth * 3 + displayStride * displayHeight)) return;

	displayFrame[a+2] = c.red;
	displayFrame[a] = c.green;
	displayFrame[a+1] = c.blue;

}

#endif
