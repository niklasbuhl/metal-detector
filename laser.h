#ifndef LASER_H
#define LASER_H

#define LASER_COLOR blue
#define LASER_SHOT_COLOR purple
#define LASER_IMPACT_COLOR turquoise
#define LASER_IMPACT_RADIUS 5

#define LASER_TEXT_C green

#define LASER_START_X 112

#define LASER_AVG 12

// Top

#define LASER_TOP_X -81
#define LASER_TOP_Y 75
#define LASER_TOP_Z 0

#define LASER_TOP_L 12
#define LASER_TOP_H 12
#define LASER_TOP_D 30

#define LASER_TOP_SY 69
#define LASER_TOP_MAX 69

#define LASER_TOP_OFFSET 26

int laser_top_ey;

// Left

#define LASER_LEFT_X -81
#define LASER_LEFT_Y 14
#define LASER_LEFT_Z -62

#define LASER_LEFT_L 12
#define LASER_LEFT_H 30
#define LASER_LEFT_D 12

#define LASER_LEFT_SZ -56
#define LASER_LEFT_MAX 56

int laser_left_ez;


// Right

#define LASER_RIGHT_X -81
#define LASER_RIGHT_Y 14
#define LASER_RIGHT_Z 62

#define LASER_RIGHT_L 12
#define LASER_RIGHT_H 30
#define LASER_RIGHT_D 12

#define LASER_RIGHT_SZ 56
#define LASER_RIGHT_MAX 56

int laser_right_ez;

int laser_top;
int laser_left;
int laser_right;

int laser_top_mm;
int laser_left_mm;
int laser_right_mm;

int laserDistances_V1[1024];
int laserDistances_V2[1024];

int laserTopAvg[LASER_AVG];
int laserLeftAvg[LASER_AVG];
int laserRightAvg[LASER_AVG];

long laser_x;

// Functions

void laser_init();

void laser_draw();

void laser_top_dist(int dist);
void laser_left_dist(int dist);
void laser_right_dist(int dist);

void laser_top_move(int mm);
void laser_left_move(int mm);
void laser_right_move(int mm);

void laser_drawLaserShots();

void laser_run();

#endif
