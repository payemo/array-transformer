#pragma once

#include <string>
#include <map>
#include "ArgumentParser.hpp"
#include "ArrayTransformer.hpp"

namespace ng
{
	using String = typename std::string;

	template<typename T = double>
	struct ArrayTransformerFactory
	{
		ArrayTransformerFactory() = default;
		ArrayTransformerFactory(const ArrayTransformerFactory&) = delete;
		ArrayTransformerFactory& operator=(const ArrayTransformerFactory&) = delete;

		static ArrayTransformer<T>* CreateTransformer(Operation op);
	};


}