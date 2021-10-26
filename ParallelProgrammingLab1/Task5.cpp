#include "ParallelProgrammingLab1.h"
#include "Matrices.h"
#include <typeinfo>
#include <iostream>
#include <omp.h>
using Matrices::MatrixClassMultiplyTest;
using Matrices::MatrixNonClassMultiplyTest;

static constexpr int SIZE_SMALL = 512;
static constexpr int SIZE_MEDIUM = SIZE_SMALL * 2;
static constexpr int SIZE_LARGE = SIZE_MEDIUM * 2;

template<class T>
static void RunClassTest()
{
    double time = 0;
    const char* typeName = typeid(T).name();
    std::cout << "Testing a Class:" << std::endl 
        << "- Matrix 512 x 512 (" << typeName << ")" << std::endl;
    time = omp_get_wtime();
    MatrixClassMultiplyTest<T, SIZE_SMALL>();
    time = time - omp_get_wtime();

    std::cout << time << " s" << std::endl;
    PrintTildaDelimeter();

    std::cout << "- Matrix 1024 x 1024 (" << typeName << ")" << std::endl;
    time = omp_get_wtime();
    MatrixClassMultiplyTest<T, SIZE_MEDIUM>();
    time = time - omp_get_wtime();

    std::cout << time << " s" << std::endl;
    PrintTildaDelimeter();

    std::cout << "- Matrix 2048 x 2048 (" << typeName << ")" << std::endl;
    time = omp_get_wtime();
    MatrixClassMultiplyTest<T, SIZE_LARGE>();
    time = time - omp_get_wtime();

    std::cout << time << " s" << std::endl;
    PrintTildaDelimeter();
}

template<class T>
static void RunNonClassTest()
{
    double time = 0;
    const char* typeName = typeid(T).name();
    std::cout << "Testing Non-Class" << std::endl
        << "- Matrix 512 x 512 (" << typeName << ")" << std::endl;
    time = omp_get_wtime();
    MatrixNonClassMultiplyTest<T>(SIZE_SMALL);
    time = time - omp_get_wtime();

    std::cout << time << " s" << std::endl;
    PrintTildaDelimeter();

    std::cout << "- Matrix 1024 x 1024 (" << typeName << ")" << std::endl;
    time = omp_get_wtime();
    MatrixNonClassMultiplyTest<T>(SIZE_MEDIUM);
    time = time - omp_get_wtime();

    std::cout << time << " s" << std::endl;
    PrintTildaDelimeter();

    std::cout << "- Matrix 2048 x 2048 (" << typeName << ")" << std::endl;
    time = omp_get_wtime();
    MatrixNonClassMultiplyTest<T>(SIZE_LARGE);
    time = time - omp_get_wtime();

    std::cout << time << " s" << std::endl;
    PrintTildaDelimeter();
}



void Task5()
{
    RunClassTest<int8_t>();
    RunClassTest<int16_t>();
    RunClassTest<int32_t>();
    RunClassTest<int64_t>();
    RunClassTest<float>();
    RunClassTest<double>();

    RunNonClassTest<int8_t>();
    RunNonClassTest<int16_t>();
    RunNonClassTest<int32_t>();
    RunNonClassTest<int64_t>();
    RunNonClassTest<float>();
    RunNonClassTest<double>();
}