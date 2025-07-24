import defs::*;
import ctrl::CtrlSig;

module BloodyRoot (
	input Instruction inst,
	input clk
);

	Opcode opcode;
	logic [11:0] operands;
	CtrlSig ctrl_sig;

	DataPath dp (.*);
	ControlPath cp (.*);

	assign opcode = inst.opcode;
	assign operands = inst.operands;

endmodule : BloodyRoot