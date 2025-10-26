#include <filesystem>

#include "VTop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main() {
  namespace fs = std::filesystem;

	Verilated::traceEverOn(true);

	VTop* top = new VTop;
	VerilatedVcdC* vcd = new VerilatedVcdC;
	top->trace(vcd, 99);
<<<<<<< Updated upstream
	vcd->open("obj_dir/waves/system.vcd");
=======

  if (!fs::exists("obj_dir/waves/")) {
    fs::create_directories("obj_dir/waves/");
  }

	vcd->open("obj_dir/waves/waveform.vcd");
>>>>>>> Stashed changes

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
