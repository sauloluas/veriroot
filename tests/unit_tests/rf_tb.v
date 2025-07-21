
module rf_tb();

	reg  	   clk = 0;
	reg 	   wr_en = 0;
	reg [3:0]  dst_id, src1_id, src2_id;
	reg [7:0]  dst_in;
	wire [7:0] src1_out, src2_out;
	

	RegisterFile dut (clk, wr_en, dst_id, src1_id, 
					  src2_id, dst_in, src1_out, src2_out);

	always #5 clk = !clk;

	initial begin
		#1;
		wr_en = 1;
		dst_id = 0'h01;
		dst_in = 0'd10;
		#10;
		dst_id = 0'h02;
		dst_in = 0'd3;
		#10;
		dst_id = 0'h03;
		src1_id = 0'h01;
		#1;
		dst_in = src1_out;
		#9;
		dst_id = 0'h03;
		src1_id = 0'h02;
		src2_id = 0'h03;
		#1;
		dst_in = src1_out + src2_out;
		#9;
	end

endmodule