#include <iostream>

// Debugging in VS Code:
// - Click in the margin to the left of a line number to add a breakpoint (red dot).
//   Alternatively, use Toggle Breakpoint (default: F9). Repeat to remove it.
//   Choose a line with executable code, e.g. the call to twoBeatsMs in main below.
// - Select "Lesson — your platform" in Run and Debug, then use Start Debugging
//   (default: F5). Execution pauses BEFORE the breakpoint's line is executed.
// - Step Over (default: F10): execute the current line, including any function calls,
//   then pause at the next line without stepping through those functions.
// - Step Into (default: F11): enter a function called on the current line so you can
//   follow its statements. Try entering twoBeatsMs, then beatDurationMs.
// - Step Out (default: Shift+F11): run the rest of the current function and pause back
//   in its caller. This executes the remaining code; it does not undo the call.
// - Continue (default: F5): run until the next breakpoint or until the program finishes.
//   Other breakpoints can interrupt stepping, including Step Over and Step Out.
//   These are the default shortcuts; use the debug toolbar if keys differ or
//   your keyboard requires Fn to access the function keys.
//
// If the debugger cannot locate a source file:
// - Debug information records source paths. Moved files or mismatched paths can
//   prevent the debugger from finding the file; save and rebuild after changes.
// - Umlauts (e.g. ä, ö, ü) in FILE OR FOLDER NAMES can cause problems with
//   some toolchains or path encodings. They are not inherently invalid, and
//   umlauts in comments or string literals do not by themselves cause this.
// - Match filename capitalization exactly in #include directives and paths.
//   Wrong case usually causes a build error on a case-sensitive filesystem;
//   on a case-insensitive filesystem it may compile but can still cause source
//   lookup problems if the tools compare recorded paths case-sensitively.
// - Check that you are debugging the freshly built executable with debug info
//   (-g on GCC/Clang, /Zi on MSVC). For sources built elsewhere, the debugger
//   may need a source-path mapping (e.g. sourceFileMap in launch.json).

double beatDurationMs(int bpm)
{
    double result = 60000 / bpm; // Deliberate arithmetic bug: investigate with the debugger.
    return result;
}

double twoBeatsMs(int bpm)
{
    double oneBeat = beatDurationMs(bpm);
    return 2.0 * oneBeat;
}

int main()
{
    int bpm = 137;
    double duration = twoBeatsMs(bpm);
    std::cout << duration << " ms\n";
}
