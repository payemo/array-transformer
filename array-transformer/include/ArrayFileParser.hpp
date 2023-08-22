#pragma once

#include "defs.hpp"
#include "ArrayFileStream.hpp"

#include <string>
#include <iterator>

namespace ng
{
	namespace fileparser
	{
		template<typename T = double>
		Vec<Vec<T>> Parse(ArrayFileStream& fs);
	}
}