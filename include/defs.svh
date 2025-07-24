package defs;

	typedef enum logic [3:0] {
		ADD = 4'h0,
		NAND = 4'h1,
		SHFT = 4'h2,
		LEAP = 4'h7,
		WHZR = 4'h8,
		WHNG = 4'h9,
		INIT = 4'hA,
		LOAD = 4'hB,
		STOR = 4'hC,
		FTCH = 4'hD,
		SEND = 4'hE,
		HALT = 4'hF
	} Opcode;

	typedef struct packed {
		Opcode opcode;
		logic [11:0] operands;
	} Instruction;

endpackage