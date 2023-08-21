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
		// to be sure that the first and second vectors are the largest
		DescSortBySize(v1, v2, v3);

		Vec<T> dummy{};
		this->sorter_->Compute(v1, v2, dummy, print);

		Intersect(v1, v2);

		print(this->out_);
	}

	template<typename T, class P>
	void TwoVectorIntersector<T, P>::Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		Vec<Vec<T>*> vecs = { {&v1, &v2, &v3} };
		DescSortBySize(v1, v2, v3);

		std::set<T> s1(v1.begin(), v2.end());
		std::set<T> s2(v1.begin(), v2.end());

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
	void TwoVectorIntersector<T, P>::DescSortBySize(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		if (v1.size() < v2.size())
		{
			v1.swap(v2);
		}
		if (v2.size() < v3.size())
		{
			v2.swap(v3);
		}
		if (v1.size() < v2.size())
		{
			v1.swap(v2);
		}
	}

	template TwoVectorIntersector<>::TwoVectorIntersector();

	template class TwoVectorIntersector<>;
}