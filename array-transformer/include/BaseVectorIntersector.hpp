#pragma once

#include "VectorSorter.hpp"

namespace net_games
{
	template<typename T>
	class BaseVectorIntersector : public VectorTransformer<T>
	{
	public:
		BaseVectorIntersector(VectorSorter<T>* sorter);
		virtual ~BaseVectorIntersector();

		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) = 0;
		virtual void Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) = 0;

		inline const Vec<T>& Result() const { return out_; };

	protected:
		VectorSorter<T>* sorter_{ nullptr };
		Vec<T> out_{};

	protected:
		void Intersect(Vec<T>& v1, Vec<T>& v2);
	};
}