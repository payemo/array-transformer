#pragma once

#include <vector>
#include <set>
#include "PrintOutput.hpp"

namespace ng
{
	template<typename T = double>
	using Vec = typename std::vector<T>;

	template<typename T = double>
	using VecIter = typename std::vector<T>::iterator;

	template<typename T = double, class P = PrintOutput<T>>
	class ArrayTransformer
	{
	public:
		virtual void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P print = PrintOutput<T>{}) = 0;
	};
}