#include "TimerTests.h"

void Task4() 
{
    const size_t SMALL_ARRAY_SIZE = 100'000;
    const size_t MEDIUM_ARRAY_SIZE = 200'000;
    const size_t LARGE_ARRAY_SIZE = 300'000;

    std::cout << "\tTask4:" << std::endl;

    ArrayTest<SMALL_ARRAY_SIZE>();

    ArrayTest<MEDIUM_ARRAY_SIZE>();

    ArrayTest<LARGE_ARRAY_SIZE>();
}