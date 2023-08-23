#pragma once

#include "defs.hpp"
#include "ArrayFileStream.hpp"

#include <map>

namespace ng
{
	namespace cmdparser
	{
		enum class TransformCommand
		{
			SORT_ARRAYS,
			INTERSECT_TWO,
			INTERSECT_THREE,
			SYM_DIFF
		};

		bool Parse(int argc, char** argv);
	}
}