import defs::*;
import ctrl::*;
import alu::AluCmd;


module ControlPath (
	input Opcode opcode,
	output CtrlSig ctrl_sig
);

	always_comb begin
		case (opcode)
			ADD: ctrl_sig <= '{0, 1, alu::ADD, 0};
			NAND: ctrl_sig <= '{0, 1, alu::NAND, 0};
			SHFT: ctrl_sig <= '{0, 1, alu::SHFT, 0};
			INIT: ctrl_sig <= '{1, 1, 'x, 0};
			STOR: ctrl_sig <= '{'x, 0, 'x, 1};
			default: ctrl_sig <= 'x;
		endcase
	end

endmodule : ControlPath