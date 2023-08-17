#ifndef ARRAY_TRANSFORM_JAGGED_ARRAY_HPP
#define ARRAY_TRANSFORM_JAGGED_ARRAY_HPP

#include <vector>

namespace net_game
{
	/*
		Jagged array represents an array of arrays that could possible be different sizes.
		[
			[1, 3, 2, -1],
			[5, 3, 3],
			[1, 5, 2, 4, 5, 10, 12]
		]
	*/
	template<typename T>
	class JaggedArray
	{
	public:
		JaggedArray(const std::vector<T>& arr1, const std::vector<T>& arr2, const std::vector<T>& arr3);
		~JaggedArray() { }

		/*
			row: number of array from which value should be retrieved.
			col: number of a column of a specific array from which value should be retrieved.
		*/
		T& GetValue(int row, int col);

		std::size_t GetArrayNLength(int n) const;

		typename std::vector<T>::iterator Begin() { return elems.begin(); }

	private: // properties
		int r2l[3]; // map row to length of an array
		std::vector<T> elems;
		std::size_t size;

	private: // functions
		int GetRowSkipIndex(int row) const;
	};
}

#endif // ARRAY_TRANSFORM_JAGGED_ARRAY_HPP