#include <algorithm> // std::swap
#include <utility> // std::move
#include "Sorter.hpp"

namespace net_game
{
	// PUBLIC DEFINITIONS

	template<typename T>
	void Sorter<T>::Compute(JaggedArray<T>& arr)
	{
		std::size_t l1 = arr.GetArrayNLength(0);
		std::size_t l2 = arr.GetArrayNLength(1);
		std::size_t l3 = arr.GetArrayNLength(2);
		typename std::vector<T>::iterator it = arr.Begin();

		QSort(it, 0, l1 - 1);
		QSort(it + l1, 0, l2 - 1);
		QSort(it + l1 + l2, 0, l3 - 1);
	}

	// PRIVATE DEFINITIONS

	template<typename T>
	void Sorter<T>::QSort(typename std::vector<T>::iterator it, int s, int e)
	{
		if (s >= 0 && e >= 0 && s < e)
		{
			int pi = Partition(it, s, e);
			QSort(it, s, pi);
			QSort(it, pi + 1, e);
		}
		return;
	}

	template<typename T>
	int Sorter<T>::Partition(typename std::vector<T>::iterator it, int s, int e)
	{
		int m = s + ((e - s) / 2);
		int p = *(it + m);

		int i = s - 1, j = e + 1;
		while (true)
		{
			do { i += 1; } while (*(it + i) < p);

			do { j -= 1; } while (*(it + j) > p);

			if (i >= j) return j;

			Swap(it + i, it + j);
		}

		return j;
	}

	template<typename T>
	void Sorter<T>::Swap(
		typename std::vector<T>::iterator it1,
		typename std::vector<T>::iterator it2)
	{
		auto tmp = std::move(*it1);
		*it1 = std::move(*it2);
		*it2 = std::move(tmp);
	}

	template class Sorter<int>;
	template class Sorter<double>;
	template class Sorter<float>;
}