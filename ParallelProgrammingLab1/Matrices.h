#include <iostream>
#include <stdlib.h>
#include <algorithm>

#ifndef MATRICES_H
#define MATRICES_H

namespace Matrices
{
	template <class T, size_t S>
	class SquareMatrix
	{
	private:
		T* _data = nullptr;

	public:
		explicit SquareMatrix()
			: _data(new T[S * S]) {}

		SquareMatrix(SquareMatrix&& another)
			: _data(another._data) 
		{
			if (another._data)
				another._data = nullptr;
		}

		~SquareMatrix()
		{
			if (_data)
			{
				delete[] _data;
			}
		}

		inline T GetValueAt(size_t row, size_t column) const
		{
			return _data[S * row + column];
		}

		inline T& GetValueAt(size_t row, size_t column)
		{
			return _data[S * row + column];
		}

		inline void SetValueAt(size_t row, size_t column, T value)
		{
			_data[S * row + column] = value;
		}

		inline void FillWithValue(T value)
		{
			std::fill_n(_data, S * S, value);
		}

		inline void FillWithRandomValues()
		{
			for (size_t i = 0; i != S * S; ++i)
			{
				_data[i] = rand() % 100;
			}
		}
	};

	template <class T, size_t S>
	SquareMatrix<T, S> MultiplyMatrices(SquareMatrix<T, S>& a, SquareMatrix<T, S>& b)
	{
		SquareMatrix<T, S> multiplyResultMatrix {};
		size_t i;
		size_t j;
		size_t k;

		for (i = 0; i < S; ++i)
		{
			for (k = 0; k < S; ++k)
			{
				for (j = 0; j < S; ++j)
				{
					multiplyResultMatrix.SetValueAt(i, k, multiplyResultMatrix.GetValueAt(i, k) + a.GetValueAt(i, k) * b.GetValueAt(k, j));
				}
			}
		}
		return multiplyResultMatrix;
	}

	template <class T>
	T** MultiplyArrayMatrices(T** a, T** b, size_t rowSize)
	{
		size_t overallSize = rowSize * rowSize;
		if (!a || !b)
		{
			return nullptr;
		}

		T** multiplyResultMatrix = new T* [rowSize];
		multiplyResultMatrix[0] = new T[overallSize];

		size_t i;
		size_t j;
		size_t k;

		for (i = 1; i < rowSize; ++i)
			multiplyResultMatrix[i] = multiplyResultMatrix[i - 1] + rowSize;

		for (i = 0; i < rowSize; ++i)
		{
			for (k = 0; k < rowSize; ++k)
			{
				for (j = 0; j < rowSize; ++j)
				{
					multiplyResultMatrix[i][k] += multiplyResultMatrix[i][k] + multiplyResultMatrix[k][j];
				}
			}
		}

		return multiplyResultMatrix;
	}

	template<class T, size_t S>
	void MatrixClassMultiplyTest()
	{
		SquareMatrix<T, S> matrix1 {};
		SquareMatrix<T, S> matrix2 {};

		matrix1.FillWithRandomValues();
		matrix2.FillWithRandomValues();

		SquareMatrix<T, S> matrixMultiplyResult = MultiplyMatrices<T, S>(matrix1, matrix2);
	}

	template<class T>
	void MatrixNonClassMultiplyTest(size_t rowSize)
	{
		T** matrix1 = new T * [rowSize];
		T** matrix2 = new T * [rowSize];

		size_t fullSize = rowSize * rowSize;
		matrix1[0] = new T[fullSize];
		matrix2[0] = new T[fullSize];

		size_t i = 0;
		for (; i < fullSize; ++i)
		{
			matrix1[0][i] = rand() % 100;
			matrix2[0][i] = rand() % 100;
		}
		
		for (i = 1; i < rowSize; ++i)
		{
			matrix1[i] = matrix1[i - 1] + rowSize;
			matrix2[i] = matrix2[i - 1] + rowSize;
		}

		T** matrixMultiplyResult = MultiplyArrayMatrices(matrix1, matrix2, rowSize);
	}
}

#endif