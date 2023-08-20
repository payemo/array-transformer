#pragma once

#include <fstream>
#include <vector>
#include <iostream>

namespace net_games
{
	class ArrayFileStream
	{
	public:
		explicit ArrayFileStream(const char* filePath)
		{
			fs.open(filePath);

			if (fs.is_open())
			{
				std::cout << "HERE!" << std::endl;
			}
		}

		~ArrayFileStream() { fs.close(); }

		ArrayFileStream(const ArrayFileStream&) = default;
		ArrayFileStream(ArrayFileStream&&) = default;

		ArrayFileStream& operator=(const ArrayFileStream&) = default;
		ArrayFileStream& operator=(ArrayFileStream&&) = default;

		inline const bool IsValid() const { return fs.is_open(); }

	private:
		std::ifstream fs;
	};
}