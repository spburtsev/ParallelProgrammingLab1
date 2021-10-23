#include <stdlib.h>
#include <intrin.h>
#include <Windows.h>

// TODO: rework this module

int RtdscTimer();
double QueryTimer();

void  Task3()
{
    
}

int RtdscTimer()
{
    int arr[1000];
    for (int i = 0; i < 1000; i++) 
    {
        arr[i] = rand() % 5 + 1;
    }
    long long sum = 1;
    int begin = __rdtsc();
    for (int i = 0; i < 1000; i++) 
    {
        sum *= arr[i];
    }
    int end = __rdtsc();
        return end - begin;
}

double QueryTimer()
{
    LARGE_INTEGER end, begin, freq;
    long long sum = 1;
    int arr[1000];
    for (int i = 0; i < 1000; i++) 
    {
        arr[i] = rand() % 5 + 1;
    }
    QueryPerformanceCounter(&begin);
    for (int i = 0; i < 1000; i++) 
    {
        sum *= arr[i];
    }
    QueryPerformanceCounter(&end);
    QueryPerformanceFrequency(&freq);
    double res = (end.QuadPart - begin.QuadPart + 0.0) / freq.QuadPart;
    return res;
}

