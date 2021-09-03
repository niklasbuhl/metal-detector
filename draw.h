#ifndef DRAW_H
#define DRAW_H

#define DISPLAY_SCALE 1
#define DISPLAY_ANGLE 15

#include "color.h"

float myAngles[14];

float sinus(int angle);
float cosinus(int angle);

void draw_rectangle(int startX, int startY, int width, int height, Color c);
void draw_pixel(int x, int y, Color c);
void draw_line(int startX, int startY, int endX, int endY, Color c);
void draw_square(int centerX, int centerY, int length, int height, Color color);
void draw_circle(int centerX, int centerY, int radius, Color c);

void draw_box(int startX, int startY, int length, int height, int depth, Color color);
void draw_boxCenter(int centerX, int centerY, int length, int height, int depth, Color color);

int scale3D(int input);

int x_2D_3D(int x, int y, int z);
int y_2D_3D(int x, int y, int z);

void draw3D_box(int centerX, int centerY, int centerZ, int length, int height, int depth, Color color);
void draw3D_circle(int centerX, int centerY, int centerZ, int radius, Color color);
void draw3D_line(int startX, int startY, int startZ, int endX, int endY, int endZ, Color color);
void draw3D_pixel(int centerX, int centerY, int centerZ, Color color);

#endif
