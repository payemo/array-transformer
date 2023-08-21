#pragma once

#include <vector>
#include <set>
#include <list>
#include <string>

namespace ng
{
	using String = typename std::string;

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
}