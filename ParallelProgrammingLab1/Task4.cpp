#include <iostream>
#include <omp.h>
#include <Windows.h>
using namespace std;

const int array_size = 200000;
int arr[array_size];
void initArray();
unsigned int sumArray();
double getTimeInSeconds();
int getTimeInTicks();

void Task4() {
    initArray();
    cout << "Array size: " << array_size << endl;
    cout << "In seconds: " << getTimeInSeconds() << " seconds" << endl;
    cout << "In ticks: " << getTimeInTicks() << " ticks" << endl;

}

void initArray() {
    for (int i = 0; i < array_size; i++)
    {
        arr[i] = rand() % 50;
    }
}

unsigned int sumArray() {
    unsigned int sum = 0;
    for (int i = 0; i < array_size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double getTimeInSeconds() {

    double time_min, time_cur;
    time_min = FLT_MAX;


    for (int i = 0; i < 6; i++) {
        time_min = FLT_MAX;
        for (int j = 0; j < 6; j++) {
            time_cur = omp_get_wtime();
            sumArray();
            time_cur = omp_get_wtime() - time_cur;
            if (time_cur < time_min) {
                time_min = time_cur;
            }
        }

    }
    return time_min;
}

int getTimeInTicks() {

    int count = 0;
    double tick_cur;
    for (int i = 0; i < 6; i++) {
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


