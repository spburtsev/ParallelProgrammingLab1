#include <iostream>

#include "ParallelProgrammingLab1.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"
#include "Task5.h"

int main()
{
<<<<<<< HEAD
   // Task1(0x7FFFFFFF);
    Task2();
    //Task4();
=======
    Task1(0x7FFFFFFF);
    PrintDelimeter();
    
    Task2();
    PrintDelimeter();
    
    Task3();
    PrintDelimeter();
    
    Task4();
    PrintDelimeter();

    Task5();


>>>>>>> master
    return 0;
}

void PrintDelimeter()
{
    std::cout << "---------------------------------" << std::endl;
}

void PrintTildaDelimeter()
{
    std::cout << "~~~~~~~~" << std::endl;
}