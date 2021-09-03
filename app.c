#ifndef APP_C
#define APP_C

#include <xil_cache.h>
#include <xil_types.h>
#include <xil_printf.h>
#include "app.h"
#include "font.h"
#include "display.h"
#include "sleep.h"
#include "marker.h"
#include "conveyor.h"
#include "laser.h"
#include "metaldetector.h"
#include "control.h"
#include "wood.h"
#include "metal.h"
#include "../IOJD.h"
#include "motor.h"

// Modes

Mode* currentMode;
Mode* prevMode;

int fullauto;

long long systemCounter;

Mode LoadSystem = {
		"Reload System",
		{},
		0,
		0, 0,
		0, &app_setup,
		0, 0
};

Mode Root = {
		"Root",
		{
				(int)&StartStop,
				(int)&SelectMode,
				(int)&Settings,
				(int)&Exit
		},
		4,
		0, &display_all,
		(int)&fullauto, &app_autoMachine,
		0, &app_control
};

Mode SelectMode = {
		"Select Mode",
		{
				(int)&Root,
				(int)&Demo,
				(int)&Disco,
				(int)&Return
		},
		4,
		0, &display_all,
		0, 0,
		0, &app_control
};

Mode StartStop = {
		"Placeholder",
		{},
		0,
		0,0,
		0,0,
		0,0
};
Mode Settings = {
		"Settings",
		{
				(int) &SetConveyorSpeed,
				(int) &SelectViewAngle,
				(int) &SelectFPS,
				(int) &LoadSystem,
				(int) &Demostration,
				(int) &Return,
		},
		6,
		0, &display_all,
		0, 0,
		0, &app_control
};
Mode Exit = {
		"Exit",
		{
				(int) &ExitNo,
				(int) &ExitYes
		},
		2,
		0, &display_all,
		0, &app_exit,
		0, &app_control
};

Mode ExitNo = {
		"No",
		{}, // Menu
		0, // Menu Points
		0, 0, // Display
		0, &app_return,
		0, 0 // Control
};
Mode ExitYes = {
		"Yes",
		{},
		0,
		0, 0,
		0, &app_exit,
		0, 0
};
Mode Demo = {
		"Manuel",
		{
			(int) &StartStopConveyor,
			(int) &SetConveyorSpeed,
			(int) &DetectWood,
			(int) &DetectMetal,
			(int) &ControlLasers,
			(int) &ControlMarker,
			(int) &Return
		},
		7,
		0, &display_all,
		0, &app_demoMachine,
		0, &app_control

};

Mode StartStopConveyor = {
		"Placeholder",
		{},
		0,
		0, 0,
		0, 0,
		0, 0
};

Mode SetConveyorSpeed = {
		"Set Conveyor Speed",
		{}, // Menu
		0, // Menu Points
		0, 0,
		0, 0,
		0, 0,
};

Mode DetectWood = {
		"Placeholder",
		{}, // Menu
		0, // Menu Points
		0, 0,
		0, 0,
		0, 0
};

Mode DetectMetal = {
		"Detect Metal",
		{
				(int) &MetalDetectorLeft,
				(int) &MetalDetectorRight,
				(int) &MetalDetect,
				(int) &Return
		},
		4,
		0, &display_all,
		0, 0,
		0, &app_control
};

Mode MetalDetectorLeft = {
		"Detect Up",
		{},
		0,
		0, 0,
		-1, &metaldect_move,
		0, 0
};
Mode MetalDetectorRight = {
		"Detect Down",
		{},
		0,
		0, 0,
		1, &metaldect_move,
		0, 0
};

Mode MetalDetect = {
		"Detect Metal",
		{},
		0,
		0, 0,
		0, &metal_detect,
		0, 0,
};

Mode ControlLasers = {
		"Control Lasers",
		{
				(int) &LaserTopUp,
				(int) &LaserTopDown,
				(int) &LaserLeftLeft,
				(int) &LaserLeftRight,
				(int) &LaserRightLeft,
				(int) &LaserRightRight,
				(int) &Return
		},
		7,
		0, &display_all,
		0, 0,
		0, &app_control,
};
Mode LaserTopUp = {
		"Move Laser Top Up",
		{},
		0,
		0,0,
		1,&laser_top_move,
		0,0
};

