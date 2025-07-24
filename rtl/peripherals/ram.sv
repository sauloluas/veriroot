module Ram #(parameter 		   D = 8,
		     parameter 	       A = 8)
	 		(input  		   clk, enable,
	  		 input     [A-1:0] addr,
	  		 input     [D-1:0] data_in,
	  		 output    [D-1:0] data_out);

	reg [D-1:0] mem_array[2**A-1:0];

	initial $readmemh("bootloader/data.hex", mem_array);

	assign data_out = mem_array[addr];

	always @ (posedge clk) 
		if (enable)
			mem_array[addr] <= data_in;

endmodule
