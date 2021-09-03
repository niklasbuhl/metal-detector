#ifndef DISPLAY_H
#define DISPLAY_H

#define MENU_TEXT_COLOR green
#define MENU_HEADER_COLOR blue

#include "color.h"
#include "xil_types.h"
#include "xil_cache.h"

u8* displayFrame;
u8* nextFrame;
u8* displayFramePtr[3];
int frame;
long displayWidth;
long displayHeight;
long displayStride;
int displayFreq;
int displayFPS;

float displaySin;
float displayCos;

int originX;
int originY;

float displayScale; // Pixel to mm

// Display System
void display_init(u8* frame, long width, long height, long stride);
void display_init_v2(u8* framePtr, long width, long height, long stride);
void display_setBackground(Color c);
void display_print();
void display_nextFrame();

// Display Elements
void display_machineBottom();
void display_machineTop();
void display_machineInfo();
void display_woodMetal();
void display_menu();
void display_message(char* message);
void display_console(char** console);
void display_credits();

// Display Modes
void display_helloWorld();
void display_loading(int progress, char* string);
void display_all(int input);

#endif