Mode LaserTopDown = {
		"Move Laser Top Down",
		{},
		0,
		0,0,
		-1,&laser_top_move,
		0,0
};

Mode LaserLeftLeft = {
		"Move Laser Left Left",
		{},
		0,
		0,0,
		-1,&laser_left_move,
		0,0
};

Mode LaserLeftRight = {
		"Move Laser Left Right",
		{},
		0,
		0,0,
		1,&laser_left_move,
		0,0
};

Mode LaserRightLeft = {
		"Move Laser Right Left",
		{},
		0,
		0,0,
		-1,&laser_right_move,
		0,0
};

Mode LaserRightRight = {
		"Move Laser Right Right",
		{},
		0,
		0,0,
		1,&laser_right_move,
		0,0
};

Mode ControlMarker = {
		"Control Marker",
		{
				(int) &MarkerLeft,
				(int) &MarkerRight,
				(int) &MarkerMark,
				(int) &Return
		},
		4,
		0,&display_all,
		0,0,
		0,&app_control
};

Mode MarkerLeft = {
		"Move Marker Left",
		{},
		0,
		0,0,
		-1,&marker_move,
		0,0

};
Mode MarkerRight = {
		"Move Marker Right",
		{},
		0,
		0,0,
		1,&marker_move,
		0,0
};

Mode MarkerMark = {
		"Mark!",
		{},
		0,
		0,0,
		0,&marker_mark,
		0,0
};
Mode Return = {
		"Return",
		{},
		0,
		0,0,
		1,&app_return,
		0,0
};
Mode Disco = {
		"Disco",
		{
				(int) &Return
		},
		1,
		0,display_all,
		0,0,
		0,&app_control
};
Mode SelectViewAngle = {
		"Select View Angle",
		{},
		0,
		0,0,
		0,0,
		0,0
};

Mode SelectFPS = {
		"Select FPS",
		{},
		0,
		0,0,
		0,0,
		0,0
};

Mode Demostration = {
		"Demonstration",
		{},
		0,
		0,0,
		7,&app_demostration,
		0,0
};

void app_init(int input) {

	menuSelection = 0;

	autoMode = 0;

	StartStop.label = "Start System";
	StartStop.execute = app_startSystem;

	xil_printf("Setting IO");


}

void init_v2(u8 *framePtr, long width, long height, long stride) {
	xil_printf("Initialize Display...\n");

	display_init_v2(framePtr,width,height,stride);

	xil_printf("Display Initialized!\n");

	currentMode = &LoadSystem;
	prevMode = &Root;

	xil_printf("Starting to load system...\n");
}

void init(u8 *frame, long width, long height, long stride) {

	xil_printf("Initialize Display...\n");

	display_init(frame,width,height,stride);

	xil_printf("Display Initialized!\n");

	currentMode = &LoadSystem;
	prevMode = &Root;

	systemCounter = 0;

	xil_printf("Starting to load system...\n");

	/*

	digitalWrite(0,LOW);
	digitalWrite(1,LOW);
	digitalWrite(2,LOW);
	digitalWrite(3,LOW);

	xil_printf("All low.");

	*/

}

void app_setup() {

	// Initialize Font

	xil_printf("Initializing Font...\n");

	font_init();

	xil_printf("Font Initialized!\n");

	// Hello, World

	display_helloWorld();
	display_print();

	sleep(1);

	int delay = 0;

	// Initialize All Systems

	app_loadStep(0,0,delay,"Initializing All System...");

	// Initialize Machine Systems

	app_loadStep(0,10,delay,"Initializing Machine Systems...");

	// Marker

	app_loadStep(10,12,delay,"Initialize Marker...");

	marker_init();

	app_loadStep(17,17,delay,"Marker Initialized!");

	// Metaldetector

	app_loadStep(17,19,delay,"Initialize Metaldetector...");

	metaldect_init();

	app_loadStep(19,27,delay,"Metaldetector Initialized!");

	// Lasers

	app_loadStep(27,32,delay,"Initialize Lasers...");



	laser_init();

	app_loadStep(32,37,delay,"Metaldetector Initialized!");

	// Motors

	app_loadStep(32,37,delay,"Initialize Motors...");

	motor_init();

	app_loadStep(32,37,delay,"Motors Initialized!");

	// Conveyor

	app_loadStep(37,42,delay,"Initialize Conveyor...");

	conveyor_init(0);

	app_loadStep(42,52,delay,"Conveyor Initialized!");

	// Wood

	app_loadStep(42,52,delay,"Initialize Wood...");

	wood_init();

	app_loadStep(42,52,delay,"Wood Initialized!");

	// Metal

	// Machine Systems

	app_loadStep(52,70,delay,"Machine Systems Initialized!");

	// App

	app_loadStep(70,72,delay,"Initializing Application...");

	app_init(0);

	app_loadStep(72,89,delay,"Application Initialized!");

	// GUI

	app_loadStep(89,91,delay,"Initializing Graphical User Interface...");

	app_loadStep(91,97,delay,"GUI Application Initialized!");

	// All Systems

	app_loadStep(97,100,delay*2,"All Systems Initialized!");

	// Setting Machine

	// Demo

	app_loadStep(100,100,delay*5,"Preparing Demo...");

	app_demostration(10);

	app_resetMachine();

	currentMode = prevMode;

	//prevMode = &Root;

}

