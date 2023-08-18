#pragma once
#include "BaseVectorIntersector.hpp"

namespace net_games
{
	template<typename T>
	class ThreeVectorIntersector : public BaseVectorIntersector<T>
	{
	public:
		ThreeVectorIntersector();

		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) override;
		void Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) override;
	};
}