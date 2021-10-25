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

		void Multiply(SquareMatrix<T, S>& another)
		{
			for (size_t i = 0; i != S * S; ++i)
			{
				_data[i] *= another._data[i];
			}
		}
	};

	template <class T, size_t S>
	SquareMatrix<T, S> MultiplyMatrices(SquareMatrix<T, S>& a, SquareMatrix<T, S>& b)
	{
		SquareMatrix<T, S> multiplyResultMatrix {};
		for (size_t r = 0; r != S; ++r) 
		{
			for (size_t c = 0; c != S; ++c)
			{
				multiplyResultMatrix.SetValueAt(r, c, a.GetValueAt(r, c) * b.GetValueAt(r, c));
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
		for (size_t i = 1; i < rowSize; ++i)
			multiplyResultMatrix[i] = multiplyResultMatrix[i - 1] + rowSize;

		size_t i = 1;

		for (; i < rowSize; ++i)
		{
			multiplyResultMatrix[i] = multiplyResultMatrix[i - 1] + rowSize;
		}

		for (i = 0; i < overallSize; ++i)
		{
			multiplyResultMatrix[0][i] = a[0][i] * b[0][i];
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