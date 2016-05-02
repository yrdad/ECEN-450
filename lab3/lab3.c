// Kyle Loyka
// ECEN 449
// Lab 3
// lab3.c

#include<xparameters.h>
#include<multiply.h>


int main(){

	unsigned int input1 = 0;
	unsigned int input2 = 0;
	unsigned int output = 0;

		/* calculating product of various input values */
		for ( ; input1 < 17; input1++){
				// put inputs into registers
				MULTIPLY_mWriteSlaveReg0(XPAR_MULTIPLY_0_BASEADDR, 0, input1);
				MULTIPLY_mWriteSlaveReg1(XPAR_MULTIPLY_0_BASEADDR, 0, 16-input1);

				// read output from hardware
				output = MULTIPLY_mReadSlaveReg2(XPAR_MULTIPLY_0_BASEADDR, 0);

				xil_printf("%d x %d = %d\n\r", input1,16-input1,output);

		}

		input1 = 0;

		/* calculating squares */
		for ( ; input1 < 17; input1++){
				// put inputs into registers
				MULTIPLY_mWriteSlaveReg0(XPAR_MULTIPLY_0_BASEADDR, 0, input1);
				MULTIPLY_mWriteSlaveReg1(XPAR_MULTIPLY_0_BASEADDR, 0, input1);

				// read output from hardware
				output = MULTIPLY_mReadSlaveReg2(XPAR_MULTIPLY_0_BASEADDR, 0);

				xil_printf("%d x %d = %d\n\r", input1,input1,output);

		}


	return 0;
}
