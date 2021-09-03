#ifndef METALDETECTOR_H_
#define METALDETECTOR_H_

#define METALDECT_LEFT_X 40
#define METALDECT_LEFT_Y 0
#define METALDECT_LEFT_Z -90

#define METALDECT_RIGHT_X 40
#define METALDECT_RIGHT_Y 0
#define METALDECT_RIGHT_Z 90

#define METALDECT_CENTER_X 46
#define METALDECT_CENTER_Y 17
#define METALDECT_CENTER_Z 0

#define METALDECT_L 8
#define METALDECT_H 8
#define METALDECT_W 8
#define METALDECT_C turquoise

#define METALDECT_START_X 233

#define METALDECT_SPHERE_C white

#define METAL_TEXT_C turquoise

#define METAL_MAX_DETECTED 32

#define METALDECT_READINGS 16

#include "metal.h"

int metaldect_left_radius;
int metaldect_right_radius;
int metaldect_center_radius;

long metaldect_x;
long lastFind;

int metalCounter;
int metalMarked;

int centerReadings[METALDECT_READINGS];

Metal* metalDetectedArray[METAL_MAX_DETECTED];

void metaldect_init();
void metaldect_draw();
void metaldect_move(int mm);
void metaldect_set(int z);
void metaldect_left(int mm);
void metaldect_right(int mm);
void metaldect_center(int mm);
void metaldect_center_rl();
void metaldect_drawSphere();
void metaldect_run();

#endif
