//Kyle Loyka
//ECEN 449 - 503
//Homework 2
//Question 1b


`define MSC   2'b00
`define EVANS 2'b01
`define WEB   2'b10

// Mealy Machine implementation.

module coffeeMachine(
    output reg S, /* when S=0, "Out of Coffee"; S=1: output coffee price.
                     This output value can be used to control the display */
    input clock,
    input reset,
    input V1,  /* tank is 100% full */
    input V2,  /* tank is >= 50% full */
    input V3,  /* tank is empty */
  );

  reg [1:0] state; // need register to store current state

  /* State logic */
  always @(posedge clock, posedge reset) begin
    if(reset) begin // needed incase robot isn't working properly
      state <= MSC; // head back to the MSC on reset
      S <= 0;       // don't sell coffee until issue is fixed
    end

    else begin

      case (state)

      MSC: begin
        if( (~V1) & (~V3) ) begin // not completely full, but not empty either
          state <= MSC; // stay at MSC
          S <= 1;   // sell coffee
        end
        if(V3) begin // empty
          state <= MSC; // stay at MSC
          S <= 0; // no coffee to sell; "Out of Coffee"
        end
        if(V1) begin // 100% full
          state <= EVANS; // go to EVANS
          S <= 1;  // sell coffee
        end
      end

      EVANS: begin
        if(V2) begin // still have more than 50% left
          state <= EVANS; // stay at EVANS
          S <= 1;  // sell coffee
        end
        if (~V2) begin // less than 50% coffee remaining
          state <= WEB; // go to WEB
          S <= 1;  // sell coffee
        end
      end

      WEB: begin
        if(~V3) begin // not empty
          state <= WEB; // stay at WEB
          S <= 1;  // sell coffee
        end
        if (V3) begin // empty, out of coffee
          state <= MSC; // go to MSC
          S <= 0;  // no coffee to sell; "Out of Coffee"
        end

      default: begin // Start at MSC, not selling coffee
        state <= MSC;
        S <= 0;
      end

      endcase
    end
  end

endmodule
