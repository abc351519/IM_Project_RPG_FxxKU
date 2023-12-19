#include "def.h"

#include <limits>
#include <random>
#include <cmath>
#include <thread>
#include <chrono>


short odds::rand()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator (seed); 
    return abs(static_cast<short>(generator()/std::numeric_limits<short>::max()));
}