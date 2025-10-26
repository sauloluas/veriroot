module cr_tb();
	
	reg  [7:0] d;
	reg        l = 0;
	reg        clk = 0;
	wire [7:0] q;

	CounterRegister dut (clk, l, d, q);

	always #5 clk = !clk;

	initial begin
		#40;
		l <= 1;
		d <= 8'hf0;
		#10;
		l <= 0;
		#40;
		l <= 1;
		d <= 8'h60;
		#10;
		l <= 0;
		#50;
	end

endmodule