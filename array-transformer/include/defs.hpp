#pragma once

#include <vector>
#include <deque>
#include <set>
#include <list>
#include <string>
#include <utility>

namespace ng
{
	using String = typename std::string;

	template<typename T>
	using Deque = typename std::deque<T>;

	template<typename T = double>
	using Vec = typename std::vector<T>;

	template<typename T = double>
	using VecIter = typename std::vector<T>::iterator;

	template<typename T>
	using Set = typename std::set<T>;
	template<typename T>
	using ConstSetIter = typename std::set<T>::const_iterator;

	template<typename T>
	using List = typename std::list<T>;

	template<typename T>
	using ConstListIter = typename std::list<T>::const_iterator;

	template<class C1, class C2>
	using Pair = typename std::pair<C1, C2>;
}