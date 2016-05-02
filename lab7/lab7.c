

//Lab 7


#include<xparameters.h>
#include<ir_demod.h>

int main(void){
	
	Xuint32 i = 0;
	Xuint32 j = 0;
	Xuint32 k = 0;
	
	xil_printf("START\n\r*********************************************\n\r");
		
	while(1){
		i = IR_DEMOD_mReadSlaveReg0(XPAR_IR_DEMOD_0_BASEADDR,0);

		j = IR_DEMOD_mReadSlaveReg1(XPAR_IR_DEMOD_0_BASEADDR,0);

		k = IR_DEMOD_mReadSlaveReg2(XPAR_IR_DEMOD_0_BASEADDR,0);
		xil_printf("ir code: %x     j_param: %x     k_param:%x\n\r",i,j,k);
		
	}


/*	Xuint32 i;
	while(1){
		i = IR_DEMOD_mReadSlaveReg0(XPAR_IR_DEMOD_0_BASEADDR,0);
		xil_printf("code: %x\n\r",i);
	}
*/
return 0;
}
