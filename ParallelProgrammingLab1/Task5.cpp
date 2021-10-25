#include "ParallelProgrammingLab1.h"
#include "Matrices.h"
#include <cstdint>
using Matrices::MatrixClassMultiplyTest;
using Matrices::MatrixNonClassMultiplyTest;

void Task5()
{
    constexpr int SIZE_SMALL = 512;
    constexpr int SIZE_MEDIUM = SIZE_SMALL * 2;
    constexpr int SIZE_LARGE = SIZE_MEDIUM * 2;

    MatrixClassMultiplyTest<int8_t, SIZE_SMALL>();
    MatrixClassMultiplyTest<int16_t, SIZE_SMALL>();
    MatrixClassMultiplyTest<int32_t, SIZE_SMALL>();
    MatrixClassMultiplyTest<int64_t, SIZE_SMALL>();
    MatrixClassMultiplyTest<double, SIZE_SMALL>();
    PrintTildaDelimeter();

    MatrixClassMultiplyTest<int8_t, SIZE_MEDIUM>();
    MatrixClassMultiplyTest<int16_t, SIZE_MEDIUM>();
    MatrixClassMultiplyTest<int32_t, SIZE_MEDIUM>();
    MatrixClassMultiplyTest<int64_t, SIZE_MEDIUM>();
    MatrixClassMultiplyTest<double, SIZE_MEDIUM>();
    PrintTildaDelimeter();
    
    MatrixClassMultiplyTest<int8_t, SIZE_LARGE>();
    MatrixClassMultiplyTest<int16_t, SIZE_LARGE>();
    MatrixClassMultiplyTest<int32_t, SIZE_LARGE>();
    MatrixClassMultiplyTest<int64_t, SIZE_LARGE>();
    MatrixClassMultiplyTest<double, SIZE_LARGE>();
    PrintTildaDelimeter();

    MatrixNonClassMultiplyTest<int8_t>(SIZE_SMALL);
    MatrixNonClassMultiplyTest<int16_t>(SIZE_SMALL);
    MatrixNonClassMultiplyTest<int32_t>(SIZE_SMALL);
    MatrixNonClassMultiplyTest<int64_t>(SIZE_SMALL);
    MatrixNonClassMultiplyTest<double>(SIZE_SMALL);
    PrintTildaDelimeter();

    MatrixNonClassMultiplyTest<int8_t>(SIZE_MEDIUM);
    MatrixNonClassMultiplyTest<int16_t>(SIZE_MEDIUM);
    MatrixNonClassMultiplyTest<int32_t>(SIZE_MEDIUM);
    MatrixNonClassMultiplyTest<int64_t>(SIZE_MEDIUM);
    MatrixNonClassMultiplyTest<double>(SIZE_MEDIUM);
    PrintTildaDelimeter();

    MatrixNonClassMultiplyTest<int8_t>(SIZE_LARGE);
    MatrixNonClassMultiplyTest<int16_t>(SIZE_LARGE);
    MatrixNonClassMultiplyTest<int32_t>(SIZE_LARGE);
    MatrixNonClassMultiplyTest<int64_t>(SIZE_LARGE);
    MatrixNonClassMultiplyTest<double>(SIZE_LARGE);
    PrintTildaDelimeter();



}