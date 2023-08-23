#include "CommandParser.hpp"
#include "ArrayFileParser.hpp"
#include "ArrayTransformerFactory.hpp"

#include <iostream>

namespace ng
{
	namespace cmdparser
	{
		std::map<String, TransformCommand> transformCommandList =
		{
			{ "--sort",					 TransformCommand::SORT_ARRAYS },
			{ "--intersect-all",		 TransformCommand::INTERSECT_THREE },
			{ "--intersect-two-largest", TransformCommand::INTERSECT_TWO },
			{ "--diff",					 TransformCommand::SYM_DIFF }
		};

		bool Parse(int argc, char** argv)
		{
			if (argc != 2)
			{
				std::cerr << "File name is not specified." << std::endl;
			}

			ArrayFileStream afs(*++argv);

			if (!afs.IsValid())
			{
				std::cerr << "File " + String(*argv) + " cannot be opened." << std::endl;
				return false;
			}

			Vec<Vec<>> data = fileparser::Parse(afs);

			for (;;)
			{
				String cmdStr;
				std::cout << "Enter command: ";
				std::cin >> cmdStr;

				if (cmdStr == "--exit")
				{
					break;
				}
				if (!transformCommandList.count(cmdStr))
				{
					std::cout << "Wrong command..." << std::endl;
					continue;
				}

				ArrayTransformer<>* at = ArrayTransformerFactory<>::CreateTransformer(transformCommandList[cmdStr]);
				at->Compute(data[0], data[1], data[2]);

				std::cout << std::endl;
			}

			return true;
		}
	}
}