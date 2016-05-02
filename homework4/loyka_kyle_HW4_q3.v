// Kyle Loyka
// ECEN 449
// Assigment 3 - Question 3

module PWM_Converter(
  input PWMSIG,
  input ClkSlowPWM,
  input ClkFast,
  output reg PPMSIG,
  output reg ClkSlowPPM
  );

reg delay;
reg flag = 0;

always@(posedge ClkFast) begin
  delay <= ClkSlowPWM;
  ClkSlowPPM <= delay;
end

always@(posedge ClkFast) begin
  if(PWMSIG) flag <= 1;
  else if (!PWMSIG & flag) begin
    flag <= 0;
    PPMSIG <= 1;
  end
  else if(!PWMSIG & !flag) begin
    PPMSIG <= 0;
  end
end
endmodule
