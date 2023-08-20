#pragma once
#include <map>
#include <string>

namespace ng
{
	enum class Operation
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
		static std::map<std::string, Operation> operations;
	};
}