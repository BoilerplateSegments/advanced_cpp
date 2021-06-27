# C++ but with superior taste and idiosyncrasy

The code here must follow the [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines) and every thing must be as elegant as possible.

> Current reading: C++ Crash Course by Josh Lospinoso -> a good book that throw away old warts.

# Additional links

* `.clang-format` -> https://clang.llvm.org/docs/ClangFormatStyleOptions.html

# Readings

## Encyclopedia

+ <https://www.learncpp.com>

# CRAP

## Windows Garbled

+ Set utf-8 for files
+`SetConsoleOutputCP(CP_UTF8)` <https://docs.microsoft.com/en-us/windows/console/setconsoleoutputcp>

if problem persist
+ Clion -> `SHIFT + CTRL + ALT + /` -> Registry -> Disable `run.Processes.with.pty`
+ Set MSVC flag to treat source as utf-8