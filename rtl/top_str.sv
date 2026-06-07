module Top (input clk);
	import defs::Instruction;
	import dmem::DMemIn;

	Instruction inst;
	logic load = 0;
	logic [7:0] ip_data = 'x;
	logic [7:0] imem_addr;
	DMemIn dmem_in;
	logic [7:0] dmem_out;

	BloodyRoot br (.*);
	Ram dmem (
		.clk(clk),
		.dmem_in(dmem_in),
		.data_out(dmem_out)
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
