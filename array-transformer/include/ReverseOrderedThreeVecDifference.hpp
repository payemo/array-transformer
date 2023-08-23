#pragma once

#include "VectorSorter.hpp"
#include <deque>

namespace ng
{
	template<typename T = double, class P = PrintOutput<T>>
	class ReverseOrderedThreeVecDifference : public ArrayTransformer<T, P>
	{
	public:
		ReverseOrderedThreeVecDifference() { };

		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3, P print) override;
		void Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3);

	protected:
		Set<T> SymmetricDiff(const Set<T>& v1, const Set<T>& v2);
		void FillUniques(Set<T> diff, const Set<T>& s1, const Set<T>& s2, const Set<T>& s3);

	private:
		Deque<T> out_;
	};
}