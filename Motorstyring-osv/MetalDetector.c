#ifndef METALDETECTOR_C
#define METALDETECTOR_C


#include "MetalDetector.h"
#include "IOJD.h"

int systemcounter;
int oldSum = 0;
int newSum = 0;
int metalBuffer[100];
int i = 0;
int detect() {
	systemcounter += 1;
  int maxMetal = 0;

  for (i = 0; i < (systemcounter % 100); i++) {
    metalBuffer[systemcounter % 100] = analRead(3);
    newSum += metalBuffer[i];
  }

  for (i = 0; i < (systemcounter % 100); i++) {

    newSum += metalBuffer[i];
  }
  newSum / (systemcounter % 100);

  if (newSum > oldSum) {
    oldSum = newSum;
  }
    else {
    	maxMetal = newSum;
  }
  return maxMetal;
}

#endif
