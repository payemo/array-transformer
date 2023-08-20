#pragma once

#include <string>
#include <map>
#include "ArrayTransformer.hpp"

namespace ng
{
	using String = typename std::string;

	template<typename T = double>
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
			{ "--sort", Operation::SORT_ARRAYS },
			{ "--intersect-all", Operation::INTERSECT_THREE },
			{ "-intersect-two-largest", Operation::INTERSECT_TWO },
			{ "--diff", Operation::SYM_DIFF }
		};
	};


}