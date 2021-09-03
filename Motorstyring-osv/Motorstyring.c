

#include "IOJD.h"
#include "Motorstyring.h"
#include "sleep.h"
#include <stdio.h>

/////////////////////////////////////////////////////////////////
////////// Stepper motor //////////////////////////////////////

void rollForward() {

  step1();
  usleep(10000);
  step2();
  usleep(10000);
  step3();
  usleep(10000);
  step4();
  usleep(10000);
  printf("run\n\r");
}

void rollBackward() {

  step4();
  usleep(10000);
  step3();
  usleep(10000);
  step2();
  usleep(10000);
  step1();
  usleep(10000);
  printf("run\n\r");
}

void step1() {

  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}
void step2() {

  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}
void step3() {

  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}
void step4() {

  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}

//////////////////////////////////////////////////////////////
/////// Printer hoved ///////////////////////////////////////

void frem() {

	printf("frem\n\r");
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  usleep(1000);
  stop();
}
void tilbage() {

  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  usleep(1000);
  stop();
}
void stop() {
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}
