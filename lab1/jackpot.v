`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:45:51 01/28/2016 
// Design Name: 
// Module Name:    jackpot 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module jackpot(
    output reg [3:0] LEDS,
    input CLOCK,
    input [3:0] SWITCHES
    );
	 
//internal nets
reg clk;
reg [31:0] peak;
reg [3:0] state;

//initialize values
initial begin
clk <= 0;
peak <= 0;
state <= 1;
end

//divide internal clock to create a slower clock (clk)
always @(posedge CLOCK) begin
	if(peak <= 32'd5000000) begin 
		peak <= peak + 1;							//counting posedges of CLOCK
		clk <= clk;									
		end
	else begin
		peak <= 0;
		clk <= ~clk;								//slower clk signal has period of 0.05s -> clk at 20Hz
		end
end

//LED states
always @(posedge clk) begin
case(state)
	1: 
	begin
		LEDS[3:0] <= 4'b0001;					//LED illumination pattern
		if(SWITCHES[3:0] == 4'b0001) begin	//win condition
			state <= 5;
		end
		else begin
			state <= 2;								//next state logic
		end
	end
	2: 
	begin
		LEDS[3:0] <= 4'b0010;
		if(SWITCHES[3:0] == 4'b0010) begin
			state <= 5;
		end
		else begin
			state <= 3;
		end
	end
	3: 
	begin
		LEDS[3:0] <= 4'b0100;
		if(SWITCHES[3:0] == 4'b0100) begin
			state <= 5;
		end
		else begin
			state <= 4;
		end
	end
	4: 
	begin
		LEDS[3:0] <= 4'b1000;
		if(SWITCHES[3:0] == 4'b1000) begin
			state <= 5;
		end
		else begin
			state <= 1;
		end
	end
	5: 												//win state
	begin
		LEDS[3:0] <= 4'b1111;
		if(SWITCHES[3:0] == 4'b0000) begin	//reset when switches are flipped off
			state <= 1;
		end
	end
endcase
end

endmodule
