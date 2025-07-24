import defs::*;
import ctrl::*;
import alu::AluCmd;


module ControlPath (
	input Opcode opcode,
	output CtrlSig ctrl_sig
);

	always_comb begin
		case (opcode)
			ADD: ctrl_sig <= '{0, 1, alu::ADD};
			NAND: ctrl_sig <= '{0, 1, alu::NAND};
			SHFT: ctrl_sig <= '{0, 1, alu::SHFT};
			INIT: ctrl_sig <= '{1, 1, 'x};
			default: ctrl_sig <= 'x;
		endcase
	end

endmodule : ControlPath