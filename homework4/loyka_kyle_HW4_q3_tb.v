// Kyle Loyka
// ECEN 449
// Assignment 3 - Question 3
// TEST BENCH
`timescale 1ns/1ps

module PWM_Converter_tb;

	reg PWMSIG = 0;
	reg ClkSlowPWM = 0;
	reg ClkFast;
	reg PPMSIG;
	reg ClkSlowPPM;

	/* instantiate unit under test */
	PWM_Converter q3(
		.PWMSIG(PWMSIG),
		.ClkSlowPWM(ClkSlowPWM),
		.ClkFast(ClkFast),
		.PPMSIG(PPMSIG),
		.ClkSlowPPM(ClkSlowPPM)
	);

	/* setting up clocks */
	initial begin
		ClkFast = 1;
		repeat(325)
		 #1 ClkFast = ~ClkFast;
	end

	initial begin
		ClkSlowPWM = 0;
		#16
		repeat(18)
		#16 ClkSlowPWM <= ~ClkSlowPWM;
	end

	/* time to drive signals to the module and see the output */
	initial begin

		int sigs[8] = '{1,2,7,8,10,12,15,3};
		#32 PWMSIG = 0;
		for(int i = 0; i < 8; i++) begin
			PWMSIG <= 1;
			#(2*sigs[i]) PWMSIG <= 0; // signals are in units of 2ns
			#(32-(2*sigs[i])) PWMSIG <= 0; //wait the rest of the time
		end
	end

endmodule
