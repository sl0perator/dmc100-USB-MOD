import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
public class Seed extends GhidraScript {
  public void run() throws Exception {
    Memory mem = currentProgram.getMemory();
    AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
    mem.createUninitializedBlock("RAM", sp.getAddress(0x20000000L), 0x18000, false).setWrite(true);
    mem.createUninitializedBlock("PERIPH", sp.getAddress(0x40000000L), 0x30000, false).setVolatile(true);
    mem.createUninitializedBlock("USBOTG", sp.getAddress(0x50000000L), 0x40000, false).setVolatile(true);
    mem.createUninitializedBlock("SCS", sp.getAddress(0xE000E000L), 0x1000, false).setVolatile(true);
    Address base = sp.getAddress(0x08007000L);
    for (int i = 1; i < 92; i++) {
      long v = mem.getInt(base.add(i*4)) & 0xffffffffL;
      if (v == 0 || (v & 1) == 0) continue;
      Address a = sp.getAddress(v & ~1L);
      currentProgram.getProgramContext().setValue(currentProgram.getProgramContext().getRegister("TMode"), a, a, java.math.BigInteger.ONE);
      disassemble(a); createFunction(a, i==1 ? "Reset_Handler" : ("vec_" + i));
    }
  }
}
