package ctrl;
	import alu::AluCmd;

	typedef struct packed {
		// Selects destination register input, 0 = AluOut, 1 = Immediate
		logic dst_in_sel;
		// Enable write on destination register
		logic reg_wr_en;
		// Selects the operation in the alu
		AluCmd alu_cmd;

		logic dmem_en;
	} CtrlSig;

endpackage : ctrl