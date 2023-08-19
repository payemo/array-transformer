#pragma once

#include <algorithm>
#include "VectorSorter.hpp"

namespace net_games
{
	template<typename T, class P = Printer<T>>
	class BaseVectorIntersector : public ArrayTransformer<T, P>
	{
	public:
		BaseVectorIntersector(VectorSorter<T, P>* sorter);
		virtual ~BaseVectorIntersector();

		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P print) = 0;
		virtual void Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) = 0;

	protected:
		VectorSorter<T, P>* sorter_{ nullptr };
		// Well, since the task is to print it seems like this member is redundand.
		Vec<T> out_{};
	};
}