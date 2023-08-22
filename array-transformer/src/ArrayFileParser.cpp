#include "ArrayFileParser.hpp"

namespace ng
{
	namespace fileparser
	{
		template<typename T>
		Vec<Vec<T>> Parse(ArrayFileStream& fs)
		{
			Vec<Vec<T>> out;

			Vec<T> vec;
			String num;
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
					vec.push_back(std::stod(num));
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

			// set last number
			if (ch == EOF && !num.empty())
			{
				vec.push_back(std::stod(num));
			}

			// insert last array
			out.push_back(vec);

			return out;
		}

		template Vec<Vec<>> Parse(ArrayFileStream&);
	}
}