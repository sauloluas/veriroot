module RegisterFile #(parameter 	    D = 8,
					  parameter 	    I = 4)
					 (input				clk,
					  input			    wr_en,
					  input     [I-1:0] dst_id,
					  input	    [I-1:0] src1_id,
					  input	    [I-1:0] src2_id,
					  input	    [D-1:0] dst_in,
					  output    [D-1:0] src1_out,
					  output    [D-1:0] src2_out);

    reg [D-1:0] regarray[2**I-1:0];

    always @ (posedge clk)
    	if (wr_en) regarray[dst_id] <= dst_in;

	assign src1_out = (src1_id != 0) ? regarray[src1_id] : 0;
	assign src2_out = (src2_id != 0) ? regarray[src2_id] : 0;

endmodule