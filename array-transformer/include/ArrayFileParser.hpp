#pragma once

#include <string>
#include <iterator>
#include "ArrayFileStream.hpp"

namespace ng
{
	class ArrayFileParser
	{
	public:
		template<typename T = double>
		static std::vector<std::vector<T>> Parse(ArrayFileStream& fs)
		{
			std::vector<std::vector<T>> out;

			std::vector<T> vec;
			std::string num;
			char ch;
			bool neg = false;
			while ((ch = fs.ReadChar()) != EOF)
			{
				if (std::isdigit(ch))
				{
					if (neg)
					{
						num += "-";
						neg = !neg;
					}
					num += ch;
				}
				else if (ch == '\n')
				{
					out.push_back(vec);
					vec.clear();
					num = "";
				}
				else if ((ch == ' ' || ch == ',') && !num.empty())
				{
					vec.push_back(std::stod(num));
					num = "";
				}
				else if (ch == '-')
				{
					neg = true;
				}
			}

			// set lasst number
			if (ch == EOF && !num.empty())
			{
				vec.push_back(std::stod(num));
			}

			// insert last array
			out.push_back(vec);

			return out;
		}
	};
}