import dmem::DMemCtrl;

module Ram #(
	parameter D = 8,
	parameter A = 8
) (
	input clk,
	DMemCtrl dmem_ctrl,
	output [D-1:0] data_out
);

	reg [D-1:0] mem_array[2**A-1:0];

	initial $readmemh("bootloader/data.hex", mem_array);

	assign data_out = mem_array[dmem_ctrl.addr];

	always @ (posedge clk) 
		if (dmem_ctrl.en)
			mem_array[dmem_ctrl.addr] <= dmem_ctrl.in;

endmodule
