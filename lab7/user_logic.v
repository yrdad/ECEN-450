//----------------------------------------------------------------------------
// user_logic.vhd - module
//----------------------------------------------------------------------------
//
// ***************************************************************************
// ** Copyright (c) 1995-2008 Xilinx, Inc.  All rights reserved.            **
// **                                                                       **
// ** Xilinx, Inc.                                                          **
// ** XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"         **
// ** AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND       **
// ** SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,        **
// ** OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,        **
// ** APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION           **
// ** THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,     **
// ** AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE      **
// ** FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY              **
// ** WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE               **
// ** IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR        **
// ** REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF       **
// ** INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS       **
// ** FOR A PARTICULAR PURPOSE.                                             **
// **                                                                       **
// ***************************************************************************
//
//----------------------------------------------------------------------------
// Filename:          user_logic.vhd
// Version:           1.00.a
// Description:       User logic module.
// Date:              Sun Mar 27 12:28:50 2016 (by Create and Import Peripheral Wizard)
// Verilog Standard:  Verilog-2001
//----------------------------------------------------------------------------
// Naming Conventions:
//   active low signals:                    "*_n"
//   clock signals:                         "clk", "clk_div#", "clk_#x"
//   reset signals:                         "rst", "rst_n"
//   generics:                              "C_*"
//   user defined types:                    "*_TYPE"
//   state machine next state:              "*_ns"
//   state machine current state:           "*_cs"
//   combinatorial signals:                 "*_com"
//   pipelined or register delay signals:   "*_d#"
//   counter signals:                       "*cnt*"
//   clock enable signals:                  "*_ce"
//   internal version of output port:       "*_i"
//   device pins:                           "*_pin"
//   ports:                                 "- Names begin with Uppercase"
//   processes:                             "*_PROCESS"
//   component instantiations:              "<ENTITY_>I_<#|FUNC>"
//----------------------------------------------------------------------------

module user_logic
(
  // -- ADD USER PORTS BELOW THIS LINE ---------------
  IR_signal, 
  // -- ADD USER PORTS ABOVE THIS LINE ---------------

  // -- DO NOT EDIT BELOW THIS LINE ------------------
  // -- Bus protocol ports, do not add to or delete 
  Bus2IP_Clk,                     // Bus to IP clock
  Bus2IP_Reset,                   // Bus to IP reset
  Bus2IP_Data,                    // Bus to IP data bus
  Bus2IP_BE,                      // Bus to IP byte enables
  Bus2IP_RdCE,                    // Bus to IP read chip enable
  Bus2IP_WrCE,                    // Bus to IP write chip enable
  IP2Bus_Data,                    // IP to Bus data bus
  IP2Bus_RdAck,                   // IP to Bus read transfer acknowledgement
  IP2Bus_WrAck,                   // IP to Bus write transfer acknowledgement
  IP2Bus_Error                    // IP to Bus error response
  // -- DO NOT EDIT ABOVE THIS LINE ------------------
); // user_logic

// -- ADD USER PARAMETERS BELOW THIS LINE ------------
// --USER parameters added here 
// -- ADD USER PARAMETERS ABOVE THIS LINE ------------

// -- DO NOT EDIT BELOW THIS LINE --------------------
// -- Bus protocol parameters, do not add to or delete
parameter C_SLV_DWIDTH                   = 32;
parameter C_NUM_REG                      = 3;
// -- DO NOT EDIT ABOVE THIS LINE --------------------

// -- ADD USER PORTS BELOW THIS LINE -----------------
input IR_signal; 
// -- ADD USER PORTS ABOVE THIS LINE -----------------

// -- DO NOT EDIT BELOW THIS LINE --------------------
// -- Bus protocol ports, do not add to or delete
input                                     Bus2IP_Clk;
input                                     Bus2IP_Reset;
input      [0 : C_SLV_DWIDTH-1]           Bus2IP_Data;
input      [0 : C_SLV_DWIDTH/8-1]         Bus2IP_BE;
input      [0 : C_NUM_REG-1]              Bus2IP_RdCE;
input      [0 : C_NUM_REG-1]              Bus2IP_WrCE;
output     [0 : C_SLV_DWIDTH-1]           IP2Bus_Data;
output                                    IP2Bus_RdAck;
output                                    IP2Bus_WrAck;
output                                    IP2Bus_Error;
// -- DO NOT EDIT ABOVE THIS LINE --------------------

