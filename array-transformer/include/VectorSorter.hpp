#pragma once
#include <utility> // std::move
#include "VectorTransformer.hpp"

namespace net_games
{
	template<typename T>
	class VectorSorter : public VectorTransformer<T>
	{
	public:
		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) override;

	protected:
		void QSort(VecIter<T> it, int from, int to);

		int Partition(VecIter<T> it, int from, int to);

		void Swap(VecIter<T> a, VecIter<T> b);
	};
}