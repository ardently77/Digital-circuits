module top(
	input wire clk,
	input wire rest,
	input wire ps2_clk,
	input wire ps2_data,
	output wire[6:0]seg0,
	output wire[6:0]seg1,
	output wire[6:0]seg2,
	output wire[6:0]seg3,
	output wire[6:0]seg4,
	output wire[6:0]seg5
);
  wire[7:0]out;
	wire[7:0]out2;
	wire[7:0]out3;
  ps2_keyboard my_keyboard(
		.clk(clk),
		.resetn(rest),
		.ps2_clk(ps2_clk),
		.ps2_data(ps2_data),
		.out(out),
		.t(out3)
	);
	seg my_seg1(
		.a(out[3:0]),
		.b(seg0)
	);
	seg my_seg2(
		.a(out[7:4]),
		.b(seg1)
	);
	mem my_mem(
		.in(out),
		.out(out2)
	);
	seg my_seg3(
		.a(out2[3:0]),
		.b(seg2)
	);
	seg my_seg4(
		.a(out2[7:4]),
		.b(seg3)
	);
	seg my_seg5(
		.a(out3[3:0]),
		.b(seg4)
	);
	seg my_seg6(
		.a(out3[7:4]),
		.b(seg5)
	);
endmodule
