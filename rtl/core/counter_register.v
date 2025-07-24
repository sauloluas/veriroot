module CounterRegister #(parameter          N = 8)
						(input              clk, l,
						 input      [N-1:0] d,
						 output reg [N-1:0] q);

	initial q = 8'h00;

	always @ (posedge clk)
		if (l)
			q <= d;
		else
			q <= q + 1;

endmodule