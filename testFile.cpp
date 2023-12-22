#include <cctype>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
 
#define FLUSH fflush(stdout)
#define SLEEP(time) std::this_thread::sleep_for(std::chrono::milliseconds(time))

int main()
{
    std::string name;
    std::cin >> name;
    name [5] = '\0';
    std::cout << name;
    return 0;
}