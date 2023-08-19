#pragma once

#include <string>
#include <map>
#include "ArrayTransformer.hpp"

namespace net_games
{
	using String = typename std::string;

	template<typename T>
	class ArrayTransformerFactory
	{
	public:
		enum class Operation
		{
			SORT_ARRAYS,
			INTERSECT_TWO,
			INTERSECT_THREE,
			SYM_DIFF
		};

	public:
		ArrayTransformerFactory(const String& operation);

		ArrayTransformer<T>* CreateTransformer();

	private:
		Operation op_;

	private:
		std::map<String, Operation> operations =
		{
			{ "-s", Operation::SORT_ARRAYS },
			{ "-i --all", Operation::INTERSECT_THREE },
			{ "-i --two-larget", Operation::INTERSECT_TWO },
			{ "-sd", Operation::SYM_DIFF }
		};
	};


}