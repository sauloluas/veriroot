module Alu #(
	parameter D = 8
) (
	input [D-1:0]  a,
 	input [D-1:0]  b,
 	input Opcode   opcode,
 	output logic [D-1:0] x
);

    logic flag;
    assign flag = b[7];
    logic shamt;
    assign shamt = b[6:0];

	always_comb begin
		case (op)
			NAND: assign x = ~(a & b);
			SHFT: assign x = flag ? a >> shamt : a << shamt;
			ADD: assign x = a + b;
			default: assign x = a + b;
		endcase
	end

endmodule : Alu
