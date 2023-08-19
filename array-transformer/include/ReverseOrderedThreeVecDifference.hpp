#pragma once

#include "VectorSorter.hpp"

namespace net_games
{
	template<typename T> using Set = typename std::set<T>;
	template<typename T> using SetIter = typename std::set<T>::iterator;

	template<typename T>
	class ReverseOrderedThreeVecDifference : public VectorTransformer<T>
	{
	public:
		ReverseOrderedThreeVecDifference() { };

		void Compute(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3) override;
		void Compute_STL(Vec<T>& v1, Vec<T>& v2, Vec<T>& v3);

		inline typename std::set<T>::reverse_iterator Result() { return out_.rbegin(); }

	protected:
		Set<T> Merge(const Set<T>& v1, const Set<T>& v2);
		void FillUnique(SetIter<T> first, SetIter<T> last, const Set<T>& s1, const Set<T>& s2, const Set<T>& s3);

	private:
		Set<T> out_;
	};
}