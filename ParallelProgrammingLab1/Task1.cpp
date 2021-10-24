#include <iostream>
#include <Time.h>
#include <Windows.h>
#include <Intrin.h>
#include <chrono>
#include <Omp.h>

void TimeToFileTime(time_t time, FILETIME* fileTime);
void PrintTime(SYSTEMTIME systemTime);

void Task1(time_t tm)
{
    std::cout << "\tTask1:" << std::endl;

    SYSTEMTIME stm;
    FILETIME ftm;
    TimeToFileTime(tm, &ftm);
    FileTimeToSystemTime(&ftm, &stm);
    PrintTime(stm);
}

void TimeToFileTime(time_t time, FILETIME* fileTime) 
{
    LONGLONG ll = Int32x32To64(time, 10000000) + 116444736000000000; 
    fileTime->dwLowDateTime = static_cast<DWORD>(ll);
    fileTime->dwHighDateTime = ll >> 32;
}

void PrintTime(SYSTEMTIME stm) 
{
    std::cout << stm.wDay << "." 
        << stm.wMonth << "."
        << stm.wYear << " " 
        << stm.wHour << ":" 
        << stm.wMinute << ":"
        << stm.wSecond << std::endl;
}