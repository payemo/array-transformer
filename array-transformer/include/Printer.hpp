#pragma once

#include <iostream>

namespace net_games
{
	template<typename Stream = std::ostream>
	struct Printer
	{
		template<template<typename...> class V, typename T>
		void operator()(const V<T>& elems) const
		{
			for (const auto& elem : elems)
			{
				std::cout << elem << " ";
			}
			std::cout << std::endl;
		}
	};
}