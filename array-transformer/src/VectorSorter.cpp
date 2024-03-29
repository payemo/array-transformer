#include "VectorSorter.hpp"

namespace ng
{
	template<typename T, class P>
	void VectorSorter<T, P>::Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P printer)
	{
		QSort(v1.begin(), 0, v1.size() - 1);
		QSort(v2.begin(), 0, v2.size() - 1);
		QSort(v3.begin(), 0, v3.size() - 1);

		printer(v1);
		printer(v2);
		printer(v3);
	}

	template<typename T, class P>
	void VectorSorter<T, P>::QSort(VecIter<T> it, int from, int to)
	{
		if (from >= 0 && to >= 0 && from < to)
		{
			int pivot = Partition(it, from, to);
			QSort(it, from, pivot);
			QSort(it, pivot + 1, to);
		}
	}

	template<typename T, class P>
	int VectorSorter<T, P>::Partition(VecIter<T> it, int from, int to)
	{
		int m = from + ((to - to) / 2);
		int p = *(it + m);

		int i = from - 1, j = to + 1;
		while (true)
		{
			do { i += 1; } while (*(it + i) < p);

			do { j -= 1; } while (*(it + j) > p);

			if (i >= j) return j;

			Swap(it + i, it + j);
		}

		return j;
	}

	template<typename T, class P>
	void VectorSorter<T, P>::Swap(VecIter<T> a, VecIter<T> b)
	{
		auto tmp = std::move(*a);
		*a = std::move(*b);
		*b = std::move(tmp);
	}

	template class VectorSorter<>;
	/*template class VectorSorter<int>;
	template class VectorSorter<unsigned int>;*/
}