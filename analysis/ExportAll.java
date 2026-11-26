import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class ExportAll extends GhidraScript {
  public void run() throws Exception {
    String out = getScriptArgs()[0];
    DecompInterface di = new DecompInterface();
    di.openProgram(currentProgram);
    PrintWriter pw = new PrintWriter(new FileWriter(out));
    FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
    while (it.hasNext()) {
      Function f = it.next();
      DecompileResults r = di.decompileFunction(f, 60, monitor);
      pw.println("// ===== " + f.getName() + " @ " + f.getEntryPoint());
      if (r != null && r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC());
      else pw.println("// decompile failed");
    }
    pw.close();
  }
}
