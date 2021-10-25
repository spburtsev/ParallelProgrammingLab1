#include <iostream>
#include <time.h>
#include <cfloat>
#include <Windows.h>
#include <intrin.h>
#include <chrono>
#include <omp.h>

double TimeAccuracy();
double ClockAccuracy();
double GetSystemTimeAsFileTimeAccuracy();
double GetSystemTimePreciseAsFileTimeAccuracy();
int TickAccuracy();
double RdtscAccuracy();
double GetAccuracyQuery();
double ChronoAccuracy();
double OmpAccuracy();

void Task2() {
	cout << "Time Accuracy: " << timeAccuracy() << " s" << endl;
	cout << "Clock Accuracy:" << clockAccuracy() << " ms" << endl;
	cout << "GetSystemTimeAsFileTime Accuracy: " << getSystemTimeAsFileTimeAccuracy() << " s" << endl;
	cout << "GetSystemTimePreciseAsFileTime Accuracy: " << getSystemTimePreciseAsFileTimeAccuracy() << " s" << endl;
	cout << "GetTickCount Accuracy: " << tickAccuracy() << " ms" << endl;
	cout << "rdtsc Accuracy: " << rdtscAccuracy() << " ticks" << endl;
	cout << "QueryPerformanceCounter Accuracy: " << getAccuracyQuery() << endl;
	cout << "Chrono Accuracy: " << chronoAccuracy() << " ns" << endl;
	cout << "Omp Accuracy: " << ompAccuracy() << " s" << endl;

	std::cout << "Time Accuracy: " << TimeAccuracy() << " s" << std::endl;
	std::cout << "Clock Accuracy:" << ClockAccuracy() << " ms" << std::endl;
	std::cout << "GetSystemTimeAsFileTime Accuracy: " << GetSystemTimeAsFileTimeAccuracy() << " ns" << std::endl;
	std::cout << "GetSystemTimePreciseAsFileTime Accuracy: " << GetSystemTimePreciseAsFileTimeAccuracy() << " ns" << std::endl;
	std::cout << "GetTickCount Accuracy: " << TickAccuracy() << " ms" << std::endl;
	std::cout << "rdtsc Accuracy: " << RdtscAccuracy() << " ticks" << std::endl;
	std::cout << "QueryPerformanceCounter Accuracy: " << GetAccuracyQuery() << std::endl;
	std::cout << "Chrono Accuracy: " << ChronoAccuracy() << " ns" << std::endl;
	std::cout << "Omp Accuracy: " << OmpAccuracy() << " s" << std::endl;
}

double TimeAccuracy() 
{
	double min = FLT_MAX;
	for (int i = 0; i < 5; i++)
	{
		double begin = time(NULL);
		double end = begin;
		while (begin==end)
		{
			end = time(0);
		}
		if (min > end - begin) {
			min = end - begin;
		}
	}

	return min;
}

double ClockAccuracy() 
{
	double min = FLT_MAX;
	for (int i = 0; i < 5; i++)
	{
		double begin = clock();
		double end = begin;
		while (begin==end)
		{
			end = clock();
		}
		if (min > end - begin) {
			min = end - begin;
		}
	}
	return min;
}

double GetSystemTimeAsFileTimeAccuracy() 
{
	double min = FLT_MAX;
	for (int i = 0; i < 5; i++)
	{
		FILETIME start, end;
		GetSystemTimeAsFileTime(&start);
		while (true)
		{
			GetSystemTimeAsFileTime(&end);
			if (end.dwLowDateTime != start.dwLowDateTime) break;
		}
		_int64* value1 = (_int64*)&end;
		double val1 = static_cast<double>(*value1);

		_int64* value2 = (_int64*)&start;
		double val2 = static_cast<double>(*value2);

		double res = (val1 - val2);
		if (min > res) {
			min = res;
		}
	}
	return min / 10000000;
}

double GetSystemTimePreciseAsFileTimeAccuracy() 
{
	double min = FLT_MAX;
	for (int i = 0; i < 5; i++)
	{
		FILETIME begin_ft, end_ft;
		GetSystemTimePreciseAsFileTime(&begin_ft);
		while (true)
		{
			GetSystemTimePreciseAsFileTime(&end_ft);
			if (end_ft.dwLowDateTime != begin_ft.dwLowDateTime) break;
		}
		ULARGE_INTEGER begin_long, end_long;

		begin_long.LowPart = begin_ft.dwLowDateTime;
		begin_long.HighPart = begin_ft.dwHighDateTime;

		end_long.LowPart = end_ft.dwLowDateTime;
		end_long.HighPart = end_ft.dwHighDateTime;

		if (min > end_long.QuadPart - begin_long.QuadPart) {
			min = end_long.QuadPart - begin_long.QuadPart;
		}
	}
	return min / 10000000;
}

int tickAccuracy() {
	int min = MAXINT32;
	for (int i = 0; i < 5; i++)
	{
		int begin = GetTickCount();
		int end = begin;
		while (begin == end)
		{
			end = GetTickCount();
		}
		if (min > end - begin) {
			min = end - begin;
		}
	}

	return min;
}

double RdtscAccuracy() 
{
	double min = FLT_MAX;
	for (int i = 0; i < 5; i++)
	{
		int begin = __rdtsc();
		int end = begin;
		while (begin == end) 
		{
			end = __rdtsc();
		}
		if (min > end - begin) 
		{
			min = end - begin;
		}
	}
	return min;
}

double GetAccuracyQuery() 
{
	double min = FLT_MAX;
	LARGE_INTEGER freq;
	for (int i = 0; i < 5; i++)
	{
		LARGE_INTEGER start, end;

		QueryPerformanceCounter(&start);
		do
		{
			QueryPerformanceCounter(&end);
		} 
		while (end.QuadPart - start.QuadPart == 0);

		QueryPerformanceFrequency(&freq);

		if (min > (double)(end.QuadPart - start.QuadPart) / freq.QuadPart) 
		{
			min = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
		}
	}
	return min;
}

double ChronoAccuracy() 
{
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point end;

	do
	{
		end = std::chrono::high_resolution_clock::now();
	} 
	while (end==begin);

	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
	return time_span.count();
}

double OmpAccuracy() 
{
	double min = FLT_MAX;
	for (int i = 0; i < 5; i++)
	{
		double begin = omp_get_wtime();
		double end = begin;
		while (begin==end)
		{
			end = omp_get_wtime();
		}
		if (min > end - begin) 
		{
			min = end - begin;
		}
	}
	return min;
}