
module rom_tb();
	
	reg         clk = 0; 
	reg  [7:0]  addr;
	wire [15:0] data_out; 

	Rom dut (clk, addr, data_out);

	always #5 clk = !clk;
	// always #10 pc = pc + 1;

	initial begin
		addr = 0;
		#10;
		addr = 1;
		#10;
		addr = 2;
		#200;
		$stop;
	end

endmodule
