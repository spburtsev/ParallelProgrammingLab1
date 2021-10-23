#include <iostream>
#include <Time.h>
#include <Windows.h>
#include <Intrin.h>
#include <chrono>
#include <Omp.h>

void TimeToFileTime(time_t time, FILETIME* fileTime);
void PrintTime(SYSTEMTIME systemTime);

void Task1()
{
    // SYSTEMTIME stm;
    // FILETIME ftm;
    // TimeToFileTime(tm, &ftm);
    // FileTimeToSystemTime(&ftm, &stm);
    // PrintTime(stm);
}


// TimeToFileTime is a Windows
// System Information function
// https://docs.microsoft.com/en-us/windows/win32/sysinfo/converting-a-time-t-value-to-a-file-time
// See the link above if you have some questions
void TimeToFileTime(time_t time, FILETIME* fileTime) 
{
    LONGLONG ll = Int32x32To64(time, 10000000) + 116444736000000000; MAXLONGLONG;
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