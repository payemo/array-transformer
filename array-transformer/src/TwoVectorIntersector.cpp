#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <variant>
#include "TwoVectorIntersector.hpp"

namespace ng
{
	// PUBLIC ROUTINE

	template<typename T, class P>
	TwoVectorIntersector<T, P>::TwoVectorIntersector()
		: BaseVectorIntersector<T, P>(new VectorSorter<T, P>())
	{
	}

	template<typename T, class P>
	void TwoVectorIntersector<T, P>::Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P print)
	{
		Vec<Vec<T>> vecs = { {v1, v2, v3} };
		auto twoLargest = GetTwoLargest(vecs);

		Vec<T> vp = twoLargest.first, vp2 = twoLargest.second;

		if (!vp.empty() && !vp2.empty())
		{
			Vec<T> dummy{};
			this->sorter_->Compute(vp, vp2, dummy, print);

			Intersect(vp, vp2);
		}

		print(this->out_);
	}

	template<typename T, class P>
	void TwoVectorIntersector<T, P>::Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		Vec<Vec<T>> vecs = { {v1, v2, v3} };
		auto twoLargest = GetTwoLargest(vecs);

		Vec<T> vp = twoLargest.first, vp2 = twoLargest.second;
		std::set<T> s1(vp.begin(), vp.end());

		vp = twoLargest.second;
		std::set<T> s2(vp.begin(), vp.end());

		std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(this->out_));
	}

	// PROTECTED ROUTINE

	template<typename T, class P>
	void TwoVectorIntersector<T, P>::Intersect(Vec<T>& v1, Vec<T>& v2)
	{
		VecIter<T> first = v1.begin(), fLast = v1.end();
		VecIter<T> second = v2.begin(), sLast = v2.end();

		while (first != fLast && second != sLast)
		{
			if (*first < *second)
			{
				++first;
			}
			else
			{
				if (!(*second < *first))
				{
					this->out_.push_back(*first++);
				}
				++second;
			}
		}
	}

	template<typename T, class P>
	Pair<Vec<T>, Vec<T>> TwoVectorIntersector<T, P>::GetTwoLargest(Vec<Vec<T>>& vecs)
	{
		Vec<T> l1, l2;
		for (Vec<T>& v : vecs)
		{
			if (v.size() > l1.size())
			{
				l2.swap(l1);
				l1.swap(v);
			}
			else if (v.size() > l2.size())
			{
				l2.swap(v);
			}
		}

		return std::make_pair(l1, l2);
	}

	template TwoVectorIntersector<>::TwoVectorIntersector();

	template class TwoVectorIntersector<>;
}