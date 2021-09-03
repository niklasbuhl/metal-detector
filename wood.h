#ifndef WOOD_H
#define WOOD_H

#define WOOD_Y 0
#define WOOD_MAX 8
#define WOOD_INCREMENT 10 // How many millimeters
#define WOOD_C black

#include "metal.h"

typedef struct {

	int id;
	int startX;
	int endX;
	int laserFinished;
	int XYZZ[64][4];
	int length;
	int x;
	Metal metal[64];
	int metalCount;
	int metaldectFinished;
	int totalFinished;

} Wood;

Wood allWood[WOOD_MAX];
Wood* thisWood;
Wood* nextWood;
Wood* lastWood;

int woodCounter;
int woodDetected;

void wood_detect();

void wood_begin();

void wood_end();

void wood_addPoint(int y, int leftZ, int rightZ, int index);

void wood_init();

void wood_draw(int index);

void wood_drawAll();

#endif
