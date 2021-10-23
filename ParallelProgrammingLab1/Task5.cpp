#include <iostream>
#include <iomanip>
#include "Matrices.h"
using Matrices::SquareMatrix;
using Matrices::MultiplyMatrices;

void task5()
{
    constexpr int SIZE_SMALL = 512;
    constexpr int SIZE_MEDIUM = SIZE_SMALL * 2;
    constexpr int SIZE_LARGE = SIZE_MEDIUM * 2;

    SquareMatrix<int8_t> smallMatrix1(SIZE_SMALL);
    SquareMatrix<int8_t> smallMatrix2(SIZE_SMALL);
    SquareMatrix<int8_t> mediumMatrix1(SIZE_MEDIUM);
    SquareMatrix<int8_t> mediumMatrix2(SIZE_MEDIUM);
    SquareMatrix<int8_t> largeMatrix1(SIZE_MEDIUM);
    SquareMatrix<int8_t> largeMatrix2(SIZE_MEDIUM);

    smallMatrix1.FillWithRandomValues();
    smallMatrix2.FillWithRandomValues();
    SquareMatrix<int8_t>* smallMatrixMultiplyResult = MultiplyMatrices<int8_t>(smallMatrix1, smallMatrix2);
    std::cout << static_cast<int>(smallMatrix1.GetValueAt(0, 0)) << std::endl;
}