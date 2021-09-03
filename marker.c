#ifndef MARKER_C_
#define MARKER_C_

#include <xil_printf.h>
#include "marker.h"
#include "draw.h"
#include "conveyor.h"
#include "metal.h"
#include "metaldetector.h"
#include "wood.h"
#include "motor.h"
#include "../IOJD.h"
#include <sleep.h>

void marker_init() {

	marker_set(0,0);
	marking = 0;
	marker_newY = MARKER_POINT_ORIG_Y;
	marker_newZ = 0;
	marker_next_metal = 0;

}

void marker_draw(int y, int z) {

	marker_draw_slider();
	marker_draw_marker();

}

void marker_set(int y, int z) {

	//marker_y = y;
	//marker_z = z;

	marker_newY = y;
	marker_newZ = z;

}

void marker_draw_slider() {

	draw3D_box(MARKER_SLIDER_X,MARKER_SLIDER_Y,marker_z,MARKER_SLIDER_L,MARKER_SLIDER_H,MARKER_SLIDER_W,MARKER_SLIDER_C);
	draw3D_box(MARKER_SOLENOID_X,MARKER_SOLENOID_Y,marker_z,MARKER_SOLENOID_L,MARKER_SOLENOID_H,MARKER_SOLENOID_W,MARKER_SOLENOID_C);
	draw3D_box(MARKER_CONTAINER_X,MARKER_CONTAINER_Y,marker_z,MARKER_CONTAINER_L,MARKER_CONTAINER_H,MARKER_CONTAINER_W,MARKER_CONTAINER_C);

}

void marker_draw_marker() {

	draw3D_box(MARKER_X,marker_y+MARKER_P+MARKER_H/2,marker_z,MARKER_L,MARKER_H,MARKER_W,MARKER_C);
	draw3D_line(MARKER_X,marker_y+MARKER_P,marker_z,MARKER_X,marker_y,marker_z,MARKER_C);
	draw3D_pixel(MARKER_X,marker_y,marker_z,MARKER_POINT_C);

}

void marker_update() {

	if(marker_z > marker_newZ) {
		printer_left();
		marker_z--;
	}
	if(marker_z < marker_newZ) {
		printer_right();
		marker_z++;
	}

	if(marker_y > marker_newY) {
		marker_y--;
	}
	if(marker_y < marker_newY) {
		marker_y++;
	}

}

void marker_move(int mm) {

	marker_newZ += mm;
	if(marker_newZ < MARKER_RIGHT_CONSTRAIN) marker_newZ = MARKER_RIGHT_CONSTRAIN;
	if(marker_newZ > MARKER_LEFT_CONSTRAIN) marker_newY = MARKER_LEFT_CONSTRAIN;

}

void marker_marking() {

	if(marker_z == marker_newZ && marker_y == marker_newY) {

		nextMetal->marked = 1;

		nextMetal = (Metal*) nextMetal->nextMetal;

		marking = 0;

		marker_next_metal = 0;

		conveyor_start();

		marker_set(0,40);

		metalMarked++;

		xil_printf("Metal Detected: %d\n",metalCounter);
		xil_printf("Metal Marked: %d\n",metalMarked);

		digitalWrite(4,HIGH);

		sleep(2);

		digitalWrite(4,LOW);

	}
}

void marker_mark() {

	marker_newY = nextMetal->y;
	marker_newZ = nextMetal->z;

	xil_printf("Marking Y: %d\n",marker_newY);
	xil_printf("Marking Z: %d\n",marker_newZ);

}

void marker_run() {

	marker_x = (long)conveyorMoved - MARKER_START_X;

	marker_update();

	if(marking) marker_marking();

	if(!marking && metalCounter > metalMarked) {

		nextMetal = metalDetectedArray[(metalCounter-(metalCounter-metalMarked))%METAL_MAX_DETECTED];

		marker_next_metal = nextMetal->realX;

		//xil_printf("Next: %d\n",marker_next_metal);

	}

	if(marker_next_metal && marker_next_metal <= marker_x) {

		if(conveyorMoving) {
			xil_printf("Stopping conveyor to mark");
			conveyor_stop();
			marker_mark();
			marking = 1;

		}
	}
}
#endif
