#include <set>
#include <algorithm>
#include <iterator>
#include "ReverseOrderedThreeVecDifference.hpp"

namespace net_games
{
	template<typename T>
	void ReverseOrderedThreeVecDifference<T>::Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		Set<T> s1(v1.begin(), v1.end());
		Set<T> s2(v2.begin(), v2.end());
		Set<T> s3(v3.begin(), v3.end());

		Set<T> diff1 = SymmetricDiff(s1, s2);
		Set<T> diff2 = SymmetricDiff(diff1, s3);

		FillUniques(diff2, s1, s2, s3);
	}

	template<typename T>
	void ReverseOrderedThreeVecDifference<T>::Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3)
	{
		Set<T> s1(v1.begin(), v1.end());
		Set<T> s2(v2.begin(), v2.end());
		Set<T> s3(v3.begin(), v3.end());

		Set<T> diff;
		std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(diff, diff.begin()));
		Set<T> diff2;
		std::set_symmetric_difference(diff.begin(), diff.end(), s3.begin(), s3.end(), std::inserter(diff2, diff2.begin()));

		FillUniques(diff2, s1, s2, s3);
	}

	template<typename T>
	Set<T> ReverseOrderedThreeVecDifference<T>::SymmetricDiff(const Set<T>& s1, const Set<T>& s2)
	{
		Set<T> out;
		auto first = s1.begin(), second = s2.begin();
		auto lFirst = s1.end(), lSecond = s2.end();

		while (first != lFirst && second != lSecond)
		{
			if (*first < *second)
			{
				out.insert(*first);
				++first;
			}
			else if (*first > *second)
			{
				out.insert(*second);
				++second;
			}
			else
			{
				++first, ++second;
			}
		}

		for (; first != lFirst; ++first)
			out.insert(*first);

		for (; second != lSecond; ++second)
			out.insert(*second);

		return out;
	}

	template<typename T>
	void ReverseOrderedThreeVecDifference<T>::FillUniques(Set<T> diff, const Set<T>& s1, const Set<T>& s2, const Set<T>& s3)
	{
		auto first = diff.begin(), last = diff.end();
		for (; first != last; ++first)
		{
			if ((s1.count(*first) && !s2.count(*first) && !s3.count(*first)) ||
				(s2.count(*first) && !s1.count(*first) && !s3.count(*first)) ||
				(s3.count(*first) && !s2.count(*first) && !s2.count(*first)))
			{
				this->out_.push_front(*first);
			}
		}
	}

	template ReverseOrderedThreeVecDifference<int>::ReverseOrderedThreeVecDifference();
	template ReverseOrderedThreeVecDifference<unsigned int>::ReverseOrderedThreeVecDifference();

	template void ReverseOrderedThreeVecDifference<int>::Compute_STL(Vec<int>& v1, Vec<int>& v2, Vec<int>& v3);
	template void ReverseOrderedThreeVecDifference<unsigned int>::Compute_STL(Vec<unsigned int>& v1, Vec<unsigned int>& v2, Vec<unsigned int>& v3);
}