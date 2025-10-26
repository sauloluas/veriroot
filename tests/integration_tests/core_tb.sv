module core_tb();
	import defs::*;

	Instruction inst;
	logic clk = 0;

	BloodyRoot dut (.*);

	always #5 clk = ~clk;

	initial begin
		inst <= {INIT, 4'h1, 8'd20};
		#10;
		inst <= {INIT, 4'h3, 8'd10};
		#10;
		inst <= {ADD, 4'h5, 4'h1, 4'h3};
		#10;
	end

endmodule : core_tb
