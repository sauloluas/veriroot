package defs;

	typedef enum logic [3:0] {
		ADD = 4'h0,
		NAND = 4'h1,
		SHFT = 4'h2,
		LEAP = 4'h7,
		WHZR = 4'h8,
		WHNG = 4'h9,
		INIT = 4'hA,
		FTCH = 4'hB,
		SEND = 4'hC
	} Opcode;

	typedef struct packed {
		Opcode opcode;
		logic [11:0] operands;
	} Instruction;

	function logic WriteEnable (Opcode op);
	    logic wr_en = 0;
	    case (op)
			ADD, NAND, SHFT, INIT : wr_en = 1;
			default : wr_en = 0;
		endcase
		return wr_en;
	endfunction;

endpackage
