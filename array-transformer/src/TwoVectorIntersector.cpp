#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include "TwoVectorIntersector.hpp"

namespace net_games
{
	// PUBLIC ROUTINE

	template<typename T>
	TwoVectorIntersector<T>::TwoVectorIntersector()
		: BaseVectorIntersector<T>(new VectorSorter<T>())
	{
	}

	template<typename T>
	void TwoVectorIntersector<T>::Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		std::pair<Vec<T>*, Vec<T>*> twoLargest = GetTwoLargest(v1, v2, v3);

		Vec<T>* vp = twoLargest.first;
		Vec<T>* vp2 = twoLargest.second;

		Vec<T> dummy{};
		this->sorter_->Compute(*vp, *vp2, dummy);

		Intersect(*vp, *vp2);
	}

	template<typename T>
	void TwoVectorIntersector<T>::Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		auto twoLargest = GetTwoLargest(v1, v2, v3);

		Vec<T>* vp = twoLargest.first;
		std::set<T> s1(vp->begin(), vp->end());

		vp = twoLargest.second;
		std::set<T> s2(vp->begin(), vp->end());

		std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(this->out_));
	}

	// PROTECTED ROUTINE

	template<typename T>
	void TwoVectorIntersector<T>::Intersect(Vec<T>& v1, Vec<T>& v2)
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

	template<typename T>
	std::pair<Vec<T>*, Vec<T>*> TwoVectorIntersector<T>::GetTwoLargest(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) const
	{
		// tackle with pointers a bit to avoid redundant copies
		std::size_t l1 = v1.size(), l2 = v2.size(), l3 = v3.size();

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

	template TwoVectorIntersector<int>::TwoVectorIntersector();
	template TwoVectorIntersector<unsigned int>::TwoVectorIntersector();

	template class TwoVectorIntersector<int>;
	template class TwoVectorIntersector<unsigned int>;
}