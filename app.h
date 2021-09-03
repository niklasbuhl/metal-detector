#ifndef APP_H
#define APP_H

#include "xil_types.h"

typedef struct {

	char* label;
	int menu[8];
	int menuSelections; // If no menu selections (only execute)

	int displayInput;
	void (*display)(int displayInput);

	int executeInput;
	void (*execute)(int executeInput);

	int controlInput;
	void (*control)(int controlInput);

} Mode;

typedef struct {
	char* label;
	int executeInput;
	void (*execute)(int executeInput);
} Action;

// Modes and Actions

Mode HelloWorld;
Mode LoadSystem;
Mode Root;
Mode SelectMode;
Mode StartStop;
Mode Settings;
Mode Exit;
Mode ExitNo;
Mode ExitYes;
Mode Demo;
Mode StartStopConveyor;
Mode SetConveyorSpeed;
Mode DetectWood;
Mode DetectMetal;
Mode MetalDetectorLeft;
Mode MetalDetectorRight;
Mode MetalDetect;
Mode ControlLasers;
Mode LaserTopUp;
Mode LaserTopDown;
Mode LaserLeftLeft;
Mode LaserLeftRight;
Mode LaserRightLeft;
Mode LaserRightRight;
Mode ControlMarker;
Mode MarkerLeft;
Mode MarkerRight;
Mode MarkerMark;
Mode Return;
Mode Disco;
Mode SelectViewAngle;
Mode SelectFPS;
Mode Demostration;

Mode* currentMode;
Mode* prevMode;

int menuSelection;

long long systemCounter;

int autoMode;

void app_control();

void init(u8 *frame, long width, long height, long stride);
void init_v2(u8 *framePtr, long width, long height, long stride);

//void app_navigation(); // Run application
void app_loading(); // Loading screen
void app_disco();
void app_loadStep(int newProg, int prevProg, int delay, char* string);
void app_main(); // The Main Function

// Execute Functions
void app_init();
void app_setup(); // Setup
void app_startSystem();
void app_stopSystem();
void app_exit();
void app_return();
void app_demostration(int seconds);

// Machine Execution Functions
void app_demoMachine(int input);
void app_autoMachine(int input);
void app_resetMachine();

#endif
