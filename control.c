#ifndef CONTROL_C
#define CONTROL_C

//#include <video_demo.h>
//#include "video_capture/video_capture.h"
//#include "display_ctrl/display_ctrl.h"
//#include "intc/intc.h"
#include <stdio.h>
#include "xuartps.h"
#include "math.h"
#include <ctype.h>
#include <stdlib.h>
#include "xil_types.h"
#include "xil_cache.h"
//#include "timer_ps/timer_ps.h"
#include "xparameters.h"
#include "meta.h"
#include "control.h"
#include "app.h"
#include "../IOJD.h"

int control_key() {

	char input;

	/* Wait for data on UART */
	//while (!XUartPs_IsReceiveData(UART_BASEADDR))
	//{}

	/* Store the first character in the UART receive FIFO and echo it */
	if (XUartPs_IsReceiveData(UART_BASEADDR))

	{
		input = XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
		xil_printf("%c", (char)input);
	}

	switch(input) {
	case('u'):
			input = UP;
			break;
	case('d'):
			input = DOWN;
			break;
	case('s'):
			input = SELECT;
			break;
	default:
		input = 0;
		break;
	}

	return (int)input;
}

int control_button() {

}

int control_buttons() {

	int input = 0;

	if(digitalRead(16)) input = SELECT; // Select
	if(digitalRead(17)) input = UP;
	if(digitalRead(18)) input = DOWN;

	if(input) lastPush = systemCounter;

	return input;
}

#endif
