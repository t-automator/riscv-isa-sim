// vslideup.vi vd, vs2, rs1
require((insn.rs2() & (P.VU.vlmul - 1)) == 0);
require((insn.rd() & (P.VU.vlmul - 1)) == 0);
require(insn.rd() != insn.rs2());
if (insn.v_vm() == 0 && P.VU.vlmul > 1)
  require(insn.rd() != 0);

const reg_t offset = insn.v_zimm5();
VI_LOOP_BASE
if (P.VU.vstart < offset && i < offset)
  continue;

switch (sew) {
case e8: {
  VI_XI_SLIDEUP_PARAMS(e8, offset);
  vd = vs2;
}
break;
case e16: {
  VI_XI_SLIDEUP_PARAMS(e16, offset);
  vd = vs2;
}
break;
case e32: {
  VI_XI_SLIDEUP_PARAMS(e32, offset);
  vd = vs2;
}
break;
default: {
  VI_XI_SLIDEUP_PARAMS(e64, offset);
  vd = vs2;
}
break;
}
VI_LOOP_END
