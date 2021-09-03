#ifndef MOTOR_H
#define MOTOR_H

long motorCounter;

void motor_init();

void step_1();
void step_2();
void step_3();
void step_4();

void conveyor_forward(long counter);

void conveyor_backward(long counter);

void printer_left();
void printer_light();
void printer_stop();

#endif
