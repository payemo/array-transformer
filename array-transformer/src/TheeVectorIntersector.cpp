#include <algorithm>
#include <iterator>
#include <set>
#include "ThreeVectorIntersector.hpp"

namespace net_games
{
	// PUBLIC ROUTINE

	template<typename T>
	ThreeVectorIntersector<T>::ThreeVectorIntersector()
		: BaseVectorIntersector<T>(new VectorSorter<T>())
	{
	}

	template<typename T>
	void ThreeVectorIntersector<T>::Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		this->sorter_->QSort(v1.begin(), 0, v1.size() - 1);
		this->sorter_->QSort(v2.begin(), 0, v2.size() - 1);
		this->sorter_->QSort(v3.begin(), 0, v3.size() - 1);
	}

	template<typename T>
	void ThreeVectorIntersector<T>::Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		std::set<T> s1(v1.begin(), v1.end());
		std::set<T> s2(v2.begin(), v2.end());
		std::set<T> s3(v3.begin(), v3.end());

		// s1 ∩ s2
		std::set<T> s0;
		std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s0, s0.begin()));
		// s0 ∩ s2
		std::set_intersection(s0.begin(), s0.end(), s3.begin(), s3.end(), std::back_inserter(this->out_));
	}

	template ThreeVectorIntersector<int>::ThreeVectorIntersector();
	template ThreeVectorIntersector<unsigned int>::ThreeVectorIntersector();
}