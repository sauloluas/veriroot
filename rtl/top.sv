import defs::*;

module Top #(parameter A = 12,           // tamanho do endereço
             parameter D = 8,           // tamanho da palavra
             parameter I = 4)            // tamanho do id do reg
            (input clk);

    // rom
    Instruction inst_mem_array[2**A-1:0];
	initial $readmemh("bootloader/text.hex", inst_mem_array);

	// ram
	reg [D-1:0] data_mem_array[2**A-1:0];
	initial $readmemh("bootloader/data.hex", data_mem_array);

	logic [A-1:0] ip = '0;

    Instruction inst;

    reg [D-1:0] regarray[2**I-1:0];
	Opcode opcode;
	logic [11:0] operands;
	logic [I-1:0] ra, rb, rc;
	logic [D-1:0] reg_a;
	logic [D-1:0] reg_b;
	logic [D-1:0] reg_c;

	logic [11:0] label;
	logic [7:0] label_cond;

	always @ (posedge clk) begin
		inst = inst_mem_array[ip];

		opcode = inst.opcode;
		operands = inst.operands;
		ra = operands[11:8];
		rb = operands[7:4];
		rc = operands[3:0];

		reg_a = regarray[ra];
		reg_b = regarray[rb];
		reg_c = regarray[rc];

		label = operands;
		label_cond = operands[7:0];

		ip = ip + 1'b1;

    	case (opcode)
    	    ADD  : regarray[ra] = reg_b + reg_c;
            NAND : regarray[ra] = ~(reg_b & reg_c);
            SHFT : regarray[ra] = reg_c[7] ? reg_b >> reg_c[6:0] : reg_b << reg_c[6:0];
            INIT : regarray[ra] = operands[7:0];
            FTCH : regarray[ra] = data_mem_array[reg_b + reg_c];
            SEND : data_mem_array[reg_b + reg_c] = reg_a;
            LEAP : ip = label;
            WHZR : if (reg_a == 0) ip = label_cond;
            WHNG : if (reg_a[7] == 1) ip = label_cond;
    	endcase

	end

endmodule : Top
