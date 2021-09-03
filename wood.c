#ifndef WOOD_C_
#define WOOD_C_


#include <xil_cache.h>
#include <xil_types.h>
#include <xil_printf.h>
#include "app.h"
#include "wood.h"
#include "laser.h"
#include "conveyor.h"
#include "draw.h"

void wood_init() {

	DetectWood.label = "Begin Wood";

	DetectWood.execute = &wood_begin;

	woodCounter = 0;
	woodDetected = 0;

	thisWood = 0;
	nextWood = &allWood[woodCounter];
	lastWood = &allWood[woodCounter];

	int i;

	for(i = 0; i < WOOD_MAX; i++) {
		allWood[i].id = 0;
	}

}

void wood_begin() {

	xil_printf("Wood begin.");

	DetectWood.label = "End Wood";

	DetectWood.execute = &wood_end;

	woodDetected = 1;

	woodCounter++;

	thisWood = &allWood[(woodCounter-1) % WOOD_MAX];

	nextWood = &allWood[(woodCounter) % WOOD_MAX];

	if(woodCounter < 8) {
		lastWood = &allWood[(woodCounter - 7) % WOOD_MAX];
	}

	thisWood->id = woodCounter;

	thisWood->startX = (long)conveyorMoved - LASER_START_X;

	thisWood->laserFinished = 0;

	thisWood->length = 0;

	thisWood->metalCount = 0;

	thisWood->metaldectFinished = 0;

	wood_addPoint(thisWood->length,laser_top_ey,laser_left_ez,laser_right_ez);

	/*

	xil_printf("Conveyor Offset: %d\n",CONVEYOR_START_OFFSET);
	xil_printf("Conveyor Moved: %d\n",(long)conveyorMoved);
	xil_printf("Laser Start X: %d\n", LASER_START_X);
	xil_printf("Wood startX: %d\n",thisWood->startX);
	xil_printf("Wood x: %d\n",thisWood->XYZZ[0][0]);
	xil_printf("Wood y: %d\n",thisWood->XYZZ[0][1]);
	xil_printf("Wood z-left: %d\n",thisWood->XYZZ[0][2]);
	xil_printf("Wood z-right: %d\n",thisWood->XYZZ[0][3]);

	*/

	int woodIndex = (thisWood->id-1)%WOOD_MAX;

	wood_draw(woodIndex);

	xil_printf("Begin Wood. ID: %d, Wood Index: %d\n",thisWood->id,woodIndex);

}

void wood_end() {

	DetectWood.label = "Begin Wood";

	DetectWood.execute = &wood_begin;

	woodDetected = 0;

	thisWood->endX = (long)conveyorMoved - LASER_START_X;

	int woodIndex = (thisWood->length)/WOOD_INCREMENT;

	wood_addPoint(woodIndex+2,thisWood->XYZZ[woodIndex][1],thisWood->XYZZ[woodIndex][2],thisWood->XYZZ[woodIndex][3]);

	thisWood->laserFinished = 1;

	xil_printf("Begin End. ID: %d, Wood Index: %d\n",thisWood->id,woodIndex);

}

void wood_detect() {

	if(woodDetected) { // Wood

		// Begin Wood

		if(thisWood->laserFinished || !thisWood->id) wood_begin();

		// Append Wood

		wood_addPoint((thisWood->length/WOOD_INCREMENT)+1,laser_top_ey,laser_left_ez,laser_right_ez);

	} else { // No Wood

		// End Wood

		if(!thisWood->laserFinished) wood_end();

		// Nothing

	}

}

void wood_addPoint(int x, int y, int leftZ, int rightZ) {

	thisWood->length = conveyorMoved - thisWood->startX - LASER_START_X;
	thisWood->x = CONVEYOR_START_OFFSET + (conveyorMoved - thisWood->startX);

	if(thisWood->laserFinished) return;

	thisWood->XYZZ[x][0] = thisWood->length;
	thisWood->XYZZ[x][1] = y;
	thisWood->XYZZ[x][2] = leftZ;
	thisWood->XYZZ[x][3] = rightZ;

}

