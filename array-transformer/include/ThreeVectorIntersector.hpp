#pragma once
#include "BaseVectorIntersector.hpp"

namespace net_games
{
	template<typename T, class P = Printer<T>>
	class ThreeVectorIntersector : public BaseVectorIntersector<T, P>
	{
	public:
		ThreeVectorIntersector();

		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P print) override;
		void Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) override;

	protected:
		void Intersect(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3);
	};
}