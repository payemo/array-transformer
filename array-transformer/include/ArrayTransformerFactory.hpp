#pragma once

#include "ArgumentParser.hpp"
#include "ArrayTransformer.hpp"

#include <string>
#include <map>

namespace ng
{
	using namespace argsparser;

	template<typename T = double>
	struct ArrayTransformerFactory
	{
		ArrayTransformerFactory() = default;
		ArrayTransformerFactory(const ArrayTransformerFactory&) = delete;
		ArrayTransformerFactory& operator=(const ArrayTransformerFactory&) = delete;

		static ArrayTransformer<T>* CreateTransformer(Command op);
	};


}