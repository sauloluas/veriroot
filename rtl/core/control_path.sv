import defs::*;
import ctrl::*;
import alu::AluCmd;

/*
typedef struct packed {
	// Selects destination register input, 0 = AluOut, 1 = Immediate
	logic dst_in_sel;
	// Enable write on destination register
	logic reg_wr_en;
	// Selects the operation in the alu
	AluCmd alu_cmd;

	logic dmem_en;
} CtrlSig;
*/

module ControlPath (
	input Opcode opcode,
	output CtrlSig ctrl_sig
);

	always_comb begin
		case (opcode)
			defs::ADD: ctrl_sig = '{0, 1, alu::ADD, 0};
			defs::NAND: ctrl_sig = '{0, 1, alu::NAND, 0};
			defs::SHFT: ctrl_sig = '{0, 1, alu::SHFT, 0};
			defs::INIT: ctrl_sig = '{1, 1, alu::DC, 0};
			defs::STOR: ctrl_sig = '{'x, 0, alu::DC, 1};
			default: ctrl_sig = 'x;
		endcase
	end

endmodule : ControlPath
