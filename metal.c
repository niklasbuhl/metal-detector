#ifndef METAL_C_
#define METAL_C_

#include <xil_cache.h>
#include <xil_printf.h>
#include "metaldetector.h"
#include "wood.h"
#include "conveyor.h"
#include "color.h"
#include "draw.h"

void metal_detect(int z) {

	if(lastFind >= 0) {
		xil_printf("To soon.\n");
		return;
	}

	Metal* newMetal;
	Wood* targetWood;

	int x = metaldect_x;
	int y;

	xil_printf("Metaldect currentX: %d\n",x);

	int found = 0;

	int woodStartX;
	int woodEndX;

	int i;

	int counter = woodCounter % 8;

	if(woodCounter >= 8) counter = 8;

	for(i = 0; i < counter; i++) {

		xil_printf("Testing wood: %d\n",allWood[i].id);

		woodStartX = allWood[i].startX;

		xil_printf("Wood Start X: %d\n",woodStartX);

		if(woodStartX > x) continue;

		if(!allWood[i].laserFinished && woodStartX < x) {

			found = 1;
			targetWood = &allWood[i];
			break;

		}

		woodEndX = allWood[i].endX;

		xil_printf("Wood length: %d\n",allWood[i].length);

		xil_printf("Wood End X: %d\n",woodEndX);

		if(woodEndX > x && woodStartX < x) {

			found = 1;
			targetWood = &allWood[i];
			break;

		}

	}

	if(!found) {
		xil_printf("Metal found, but didn't match any wood.\n");
		return;

	} else {
		xil_printf("Metal found.\n");
		xil_printf("Wood id: %d\n",targetWood->id);
		xil_printf("x: %d\n",x);
		xil_printf("Wood Begin: %d\n",woodStartX);
		xil_printf("MetalDect X: %d\n",x);
		xil_printf("Index: %d\n",(x-woodStartX)/WOOD_INCREMENT);
		y = targetWood->XYZZ[(x-woodStartX)/WOOD_INCREMENT][1];
		xil_printf("y: %d\n",y);
		xil_printf("z: %d\n",z);
	}

	newMetal = &targetWood->metal[targetWood->metalCount];

	lastFind = x;

	x = targetWood->startX - x;

	newMetal->id = targetWood->metalCount + 1;
	newMetal->x = x;
	newMetal->realX = metaldect_x;
	newMetal->y = y;
	newMetal->z = z;
	newMetal->marked = 0;
	newMetal->woodPtr = (int)targetWood;

	metalDetectedArray[metalCounter] = newMetal;

	targetWood->metalCount++;

	if(!thisMetal) thisMetal->nextMetal = (int)newMetal; // set previous metal nextMetal pointer to newMetal

	thisMetal = newMetal; // update thisMetal to newMetal

	if(!metalCounter) {
		xil_printf("First Metal!\n");
		nextMetal = newMetal;
		xil_printf("Metal at X: %d\n",nextMetal->realX);
	}

	metalCounter++;

}

void metal_marked(Metal* metal) {

	metal->marked = 1;

}

void metal_draw(Metal* metal, int startDrawX) {

	if(metal->marked == 0) draw3D_box(startDrawX+metal->x,metal->y,metal->z,METAL_SIZE,METAL_SIZE,METAL_SIZE,METAL_C);

	if(metal->marked == 1) {
		//xil_printf("Drawing Marked Metal");

		draw3D_box(startDrawX+metal->x,metal->y,metal->z,METAL_SIZE,METAL_SIZE,METAL_SIZE,METAL_C);
		draw3D_line(
				(startDrawX + metal->x) + METAL_SIZE/2,
				metal->y + METAL_SIZE/2,
				metal->z - METAL_SIZE/2,
				(startDrawX + metal->x) - METAL_SIZE/2,
				metal->y + METAL_SIZE/2,
				metal->z + METAL_SIZE/2,
				METAL_C
		);
		draw3D_line(
				(startDrawX + metal->x) + METAL_SIZE/2,
				metal->y + METAL_SIZE/2,
				metal->z + METAL_SIZE/2,
				(startDrawX + metal->x) - METAL_SIZE/2,
				metal->y + METAL_SIZE/2,
				metal->z - METAL_SIZE/2,
				METAL_C
		);
	}
}

#endif
