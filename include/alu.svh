package alu;

	typedef enum logic [1:0] {
		DC = 'x,
		ADD = 2'h0,
		NAND = 2'h1,
		SHFT = 2'h2
	} AluCmd;

	typedef struct packed {
		logic flag;
		logic [2:0] shamt;
	} Immed;

endpackage : alu
