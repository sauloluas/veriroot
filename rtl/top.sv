module Top (input clk);
	import defs::Instruction;

	Instruction inst;
	logic load = 0;
	logic [7:0] ip_data = 'x;
	logic [7:0] imem_addr;

	BloodyRoot br (.*);
	// Ram dmem (.*);
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