// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop___024root__trace_chg_0_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_0\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VTop___024root__trace_chg_0_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->Top__DOT__inst),16);
        bufp->chgCData(oldp+1,(vlSelf->Top__DOT__imem_addr),8);
        bufp->chgCData(oldp+2,(vlSelf->Top__DOT__dmem__DOT__mem_array
                               [(0xffU & (vlSelf->Top__DOT__dmem_ctrl 
                                          >> 8U))]),8);
        bufp->chgCData(oldp+3,((0xfU & ((IData)(vlSelf->Top__DOT__inst) 
                                        >> 0xcU))),4);
        bufp->chgSData(oldp+4,((0xfffU & (IData)(vlSelf->Top__DOT__inst))),12);
        bufp->chgCData(oldp+5,(vlSelf->Top__DOT__br__DOT__ctrl_sig),5);
        bufp->chgBit(oldp+6,((1U & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                    >> 3U))));
        bufp->chgCData(oldp+7,((0xfU & ((IData)(vlSelf->Top__DOT__inst) 
                                        >> 8U))),4);
        bufp->chgCData(oldp+8,((0xfU & ((IData)(vlSelf->Top__DOT__inst) 
                                        >> 4U))),4);
        bufp->chgCData(oldp+9,((0xfU & (IData)(vlSelf->Top__DOT__inst))),4);
        bufp->chgCData(oldp+10,((0xffU & ((0x10U & (IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig))
                                           ? (IData)(vlSelf->Top__DOT__inst)
                                           : ((0U == 
                                               (3U 
                                                & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                                   >> 1U)))
                                               ? ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                                  + (IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src2_out))
                                               : ((1U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                                       >> 1U)))
                                                   ? 
                                                  (~ 
                                                   ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                                    & (IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src2_out)))
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                                        >> 1U)))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->Top__DOT__inst))
                                                     ? 
                                                    ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                                     >> 
                                                     (7U 
                                                      & (IData)(vlSelf->Top__DOT__inst)))
                                                     : 
                                                    ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                                     << 
                                                     (7U 
                                                      & (IData)(vlSelf->Top__DOT__inst))))
                                                    : 0U)))))),8);
        bufp->chgCData(oldp+11,(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out),8);
        bufp->chgCData(oldp+12,(vlSelf->Top__DOT__br__DOT__dp__DOT__src2_out),8);
        bufp->chgCData(oldp+13,((0xffU & (IData)(vlSelf->Top__DOT__inst))),8);
        bufp->chgCData(oldp+14,((3U & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                       >> 1U))),2);
        bufp->chgCData(oldp+15,((0xffU & ((0U == (3U 
                                                  & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                                     >> 1U)))
                                           ? ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                              + (IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src2_out))
                                           : ((1U == 
                                               (3U 
                                                & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                                   >> 1U)))
                                               ? (~ 
                                                  ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                                   & (IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src2_out)))
                                               : ((2U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                                       >> 1U)))
                                                   ? 
                                                  ((8U 
                                                    & (IData)(vlSelf->Top__DOT__inst))
                                                    ? 
                                                   ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                                    >> 
                                                    (7U 
                                                     & (IData)(vlSelf->Top__DOT__inst)))
                                                    : 
                                                   ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                                    << 
                                                    (7U 
                                                     & (IData)(vlSelf->Top__DOT__inst))))
                                                   : 0U))))),8);
        bufp->chgCData(oldp+16,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[0]),8);
        bufp->chgCData(oldp+17,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[1]),8);
        bufp->chgCData(oldp+18,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[2]),8);
        bufp->chgCData(oldp+19,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[3]),8);
        bufp->chgCData(oldp+20,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[4]),8);
        bufp->chgCData(oldp+21,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[5]),8);
        bufp->chgCData(oldp+22,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[6]),8);
        bufp->chgCData(oldp+23,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[7]),8);
        bufp->chgCData(oldp+24,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[8]),8);
        bufp->chgCData(oldp+25,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[9]),8);
        bufp->chgCData(oldp+26,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[10]),8);
        bufp->chgCData(oldp+27,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[11]),8);
        bufp->chgCData(oldp+28,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[12]),8);
        bufp->chgCData(oldp+29,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[13]),8);
        bufp->chgCData(oldp+30,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[14]),8);
        bufp->chgCData(oldp+31,(vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[15]),8);
    }
    bufp->chgBit(oldp+32,(vlSelf->clk));
}

void VTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_cleanup\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
