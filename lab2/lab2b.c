// Kyle Loyka
// ECEN 449 - 503
// Lab2
// lab2a.c

#include<xparameters.h>
#include<xgpio.h>

#define WAIT_VAL 0X1000000 // sets frequency
//#define center 0x100
//#define west 0x80
//#define east 0x40
//#define south 0x20
//#define north 0x10
#define center 0x1
#define west 0x2
#define east 0x4
#define south 0x8
#define north 0x10

int delay(void);

int main(){
	int count = 0;
	int count_masked = 0;
	int switches = 0;
	int disp_mode = 0;
	XGpio led;
	XGpio dips_push;

	// initializing LEDs
	XGpio_Initialize(&led, XPAR_LEDS_DEVICE_ID);
	XGpio_SetDataDirection(&led,1,0);

	// initialize the DIPS and Push buttons
	XGpio_Initialize(&dips_push, XPAR_DIPS_PUSH_DEVICE_ID);
	XGpio_SetDataDirection(&dips_push,1,1);

	xil_printf("start!\n--------------------\n");
	while(1){

		// shows what button(s) are pressed
		//xil_printf("gpio: %x\n\n", XGpio_DiscreteRead(&dips_push,1));

		/* count logic */

		// check if center is pressed, filter out all other inputs
		if( (center & XGpio_DiscreteRead(&dips_push,1) ) == center){
			count = 0;				          // reset count if center  is pressed
			xil_printf("reset\n");         // print action
		}
		// check if north is pressed
		else if( (north & XGpio_DiscreteRead(&dips_push,1) ) == north){
			count++;					          // increment count
			xil_printf("increment count\n"); // print action
		}
		// check if south is pressed
		else if( (south & XGpio_DiscreteRead(&dips_push,1) ) == south){
			count--;					    		 // decrement count
			xil_printf("decrement count\n"); // print action
		}


		/* masking logic */

		// take bottom four bits of count to display on LEDs
		count_masked = 0xf & count;

		// mask for switches (upper four bits of gpio block)
		switches = 0x1E0 & XGpio_DiscreteRead(&dips_push,1);
		// shift bits to lowest order
		switches = switches>>5;


		/* display logic */
		// previous state is kept until new input

		// check if west is pressed
		if( (west & XGpio_DiscreteRead(&dips_push,1) ) == west){
			disp_mode = 1;					     // set display mode
			xil_printf("display count\n\r");
		}
		// check if east is pressed
		else if( (east & XGpio_DiscreteRead(&dips_push,1) ) == east){
			disp_mode = 0;					     // set display mode
			xil_printf("display switches\n\r");
		}

		// display count on LEDs
		if(disp_mode){
			XGpio_DiscreteWrite(&led, 1, count_masked);
			xil_printf("LEDs = %x\n\r", count_masked); // print action, LED value
		}
		// display switches on LEDs
		else {
			XGpio_DiscreteWrite(&led, 1, switches);
			xil_printf("LEDs = %x\n\r", switches);	// print action, LED value
		}

		/* mimick clock */
		delay();
	}

	return 0;
}

// function to delay program execution approximately 1 second
int delay(void){
	volatile int delay_count = 0;
	while(delay_count < WAIT_VAL)
		delay_count++;
	return 0;
}
