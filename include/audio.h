#include <stdio.h>

#ifdef _WIN32 || _WIN64 || __CYGWIN__ || WIN32 || __WIN32 || __WIN32__ || __MINGW32__ || WINNT || __WINNT || __WINNT__ || _X86_ || i386 || __i386
#include <Windows.h>
void beep() 
{
    Beep(440, 1000);
}
#elif __linux__ || linux || __linux 
void beep()
{
    system("echo -e "\007" >/dev/tty10");
}
#elif __APPLE__ || __MACH__
#include <iostream>
void beep()
{
    std::cout << "\a" << std::flush;
}
#else
#include <iostream>
void beep() 
{
    std::cout << "\a" << std::flush;
}
#endif