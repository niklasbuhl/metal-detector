#ifndef DISPLAY_C
#define DISPLAY_C

#include "display.h"
#include "color.h"
#include <xil_cache.h>
#include "../video_demo.h"
#include <xil_types.h>
#include "draw.h"
#include "text.h"
#include "conveyor.h"
#include "laser.h"
#include "marker.h"
#include "metaldetector.h"
#include "sleep.h"
#include "wood.h"
#include "app.h"


u8* displayFrame;
u8* nextFrame;
u8* displayFramePtr[3];
int currentFrame;
long displayWidth;
long displayHeight;
long displayStride;

float displayScale; // mm to pixel scale
float displaySin;
float displayCos;

int originX;
int originY;

// Display System

void display_init(u8 *frame, long width, long height, long stride) {

	displayFrame = frame;
	displayWidth = width;
	displayHeight = height;
	displayStride = stride;

	originX = (int)(displayWidth/2);
	originY = (int)(displayHeight/2);

	displaySin = myAngles[2];
	displayCos = myAngles[3];

	displayScale = 1;

	displayFreq = 12;
	displayFPS = 1000/displayFreq;

}

void display_init_v2(u8* framePtr, long width, long height, long stride) {

	int i;

	for(i = 0; i < 3; i++) {
		displayFramePtr[i] = (u8*) framePtr[i];
	}

	displayWidth = width;
	displayHeight = height;
	displayStride = stride;
	displayFrame = displayFramePtr[0];

	originX = (int)(displayWidth/2);
	originY = (int)(displayHeight/2);

	displayScale = 1;

	displayFreq = 12;
	displayFPS = 1000/displayFreq;

}

void display_setBackground(Color c) {

	long x, y, iPixelAddr;

	for(x = 0; x < (displayWidth*3); x+=3) {

		iPixelAddr = x;

		for(y = 0; y < displayHeight; y++) {

			colorPixel(iPixelAddr, c);

			iPixelAddr += displayStride;

		}
	}
}

void display_nextFrame(int i) {

	displayFrame = nextFrame;
	nextFrame = displayFramePtr[i];

	//u8 *framePtr[DISPLAY_NUM_FRAMES]

}

void display_print() {

	/*

	currentFrame++;
	if(currentFrame >= 3) frame = 0;
	display_nextFrame(currentFrame);

	*/

	Xil_DCacheFlushRange((unsigned int) displayFrame, DEMO_MAX_FRAME);

}

// Display Modes

void display_helloWorld() {

	display_setBackground(white);

	draw_square(170,140,300,200,black);

	text_begin(210,180);
	text_string("Hello, World!",black);
	text_newLine();
	text_newLine();
	text_string("Press SPACE to continue...",black);
	text_newLine();
	text_newLine();
	text_newLine();
	text_string("Project Metal Wood Detection by",purple);
	text_newLine();
	text_newLine();
	text_string("   Taras Karapin",purple);
	text_newLine();
	text_string("   Jesper Kirial",purple);
	text_newLine();
	text_string("   Niklas Buhl",purple);

}

void display_loading(int progress, char* string) {

	display_setBackground(white);

	int bar = (progress*292)/100;

	draw_square(170,200,300,40,black);

	//xil_printf("Bar: %d\n",(int)bar);

	draw_rectangle(174,204,bar,32,red);

	text_begin(170,250);
	text_string(string,black);

}

void display_all(int input) {

	//xil_printf("Displaying All.\n");


	display_setBackground(red);

	display_machineBottom();
	display_woodMetal();
	display_machineTop();
	display_machineInfo();
	display_menu();
	display_credits();

	display_print();

	usleep(displayFPS);

	//xil_printf("Displayed All.\n");

}

// Display Elements

void display_machineBottom() {

	conveyor_draw();
	conveyor_band();

}

void display_machineTop() {



	metaldect_draw();
	metaldect_drawSphere();

	laser_draw();
	laser_drawLaserShots();

	marker_draw();

}

void display_woodMetal() {

	wood_drawAll();
}

void display_machineInfo() {

	// Conveyor Band

	text_begin(150,370);
	text_string("Conveyorband: ",green); text_int((int)conveyorMoved,green); text_string("mm",green);
	text_newLine();
	text_string("Speed: ",CONVEYOR_TEXT_C); text_int((int)conveyorSpeed,CONVEYOR_TEXT_C); text_string("mm/sec",CONVEYOR_TEXT_C);

	text_begin(100,200);
	text_string("Laser Left: ",LASER_TEXT_C); text_int(laser_left_mm,LASER_TEXT_C); text_string("mm",LASER_TEXT_C);

	text_begin(170,150);
	text_string("Laser Top: ",LASER_TEXT_C); text_int(laser_top_mm,LASER_TEXT_C); text_string("mm",LASER_TEXT_C);

	text_begin(220,350);
	text_string("Laser Right:",LASER_TEXT_C); text_int(laser_right_mm,LASER_TEXT_C); text_string("mm",LASER_TEXT_C);

	text_begin(240,330);
	text_string("Laser X: ",LASER_TEXT_C); text_int(laser_x,LASER_TEXT_C);

	text_begin(240,80);
	text_string("Left Metal Detecter: ", METAL_TEXT_C); text_int(metaldect_left_radius, METAL_TEXT_C); text_string("mm",METAL_TEXT_C);

	text_begin(350,370);
	text_string("Right Metal Detector: ", METAL_TEXT_C); text_int(metaldect_right_radius, METAL_TEXT_C); text_string("mm",METAL_TEXT_C);
	text_newLine();
	text_string("Metal Detector X: ",MARKER_TEXT_C);
	text_int(metaldect_x,MARKER_TEXT_C);
	text_newLine();

	text_begin(530,200);
	text_string("Marker X: ", MARKER_TEXT_C);
	text_int(marker_x,MARKER_TEXT_C);
	text_string("mm",MARKER_TEXT_C);

	text_newLine();

	text_string("Marker Y: ", MARKER_TEXT_C);
	text_int(marker_y,MARKER_TEXT_C);
	text_string("mm",MARKER_TEXT_C);

	text_newLine();

	text_string("Marker Z: ", MARKER_TEXT_C);
	text_int(marker_z,MARKER_TEXT_C);
	text_string("mm",MARKER_TEXT_C);

}

void display_menu() {

	draw_square(20,20,170,120,green);

	text_begin(50,30);

	int i;

	int menuPoints = currentMode->menuSelections;

	text_string(currentMode->label,MENU_HEADER_COLOR);
	text_newLine();
	text_newLine();

	//xil_printf("Menupoints: %d\n",menuPoints);

	for(i = 0; i < menuPoints; i++) {
		Mode* newMenu = (Mode*)currentMode->menu[i];
		text_string(newMenu->label,MENU_TEXT_COLOR);
		text_newLine();
	}

	if(menuPoints) {
		text_begin(30,30+((menuSelection+2)*(CHAR_HEIGHT+CHAR_OFFSET_Y)));
		text_string("x",MENU_TEXT_COLOR);

	}
}

void display_credits() {
	text_begin(20,480-CHAR_HEIGHT-CHAR_OFFSET_Y-20);
	text_string("Project Detect Metal Wood. By Taras Karpin, Jesper Kirial & Niklas Buhl.",green);
}

#endif
