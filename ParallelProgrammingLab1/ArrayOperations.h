#include <array>

#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

namespace ArrayOperations
{
	template <class T, size_t S>
	class RandomValuesArrayOperator
	{
	private:
		std::array<T, S> _firstArray = {};
		std::array<T, S> _secondArray = {};

	public:
		explicit RandomValuesArrayOperator()
		{
			for (auto& element : _firstArray)
				element = rand() % 100;

			for (auto& element : _secondArray)
				element = rand() % 100;
		}

		~RandomValuesArrayOperator() = default;

		std::array<T, S> GetArraysSum()
		{
			std::array<T, S> resultArray = {};

			for (size_t i = 0; i != S; ++i)
			{
				resultArray.at(i) = _firstArray.at(i) + _secondArray.at(i);
			}

			return resultArray;
		}
	};
}

#endif