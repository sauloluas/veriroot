#include "VTop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main() {

	Verilated::traceEverOn(true);

	VTop* top = new VTop;
	VerilatedVcdC* vcd = new VerilatedVcdC;
	top->trace(vcd, 99);
	vcd->open("waveform.vcd");

	top->clk = 0;

	for (int i = 0; i < 30; i++) {
		top->clk = !top->clk;
		top->eval();
		vcd->dump(Verilated::time());
		Verilated::timeInc(1);

	}


	vcd->close();
	delete vcd;
	delete top;
	return 0;
}
