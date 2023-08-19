#include <algorithm>
#include <iterator>
#include <set>
#include "ThreeVectorIntersector.hpp"

namespace net_games
{
	// PUBLIC ROUTINE

	template<typename T, class P>
	ThreeVectorIntersector<T, P>::ThreeVectorIntersector()
		: BaseVectorIntersector<T, P>(new VectorSorter<T, P>())
	{
	}

	template<typename T, class P>
	void ThreeVectorIntersector<T, P>::Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P print)
	{
		this->sorter_->Compute(v1, v2, v3, print);

		Intersect(v1, v2, v3);

		print(this->out_);
	}

	template<typename T, class P>
	void ThreeVectorIntersector<T, P>::Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
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

	template<typename T, class P>
	void ThreeVectorIntersector<T, P>::Intersect(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		VecIter<T> first = v1.begin(), second = v2.begin(), third = v3.begin();
		VecIter<T> lFirst = v1.end(), lSecond = v2.end(), lThird = v3.end();

		while (first != lFirst && second != lSecond && third != lThird)
		{
			if (*first == *second && *second == *third)
			{
				this->out_.push_back(*first);
				++first, ++second, ++third;
			}
			else if (*first < *second)
			{
				++first;
			}
			else if (*second < *third)
			{
				++second;
			}
			else
			{
				++third;
			}
		}
	}

	template ThreeVectorIntersector<int>::ThreeVectorIntersector();
	template ThreeVectorIntersector<unsigned int>::ThreeVectorIntersector();
}