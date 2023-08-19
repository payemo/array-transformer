#pragma once

#include <vector>
#include <set>
#include "Printer.hpp"

namespace net_games
{
	template<typename T>
	using Vec = typename std::vector<T>;

	template<typename T>
	using VecIter = typename std::vector<T>::iterator;

	template<typename T, class P = Printer<T>>
	class ArrayTransformer
	{
	public:
		virtual void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P print = Printer<T>{}) = 0;
	};
}