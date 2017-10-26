#include <stdlib.h>
#include <signal.h>
#include <tchar.h>

extern "C" { #include "c_interface.h" }
#include "StackWalker.h"

void SignalHandler(int signal)
{
    StackWalker sw; sw.ShowCallstack();
    exit(1);
}

extern "C" void _install_win32_handlers()
{
    typedef void (*SignalHandlerPointer)(int);

    SignalHandlerPointer previousHandler;
    previousHandler = signal(SIGSEGV , SignalHandler);
}
