#include <set>
#include <map>
#include <algorithm>
#include <iterator>
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
		std::pair<Vec<T>*, Vec<T>*> twoLargest = GetTwoLargest(v1, v2, v3);

		Vec<T>* vp = twoLargest.first;
		Vec<T>* vp2 = twoLargest.second;

		Vec<T> dummy{};
		this->sorter_->Compute(*vp, *vp2, dummy, print);

		Intersect(*vp, *vp2);

		print(this->out_);
	}

	template<typename T, class P>
	void TwoVectorIntersector<T, P>::Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		auto twoLargest = GetTwoLargest(v1, v2, v3);

		Vec<T>* vp = twoLargest.first;
		std::set<T> s1(vp->begin(), vp->end());

		vp = twoLargest.second;
		std::set<T> s2(vp->begin(), vp->end());

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
	std::pair<Vec<T>*, Vec<T>*> TwoVectorIntersector<T, P>::GetTwoLargest(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) const
	{
		std::size_t l1 = v1.size(), l2 = v2.size(), l3 = v3.size();

		// Bug: same size of vectors.
		std::map<std::size_t, Vec<T>*> m = {
			{ l1, &v1 },
			{ l2, &v2 },
			{ l3, &v3 }
		};

		// (minSize, maxSize)
		auto minMax = std::minmax({ l1, l2, l3 });
		// second biggest
		std::size_t sb = (l1 + l2 + l3) - minMax.second - minMax.first;

		return std::make_pair(m[minMax.second], m[sb]);
	}

	template TwoVectorIntersector<>::TwoVectorIntersector();

	template class TwoVectorIntersector<>;
}