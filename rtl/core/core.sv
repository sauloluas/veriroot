import defs::*;
import ctrl::CtrlSig;
import dmem::DMemCtrl;

module BloodyRoot (
	input Instruction inst,
	input clk,
	input [7:0] dmem_out,
	output DMemCtrl dmem_ctrl
);

	Opcode opcode;
	logic [11:0] operands;
	CtrlSig ctrl_sig;

	DataPath dp (.*);
	ControlPath cp (.*);

	assign opcode = inst.opcode;
	assign operands = inst.operands;

endmodule : BloodyRoot