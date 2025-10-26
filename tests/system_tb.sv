module system_tb();

	logic clk = 0;

	Top dut (clk);

	always #5 clk = ~clk;

endmodule : system_tb