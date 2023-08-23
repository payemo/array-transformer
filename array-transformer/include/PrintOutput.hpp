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

			for (auto it = elems.begin(); it != elems.end(); ++it)
			{
				std::cout << *it << " ";
			}
			
			std::cout << std::endl;
		}
	};
}