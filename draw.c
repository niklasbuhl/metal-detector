#ifndef DRAW_C
#define DRAW_C

#include "draw.h"
#include "color.h"
#include "display.h"
#include "xil_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

//#include <hls_math.h>

float sinus(int angle) {
	switch(angle) {
	case 0:
	case 180:
		return 0.0000;
		break;
	case 15:
	case 165:
		return 0.2588;
		break;
	case 30:
	case 150:
		return 0.5000;
		break;
	case 45:
	case 135:
		return 0.7071;
		break;
	case 60:
	case 120:
		break;
		return 0.8660;
	case 75:
	case 105:
		return 0.9659;
		break;
	case 90:
		return 1.0000;
		break;
	case 195:
	case 345:
		return -0.2588;
		break;
	case 210:
	case 330:
		return -0.5000;
		break;
	case 225:
	case 315:
		return -0.7071;
		break;
	case 240:
	case 300:
		return -0.8660;
		break;
	case 255:
	case 285:
		return -0.9659;
		break;
	case 270:
		return -1;
		break;
	default:
		break;
		return 0;
	}

	return 0;
}

float cosinus(int angle) {
	switch(angle) {
	case 0:
		return 1.0000;
		break;
	case 15:
	case 345:
		return 0.9659;
		break;
	case 30:
	case 330:
		return 0.8660;
		break;
	case 45:
	case 315:
		return 0.7071;
		break;
	case 60:
	case 300:
		break;
		return 0.5000;
	case 75:
	case 285:
		return 0.2588;
		break;
	case 90:
	case 270:
		return 0.0000;
		break;
	case 105:
	case 255:
		return -0.2588;
		break;
	case 120:
	case 240:
		return -0.5000;
		break;
	case 135:
	case 225:
		return -0.7071;
		break;
	case 150:
	case 210:
		return -0.8660;
		break;
	case 165:
	case 195:
		return -0.9659;
		break;
	case 180:
		return -1;
		break;
	default:
		break;
		return 0;
	}

	return 0;
}

float myAngles[14] = {
		0.0000,
		1.0000,
		0.2588,
		0.9659,
		0.5000,
		0.8660,
		0.7071,
		0.7071,
		0.8660,
		0.5000,
		0.9659,
		0.2588,
		1.0000,
		0.0000
};

void draw_rectangle(int startX, int startY, int width, int height, Color c) {

	long p, x, y;

	for(x = startX*3; x < (startX + width)*3; x+=3) {

		p = x + (displayStride * startY);

		for(y = startY; y < startY + height; y++) {

			colorPixel(p,c);
			p += displayStride;

		}
	}

}

void draw_pixel(int x, int y, Color c) {

	long p;

	p = x*3 + (displayStride * y);

	colorPixel(p,c);

}

void draw_line(int startX, int startY, int endX, int endY, Color c) {

	long p,x,y;

	int tempX;
	int tempY;

	if(startX > endX || (startX == endX && endY < startY)) {
		tempX = startX;
		tempY = startY;
		startX = endX;
		startY = endY;
		endX = tempX;
		endY = tempY;
	}

	float slope = (float)(endY - startY) / (float)(endX - startX);

	if(abs(slope) <= 1 ) {

		for(x = startX*3; x < (endX*3); x += 3) {

			p = x + (displayStride * startY);

			y = (x - startX*3) / 3;

			p += (long)(y * slope) * displayStride;

			colorPixel(p,c);

		}

	} else {

		for(y = startY; y < endY; y++) {

			//p = startX * 3;

			//xil_printf("%d\n",(long)(y - startY) * abs(endX-startX) / abs(endY-startY) );

			p = (startX * 3) + (long)(y - startY)* abs(endX-startX) / abs(endY-startY)  * 3;

			p += displayStride * y;

			colorPixel(p,c);

		}

	}

}

void draw_box(int startX, int startY, int length, int height, int depth, Color color) {

	int aX = startX;
	int aY = startY;

	int bX = aX + (int)(displayCos * length);
	int bY = aY - (int)(displaySin * length);

	int cX = bX;
	int cY = bY - height;

	int dX = cX - (int)(displaySin * depth);
	int dY = cY - (int)(displayCos * depth);

	int eX = dX - (int)(displayCos * length);
	int eY = dY + (int)(displaySin * length);

	int fX = eX;
	int fY = eY + height;

	int oX = aX;
	int oY = aY - height;

	int zX = dX;
	int zY = bY - (int)(displayCos * depth);

	draw_line(aX,aY,bX,bY,color);
	draw_line(bX,bY,cX,cY,color);
	draw_line(cX,cY,dX,dY,color);
	draw_line(dX,dY,eX,eY,color);
	draw_line(eX,eY,fX,fY,color);
	draw_line(fX,fY,aX,aY,color);

	draw_line(bX,bY,zX,zY,color);
	draw_line(dX,dY,zX,zY,color);
	draw_line(fX,fY,zX,zY,color);

	draw_line(aX,aY,oX,oY,color);
	draw_line(eX,eY,oX,oY,color);
	draw_line(cX,cY,oX,oY,color);

}

