// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*7:0*/ Top__DOT__imem_addr;
    CData/*4:0*/ Top__DOT__br__DOT__ctrl_sig;
    CData/*7:0*/ Top__DOT__br__DOT__dp__DOT__src1_out;
    CData/*7:0*/ Top__DOT__br__DOT__dp__DOT__src2_out;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ Top__DOT__inst;
    IData/*16:0*/ Top__DOT__dmem_ctrl;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray;
    VlUnpacked<CData/*7:0*/, 256> Top__DOT__dmem__DOT__mem_array;
    VlUnpacked<SData/*15:0*/, 256> Top__DOT__imem__DOT__mem_array;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop___024root(VTop__Syms* symsp, const char* v__name);
    ~VTop___024root();
    VL_UNCOPYABLE(VTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
