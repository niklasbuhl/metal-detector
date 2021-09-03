#ifndef METALDETECTOR_C
#define METALDETECTOR_C

#include "metaldetector.h"
#include "draw.h"
#include "conveyor.h"
#include "metal.h"
#include "../IOJD.h"
#include "app.h"

void metaldect_init() {

	lastFind = -1;

	nextMetal = 0;

	thisMetal = 0;

	metalCounter = 0;
	metalMarked = 0;

	//metaldect_left(0);
	//metaldect_right(0);

	metaldect_center(0);

}

void metaldect_draw() {

	/*

	// Left
	draw3D_box(
		METALDECT_LEFT_X,
		METALDECT_LEFT_Y,
		METALDECT_LEFT_Z,
		METALDECT_L,
		METALDECT_H,
		METALDECT_W,
		METALDECT_C
	);

	// Right
	draw3D_box(
		METALDECT_RIGHT_X,
		METALDECT_RIGHT_Y,
		METALDECT_RIGHT_Z,
		METALDECT_L,
		METALDECT_H,
		METALDECT_W,
		METALDECT_C
	);

	*/

	//Center

	draw3D_box(
		METALDECT_CENTER_X,
		METALDECT_CENTER_Y,
		METALDECT_CENTER_Z,
		METALDECT_L,
		METALDECT_H,
		METALDECT_W,
		METALDECT_C
	);
}

void metaldect_set(int z) {
	metaldect_left(-(METALDECT_LEFT_Z)+z);
	metaldect_right((METALDECT_RIGHT_Z)-z);
	metaldect_center(z);
}

void metaldect_move(int mm) {
	//metaldect_left_radius += mm;
	//metaldect_right_radius -= mm;
	metaldect_center_radius += mm;
}

void metaldect_left(int mm) {
	metaldect_left_radius = mm;
}

void metaldect_right(int mm) {
	metaldect_right_radius = mm;
}

void metaldect_center(int mm) {
	metaldect_center_radius = mm;
}

void metaldect_drawSphere() {
	/*
	draw3D_circle(
			METALDECT_LEFT_X,
			METALDECT_LEFT_Y,
			METALDECT_LEFT_Z,
			metaldect_left_radius,
			METALDECT_SPHERE_C
			);

	draw3D_circle(
			METALDECT_RIGHT_X,
			METALDECT_RIGHT_Y,
			METALDECT_RIGHT_Z,
			metaldect_right_radius,
			METALDECT_SPHERE_C
			);
	*/
	draw3D_circle(
			METALDECT_CENTER_X,
			METALDECT_CENTER_Y,
			METALDECT_CENTER_Z,
			metaldect_center_radius,
			METALDECT_SPHERE_C
			);

}

void metaldect_run() {

	metaldect_x = (long)conveyorMoved - METALDECT_START_X;

	metaldect_center_rl();

	if(lastFind >= 0) {
		if(lastFind + METAL_MINIMUM_SPACE < metaldect_x) {
			lastFind = -1;
		}
	}
}

void metaldect_center_rl() {

	int reading = analRead(3);



	centerReadings[systemCounter%METALDECT_READINGS] = reading;

	int i;

	int avgReading = 0;

	for(i = 0; i < METALDECT_READINGS; i++) {

		avgReading += centerReadings[i];

	}

	avgReading = avgReading / METALDECT_READINGS;

	//xil_printf("%d",avgReading);

	reading = (avgReading - 155);

	//xil_printf("Metaldect: %d\n",reading);

	metaldect_center(reading);

	if(reading > 15) {
		metal_detect(0);
	}

}

#endif
