//Kyle Loyka
//ECEN 449 - 503
//Homework 1
//Question 1

`timescale 1ns/1ps  /* added tilde (`) */

module BuggyCode(input A, input B, input clock, output C);
	wire flag;

	//reg [7:0] data = 8'b10101011; //not needed. changed value to correct bit length identifier.

	reg D; /* changed to reg */
	assign flag = A & B;  /* added 'assign' statement */
	And and1(A,B,C);  /* module needs name. */
	always @(posedge clock)  /* took out the semi-colon */
		begin
			if (flag == 0)
				begin
					 D <= A + C; /* took out assign, so D only changes when the
							desired conditions are met */

					//data <= data & 8'b11111111; removed. Not needed.
					// why is this even here? The 'data' value will never change

				end  /* put 'end' statement */
			else
				D <= ~D; /* since D is only 1 bit, the subtraction basically inverts
					the value of D. */
		end
endmodule

module And(input a, input b, output reg c);
	always @(a or b)
		c <= a & b;  /* removed 'assign' assignment since 'c' is a reg */
endmodule
