#pragma once

#include "ArrayTransformer.hpp"

namespace net_game
{
	template<typename T>
	class Sorter : public ArrayTransformer<T>
	{
	public:
		void Compute(JaggedArray<T>& arr) override;

	private:
		void QSort(typename std::vector<T>::iterator it, int s, int e);
		int Partition(typename std::vector<T>::iterator it, int s, int e);
		void Swap(
			typename std::vector<T>::iterator it,
			typename std::vector<T>::iterator it2);
	};
}