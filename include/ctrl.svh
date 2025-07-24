package ctrl;

	typedef struct packed {
		// Selects destination register input, 0 = AluOut, 1 = Immediate
		logic dst_in_sel;
	} CtrlSig;

endpackage : ctrl