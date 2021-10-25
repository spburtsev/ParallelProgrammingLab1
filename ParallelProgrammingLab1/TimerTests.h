#include <iostream>
#include <array>
#include <numeric>
#include <omp.h>
#include <Windows.h>

#ifndef TIMER_TESTS_H
#define TIMER_TESTS_H

template <size_t S>
double AbsoluteTimerTest()
{
    std::array<int32_t, S>* testArray = new std::array<int32_t, S>;
    for (auto& element : *testArray)
        element = rand() % 100;

    double currentTime = 0;
    int64_t sum = 0;

    currentTime = omp_get_wtime();
    sum = std::accumulate(testArray->begin(), testArray->end(), 0);
    currentTime = omp_get_wtime() - currentTime;
    
    delete testArray;
    return currentTime;
}

template <size_t S>
double RelativeTimerTest()
{
    std::array<int32_t, S>* testArray = new std::array<int32_t, S>;
    for (auto& element : *testArray)
        element = rand() % 100;

    int64_t currentTick = 0;
    int64_t beginTicks = 0;
    int64_t sum = 0;
    int32_t cycleCounter = 0;

    beginTicks = GetTickCount();
    for (currentTick = GetTickCount64(); currentTick - beginTicks < 2000; currentTick = GetTickCount64())
    {
        sum = std::accumulate(testArray->begin(), testArray->end(), 0);
        ++cycleCounter;
    }
        
    delete testArray;
    return 2.0 / (cycleCounter);
}

template<size_t S>
void ArrayTest()
{
    double absoluteTimerTestResult = AbsoluteTimerTest<S>();
    double relativeTimerTestResult = RelativeTimerTest<S>();

    std::cout << "Array size: " << S << std::endl;
    std::cout << "Absolute: " << absoluteTimerTestResult << " seconds" << std::endl;
    std::cout << "Relative: " << relativeTimerTestResult << " seconds" << std::endl;
}

#endif