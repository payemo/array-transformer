#pragma once

#include "BaseVectorIntersector.hpp"

namespace ng
{
	template<typename T = double, class P = PrintOutput<T>>
	class TwoVectorIntersector : public BaseVectorIntersector<T, P>
	{
	public:
		TwoVectorIntersector();

		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P print) override;
		void Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) override;

	protected:
		void Intersect(Vec<T>& v1, Vec<T>& v2);

		std::pair<Vec<T>*, Vec<T>*> GetTwoLargest(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) const;
	};
}