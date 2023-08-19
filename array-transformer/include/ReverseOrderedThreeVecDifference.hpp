#pragma once

#include <list>
#include "VectorSorter.hpp"

namespace net_games
{
	template<typename T> using Set = typename std::set<T>;
	template<typename T> using ConstSetIter = typename std::set<T>::const_iterator;

	template<typename T> using List = typename std::list<T>;
	template<typename T> using ConstListIter = typename std::list<T>::const_iterator;

	template<typename T>
	class ReverseOrderedThreeVecDifference : public VectorTransformer<T>
	{
	public:
		ReverseOrderedThreeVecDifference() { };

		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) override;
		void Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3);

		inline const List<T>& Result() const { return out_; }

	protected:
		Set<T> SymmetricDiff(const Set<T>& v1, const Set<T>& v2);
		void FillUniques(Set<T> diff, const Set<T>& s1, const Set<T>& s2, const Set<T>& s3);

	private:
		// use O(1) for insertion
		List<T> out_;
	};
}