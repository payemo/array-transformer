#pragma once
#include <map>
#include "defs.hpp"

namespace ng
{
	enum class Command
	{
		BREAK,
		SORT_ARRAYS,
		INTERSECT_TWO,
		INTERSECT_THREE,
		SYM_DIFF
	};

	class ArgumentParser
	{
	public:
		static bool Parse(int argc, char** argv);

	private:
		static std::map<String, Command> commandList;
	};
}