void app_main() {

	while(1) {

		systemCounter++;

		if(currentMode->execute != 0)currentMode->execute(currentMode->executeInput);
		if(currentMode->display != 0)currentMode->display(currentMode->displayInput);
		if(currentMode->control != 0)currentMode->control(control_buttons());

	}
}

void app_disco() {

}

void app_control(int input) {

	int menuEnd = currentMode->menuSelections;

	if(input == UP) menuSelection--;
	if(input == DOWN) menuSelection++;

	if(menuSelection < 0) menuSelection = menuEnd;
	if(menuSelection >= menuEnd) menuSelection = 0;

	if(input == SELECT) {
		Mode* selectedMode = (Mode*)currentMode->menu[menuSelection];
		if(selectedMode->menuSelections != 0) {
			prevMode = currentMode;
			currentMode = (Mode*) currentMode->menu[menuSelection];
			menuSelection = 0;
		} else {
			if(selectedMode->execute != 0)selectedMode->execute(selectedMode->executeInput);
		}
	}
}

void app_stopSystem() {
	xil_printf("System has been stopped.");

	conveyorMoving = 0;

	autoMode = 0;

	StartStop.label = "Start System";
	StartStop.execute = app_startSystem;

}

void app_startSystem() {
	xil_printf("System has been started.");

	conveyorMoving = 1;

	autoMode = 1;

	StartStop.label = "Stop System";
	StartStop.execute = app_stopSystem;

}

void app_return() {
	xil_printf("Returning from %s to %s\n",currentMode->label,prevMode->label);
	currentMode = prevMode;
}

void app_exit() {
	// How to quit?
}

void app_loadStep(int prevProg, int newProg, int delay, char* string) {

	if(newProg != prevProg) {

		for(prevProg; prevProg < newProg; prevProg++) {

			display_loading(prevProg,string);

			usleep(displayFPS);

			display_print();

		}

	} else {

		display_loading(prevProg,string);

	}

	sleep(delay);

}

void app_demostration(int s) {

	int timer;

	int duration = s * displayFreq;

	xil_printf("Demostration Duration: %ds\n",duration);

	for(timer = 0; timer < duration; timer++) {

		display_setBackground(red);

		//xil_printf("Timer: %d\n",timer);

		display_menu();

		display_machineBottom();

		display_machineTop();

		conveyor_move(1);

		marker_set(timer%20,50-timer%100);

		metaldect_left(timer%70);
		metaldect_right(70-timer%70);

		laser_top_dist(timer%70);
		laser_left_dist(timer%70);
		laser_right_dist(timer%70);

		display_menu(timer%5);

		display_credits();

		display_machineInfo();

		usleep(displayFPS);

		display_print();

		control_key();

	}

}

void app_autoMachine(int input) {
	if((int*)input) {
		// The Complete System
		conveyor_run();
		laser_run();
		metaldect_run();
		marker_run();
	}
}

void app_demoMachine(int input) {
	conveyor_run();
	//wood_detect();
	laser_run();
	metaldect_run();
	marker_run();
}

void app_resetMachine() {
	marker_set(MARKER_POINT_ORIG_Y,0);

	laser_top_dist(20);
	laser_left_dist(20);
	laser_right_dist(20);

}

#endif
