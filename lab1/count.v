//Kyle Loyka
//ECEN 449-503
//Lab 1
//counter

`timescale 1ns / 1ps

module count(
    input UP,
    input DOWN,
    input RESET,
    input CLOCK,
     output reg [3:0] LEDS
    );


	/* CLOCK SIGNAL */
	reg [31:0] clkCount = 0;
	reg clk = 0;
	always @(posedge CLOCK) begin
		if(clkCount == 100000000) begin	// CLOCK runs at 100MHz, clk runs at 1Hz
			clkCount <= 0;
			clk <= ~clk;
		end
		else clkCount <= clkCount + 1;
	end
		
	/* change LEDS based on state */
	reg [3:0] count = 4'b0000;	
	always @(posedge clk) begin
		// RESET
		if (RESET) count <= 0;
		
		// state: UP
		else if(UP) begin
			if(count == 4'b1111) begin
				count <= 4'b0000;
			end
			else begin
				count <= count + 1;
			end
		end
		
		// state: DOWN
		else if (DOWN) begin
			if(count == 4'b0000) begin
				count <= 4'b1111;
			end
			else begin
				count <= count - 1;
			end
		end

		// otherwise, stay the same value
		else count <= count;
		
		// update LEDS
		// LED[0] is most significant bit, with LED[3] being least significant
		// count[0] is most significant bit, count[3] is least significant
		LEDS[3] <= count [0];
		LEDS[2] <= count [1];
		LEDS[1] <= count [2];
		LEDS[0] <= count [3];
		
	end

endmodule
