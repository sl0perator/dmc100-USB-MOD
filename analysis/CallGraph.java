import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
public class CallGraph extends GhidraScript {
  public void run() throws Exception {
    PrintWriter pw = new PrintWriter(new FileWriter(getScriptArgs()[0]));
    FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
    while (it.hasNext()) {
      Function f = it.next();
      for (Function c : f.getCalledFunctions(monitor))
        pw.println(f.getEntryPoint() + " " + c.getEntryPoint());
    }
    pw.close();
  }
}
