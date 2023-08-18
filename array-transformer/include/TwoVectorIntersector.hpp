#pragma once

#include "BaseVectorIntersector.hpp"

namespace net_games
{
	template<typename T>
	class TwoVectorIntersector : public BaseVectorIntersector<T>
	{
	public:
		TwoVectorIntersector();

		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) override;
		void Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) override;

	protected:
		void Intersect(Vec<T>& v1, Vec<T>& v2);

		std::pair<Vec<T>*, Vec<T>*> GetTwoLargest(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) const;
	};
}