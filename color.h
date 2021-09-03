#ifndef COLOR_H
#define COLOR_H

// Variables

#include <xil_types.h>

typedef struct {
	char* name;
	int red;
	int green;
	int blue;
} Color;

Color red;
Color green;
Color blue;
Color purple;
Color yellow;
Color turquoise;
Color white;
Color black;
Color grey;

void colorPixel(long a, Color c);

#endif
