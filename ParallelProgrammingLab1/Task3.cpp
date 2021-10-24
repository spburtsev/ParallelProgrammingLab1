#include <array>
#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <intrin.h>
#include <Windows.h>
#include <tuple>

std::tuple<uint64_t, int32_t> RdtscTimerTest();
std::tuple<uint64_t, int32_t> QueryTimerTest();

void  Task3()
{
    std::cout << "\tTask3:" << std::endl;

    std::tuple<uint64_t, int32_t> rdtscTestResults = RdtscTimerTest();
    std::tuple<uint64_t, int32_t> queryTestResults = QueryTimerTest();

    uint64_t rtdscTime = std::get<0>(rdtscTestResults);
    uint64_t queryTime = std::get<0>(queryTestResults);
    int32_t rtdscTimeSum = std::get<1>(rdtscTestResults);
    int32_t queryTimeSum = std::get<1>(queryTestResults);

    std::cout << "RtsdcTimer result: " << rtdscTime << " ticks, sum = " << rtdscTimeSum << std::endl
        << "QueryTimer result: " << queryTime << " ticks, sum = " << queryTimeSum << std::endl;

}

std::tuple<uint64_t, int32_t> RdtscTimerTest()
{
    uint64_t end;
    uint64_t begin;

    std::array<int16_t, 1000> testArray {};
    for (auto& element : testArray)
        element = rand() % 100 + 1;

    int32_t sum = 0;
    begin = __rdtsc();
    sum = accumulate(testArray.begin(), testArray.end(), sum);
    end = __rdtsc();

    return { (end - begin), sum };
}

std::tuple<uint64_t, int32_t> QueryTimerTest()
{
    LARGE_INTEGER end;
    LARGE_INTEGER begin;

    std::array<int16_t, 1000> testArray {};
    for (auto& element : testArray)
        element = rand() % 100 + 1;

    int32_t sum = 0;
    QueryPerformanceCounter(&begin);
    sum = accumulate(testArray.begin(), testArray.end(), sum);
    QueryPerformanceCounter(&end);

    return { (end.QuadPart - begin.QuadPart), sum };
}

