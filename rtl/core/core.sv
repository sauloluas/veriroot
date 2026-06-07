import defs::*;
import ctrl::CtrlSig;
import dmem::DMemIn;

module BloodyRoot (
	input Instruction inst,
	input clk,
	input [7:0] dmem_out,
	output DMemIn dmem_in
);

    reg [D-1:0] regarray[2**I-1:0];
	Opcode opcode;
	logic [11:0] operands;
	logic [3:0] ra, rb, rc;

	assign opcode = inst.opcode;
	assign operands = inst.operands;
	assign ra = operands[11:8];
	assign rb = operands[7:4];
	assign rc = operands[3:0];

	always @ (posedge clk) begin
		logic [7:0] reg_b;
		logic [7:0] reg_c;

		reg_b = regarray[rb];
		reg_c = regarray[rc];

		// dmem_in.en = ctrl_sig.dmem_en;
  //      	dmem_in.in = src2_out;
  //      	dmem_in.addr = operands[11:4];

    	case (opcode)
    	    ADD  : regarray[ra] = reg_b + reg_c;
            NAND : regarray[ra] = ~(reg_b & reg_c);
            SHFT : regarray[ra] = reg_c[7] ? reg_b >> reg_c[6:0] : reg_b << reg_c[6:0];
            INIT : regarray[ra] = operands[7:0];
    	endcase
    end




endmodule : BloodyRoot
