#pragma once
#include "JaggedArray.hpp"

namespace net_game
{
	template<typename T>
	class ArrayTransformer
	{
	public:
		virtual void Compute(JaggedArray<T>& arr) = 0;
	};
}