#ifndef CONVEYOR_C_
#define CONVEYOR_C_

#include "conveyor.h"
#include "draw.h"
#include "app.h"
#include "motor.h"

void conveyor_run() {
	if(conveyorMoving) {
		conveyorMoved += conveyorSpeed;
		conveyorStep++;
		conveyor_forward(conveyorStep);
	}
}

void conveyor_move(int mm) {
	conveyorMoved += (float)(mm);
}

void conveyor_setSpeed(float speed) {
	conveyorSpeed = speed;
}

void conveyor_start() {

	StartStopConveyor.label = "Stop Conveyor";

	StartStopConveyor.execute = &conveyor_stop;

	conveyorMoving = 1;

}

void conveyor_stop() {

	StartStopConveyor.label ="Start Conveyor";

	StartStopConveyor.execute = &conveyor_start;

	conveyorMoving = 0;

}

void conveyor_draw() {

	draw3D_box(CONVEYOR_X,CONVEYOR_Y,CONVEYOR_Z,CONVEYOR_L,CONVEYOR_H,CONVEYOR_D, CONVEYOR_C);

}

void conveyor_band() {

	int bandStripes = (CONVEYOR_L / CONVEYOR_BAND_L) + 1;

	int offset = (int)(conveyorMoved) % CONVEYOR_BAND_L;

	int i;

	for(i = 0; i < bandStripes; i++) {

		if(offset+(i*CONVEYOR_BAND_L) < CONVEYOR_L) {
			draw3D_line(
				CONVEYOR_X-(CONVEYOR_L/2)+offset+(i*CONVEYOR_BAND_L),
				CONVEYOR_Y+CONVEYOR_H/2,
				CONVEYOR_Z-CONVEYOR_D/2,
				CONVEYOR_X-(CONVEYOR_L/2)+offset+(i*CONVEYOR_BAND_L),
				CONVEYOR_Y+CONVEYOR_H/2,
				CONVEYOR_Z+CONVEYOR_D/2,
				CONVEYOR_C

			);

		}

	}

}

void conveyor_init(int input) {
	StartStopConveyor.label = "Start Conveyor";

	StartStopConveyor.execute = &conveyor_start;

	conveyorSpeed = 0.23;

	conveyorMoved = 0;
	conveyorStep = 0;

}

#endif
