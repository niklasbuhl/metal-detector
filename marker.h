#ifndef MARKER_H_
#define MARKER_H_

// General

int marker_x;
int marker_y;
long marker_z;
long marker_next_metal;

#define MARKER_TEXT_C blue

#define MARKER_LEFT_CONSTRAIN -50
#define MARKER_RIGHT_CONSTRAIN 50

#define MARKER_START_X 321

// Slider

#define MARKER_SLIDER_L 70
#define MARKER_SLIDER_H 10
#define MARKER_SLIDER_W 76
#define MARKER_SLIDER_X 192-15+35
#define MARKER_SLIDER_Y 100+5
#define MARKER_SLIDER_C blue

// Solenoid

#define MARKER_SOLENOID_L 40
#define MARKER_SOLENOID_H 39
#define MARKER_SOLENOID_W 40
#define MARKER_SOLENOID_X 192-15-20
#define MARKER_SOLENOID_Y 100+13-19
#define MARKER_SOLENOID_C blue

// Marker Holder

#define MARKER_CONTAINER_L 17
#define MARKER_CONTAINER_H 39
#define MARKER_CONTAINER_W 17
#define MARKER_CONTAINER_X 192-15-40-9
#define MARKER_CONTAINER_Y 100+13-19
#define MARKER_CONTAINER_C blue

// Marker

#define MARKER_L 11
#define MARKER_H 107
#define MARKER_W 11
#define MARKER_X 192-15-40-9
#define MARKER_P 17
#define MARKER_C green
#define MARKER_POINT_C blue

#define MARKER_POINT_ORIG_Y 20
#define MARKER_POINT_STOP_Y 7

int marking;
int metalReady;

int marker_newY;
int marker_newZ;

void marker_init();
void marker_control();
void marker_set(int y, int z);
void marker_move(int mm);
void marker_draw();
void marker_update();
void marker_draw_marker();
void marker_draw_slider();
void marker_mark();
void marker_run();

#endif
