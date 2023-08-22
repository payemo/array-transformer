#pragma once

#include "defs.hpp"

#include <map>

namespace ng
{
	namespace argsparser
	{
		enum class Command
		{
			SORT_ARRAYS,
			INTERSECT_TWO,
			INTERSECT_THREE,
			SYM_DIFF
		};

		bool Parse(int argc, char** argv);
	}
}