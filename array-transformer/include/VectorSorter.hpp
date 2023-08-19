#pragma once
#include <utility> // std::move
#include "ArrayTransformer.hpp"

namespace net_games
{
	template<typename T, class P = Printer<T>>
	class VectorSorter : public ArrayTransformer<T, P>
	{
	public:
		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P printer) override;

		friend class ArraySorterPrinter;

	protected:
		void QSort(VecIter<T> it, int from, int to);

		int Partition(VecIter<T> it, int from, int to);

		void Swap(VecIter<T> a, VecIter<T> b);
	};
}