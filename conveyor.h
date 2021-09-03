#ifndef CONVEYOR_H_
#define CONVEYOR_H_

#define CONVEYOR_TOP 0

#define CONVEYOR_L 385
#define CONVEYOR_D 100
#define CONVEYOR_H 16

#define CONVEYOR_BAND_L 20

#define CONVEYOR_X 0
#define CONVEYOR_Y -8
#define CONVEYOR_Z 0

#define CONVEYOR_C green

#define CONVEYOR_TEXT_C green

#define CONVEYOR_START_X 0
#define CONVEYOR_START_OFFSET -193

double conveyorMoved;
float conveyorSpeed;
int conveyorMoving;
long conveyorStep;

void conveyor_init();
void conveyor_draw();
void conveyor_move(int mm);
void conveyor_setSpeed(float speed);
void conveyor_start();
void conveyor_stop();
void conveyor_run();
void conveyor_band();
void conveyor_init();

#endif
