#ifndef METAL_H
#define METAL_H

#define METAL_SIZE 10
#define METAL_C white
#define METAL_MINIMUM_SPACE 10

typedef struct {

	int id;
	int x;
	int realX;
	int y;
	int z;
	int marked;
	int woodPtr;
	int nextMetal;

} Metal;

Metal* thisMetal;
Metal* nextMetal;

void metal_detect(int z);

void metal_marked(Metal* metal);

void metal_draw(Metal* metal, int startDrawX);

#endif
