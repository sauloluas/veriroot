import defs::Instruction;

module Rom #(parameter 		    D = 16,
			 parameter		    A = 8)
	 		(input  		    clk,
	  		 input     [A-1:0]  addr,
	  		 output Instruction data_out);

	Instruction mem_array[2**A-1:0];

	initial $readmemh("bootloader/text.hex", mem_array);

	assign data_out = mem_array[addr];

endmodule
