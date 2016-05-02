//Kyle Loyka
//ECEN 449 - 503
//Homework 1
//Question 4,b

`timescale 1ns/1ps

module communication_module(
  inout D,  // allows D to read and write
  input C,
  input read_data_port,
  output write_data_port
  );

  /* module to handle communications of ONE module */

  /* when C is high, take data from the write_data_port and send it through D */
  bufif1 write(D,write_data_port,C);

  /* when C is low, read data from D and output it to read_data_port */
  bufif0 read(read_data_port,D,C);

endmodule
