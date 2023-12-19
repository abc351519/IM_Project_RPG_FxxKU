#include <cctype>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
 
#define FLUSH fflush(stdout)
#define SLEEP(time) std::this_thread::sleep_for(std::chrono::milliseconds(time))

int main()
{
    for ( int i = 0; i < 20; i++ )
    {
        std::cout << i << ' ';
        SLEEP(100);
        FLUSH;
    }
    return 0;
}