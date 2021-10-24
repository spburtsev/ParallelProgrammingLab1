#ifndef MATRICES_H
#define MATRICES_H

namespace Matrices
{
	template <class T>
	class SquareMatrix
	{
	private:
		size_t _rowSize = 0;
		T* _data = nullptr;

	public:
		explicit constexpr SquareMatrix(size_t rowSize) : _rowSize(rowSize)
		{
			_data = new T [rowSize * rowSize];
		}

		~SquareMatrix()
		{
			if (_data)
			{
				delete[] _data;
			}
		}

		inline constexpr T GetRowSize() const
		{
			return _rowSize;
		}

		inline constexpr T GetValueAt(size_t row, size_t column) const
		{
			return _data[_rowSize * row + column];
		}

		inline T& GetValueAt(size_t row, size_t column)
		{
			return _data[_rowSize * row + column];
		}

		inline void SetValueAt(size_t row, size_t column, T value)
		{
			_data[_rowSize * row + column] = value;
		}

		inline void FillWithValue(T value)
		{
			std::fill_n(_data, _rowSize * _rowSize, value);
		}

		void FillWithRandomValues()
		{
			for (size_t i = 0; i != _rowSize * _rowSize; ++i)
			{
				_data[i] = rand() % 100;
			}
		}

		void Multiply(SquareMatrix<T>& another)
		{
			for (size_t i = 0; i != _rowSize * _rowSize; ++i)
			{
				_data[i] *= another._data[i];
			}
		}
	};

	template <class T>
	SquareMatrix<T>* MultiplyMatrices(SquareMatrix<T>& a, SquareMatrix<T>& b)
	{
		size_t firstMatrixRowSize = a.GetRowSize();
		if (firstMatrixRowSize != b.GetRowSize())
		{
			return nullptr;
		}

		SquareMatrix<T>* multiplyResultMatrix = new SquareMatrix<T>(firstMatrixRowSize);
		for (size_t r = 0; r != firstMatrixRowSize; ++r) 
		{
			for (size_t c = 0; c != firstMatrixRowSize; ++c)
			{
				multiplyResultMatrix->SetValueAt(r, c, a.GetValueAt(r, c) * b.GetValueAt(r, c));
			}
		}
		return multiplyResultMatrix;
	}

	template <class T>
	T** MultiplyMatrices(T** a, T** b, size_t rowSize)
	{
		size_t overallSize = rowSize * rowSize;
		if (!a || !b)
		{
			return nullptr;
		}

		T** multiplyResultMatrix = new T* [rowSize];
		multiplyResultMatrix[0] = new T[overallSize];

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
}

#endif