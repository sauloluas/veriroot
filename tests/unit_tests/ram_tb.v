
module ram_tb();
	
	reg        clk = 0; 
	reg		   enable;
	reg  [7:0] addr, data_in; 
	wire [7:0] data_out; 

	Ram dut (clk, enable, addr, data_in, data_out);

	always #5 clk = !clk;

	initial begin
		enable <= 0;
		addr <= 1;
		data_in <= 40;
		#20; 
		enable <= 1;
		#20;
		addr <= 2;
		data_in <= 50;
	end

endmodule
