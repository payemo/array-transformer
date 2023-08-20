#pragma once

#include <list>
#include "VectorSorter.hpp"

namespace ng
{
	template<typename T> using Set = typename std::set<T>;
	template<typename T> using ConstSetIter = typename std::set<T>::const_iterator;

	template<typename T> using List = typename std::list<T>;
	template<typename T> using ConstListIter = typename std::list<T>::const_iterator;

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
		// use O(1) for insertion
		List<T> out_;
	};
}