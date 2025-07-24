module alu_tb();
	import alu::*;

	logic [7:0] a, b, x;
	Immed n;
	AluCmd cmd;

	Alu dut (a, b, n, cmd, x);

	initial begin
		a <= 'd6;
		b <= 'd4;
		cmd <= ADD;
		#40;
		a <= 8'b0101;
		b <= 8'b0011;
		cmd <= NAND;
		#40;
		a <= 'd4;
		n <= '{flag: 'b0, shamt: 'd2};
		cmd <= SHFT;
		#40;
		a <= 'd64;
		n <= '{flag: 'b1, shamt: 'd2};
	end


endmodule : alu_tb