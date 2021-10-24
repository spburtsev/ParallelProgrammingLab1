#include <iostream>
#include <omp.h>
#include <Windows.h>

constexpr int ARRAY_SIZE = 200000;
int ARR[ARRAY_SIZE];

void initArray();
unsigned int sumArray();
double getTimeInSeconds();
int getTimeInTicks();

void Task4() 
{
    std::cout << "\tTask4:" << std::endl;

    initArray();
    std::cout << "Array size: " << ARRAY_SIZE << std::endl;
    std::cout << "In seconds: " << getTimeInSeconds() << " seconds" << std::endl;
    std::cout << "In ticks: " << getTimeInTicks() << " ticks" << std::endl;
}

void initArray() 
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        ARR[i] = rand() % 50;
    }
}

unsigned int sumArray() 
{
    unsigned int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum += ARR[i];
    }
    return sum;
}

double getTimeInSeconds() 
{
    double time_min, time_cur;
    time_min = FLT_MAX;

    for (int i = 0; i < 6; i++) 
    {
        time_min = FLT_MAX;
        for (int j = 0; j < 6; j++) 
        {
            time_cur = omp_get_wtime();
            sumArray();
            time_cur = omp_get_wtime() - time_cur;
            if (time_cur < time_min) 
            {
                time_min = time_cur;
            }
        }

    }
    return time_min;
}

int getTimeInTicks() 
{
    int count = 0;
    double tick_cur;
    for (int i = 0; i < 6; i++) 
    {
        count = 0;
        tick_cur = GetTickCount();

        while (GetTickCount() - tick_cur < 2000)
        {
            count++;
            sumArray();
        }
    }
    return count;
}


