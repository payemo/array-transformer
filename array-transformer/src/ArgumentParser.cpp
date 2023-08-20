#include <iostream>
#include "ArgumentParser.hpp"
#include "ArrayFileParser.hpp"
#include "ArrayTransformerFactory.hpp"

namespace ng
{
	std::map<std::string, Operation> ArgumentParser::operations =
	{
		{ "--exit",					 Operation::BREAK },
		{ "--sort",					 Operation::SORT_ARRAYS },
		{ "--intersect-all",		 Operation::INTERSECT_THREE },
		{ "--intersect-two-largest", Operation::INTERSECT_TWO },
		{ "--diff",					 Operation::SYM_DIFF }
	};

	bool ArgumentParser::Parse(int argc, char** argv)
	{
		if (argc != 2)
		{
			std::cerr << "File name is not specified." << std::endl;
		}

		ArrayFileStream afs(*++argv);

		if (!afs.IsValid())
		{
			std::cerr << "File " + std::string(*argv) + " cannot be opened." << std::endl;
			return false;
		}

		auto data = ArrayFileParser::Parse(afs);

		while (true)
		{
			std::string cmd;
			std::cout << "Command: ";
			std::cin >> cmd;

			if (!operations.count(cmd))
			{
				std::cout << "Wrong command..." << std::endl;
			}
			else if (operations[cmd] == Operation::BREAK)
			{
				break;
			}
			else
			{
				ArrayTransformer<>* at = ArrayTransformerFactory<>::CreateTransformer(operations[cmd]);
				at->Compute(data[0], data[1], data[2]);

				std::cout << std::endl;
			}
		}

		return true;
	}
}