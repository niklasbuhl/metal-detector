#ifndef MOTOR_C
#define MOTOR_C

#include "../IOJD.h"
#include "motor.h"
#include "sleep.h"
#include <stdio.h>
#include <xil_printf.h>

void motor_init() {

	setIO();

	pinMode(0,OUTPUT);
	pinMode(1,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(6,OUTPUT);
	pinMode(7,OUTPUT);

}

void step_1() {

	//xil_printf("Step 1.\n");

  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);

}

void step_2() {

//	xil_printf("Step 2.\n");

  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void step_3() {

	//xil_printf("Step 3.\n");

  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void step_4() {

 // xil_printf("Step 4.\n");

  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);

}

void conveyor_forward(long counter) {

	//xil_printf("Moving conveyor forward\n");

	switch(counter%4) {
	case 0:
		step_1();
		break;
	case 1:
		step_2();
		break;
	case 2:
		step_3();
		break;
	case 3:
		step_4();
		break;
	default:
		break;
	}

	//usleep(10000);

	/*


	  usleep(10000);
	  step2();
	  usleep(10000);
	  step3();
	  usleep(10000);
	  step4();
	  usleep(10000);
	  printf("run\n\r");

	 */
}

void conveyor_backward(long counter) {

	switch(counter%4) {
	case 0:
		step_4();
		break;
	case 1:
		step_3();
		break;
	case 2:
		step_2();
		break;
	case 3:
		step_1();
		break;
	}

	/*

  step4();
  usleep(10000);
  step3();
  usleep(10000);
  step2();
  usleep(10000);
  step1();
  usleep(10000);
  printf("run\n\r");

  	  */
}

//////////////////////////////////////////////////////////////
/////// Printer hoved ///////////////////////////////////////

void printer_right() {

	xil_printf("Printer Right.\n");
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  usleep(1000);
  printer_stop();
}
void printer_left() {

	xil_printf("Printer Left.\n");

  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  usleep(1000);
  printer_stop();
}
void printer_stop() {
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

#endif
