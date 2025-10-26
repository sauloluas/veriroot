module Top (input clk);
	import defs::Instruction;
	import dmem::DMemCtrl;

	Instruction inst;
	logic load = 0;
	logic [7:0] ip_data = 'x;
	logic [7:0] imem_addr;
	DMemCtrl dmem_ctrl;
	logic [7:0] dmem_out;

	BloodyRoot br (.*);
	Ram dmem (
		.clk(clk),
		.dmem_ctrl(dmem_ctrl),
		.data_out(dmem_out),
	);
	Rom imem (
		.clk(clk),
		.addr(imem_addr),
		.data_out(inst)
	);
	CounterRegister ip (
		.clk(clk),
		.l(load),
		.d(ip_data),
		.q(imem_addr)
	);


endmodule : Top