void draw_boxCenter(int centerX, int centerY, int length, int height, int depth, Color color) {

	draw_pixel(centerX, centerY, color);

	int newY;
	int newX;
	newX = centerX;
	newY = centerY;

	newY += (int)(height/2);

	//draw_line(centerX,centerY,newX,newY,blue);

	//int oldX = newX;
	//int oldY = newY;

	newX += (int)(depth/2 * sinus(DISPLAY_ANGLE));
	newY += (int)(depth/2 * cosinus(DISPLAY_ANGLE));

	//draw_line(newX,newY,oldX,oldY,blue);

	//oldX = newX;
	//oldY = newY;

	newX -= (int)(length/2 * cosinus(DISPLAY_ANGLE));
	newY += (int)(length/2 * sinus(DISPLAY_ANGLE));

	//draw_line(newX,newY,oldX,oldY,blue);

	draw_box(newX, newY, length, height, depth, color);

}

void draw_square(int centerX, int centerY, int length, int height, Color color) {

	draw_line(
			centerX,
			centerY,
			centerX + length,
			centerY,
			color
	);

	draw_line(
			centerX + length,
			centerY,
			centerX + length,
			centerY + height,
			color
	);

	draw_line(
			centerX + length,
			centerY + height,
			centerX,
			centerY + height,
			color
	);

	draw_line(
			centerX,
			centerY + height,
			centerX,
			centerY,
			color
	);

}

void draw_circle(int centerX, int centerY, int radius, Color c) {

	if(radius <= 0) return;

	int aX = centerX + radius;
	int aY = centerY;

	int bX;
	int bY;

	int pi;
	int step;

	for(pi = 0; pi < 4; pi++) {

		for(step = 0; step < 6; step++) {

			bX = aX;
			bY = aY;

			switch(pi) {
			case 0:

				aX = centerX + (int)(radius * myAngles[step*2+3]); 	// cos
				aY = centerY - (int)(radius * myAngles[step*2+2]); 	// sin

				break;
			case 1:

				aX = centerX - (int)(radius * myAngles[step*2+2]); 	// sin
				aY = centerY - (int)(radius * myAngles[step*2+3]); 	// cos

				break;
			case 2:
				aX = centerX - (int)(radius * myAngles[step*2+3]); 	// cos
				aY = centerY + (int)(radius * myAngles[step*2+2]); 	// sin

				break;
			case 3:
				aX = centerX + (int)(radius * myAngles[step*2+2]); 	// sin
				aY = centerY + (int)(radius * myAngles[step*2+3]); 	// cos
				break;
			default:
				break;
			}

			draw_line(aX,aY,bX,bY,c);
		}
	}

}

//
// From 3D to 2D functions
//

int scaleToDisplay(int input) {

	return (int)(DISPLAY_SCALE * input);

}

int x_2D_3D(int x, int y, int z) {

	int outputX = originX;

	outputX += (int)(scaleToDisplay(x * cosinus(DISPLAY_ANGLE)));

	outputX = outputX;

	outputX += (int)(scaleToDisplay(z * sinus(DISPLAY_ANGLE)));

	return outputX;

	//return (int)scaleToDisplay(originX + (x * cosinus(DISPLAY_ANGLE)) + (z * sinus(DISPLAY_ANGLE)));

	//return originX + (x * displayCos) + (z * displayCos);

}

int y_2D_3D(int x, int y, int z) {

	int outputY = originY;

	outputY -= (int)(scaleToDisplay(x * sinus(DISPLAY_ANGLE)));

	outputY -= y;

	outputY += (int)(scaleToDisplay(z * cosinus(DISPLAY_ANGLE)));

	return outputY;

	//return (int)scaleToDisplay(originY - y - (x * sinus(DISPLAY_ANGLE) - (z * cosinus(DISPLAY_ANGLE))));

	//return originY - (x * displaySin) + (z * displaySin) + y;

}

//
// 3D Functions
//

void draw3D_box(int centerX, int centerY, int centerZ, int length, int height, int depth, Color color) {

	draw_boxCenter(x_2D_3D(centerX,centerY,centerZ),y_2D_3D(centerX,centerY,centerZ),scaleToDisplay(length),scaleToDisplay(height),scaleToDisplay(depth),color);

}

void draw3D_circle(int centerX, int centerY, int centerZ, int radius, Color color) {

	draw_circle(x_2D_3D(centerX,centerY,centerZ),y_2D_3D(centerX,centerY,centerZ),scaleToDisplay(radius),color);

}

void draw3D_line(int startX, int startY, int startZ, int endX, int endY, int endZ, Color color) {

	draw_line(x_2D_3D(startX,startY,startZ),y_2D_3D(startX,startY,startZ),x_2D_3D(endX,endY,endZ),y_2D_3D(endX,endY,endZ),color);

}

void draw3D_pixel(int centerX, int centerY, int centerZ, Color color) {

	draw_pixel(x_2D_3D(centerX,centerY,centerZ),y_2D_3D(centerX,centerY,centerZ),color);

}

#endif
