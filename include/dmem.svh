package dmem;

	typedef struct packed {
		logic en;
		logic [7:0] addr;
		logic [7:0] in;
	} DMemIn;

endpackage : dmem