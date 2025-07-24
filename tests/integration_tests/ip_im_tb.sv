module ip_im_tb();

	import defs::Instruction;

	reg         clk;
	reg         l = 0;
	reg  [7:0]  d;
	wire [7:0]  addr;
	Instruction data_out;

	CounterRegister ip (clk, l, d, addr);
	Rom ins_mem (clk, addr, data_out);

	initial clk = 0;
	always #5 clk = !clk;

	initial begin
		#40;
		l <= 1;
		d <= 8'h0;
		#10;
		l <= 0;
		#50;
	end

endmodule