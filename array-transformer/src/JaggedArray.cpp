#include <stdexcept>
#include "JaggedArray.hpp"

namespace net_game
{
	// PUBLIC DEFINITIONS

	template<typename T>
	JaggedArray<T>::JaggedArray(const std::vector<T>& a1, const std::vector<T>& a2, const std::vector<T>& a3)
	{
		r2l[0] = a1.size();
		r2l[1] = a2.size();
		r2l[2] = a3.size();

		size = r2l[0] + r2l[1] + r2l[2];

		// reserve enough space for a linear array and fill it by input values.
		elems.reserve(size);
		elems.insert(elems.begin(), a1.begin(), a1.end());
		elems.insert(elems.begin() + (r2l[0]), a2.begin(), a2.end());
		elems.insert(elems.begin() + (r2l[0] + r2l[1]), a3.begin(), a3.end());
	}

	template<typename T>
	T& JaggedArray<T>::GetValue(int row, int col)
	{
		int si = GetRowSkipIndex(row);
		return elems[si + col];
	}

	// PRIVATE DEFINITIONS

	template<typename T>
	int JaggedArray<T>::GetRowSkipIndex(int row) const
	{
		if (row < 0 || row > 2)
		{
			throw std::out_of_range("Invalid row index: " + row);
		}

		if (row == 1)
		{
			return r2l[row - 1]; // [0]
		}
		else if (row == 2)
		{
			return r2l[row - 2] + r2l[row - 1];
		}
		return 0;
		/*return (r == 1) ? (r2l[r - 1]) :
			(r == 2) ? r2l[r - 2] + r2l[r - 1] : 0;*/
	}

	template<typename T>
	std::size_t JaggedArray<T>::GetArrayNLength(int n) const
	{
		if (n < 0 || n > 2)
		{
			throw std::out_of_range("Invalid row index: " + n);
		}

		return r2l[n];
	}

	// JaggedArray type template declaration;
	template class JaggedArray<int>;
	template class JaggedArray<double>;
	template class JaggedArray<float>;
}