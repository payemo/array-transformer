#pragma once

#include <iostream>

namespace ng
{
	template<typename Stream = std::ostream>
	struct PrintOutput
	{
		template<template<typename...> class V, typename T = double>
		void operator()(const V<T>& elems) const
		{
			std::cout << "Result: ";
			for (const auto& elem : elems)
			{
				std::cout << elem << " ";
			}
			std::cout << std::endl;
		}
	};
}