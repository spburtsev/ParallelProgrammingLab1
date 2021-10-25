#include <iostream>
#include <iomanip>
#include "Matrices.h"
using Matrices::SquareMatrix;
using Matrices::MultiplyMatrices;

void Task5()
{
    constexpr int SIZE_SMALL = 512;
    constexpr int SIZE_MEDIUM = SIZE_SMALL * 2;
    constexpr int SIZE_LARGE = SIZE_MEDIUM * 2;

    SquareMatrix<int8_t, SIZE_SMALL> smallMatrix1 {};
    SquareMatrix<int8_t, SIZE_SMALL> smallMatrix2 {};
    SquareMatrix<int8_t, SIZE_MEDIUM> mediumMatrix1 {};
    SquareMatrix<int8_t, SIZE_MEDIUM> mediumMatrix2 {};
    SquareMatrix<int8_t, SIZE_MEDIUM> largeMatrix1 {};
    SquareMatrix<int8_t, SIZE_MEDIUM> largeMatrix2 {};

    smallMatrix1.FillWithRandomValues();
    smallMatrix2.FillWithRandomValues();
    SquareMatrix<int8_t, SIZE_SMALL> smallMatrixMultiplyResult = MultiplyMatrices<int8_t, SIZE_SMALL>(smallMatrix1, smallMatrix2);
    std::cout << static_cast<int>(smallMatrix1.GetValueAt(0, 0)) << std::endl;
}