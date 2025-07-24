module dp_tb();
	import alu::AluCmd;
	import ctrl::CtrlSig;

	logic clk = 0;
	logic reg_wr_en;
	logic [11:0] operands;
	AluCmd alu_cmd;
	CtrlSig ctrl_sig;

	DataPath dut (.*);

	always #5 clk = ~clk;

	initial begin
		// testing init instruction
		reg_wr_en <= 1;
		operands <= {4'h1, 8'd20};
		ctrl_sig.dst_in_sel <= 1;
		#10;
		operands <= {4'h3, 8'd10};
		#10;
		// testing add instruction
		operands <= {4'h5, 4'h1, 4'h3};
		ctrl_sig.dst_in_sel <= 0;
		alu_cmd <= alu::ADD;
		#10;
	end

endmodule : dp_tb