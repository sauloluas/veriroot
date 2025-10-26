// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*4:0*/, 16> VTop__ConstPool__TABLE_h5617c9fb_0;

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vdlyvdim0__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0;
    __Vdlyvdim0__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0 = 0;
    CData/*7:0*/ __Vdlyvval__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0;
    __Vdlyvval__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0;
    __Vdlyvset__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__Top__DOT__dmem__DOT__mem_array__v0;
    __Vdlyvdim0__Top__DOT__dmem__DOT__mem_array__v0 = 0;
    CData/*7:0*/ __Vdlyvval__Top__DOT__dmem__DOT__mem_array__v0;
    __Vdlyvval__Top__DOT__dmem__DOT__mem_array__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__dmem__DOT__mem_array__v0;
    __Vdlyvset__Top__DOT__dmem__DOT__mem_array__v0 = 0;
    // Body
    __Vdlyvset__Top__DOT__dmem__DOT__mem_array__v0 = 0U;
    __Vdlyvset__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0 = 0U;
    if ((0x10000U & vlSelf->Top__DOT__dmem_ctrl)) {
        __Vdlyvval__Top__DOT__dmem__DOT__mem_array__v0 
            = (0xffU & vlSelf->Top__DOT__dmem_ctrl);
        __Vdlyvset__Top__DOT__dmem__DOT__mem_array__v0 = 1U;
        __Vdlyvdim0__Top__DOT__dmem__DOT__mem_array__v0 
            = (0xffU & (vlSelf->Top__DOT__dmem_ctrl 
                        >> 8U));
    }
    vlSelf->Top__DOT__imem_addr = (0xffU & ((IData)(1U) 
                                            + (IData)(vlSelf->Top__DOT__imem_addr)));
    if ((8U & (IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig))) {
        __Vdlyvval__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0 
            = (0xffU & ((0x10U & (IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig))
                         ? (IData)(vlSelf->Top__DOT__inst)
                         : ((0U == (3U & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                          >> 1U))) ? 
                            ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                             + (IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src2_out))
                             : ((1U == (3U & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                              >> 1U)))
                                 ? (~ ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                       & (IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src2_out)))
                                 : ((2U == (3U & ((IData)(vlSelf->Top__DOT__br__DOT__ctrl_sig) 
                                                  >> 1U)))
                                     ? ((8U & (IData)(vlSelf->Top__DOT__inst))
                                         ? ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                            >> (7U 
                                                & (IData)(vlSelf->Top__DOT__inst)))
                                         : ((IData)(vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out) 
                                            << (7U 
                                                & (IData)(vlSelf->Top__DOT__inst))))
                                     : 0U)))));
        __Vdlyvset__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0 = 1U;
        __Vdlyvdim0__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0 
            = (0xfU & ((IData)(vlSelf->Top__DOT__inst) 
                       >> 8U));
    }
    if (__Vdlyvset__Top__DOT__dmem__DOT__mem_array__v0) {
        vlSelf->Top__DOT__dmem__DOT__mem_array[__Vdlyvdim0__Top__DOT__dmem__DOT__mem_array__v0] 
            = __Vdlyvval__Top__DOT__dmem__DOT__mem_array__v0;
    }
    if (__Vdlyvset__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0) {
        vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray[__Vdlyvdim0__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0] 
            = __Vdlyvval__Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray__v0;
    }
    vlSelf->Top__DOT__inst = vlSelf->Top__DOT__imem__DOT__mem_array
        [vlSelf->Top__DOT__imem_addr];
    vlSelf->Top__DOT__br__DOT__dp__DOT__src1_out = 
        ((0U == (0xfU & ((IData)(vlSelf->Top__DOT__inst) 
                         >> 4U))) ? 0U : vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray
         [(0xfU & ((IData)(vlSelf->Top__DOT__inst) 
                   >> 4U))]);
    vlSelf->Top__DOT__br__DOT__dp__DOT__src2_out = 
        ((0U == (0xfU & (IData)(vlSelf->Top__DOT__inst)))
          ? 0U : vlSelf->Top__DOT__br__DOT__dp__DOT__rf__DOT__regarray
         [(0xfU & (IData)(vlSelf->Top__DOT__inst))]);
    __Vtableidx1 = (0xfU & ((IData)(vlSelf->Top__DOT__inst) 
                            >> 0xcU));
    vlSelf->Top__DOT__br__DOT__ctrl_sig = VTop__ConstPool__TABLE_h5617c9fb_0
        [__Vtableidx1];
}

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VTop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VTop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VTop___024root___eval_phase__nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VTop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/top.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VTop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VTop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
