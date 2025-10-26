import alu::*;
import ctrl::CtrlSig;

module DataPath (
	input clk,
	input [11:0] operands,
	input CtrlSig ctrl_sig,
	input [7:0] dmem_out,
	output DMemCtrl dmem_ctrl
);

	// rf
	logic wr_en;
	logic [3:0] dst_id;
	logic [3:0] src1_id;
	logic [3:0] src2_id;
	logic [7:0] dst_in;
	logic [7:0] src1_out;
	logic [7:0] src2_out;
	logic [7:0] imm;

	// ula
	logic [7:0] a;
 	logic [7:0] b;
 	Immed n;
	AluCmd cmd;
	logic [7:0] x;

	RegisterFile rf(.*);
	Alu alu (.*);


	
	// register file wirings
	assign wr_en = ctrl_sig.reg_wr_en;
	assign dst_id = operands[11:8];
	assign src1_id = operands[7:4];
	assign src2_id = operands[3:0];
	assign imm = operands[7:0];

	// ula wirings
 	assign n = operands[3:0];
 	assign cmd = ctrl_sig.alu_cmd;

 	assign a = src1_out;
 	assign b = src2_out;
 	assign dst_in = ctrl_sig.dst_in_sel ? imm : x;


endmodule