//----------------------------------------------------------------------------
// Implementation
//----------------------------------------------------------------------------

  // --USER nets declarations added here, as needed for user logic

  // Nets for user logic slave model s/w accessible register example
  reg        [0 : C_SLV_DWIDTH-1]           slv_reg0;
  reg        [0 : C_SLV_DWIDTH-1]           slv_reg1;
  reg        [0 : C_SLV_DWIDTH-1]           slv_reg2;
  wire       [0 : 2]                        slv_reg_write_sel;
  wire       [0 : 2]                        slv_reg_read_sel;
  reg        [0 : C_SLV_DWIDTH-1]           slv_ip2bus_data;
  wire                                      slv_read_ack;
  wire                                      slv_write_ack;
  integer                                   byte_index, bit_index;

  // --USER logic implementation added here

  // ------------------------------------------------------
  // Example code to read/write user logic slave model s/w accessible registers
  // 
  // Note:
  // The example code presented here is to show you one way of reading/writing
  // software accessible registers implemented in the user logic slave model.
  // Each bit of the Bus2IP_WrCE/Bus2IP_RdCE signals is configured to correspond
  // to one software accessible register by the top level template. For example,
  // if you have four 32 bit software accessible registers in the user logic,
  // you are basically operating on the following memory mapped registers:
  // 
  //    Bus2IP_WrCE/Bus2IP_RdCE   Memory Mapped Register
  //                     "1000"   C_BASEADDR + 0x0
  //                     "0100"   C_BASEADDR + 0x4
  //                     "0010"   C_BASEADDR + 0x8
  //                     "0001"   C_BASEADDR + 0xC
  // 
  // ------------------------------------------------------

  assign
    slv_reg_write_sel = Bus2IP_WrCE[0:2],
    slv_reg_read_sel  = Bus2IP_RdCE[0:2],
    slv_write_ack     = Bus2IP_WrCE[0] || Bus2IP_WrCE[1] || Bus2IP_WrCE[2],
    slv_read_ack      = Bus2IP_RdCE[0] || Bus2IP_RdCE[1] || Bus2IP_RdCE[2];

  // implement slave model register read mux
  always @( slv_reg_read_sel or slv_reg0 or slv_reg1 or slv_reg2 )
    begin: SLAVE_REG_READ_PROC

      case ( slv_reg_read_sel )
        3'b100 : slv_ip2bus_data <= slv_reg0;
        3'b010 : slv_ip2bus_data <= slv_reg1;
        3'b001 : slv_ip2bus_data <= slv_reg2;
        default : slv_ip2bus_data <= 0;
      endcase

    end // SLAVE_REG_READ_PROC


  // ------------------------------------------------------------
  // IR_DEMOD HARDWARE LOGIC

  // slv_reg0 holds latest demodulated message
  // slv_reg1 holds running count of # of messages recieved **TA won't check this value
  // slv_reg2 debugging

  reg [17:0] counter = 0; 	// clock cycle counter to determine IR signal type: Start, 1, or 0
  reg [3:0]  msg_index = 0; 	// keeps track of index of the message
  reg [0:11] msg = 12'b0;
  reg [0:11] curr_msg = 12'b0;	// message repeat signal on initial start
  reg buffer = 0;
  reg [3:0] index = 0;
  reg enableCounting = 0;
  reg state = 0;
  reg startFlag = 0;
  reg [17:0] temp = 0;

reg [9:0] slowClkCounter = 0;
reg slowClk = 0;

always@(posedge Bus2IP_Clk) begin
	// this will create a posedge clock signal.
	slowClkCounter <= slowClkCounter + 1;
	if (slowClkCounter == 1000) begin 
		slowClk <= 1;
		slowClkCounter <= 0;
	end
	else slowClk <= 0;
end
	 

always@(posedge slowClk) begin
	
	buffer <= IR_signal;

	slv_reg1 <= index;
	slv_reg2 <= counter;
	
	if (buffer && !IR_signal) enableCounting <= 1;	//negedge
	else if(!buffer && IR_signal) begin		//posedge
		enableCounting <= 0;
	 	counter <= 0;
		index <= index + 1;
		if (startFlag) begin
			if (index < 12) begin
				if (index != 0) msg[index-1] <= state;
			end
			else begin
				slv_reg0 <= msg;
				index <= 0;
				startFlag <= 0;
			end
		end
	end
	if(enableCounting && !IR_signal) begin
		counter <= counter + 1;
		if( (counter < 59) && (counter > 29) ) begin
			state <= 0;
		end
		else if( (counter < 104) && (counter > 74) ) begin
			state <= 1;
		end
		else if( (counter < 300) && (counter > 150) ) begin
			startFlag <= 1;
			index <= 0;
		end

	end
end


/*
reg [31:0] count = 0;
reg [3:0] i = 0;
reg [0:11] m = 0;
reg flag = 0;
reg neg = 0;

always@(posedge slowClk) begin

	buffer <= IR_signal;	
	if (buffer && !IR_signal) neg <= 1; //negedge

	if (!buffer && IR_signal) begin //posedge
		i <= i + 1;
		neg <= 0;
		counter <= 0;
		if (flag && (i > 11) ) begin
			slv_reg0 <= m;
			i <= 0;
			flag <= 0;
		end
	end

	if (neg && !IR_signal) begin
		count <= count + 1;
		if( (29 < count) && (count < 59) ) begin
			m[i] <= 0;	
		end
		else if( (74 < count) && (count < 104) ) begin
			m[i] <= 1;
		end
		else if( (150 < count) && (count < 300) ) begin
			i <= 0;
			flag <= 1;
		end
	end
end
	*/		


/*always@(posedge Bus2IP_Clk) begin

	buffer <= IR_signal;
	
	// edge detection
	if(buffer && !IR_signal) enableCounting <= 1; //negedge enables counting
	else if (!buffer && IR_signal) begin	       //posedge
		enableCounting <= 0; 
		counter <= 0;
		msg_index <= msg_index + 1;

		if (msg_index < 12) begin
			if (startFlag && msg_index != 0) curr_msg[msg_index] <= state;
			else if (startFlag) begin
				slv_reg0 <= curr_msg;
				msg_index <= 0;
				startFlag <= 0;
			end
		end
		

	end
	if(!IR_signal && enableCounting) begin
		counter <= counter + 1; // counting
		if ( (counter < 70000) && (counter > 40000) ) state <= 0;
		else if ( (counter < 110000) && (counter > 85000) ) state <= 1;
		else if( (counter < 190000) && (counter > 165000) ) begin
			msg_index <= 0;
			counter <= 0;
			startFlag <= 1;
		end		
	end
end
*/


  // ------------------------------------------------------------
  // Example code to drive IP to Bus signals
  // ------------------------------------------------------------

  assign IP2Bus_Data    = slv_ip2bus_data;
  assign IP2Bus_WrAck   = slv_write_ack;
  assign IP2Bus_RdAck   = slv_read_ack;
  assign IP2Bus_Error   = 0;

endmodule
