#pragma once
#include "ArrayTransformer.hpp"

#include <utility>

namespace ng
{
	template<typename T = double, class P = PrintOutput<T>>
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