void wood_draw(int index) {

	//xil_printf("Drawing Wood.\n");

	Wood* wood = &allWood[index];

	int startDrawX = CONVEYOR_START_OFFSET + (conveyorMoved - wood->startX);

	/*

	xil_printf("Wood StartX: %d\n",startDrawX);
	xil_printf("Wood y: %d\n",wood->XYZZ[0][1]);
	xil_printf("Wood z-left: %d\n",wood->XYZZ[0][2]);
	xil_printf("Wood z-right: %d\n",wood->XYZZ[0][3]);

	*/

	draw3D_line(
			startDrawX,CONVEYOR_TOP,wood->XYZZ[0][2],
			startDrawX,CONVEYOR_TOP,wood->XYZZ[0][3],
			WOOD_C
	);

	draw3D_line(
			startDrawX,CONVEYOR_TOP,wood->XYZZ[0][3],
			startDrawX,wood->XYZZ[0][1],wood->XYZZ[0][3],
			WOOD_C

	);

	draw3D_line(
			startDrawX,wood->XYZZ[0][1],wood->XYZZ[0][3],
			startDrawX,wood->XYZZ[0][1],wood->XYZZ[0][2],
			WOOD_C
	);

	draw3D_line(
			startDrawX,wood->XYZZ[0][1],wood->XYZZ[0][2],
			startDrawX,CONVEYOR_TOP,wood->XYZZ[0][2],
			WOOD_C
	);

	//xil_printf("Drawing Wood: %d\n",wood->id);

	int loopDraw = (wood->length/WOOD_INCREMENT)+1;

	int i;

	for(i = 0; i < loopDraw;i++) {
		draw3D_line(
				startDrawX - wood->XYZZ[i][0],CONVEYOR_TOP,wood->XYZZ[i][2],
				startDrawX - wood->XYZZ[i+1][0],CONVEYOR_TOP,wood->XYZZ[i+1][2],
				WOOD_C
		);
		draw3D_line(
				startDrawX - wood->XYZZ[i][0],CONVEYOR_TOP,wood->XYZZ[i][3],
				startDrawX - wood->XYZZ[i+1][0],CONVEYOR_TOP,wood->XYZZ[i+1][3],
				WOOD_C
		);
		draw3D_line(
				startDrawX - wood->XYZZ[i][0],wood->XYZZ[i][1],wood->XYZZ[i][2],
				startDrawX - wood->XYZZ[i+1][0],wood->XYZZ[i+1][1],wood->XYZZ[i+1][2],
				WOOD_C
		);
		draw3D_line(
				startDrawX - wood->XYZZ[i][0],wood->XYZZ[i][1],wood->XYZZ[i][3],
				startDrawX - wood->XYZZ[i+1][0],wood->XYZZ[i+1][1],wood->XYZZ[i+1][3],
				WOOD_C
		);

	}

	if(wood->laserFinished) loopDraw++;

	i = loopDraw;

	draw3D_line(
			startDrawX-wood->XYZZ[i][0],CONVEYOR_TOP,wood->XYZZ[i][2],
			startDrawX-wood->XYZZ[i][0],CONVEYOR_TOP,wood->XYZZ[i][3],
			WOOD_C
	);

	draw3D_line( // Right
			startDrawX-wood->XYZZ[i][0],CONVEYOR_TOP,wood->XYZZ[i][3],
			startDrawX-wood->XYZZ[i][0],wood->XYZZ[i][1],wood->XYZZ[i][3],
			green

	);

	draw3D_line(
			startDrawX-wood->XYZZ[i][0],wood->XYZZ[i][1],wood->XYZZ[i][3],
			startDrawX-wood->XYZZ[i][0],wood->XYZZ[i][1],wood->XYZZ[i][2],
			WOOD_C
	);

	draw3D_line( // Left
			startDrawX-wood->XYZZ[i][0],wood->XYZZ[i][1],wood->XYZZ[i][2],
			startDrawX-wood->XYZZ[i][0],CONVEYOR_TOP,wood->XYZZ[i][2],
			blue
	);

	// Draw Metal In Wood

	int metalCount = wood->metalCount;

	if(metalCount) {
		for(i = 0; i < metalCount; i++) {
			Metal* someMetal = &(wood->metal[i]);
			//xil_printf("Wood id: %d, Metal id: %d\n",wood->id,someMetal->id);
			metal_draw(someMetal,startDrawX);
		}
	}
}

void wood_drawAll() {

	int counter = woodCounter % 8;

	if(woodCounter >= 8) counter = 8;

	int i;

	for(i = 0; i < counter; i++) {
		//xil_printf("Go to draw wood: %d\n",i);
		wood_draw(i);
	}

}

#endif
