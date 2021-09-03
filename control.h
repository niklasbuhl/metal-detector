#ifndef CONTROL_H
#define CONTROL_H

#define UP 1
#define DOWN 2
#define SELECT 3

int pushed;
long lastPush;

int control_key();
int control_buttons();
//int function(void(*func)(int input));

#endif
